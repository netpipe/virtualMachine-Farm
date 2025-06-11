#!/bin/sh
# AQEMU 0.7 Configure Script
# Lisence: GPL v2
# Author: Andrey Rijov (aka RDron)

QMAKE_PATH="/usr/bin/qmake"
QMAKE_QT4_PATH="/usr/bin/qmake-qt4"
VNC_HEADERS_PATH="/usr/include/rfb"
AQEMU_PROJECT_FILE="AQEMU.pro"

# OS Detection
if uname -a | grep "FreeBSD" > /dev/null; then
	QMAKE_PATH="/usr/local/bin/qmake"
	QMAKE_QT4_PATH="/usr/local/bin/qmake-qt4"
	VNC_HEADERS_PATH="/usr/local/include/rfb"
fi

# Use Embedded VNC Display
if [ "$1" = "--disable-embedded-display" ];
then
	echo "Embedded VNC Display Disabled"
	AQEMU_PROJECT_FILE="AQEMU_Without_VNC.pro"
else
	echo "Find Headers for Compile Embedded VNC Display..."
	
	if [ -e $VNC_HEADERS_PATH/rfbclient.h ];
	then
		echo "OK. Headers Finded."
	else
		echo "Error! Cannot Find VNC Headers!"
		echo "For Continue Compile Install libvncserver"
		echo "http://libvncserver.sourceforge.net/"
		echo ""
		echo "Or You Can Disable This Option by Running: ./configure --disable-embedded-display"
		exit 3
	fi
fi

# Find qmake
if [ -x $QMAKE_QT4_PATH ]
then
	echo "OK qmake-qt4 Installed on This Machine. Configuring..."
	
	if qmake-qt4 $AQEMU_PROJECT_FILE
	then
		echo "Type make for building AQEMU."
		exit 0
	else
		echo "Error! qmake-qt4 Return Non 0 Value!"
		exit 1
	fi
else
	if [ -x $QMAKE_PATH ]
	then
		echo "OK qmake Installed on This Machine. Configuring..."
		
		if qmake $AQEMU_PROJECT_FILE
		then
			echo "Type make for building AQEMU."
			exit 0
		else
			echo "Error! qmake Return Non 0 Value!"
			exit 1
		fi
	else
		echo "Error! Cannot Find qmake!"
		echo "For Continue You Most Type: qmake AQEMU.pro or qmake-qt4 AQEMU.pro"
		exit 2
	fi
fi
