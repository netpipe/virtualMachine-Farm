/****************************************************************************
**
** Copyright (C) 2002-2003 Tim Jansen <tim@tjansen.de>
** Copyright (C) 2007-2008 Urs Wolfer <uwolfer @ kde.org>
** Copyright (C) 2009 Andrey Rijov <ANDron142@yandex.ru>
**
** This file is part of KDE, QtEMU, AQEMU..
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; see the file COPYING. If not, write to
** the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
** Boston, MA 02110-1301, USA.
**
****************************************************************************/

#include "Remote_View.h"

#include <QBitmap>

RemoteView::RemoteView(QWidget *parent)
        : QWidget(parent),
        m_status(Disconnected),
        m_host(QString()),
        m_port(0),
        m_viewOnly(false),
        m_grabAllKeys(false),
        m_scale(false),
        m_keyboardIsGrabbed(false),
        m_dotCursorState(CursorOff)
{
}

RemoteView::~RemoteView()
{
}

RemoteView::RemoteStatus RemoteView::status()
{
    return m_status;
}

void RemoteView::setStatus(RemoteView::RemoteStatus s)
{
    if (m_status == s)
        return;

    if (((1+ m_status) != s) && (s != Disconnected)) {
        // follow state transition rules

        if (s == Disconnecting) {
            if (m_status == Disconnected)
                return;
        } else {
            Q_ASSERT(((int) s) >= 0);
            if (m_status > s) {
                m_status = Disconnected;
                emit statusChanged(Disconnected);
            }
            // smooth state transition
            RemoteStatus origState = m_status;
            for (int i = origState; i < s; i++) {
                m_status = (RemoteStatus) i;
                emit statusChanged((RemoteStatus) i);
            }
        }
    }
    m_status = s;
    emit statusChanged(m_status);
}

bool RemoteView::supportsScaling() const
{
    return false;
}

bool RemoteView::supportsLocalCursor() const
{
    return false;
}

QString RemoteView::host()
{
    return m_host;
}

QSize RemoteView::framebufferSize()
{
    return QSize(0, 0);
}

void RemoteView::startQuitting()
{
}

bool RemoteView::isQuitting()
{
    return false;
}

int RemoteView::port()
{
    return m_port;
}

void RemoteView::updateConfiguration()
{
}

void RemoteView::keyEvent(QKeyEvent *)
{
}

bool RemoteView::viewOnly()
{
    return m_viewOnly;
}

void RemoteView::setViewOnly(bool viewOnly)
{
    m_viewOnly = viewOnly;
}

bool RemoteView::grabAllKeys()
{
    return m_grabAllKeys;
}

void RemoteView::setGrabAllKeys(bool grabAllKeys)
{
    m_grabAllKeys = grabAllKeys;

    if (grabAllKeys) {
        m_keyboardIsGrabbed = true;
        grabKeyboard();
    } else if (m_keyboardIsGrabbed) {
        releaseKeyboard();
    }
}

void RemoteView::showDotCursor(DotCursorState state)
{
    m_dotCursorState = state;
}

RemoteView::DotCursorState RemoteView::dotCursorState() const
{
    return m_dotCursorState;
}

bool RemoteView::scaling() const
{
    return m_scale;
}

void RemoteView::enableScaling(bool scale)
{
    m_scale = scale;
}

void RemoteView::switchFullscreen(bool)
{
}

void RemoteView::scaleResize(int, int)
{
}

QUrl RemoteView::url()
{
    return m_url;
}

QCursor RemoteView::localDotCursor() const
{
    return QCursor();

	/* FIXME Cursor
    QBitmap cursorBitmap(KGlobal::dirs()->findResource("appdata","pics/pointcursor.png"));
    QBitmap cursorMask(KGlobal::dirs()->findResource("appdata","pics/pointcursormask.png"));
    return QCursor(cursorBitmap, cursorMask);
	*/
}

void RemoteView::focusInEvent(QFocusEvent *event)
{
    if (m_grabAllKeys) {
        m_keyboardIsGrabbed = true;
        grabKeyboard();
    }

    QWidget::focusInEvent(event);
}

void RemoteView::focusOutEvent(QFocusEvent *event)
{
    if (m_grabAllKeys || m_keyboardIsGrabbed) {
        m_keyboardIsGrabbed = false;
        releaseKeyboard();
    }

    QWidget::focusOutEvent(event);
}
