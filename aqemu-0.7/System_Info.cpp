/****************************************************************************
**
** Copyright (C) 2008-2009 Andrey Rijov <ANDron142@yandex.ru>
**
** This file is part of AQEMU.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor,
** Boston, MA  02110-1301, USA.
**
****************************************************************************/

#include <QSettings>
#include <QRegExp>
#include <QProcess>
#include <QFile>
#include <QTextStream>

#include "System_Info.h"

System_Info::System_Info()
{
}

bool System_Info::Update_VM_Computers_List()
{
	QSettings settings;
	
	QString ver = settings.value("QEMU_Version", "0.9.0").toString();
	
	Averable_Devices tmp_sys;
	
	// Devices Lists
	QList<Device_Map> CPU_x86;
	QList<Device_Map> CPU_ARM;
	QList<Device_Map> CPU_MIPS;
	QList<Device_Map> CPU_PPC;
	QList<Device_Map> CPU_Sparc;
	
	QList<Device_Map> Machine_x86;
	QList<Device_Map> Machine_ARM;
	QList<Device_Map> Machine_M68K;
	QList<Device_Map> Machine_MIPS;
	QList<Device_Map> Machine_PPC;
	QList<Device_Map> Machine_SH4;
	QList<Device_Map> Machine_Sparc;
	
	QList<Device_Map> Network_Card_x86;
	QList<Device_Map> Network_Card_x86_v090;
	QList<Device_Map> Network_Card_ARM;
	QList<Device_Map> Network_Card_M68K;
	QList<Device_Map> Network_Card_MIPS;
	QList<Device_Map> Network_Card_PPC;
	QList<Device_Map> Network_Card_Sparc;
	
	QList<Device_Map> Video_Card_Standart;
	QList<Device_Map> Video_Card_x86;
	
	VM::Sound_Cards Audio_Card_x86;
	VM::Sound_Cards Audio_Card_PPC;
	
	CPU_x86 << Device_Map( QObject::tr("Default"), "" );
	CPU_x86 << Device_Map( "QEMU 32Bit", "qemu32" );
	CPU_x86 << Device_Map( "Intel 486", "486" );
	CPU_x86 << Device_Map( "Pentium", "pentium" );
	CPU_x86 << Device_Map( "Pentium 2", "pentium2" );
	CPU_x86 << Device_Map( "Pentium 3", "pentium3" );
	
	CPU_ARM << Device_Map( QObject::tr("Default"), "" );
	CPU_ARM << Device_Map( "ARM 926", "arm926" );
	CPU_ARM << Device_Map( "ARM 946", "arm946" );
	CPU_ARM << Device_Map( "ARM 1026", "arm1026" );
	CPU_ARM << Device_Map( "ARM 1136", "arm1136" );
	CPU_ARM << Device_Map( "ARM 11 MPCORE", "arm11mpcore" );
	CPU_ARM << Device_Map( "Cortex-M3", "cortex-m3" );
	CPU_ARM << Device_Map( "Cortex-A8", "cortex-a8" );
	CPU_ARM << Device_Map( "Ti925T", "ti925t" );
	CPU_ARM << Device_Map( "PXA 250", "pxa250" );
	CPU_ARM << Device_Map( "PXA 255", "pxa255" );
	CPU_ARM << Device_Map( "PXA 260", "pxa260" );
	CPU_ARM << Device_Map( "PXA 261", "pxa261" );
	CPU_ARM << Device_Map( "PXA 262", "pxa262" );
	CPU_ARM << Device_Map( "PXA 270", "pxa270" );
	CPU_ARM << Device_Map( "PXA 270-a0", "pxa270-a0" );
	CPU_ARM << Device_Map( "PXA 270-a1", "pxa270-a1" );
	CPU_ARM << Device_Map( "PXA 270-b0", "pxa270-b0" );
	CPU_ARM << Device_Map( "PXA 270-b1", "pxa270-b1" );
	CPU_ARM << Device_Map( "PXA 270-c0", "pxa270-c0" );
	CPU_ARM << Device_Map( "PXA 270-c5", "pxa270-c5" );
	CPU_ARM << Device_Map( "Any", "any" );
	
	CPU_MIPS << Device_Map( QObject::tr("Default"), "" );
	CPU_MIPS << Device_Map( "4Kc", "4Kc" );
	CPU_MIPS << Device_Map( "4Km", "4Km" );
	CPU_MIPS << Device_Map( "4KEcR1", "4KEcR1" );
	CPU_MIPS << Device_Map( "4KEmR1", "4KEmR1" );
	CPU_MIPS << Device_Map( "4KEc", "4KEc" );
	CPU_MIPS << Device_Map( "4KEm", "4KEm" );
	CPU_MIPS << Device_Map( "24Kc", "24Kc" );
	CPU_MIPS << Device_Map( "24Kf", "24Kf" );
	CPU_MIPS << Device_Map( "34Kf", "34Kf" );
	
	CPU_PPC << Device_Map( QObject::tr("Default"), "default" );
	CPU_PPC << Device_Map( "401", "401" );
	CPU_PPC << Device_Map( "401A1", "401A1" );
	CPU_PPC << Device_Map( "401B2", "401B2" );
	CPU_PPC << Device_Map( "401C2", "401C2" );
	CPU_PPC << Device_Map( "401D2", "401D2" );
	CPU_PPC << Device_Map( "401E2", "401E2" );
	CPU_PPC << Device_Map( "401F2", "401F2" );
	CPU_PPC << Device_Map( "401G2", "401G2" );
	CPU_PPC << Device_Map( "IOP480", "IOP480" );
	CPU_PPC << Device_Map( "Cobra", "Cobra" );
	CPU_PPC << Device_Map( "403", "403" );
	CPU_PPC << Device_Map( "403GA", "403GA" );
	CPU_PPC << Device_Map( "403GB", "403GB" );
	CPU_PPC << Device_Map( "403GC", "403GC" );
	CPU_PPC << Device_Map( "403GCX", "403GCX" );
	CPU_PPC << Device_Map( "405", "405" );
	CPU_PPC << Device_Map( "405D2", "405D2" );
	CPU_PPC << Device_Map( "405D4", "405D4" );
	CPU_PPC << Device_Map( "405CR", "405CR" );
	CPU_PPC << Device_Map( "405CRa", "405CRa" );
	CPU_PPC << Device_Map( "405CRb", "405CRb" );
	CPU_PPC << Device_Map( "405CRc", "405CRc" );
	CPU_PPC << Device_Map( "405EP", "405EP" );
	CPU_PPC << Device_Map( "405EZ", "405EZ" );
	CPU_PPC << Device_Map( "405GP", "405GP" );
	CPU_PPC << Device_Map( "405GPa", "405GPa" );
	CPU_PPC << Device_Map( "405GPb", "405GPb" );
	CPU_PPC << Device_Map( "405GPc", "405GPc" );
	CPU_PPC << Device_Map( "405GPd", "405GPd" );
	CPU_PPC << Device_Map( "405GPe", "405GPe" );
	CPU_PPC << Device_Map( "405GPR", "405GPR" );
	CPU_PPC << Device_Map( "405LP", "405LP" );
	CPU_PPC << Device_Map( "Npe405H", "Npe405H" );
	CPU_PPC << Device_Map( "Npe405H2", "Npe405H2" );
	CPU_PPC << Device_Map( "Npe405L", "Npe405L" );
	CPU_PPC << Device_Map( "Npe4GS3", "Npe4GS3" );
	CPU_PPC << Device_Map( "STB03", "STB03" );
	CPU_PPC << Device_Map( "STB04", "STB04" );
	CPU_PPC << Device_Map( "STB25", "STB25" );
	CPU_PPC << Device_Map( "x2vp4", "x2vp4" );
	CPU_PPC << Device_Map( "x2vp7", "x2vp7" );
	CPU_PPC << Device_Map( "x2vp20", "x2vp20" );
	CPU_PPC << Device_Map( "x2vp50", "x2vp50" );
	CPU_PPC << Device_Map( "MPC52xx", "MPC52xx" );
	CPU_PPC << Device_Map( "MPC82xx", "MPC82xx" );
	CPU_PPC << Device_Map( "PowerQUICC-II", "\"PowerQUICC-II\"" );
	CPU_PPC << Device_Map( "G2", "G2" );
	CPU_PPC << Device_Map( "G2H4", "G2H4" );
	CPU_PPC << Device_Map( "G2GP", "G2GP" );
	CPU_PPC << Device_Map( "G2LS", "G2LS" );
	CPU_PPC << Device_Map( "G2HiP3", "G2HiP3" );
	CPU_PPC << Device_Map( "G2HiP4", "G2HiP4" );
	CPU_PPC << Device_Map( "MPC603", "MPC603" );
	CPU_PPC << Device_Map( "G2le", "G2le" );
	CPU_PPC << Device_Map( "G2leGP", "G2leGP" );
	CPU_PPC << Device_Map( "G2leLS", "G2leLS" );
	CPU_PPC << Device_Map( "G2leGP1", "G2leGP1" );
	CPU_PPC << Device_Map( "G2leGP3", "G2leGP3" );
	CPU_PPC << Device_Map( "MPC8240", "MPC8240" );
	CPU_PPC << Device_Map( "MPC5200", "MPC5200" );
	CPU_PPC << Device_Map( "MPC5200_v10", "MPC5200_v10" );
	CPU_PPC << Device_Map( "MPC5200_v11", "MPC5200_v11" );
	CPU_PPC << Device_Map( "MPC5200_v12", "MPC5200_v12" );
	CPU_PPC << Device_Map( "MPC5200B", "MPC5200B" );
	CPU_PPC << Device_Map( "MPC5200B_v20", "MPC5200B_v20" );
	CPU_PPC << Device_Map( "MPC5200B_v21", "MPC5200B_v21" );
	CPU_PPC << Device_Map( "MPC8241", "MPC8241" );
	CPU_PPC << Device_Map( "MPC8245", "MPC8245" );
	CPU_PPC << Device_Map( "MPC8247", "MPC8247" );
	CPU_PPC << Device_Map( "MPC8248", "MPC8248" );
	CPU_PPC << Device_Map( "MPC8250", "MPC8250" );
	CPU_PPC << Device_Map( "MPC8250_HiP3", "MPC8250_HiP3" );
	CPU_PPC << Device_Map( "MPC8250_HiP4", "MPC8250_HiP4" );
	CPU_PPC << Device_Map( "MPC8255", "MPC8255" );
	CPU_PPC << Device_Map( "MPC8255_HiP3", "MPC8255_HiP3" );
	CPU_PPC << Device_Map( "MPC8255_HiP4", "MPC8255_HiP4" );
	CPU_PPC << Device_Map( "MPC8260", "MPC8260" );
	CPU_PPC << Device_Map( "MPC8260_HiP3", "MPC8260_HiP3" );
	CPU_PPC << Device_Map( "MPC8260_HiP4", "MPC8260_HiP4" );
	CPU_PPC << Device_Map( "MPC8264", "MPC8264" );
	CPU_PPC << Device_Map( "MPC8264_HiP3", "MPC8264_HiP3" );
	CPU_PPC << Device_Map( "MPC8264_HiP4", "MPC8264_HiP4" );
	CPU_PPC << Device_Map( "MPC8265", "MPC8265" );
	CPU_PPC << Device_Map( "MPC8265_HiP3", "MPC8265_HiP3" );
	CPU_PPC << Device_Map( "MPC8265_HiP4", "MPC8265_HiP4" );
	CPU_PPC << Device_Map( "MPC8266", "MPC8266" );
	CPU_PPC << Device_Map( "MPC8266_HiP3", "MPC8266_HiP3" );
	CPU_PPC << Device_Map( "MPC8266_HiP4", "MPC8266_HiP4" );
	CPU_PPC << Device_Map( "MPC8270", "MPC8270" );
	CPU_PPC << Device_Map( "MPC8271", "MPC8271" );
	CPU_PPC << Device_Map( "MPC8272", "MPC8272" );
	CPU_PPC << Device_Map( "MPC8275", "MPC8275" );
	CPU_PPC << Device_Map( "MPC8280", "MPC8280" );
	CPU_PPC << Device_Map( "e200", "e200" );
	CPU_PPC << Device_Map( "e200z5", "e200z5" );
	CPU_PPC << Device_Map( "e200z6", "e200z6" );
	CPU_PPC << Device_Map( "e300", "e300" );
	CPU_PPC << Device_Map( "e300c1", "e300c1" );
	CPU_PPC << Device_Map( "e300c2", "e300c2" );
	CPU_PPC << Device_Map( "e300c3", "e300c3" );
	CPU_PPC << Device_Map( "e300c4", "e300c4" );
	CPU_PPC << Device_Map( "MPC8343A", "MPC8343A" );
	CPU_PPC << Device_Map( "MPC8343EA", "MPC8343EA" );
	CPU_PPC << Device_Map( "MPC8347A", "MPC8347A" );
	CPU_PPC << Device_Map( "MPC8347AT", "MPC8347AT" );
	CPU_PPC << Device_Map( "MPC8347AP", "MPC8347AP" );
	CPU_PPC << Device_Map( "MPC8347EA", "MPC8347EA" );
	CPU_PPC << Device_Map( "MPC8347EAT", "MPC8347EAT" );
	CPU_PPC << Device_Map( "MPC8347EAP", "MPC8347EAP" );
	CPU_PPC << Device_Map( "MPC8349", "MPC8349" );
	CPU_PPC << Device_Map( "MPC8349A", "MPC8349A" );
	CPU_PPC << Device_Map( "MPC8349E", "MPC8349E" );
	CPU_PPC << Device_Map( "MPC8349EA", "MPC8349EA" );
	CPU_PPC << Device_Map( "MPC8377", "MPC8377" );
	CPU_PPC << Device_Map( "MPC8377E", "MPC8377E" );
	CPU_PPC << Device_Map( "MPC8378", "MPC8378" );
	CPU_PPC << Device_Map( "MPC8378E", "MPC8378E" );
	CPU_PPC << Device_Map( "MPC8379", "MPC8379" );
	CPU_PPC << Device_Map( "MPC8379E", "MPC8379E" );
	CPU_PPC << Device_Map( "e500", "e500" );
	CPU_PPC << Device_Map( "e500_v10", "e500_v10" );
	CPU_PPC << Device_Map( "e500_v20", "e500_v20" );
	CPU_PPC << Device_Map( "e500v2", "e500v2" );
	CPU_PPC << Device_Map( "e500v2_v10", "e500v2_v10" );
	CPU_PPC << Device_Map( "e500v2_v20", "e500v2_v20" );
	CPU_PPC << Device_Map( "e500v2_v21", "e500v2_v21" );
	CPU_PPC << Device_Map( "e500v2_v22", "e500v2_v22" );
	CPU_PPC << Device_Map( "e500v2_v30", "e500v2_v30" );
	CPU_PPC << Device_Map( "MPC8533", "MPC8533" );
	CPU_PPC << Device_Map( "MPC8533_v10", "MPC8533_v10" );
	CPU_PPC << Device_Map( "MPC8533_v11", "MPC8533_v11" );
	CPU_PPC << Device_Map( "MPC8533E", "MPC8533E" );
	CPU_PPC << Device_Map( "MPC8533E_v10", "MPC8533E_v10" );
	CPU_PPC << Device_Map( "MPC8533E_v11", "MPC8533E_v11" );
	CPU_PPC << Device_Map( "MPC8540", "MPC8540" );
	CPU_PPC << Device_Map( "MPC8540_v10", "MPC8540_v10" );
	CPU_PPC << Device_Map( "MPC8540_v20", "MPC8540_v20" );
	CPU_PPC << Device_Map( "MPC8540_v21", "MPC8540_v21" );
	CPU_PPC << Device_Map( "MPC8541", "MPC8541" );
	CPU_PPC << Device_Map( "MPC8541_v10", "MPC8541_v10" );
	CPU_PPC << Device_Map( "MPC8541_v11", "MPC8541_v11" );
	CPU_PPC << Device_Map( "MPC8541E", "MPC8541E" );
	CPU_PPC << Device_Map( "MPC8541E_v10", "MPC8541E_v10" );
	CPU_PPC << Device_Map( "MPC8541E_v11", "MPC8541E_v11" );
	CPU_PPC << Device_Map( "MPC8543", "MPC8543" );
	CPU_PPC << Device_Map( "MPC8543_v10", "MPC8543_v10" );
	CPU_PPC << Device_Map( "MPC8543_v11", "MPC8543_v11" );
	CPU_PPC << Device_Map( "MPC8543_v20", "MPC8543_v20" );
	CPU_PPC << Device_Map( "MPC8543_v21", "MPC8543_v21" );
	CPU_PPC << Device_Map( "MPC8543E", "MPC8543E" );
	CPU_PPC << Device_Map( "MPC8543E_v10", "MPC8543E_v10" );
	CPU_PPC << Device_Map( "MPC8543E_v11", "MPC8543E_v11" );
	CPU_PPC << Device_Map( "MPC8543E_v20", "MPC8543E_v20" );
	CPU_PPC << Device_Map( "MPC8543E_v21", "MPC8543E_v21" );
	CPU_PPC << Device_Map( "MPC8544", "MPC8544" );
	CPU_PPC << Device_Map( "MPC8544_v10", "MPC8544_v10" );
	CPU_PPC << Device_Map( "MPC8544_v11", "MPC8544_v11" );
	CPU_PPC << Device_Map( "MPC8544E", "MPC8544E" );
	CPU_PPC << Device_Map( "MPC8544E_v10", "MPC8544E_v10" );
	CPU_PPC << Device_Map( "MPC8544E_v11", "MPC8544E_v11" );
	CPU_PPC << Device_Map( "MPC8545", "MPC8545" );
	CPU_PPC << Device_Map( "MPC8545_v20", "MPC8545_v20" );
	CPU_PPC << Device_Map( "MPC8545_v21", "MPC8545_v21" );
	CPU_PPC << Device_Map( "MPC8545E", "MPC8545E" );
	CPU_PPC << Device_Map( "MPC8545E_v20", "MPC8545E_v20" );
	CPU_PPC << Device_Map( "MPC8545E_v21", "MPC8545E_v21" );
	CPU_PPC << Device_Map( "MPC8547E", "MPC8547E" );
	CPU_PPC << Device_Map( "MPC8547E_v20", "MPC8547E_v20" );
	CPU_PPC << Device_Map( "MPC8547E_v21", "MPC8547E_v21" );
	CPU_PPC << Device_Map( "MPC8548", "MPC8548" );
	CPU_PPC << Device_Map( "MPC8548_v10", "MPC8548_v10" );
	CPU_PPC << Device_Map( "MPC8548_v11", "MPC8548_v11" );
	CPU_PPC << Device_Map( "MPC8548_v20", "MPC8548_v20" );
	CPU_PPC << Device_Map( "MPC8548_v21", "MPC8548_v21" );
	CPU_PPC << Device_Map( "MPC8548E", "MPC8548E" );
	CPU_PPC << Device_Map( "MPC8548E_v10", "MPC8548E_v10" );
	CPU_PPC << Device_Map( "MPC8548E_v11", "MPC8548E_v11" );
	CPU_PPC << Device_Map( "MPC8548E_v20", "MPC8548E_v20" );
	CPU_PPC << Device_Map( "MPC8548E_v21", "MPC8548E_v21" );
	CPU_PPC << Device_Map( "MPC8555", "MPC8555" );
	CPU_PPC << Device_Map( "MPC8555_v10", "MPC8555_v10" );
	CPU_PPC << Device_Map( "MPC8555_v11", "MPC8555_v11" );
	CPU_PPC << Device_Map( "MPC8555E", "MPC8555E" );
	CPU_PPC << Device_Map( "MPC8555E_v10", "MPC8555E_v10" );
	CPU_PPC << Device_Map( "MPC8555E_v11", "MPC8555E_v11" );
	CPU_PPC << Device_Map( "MPC8560", "MPC8560" );
	CPU_PPC << Device_Map( "MPC8560_v10", "MPC8560_v10" );
	CPU_PPC << Device_Map( "MPC8560_v20", "MPC8560_v20" );
	CPU_PPC << Device_Map( "MPC8560_v21", "MPC8560_v21" );
	CPU_PPC << Device_Map( "MPC8567", "MPC8567" );
	CPU_PPC << Device_Map( "MPC8567E", "MPC8567E" );
	CPU_PPC << Device_Map( "MPC8568", "MPC8568" );
	CPU_PPC << Device_Map( "MPC8568E", "MPC8568E" );
	CPU_PPC << Device_Map( "MPC8572", "MPC8572" );
	CPU_PPC << Device_Map( "MPC8572E", "MPC8572E" );
	CPU_PPC << Device_Map( "e600", "e600" );
	CPU_PPC << Device_Map( "MPC8641", "MPC8641" );
	CPU_PPC << Device_Map( "MPC8641D", "MPC8641D" );
	CPU_PPC << Device_Map( "601", "601" );
	CPU_PPC << Device_Map( "601_v0", "601_v0" );
	CPU_PPC << Device_Map( "601_v1", "601_v1" );
	CPU_PPC << Device_Map( "601v", "601v" );
	CPU_PPC << Device_Map( "601_v2", "601_v2" );
	CPU_PPC << Device_Map( "602", "602" );
	CPU_PPC << Device_Map( "603", "603" );
	CPU_PPC << Device_Map( "Vanilla", "Vanilla" );
	CPU_PPC << Device_Map( "603e", "603e" );
	CPU_PPC << Device_Map( "Stretch", "Stretch" );
	CPU_PPC << Device_Map( "603e_v1.1", "\"603e_v1.1\"" );
	CPU_PPC << Device_Map( "603e_v1.2", "\"603e_v1.2\"" );
	CPU_PPC << Device_Map( "603e_v1.3", "\"603e_v1.3\"" );
	CPU_PPC << Device_Map( "603e_v1.4", "\"603e_v1.4\"" );
	CPU_PPC << Device_Map( "603e_v2.2", "\"603e_v2.2\"" );
	CPU_PPC << Device_Map( "603e_v3", "603e_v3" );
	CPU_PPC << Device_Map( "603e_v4", "603e_v4" );
	CPU_PPC << Device_Map( "603e_v4.1", "\"603e_v4.1\"" );
	CPU_PPC << Device_Map( "603e7", "603e7" );
	CPU_PPC << Device_Map( "603e7t", "603e7t" );
	CPU_PPC << Device_Map( "603e7v", "603e7v" );
	CPU_PPC << Device_Map( "Vaillant", "Vaillant" );
	CPU_PPC << Device_Map( "603e7v1", "603e7v1" );
	CPU_PPC << Device_Map( "603e7v2", "603e7v2" );
	CPU_PPC << Device_Map( "603p", "603p" );
	CPU_PPC << Device_Map( "603r", "603r" );
	CPU_PPC << Device_Map( "Goldeneye", "Goldeneye" );
	CPU_PPC << Device_Map( "604", "604" );
	CPU_PPC << Device_Map( "604e", "604e" );
	CPU_PPC << Device_Map( "Sirocco", "Sirocco" );
	CPU_PPC << Device_Map( "604e_v1.0", "\"604e_v1.0\"" );
	CPU_PPC << Device_Map( "604e_v2.2", "\"604e_v2.2\"" );
	CPU_PPC << Device_Map( "604e_v2.4", "\"604e_v2.4\"" );
	CPU_PPC << Device_Map( "604r", "604r" );
	CPU_PPC << Device_Map( "Mach5", "Mach5" );
	CPU_PPC << Device_Map( "740", "740" );
	CPU_PPC << Device_Map( "Arthur", "Arthur" );
	CPU_PPC << Device_Map( "750", "750" );
	CPU_PPC << Device_Map( "Typhoon", "Typhoon" );
	CPU_PPC << Device_Map( "G3", "G3" );
	CPU_PPC << Device_Map( "740_v1.0", "\"740_v1.0\"" );
	CPU_PPC << Device_Map( "750_v1.0", "\"750_v1.0\"" );
	CPU_PPC << Device_Map( "740_v2.0", "\"740_v2.0\"" );
	CPU_PPC << Device_Map( "750_v2.0", "\"750_v2.0\"" );
	CPU_PPC << Device_Map( "740_v2.1", "\"740_v2.1\"" );
	CPU_PPC << Device_Map( "750_v2.1", "\"750_v2.1\"" );
	CPU_PPC << Device_Map( "740_v2.2", "\"740_v2.2\"" );
	CPU_PPC << Device_Map( "750_v2.2", "\"750_v2.2\"" );
	CPU_PPC << Device_Map( "740_v3.0", "\"740_v3.0\"" );
	CPU_PPC << Device_Map( "750_v3.0", "\"750_v3.0\"" );
	CPU_PPC << Device_Map( "740_v3.1", "\"740_v3.1\"" );
	CPU_PPC << Device_Map( "750_v3.1", "\"750_v3.1\"" );
	CPU_PPC << Device_Map( "740e", "740e" );
	CPU_PPC << Device_Map( "750e", "750e" );
	CPU_PPC << Device_Map( "740p", "740p" );
	CPU_PPC << Device_Map( "750p", "750p" );
	CPU_PPC << Device_Map( "Conan/Doyle", "\"Conan/Doyle\"" );
	CPU_PPC << Device_Map( "750cl", "750cl" );
	CPU_PPC << Device_Map( "750cl_v1.0", "\"750cl_v1.0\"" );
	CPU_PPC << Device_Map( "750cl_v2.0", "\"750cl_v2.0\"" );
	CPU_PPC << Device_Map( "750cx", "750cx" );
	CPU_PPC << Device_Map( "750cx_v1.0", "\"750cx_v1.0\"" );
	CPU_PPC << Device_Map( "750cx_v2.0", "\"750cx_v2.0\"" );
	CPU_PPC << Device_Map( "750cx_v2.1", "\"750cx_v2.1\"" );
	CPU_PPC << Device_Map( "750cx_v2.2", "\"750cx_v2.2\"" );
	CPU_PPC << Device_Map( "750cxe", "750cxe" );
	CPU_PPC << Device_Map( "750cxe_v2.1", "\"750cxe_v2.1\"" );
	CPU_PPC << Device_Map( "750cxe_v2.2", "\"750cxe_v2.2\"" );
	CPU_PPC << Device_Map( "750cxe_v2.3", "\"750cxe_v2.3\"" );
	CPU_PPC << Device_Map( "750cxe_v2.4", "\"750cxe_v2.4\"" );
	CPU_PPC << Device_Map( "750cxe_v2.4b", "\"750cxe_v2.4b\"" );
	CPU_PPC << Device_Map( "750cxe_v3.0", "\"750cxe_v3.0\"" );
	CPU_PPC << Device_Map( "750cxe_v3.1", "\"750cxe_v3.1\"" );
	CPU_PPC << Device_Map( "750cxe_v3.1b", "\"750cxe_v3.1b\"" );
	CPU_PPC << Device_Map( "750cxr", "750cxr" );
	CPU_PPC << Device_Map( "750fl", "750fl" );
	CPU_PPC << Device_Map( "750fx", "750fx" );
	CPU_PPC << Device_Map( "750fx_v1.0", "\"750fx_v1.0\"" );
	CPU_PPC << Device_Map( "750fx_v2.0", "\"750fx_v2.0\"" );
	CPU_PPC << Device_Map( "750fx_v2.1", "\"750fx_v2.1\"" );
	CPU_PPC << Device_Map( "750fx_v2.2", "\"750fx_v2.2\"" );
	CPU_PPC << Device_Map( "750fx_v2.3", "\"750fx_v2.3\"" );
	CPU_PPC << Device_Map( "750gl", "750gl" );
	CPU_PPC << Device_Map( "750gx", "750gx" );
	CPU_PPC << Device_Map( "750gx_v1.0", "\"750gx_v1.0\"" );
	CPU_PPC << Device_Map( "750gx_v1.1", "\"750gx_v1.1\"" );
	CPU_PPC << Device_Map( "750gx_v1.2", "\"750gx_v1.2\"" );
	CPU_PPC << Device_Map( "750l", "750l" );
	CPU_PPC << Device_Map( "LoneStar", "LoneStar" );
	CPU_PPC << Device_Map( "750l_v2.0", "\"750l_v2.0\"" );
	CPU_PPC << Device_Map( "750l_v2.1", "\"750l_v2.1\"" );
	CPU_PPC << Device_Map( "750l_v2.2", "\"750l_v2.2\"" );
	CPU_PPC << Device_Map( "750l_v3.0", "\"750l_v3.0\"" );
	CPU_PPC << Device_Map( "750l_v3.2", "\"750l_v3.2\"" );
	CPU_PPC << Device_Map( "745", "745" );
	CPU_PPC << Device_Map( "755", "755" );
	CPU_PPC << Device_Map( "Goldfinger", "Goldfinger" );
	CPU_PPC << Device_Map( "745_v1.0", "\"745_v1.0\"" );
	CPU_PPC << Device_Map( "755_v1.0", "\"755_v1.0\"" );
	CPU_PPC << Device_Map( "745_v1.1", "\"745_v1.1\"" );
	CPU_PPC << Device_Map( "755_v1.1", "\"755_v1.1\"" );
	CPU_PPC << Device_Map( "745_v2.0", "\"745_v2.0\"" );
	CPU_PPC << Device_Map( "755_v2.0", "\"755_v2.0\"" );
	CPU_PPC << Device_Map( "745_v2.1", "\"745_v2.1\"" );
	CPU_PPC << Device_Map( "755_v2.1", "\"755_v2.1\"" );
	CPU_PPC << Device_Map( "745_v2.2", "\"745_v2.2\"" );
	CPU_PPC << Device_Map( "755_v2.2", "\"755_v2.2\"" );
	CPU_PPC << Device_Map( "745_v2.3", "\"745_v2.3\"" );
	CPU_PPC << Device_Map( "755_v2.3", "\"755_v2.3\"" );
	CPU_PPC << Device_Map( "745_v2.4", "\"745_v2.4\"" );
	CPU_PPC << Device_Map( "755_v2.4", "\"755_v2.4\"" );
	CPU_PPC << Device_Map( "745_v2.5", "\"745_v2.5\"" );
	CPU_PPC << Device_Map( "755_v2.5", "\"755_v2.5\"" );
	CPU_PPC << Device_Map( "745_v2.6", "\"745_v2.6\"" );
	CPU_PPC << Device_Map( "755_v2.6", "\"755_v2.6\"" );
	CPU_PPC << Device_Map( "745_v2.7", "\"745_v2.7\"" );
	CPU_PPC << Device_Map( "755_v2.7", "\"755_v2.7\"" );
	CPU_PPC << Device_Map( "745_v2.8", "\"745_v2.8\"" );
	CPU_PPC << Device_Map( "755_v2.8", "\"755_v2.8\"" );
	CPU_PPC << Device_Map( "7400", "7400" );
	CPU_PPC << Device_Map( "Max", "Max" );
	CPU_PPC << Device_Map( "G4", "G4" );
	CPU_PPC << Device_Map( "7400_v1.0", "\"7400_v1.0\"" );
	CPU_PPC << Device_Map( "7400_v1.1", "\"7400_v1.1\"" );
	CPU_PPC << Device_Map( "7400_v2.0", "\"7400_v2.0\"" );
	CPU_PPC << Device_Map( "7400_v2.1", "\"7400_v2.1\"" );
	CPU_PPC << Device_Map( "7400_v2.2", "\"7400_v2.2\"" );
	CPU_PPC << Device_Map( "7400_v2.6", "\"7400_v2.6\"" );
	CPU_PPC << Device_Map( "7400_v2.7", "\"7400_v2.7\"" );
	CPU_PPC << Device_Map( "7400_v2.8", "\"7400_v2.8\"" );
	CPU_PPC << Device_Map( "7400_v2.9", "\"7400_v2.9\"" );
	CPU_PPC << Device_Map( "7410", "7410" );
	CPU_PPC << Device_Map( "Nitro", "Nitro" );
	CPU_PPC << Device_Map( "7410_v1.0", "\"7410_v1.0\"" );
	CPU_PPC << Device_Map( "7410_v1.1", "\"7410_v1.1\"" );
	CPU_PPC << Device_Map( "7410_v1.2", "\"7410_v1.2\"" );
	CPU_PPC << Device_Map( "7410_v1.3", "\"7410_v1.3\"" );
	CPU_PPC << Device_Map( "7410_v1.4", "\"7410_v1.4\"" );
	CPU_PPC << Device_Map( "7448", "7448" );
	CPU_PPC << Device_Map( "7448_v1.0", "\"7448_v1.0\"" );
	CPU_PPC << Device_Map( "7448_v1.1", "\"7448_v1.1\"" );
	CPU_PPC << Device_Map( "7448_v2.0", "\"7448_v2.0\"" );
	CPU_PPC << Device_Map( "7448_v2.1", "\"7448_v2.1\"" );
	CPU_PPC << Device_Map( "7450", "7450" );
	CPU_PPC << Device_Map( "Vger", "Vger" );
	CPU_PPC << Device_Map( "7450_v1.0", "\"7450_v1.0\"" );
	CPU_PPC << Device_Map( "7450_v1.1", "\"7450_v1.1\"" );
	CPU_PPC << Device_Map( "7450_v1.2", "\"7450_v1.2\"" );
	CPU_PPC << Device_Map( "7450_v2.0", "\"7450_v2.0\"" );
	CPU_PPC << Device_Map( "7450_v2.1", "\"7450_v2.1\"" );
	CPU_PPC << Device_Map( "7441", "7441" );
	CPU_PPC << Device_Map( "7451", "7451" );
	CPU_PPC << Device_Map( "7441_v2.1", "\"7441_v2.1\"" );
	CPU_PPC << Device_Map( "7441_v2.3", "\"7441_v2.3\"" );
	CPU_PPC << Device_Map( "7451_v2.3", "\"7451_v2.3\"" );
	CPU_PPC << Device_Map( "7441_v2.10", "\"7441_v2.10\"" );
	CPU_PPC << Device_Map( "7451_v2.10", "\"7451_v2.10\"" );
	CPU_PPC << Device_Map( "7445", "7445" );
	CPU_PPC << Device_Map( "7455", "7455" );
	CPU_PPC << Device_Map( "Apollo6", "Apollo6" );
	CPU_PPC << Device_Map( "7445_v1.0", "\"7445_v1.0\"" );
	CPU_PPC << Device_Map( "7455_v1.0", "\"7455_v1.0\"" );
	CPU_PPC << Device_Map( "7445_v2.1", "\"7445_v2.1\"" );
	CPU_PPC << Device_Map( "7455_v2.1", "\"7455_v2.1\"" );
	CPU_PPC << Device_Map( "7445_v3.2", "\"7445_v3.2\"" );
	CPU_PPC << Device_Map( "7455_v3.2", "\"7455_v3.2\"" );
	CPU_PPC << Device_Map( "7445_v3.3", "\"7445_v3.3\"" );
	CPU_PPC << Device_Map( "7455_v3.3", "\"7455_v3.3\"" );
	CPU_PPC << Device_Map( "7445_v3.4", "\"7445_v3.4\"" );
	CPU_PPC << Device_Map( "7455_v3.4", "\"7455_v3.4\"" );
	CPU_PPC << Device_Map( "7447", "7447" );
	CPU_PPC << Device_Map( "7457", "7457" );
	CPU_PPC << Device_Map( "Apollo7", "Apollo7" );
	CPU_PPC << Device_Map( "7447_v1.0", "\"7447_v1.0\"" );
	CPU_PPC << Device_Map( "7457_v1.0", "\"7457_v1.0\"" );
	CPU_PPC << Device_Map( "7447_v1.1", "\"7447_v1.1\"" );
	CPU_PPC << Device_Map( "7457_v1.1", "\"7457_v1.1\"" );
	CPU_PPC << Device_Map( "7457_v1.2", "\"7457_v1.2\"" );
	CPU_PPC << Device_Map( "7447A", "7447A" );
	CPU_PPC << Device_Map( "7457A", "7457A" );
	CPU_PPC << Device_Map( "7447A_v1.0", "\"7447A_v1.0\"" );
	CPU_PPC << Device_Map( "7457A_v1.0", "\"7457A_v1.0\"" );
	CPU_PPC << Device_Map( "Apollo7PM", "Apollo7PM" );
	CPU_PPC << Device_Map( "7447A_v1.1", "\"7447A_v1.1\"" );
	CPU_PPC << Device_Map( "7457A_v1.1", "\"7457A_v1.1\"" );
	CPU_PPC << Device_Map( "7447A_v1.2", "\"7447A_v1.2\"" );
	CPU_PPC << Device_Map( "7457A_v1.2", "\"7457A_v1.2\"" );
	CPU_PPC << Device_Map( "ppc32", "ppc32" );
	CPU_PPC << Device_Map( "ppc", "ppc" );
	
	CPU_Sparc << Device_Map( QObject::tr("Default"), "" );
	CPU_Sparc << Device_Map( "Fujitsu MB86900", "\"Fujitsu MB86900\"" );
	CPU_Sparc << Device_Map( "Fujitsu MB86904", "\"Fujitsu MB86904\"" );
	CPU_Sparc << Device_Map( "Fujitsu MB86907", "\"Fujitsu MB86907\"" );
	CPU_Sparc << Device_Map( "LSI L64811", "\"LSI L64811\"" );
	CPU_Sparc << Device_Map( "Cypress CY7C601", "\"Cypress CY7C601\"" );
	CPU_Sparc << Device_Map( "Cypress CY7C611", "\"Cypress CY7C611\"" );
	CPU_Sparc << Device_Map( "TI SuperSparc II", "\"TI SuperSparc II\"" );
	CPU_Sparc << Device_Map( "TI MicroSparc I", "\"TI MicroSparc I\"" );
	CPU_Sparc << Device_Map( "TI MicroSparc II", "\"TI MicroSparc II\"" );
	CPU_Sparc << Device_Map( "TI MicroSparc IIep", "\"TI MicroSparc IIep\"" );
	CPU_Sparc << Device_Map( "TI SuperSparc 51", "\"TI SuperSparc 51\"" );
	CPU_Sparc << Device_Map( "TI SuperSparc 61", "\"TI SuperSparc 61\"" );
	CPU_Sparc << Device_Map( "Ross RT625", "\"Ross RT625\"" );
	CPU_Sparc << Device_Map( "Ross RT620", "\"Ross RT620\"" );
	CPU_Sparc << Device_Map( "BIT", "\"BIT\"" );
	CPU_Sparc << Device_Map( "Matsushita MN10501", "\"Matsushita MN10501\"" );
	CPU_Sparc << Device_Map( "Weitek W8601", "\"Weitek W8601\"" );
	CPU_Sparc << Device_Map( "LEON2", "\"LEON2\"" );
	CPU_Sparc << Device_Map( "LEON3", "\"LEON3\"" );
	
	// Machines
	Machine_x86 << Device_Map( QObject::tr("Standard PC (default)"), "" );
	Machine_x86 << Device_Map( QObject::tr("Standard PC"), "pc" );
	Machine_x86 << Device_Map( QObject::tr("ISA-only PC"), "isapc" );
	
	Machine_ARM << Device_Map( QObject::tr("Default"), "" );
	Machine_ARM << Device_Map( QObject::tr("Integrator/CP (ARM926EJ-S)"), "integratorcp926" );
	Machine_ARM << Device_Map( QObject::tr("Integrator/CP (ARM1026EJ-S)"), "integratorcp1026" );
	Machine_ARM << Device_Map( QObject::tr("Versatile/PB (ARM926EJ-S)"), "versatilepb" );
	Machine_ARM << Device_Map( QObject::tr("Versatile/AB (ARM926EJ-S)"), "versatileab" );
	Machine_ARM << Device_Map( QObject::tr("RealView (ARM926EJ-S)"), "realview" );
	
	Machine_MIPS << Device_Map( QObject::tr("Default"), "" );
	Machine_MIPS << Device_Map( QObject::tr("R4k platform"), "mips" );
	Machine_MIPS << Device_Map( QObject::tr("Malta Core LV"), "malta" );
	
	Machine_PPC << Device_Map( QObject::tr("Default"), "" );
	Machine_PPC << Device_Map( QObject::tr("Heathrow PowerMAC"), "g3bw" );
	Machine_PPC << Device_Map( QObject::tr("Mac99 PowerMAC"), "mac99" );
	Machine_PPC << Device_Map( QObject::tr("PowerPC PREP"), "prep" );
	
	Machine_Sparc << Device_Map( QObject::tr("Default"), "" );
	Machine_Sparc << Device_Map( QObject::tr("SPARCstation 2 (Sun4c)"), "SS-2" );
	Machine_Sparc << Device_Map( QObject::tr("SPARCstation 5 (Sun4m)"), "SS-5" );
	Machine_Sparc << Device_Map( QObject::tr("SPARCstation 10 (Sun4m)"), "SS-10" );
	Machine_Sparc << Device_Map( QObject::tr("SPARCstation 20 (Sun4m)"), "SS-20" );
	Machine_Sparc << Device_Map( QObject::tr("SPARCserver 600MP (Sun4m)"), "SS-600MP" );
	Machine_Sparc << Device_Map( QObject::tr("SPARCserver 1000 (Sun4d)"), "SS-1000" );
	Machine_Sparc << Device_Map( QObject::tr("SPARCcenter 2000 (Sun4d)"), "SS-2000" );
	
	// Net Cards
	Network_Card_x86 << Device_Map( QObject::tr("NE2000 (default)"), "" );
	Network_Card_x86 << Device_Map( QObject::tr("NE2000 PCI"), "ne2k_pci" );
	Network_Card_x86 << Device_Map( QObject::tr("NE2000 ISA"), "ne2k_isa" );
	Network_Card_x86 << Device_Map( QObject::tr("i82551"), "i82551" );
	Network_Card_x86 << Device_Map( QObject::tr("i82557B"), "i82557b" );
	Network_Card_x86 << Device_Map( QObject::tr("i82559ER"), "i82559er" );
	Network_Card_x86 << Device_Map( QObject::tr("PCnet32 PCI"), "pcnet" );
	Network_Card_x86 << Device_Map( QObject::tr("RTL8139"), "rtl8139" );
	
	Network_Card_x86_v090 << Device_Map( QObject::tr("NE2000 (default)"), "" );
	Network_Card_x86_v090 << Device_Map( QObject::tr("NE2000 PCI"), "ne2k_pci" );
	Network_Card_x86_v090 << Device_Map( QObject::tr("NE2000 ISA"), "ne2k_isa" );
	Network_Card_x86_v090 << Device_Map( QObject::tr("RTL8139"), "rtl8139" );
	
	Network_Card_ARM << Device_Map( QObject::tr("Default"), "" );
	Network_Card_ARM << Device_Map( QObject::tr("SMC91C111"), "smc91c111" );
	
	Network_Card_M68K << Device_Map( QObject::tr("Default"), "" );
	Network_Card_M68K << Device_Map( QObject::tr("MCF FEC"), "mcf_fec" );
	
	Network_Card_MIPS << Device_Map( QObject::tr("Default"), "" );
	Network_Card_MIPS << Device_Map( QObject::tr("NE2000 ISA"), "ne2k_isa" );
	
	Network_Card_PPC << Device_Map( QObject::tr("Default"), "" );
	Network_Card_PPC << Device_Map( QObject::tr("i82551"), "i82551" );
	Network_Card_PPC << Device_Map( QObject::tr("i82557B"), "i82557b" );
	Network_Card_PPC << Device_Map( QObject::tr("i82559ER"), "i82559er" );
	Network_Card_PPC << Device_Map( QObject::tr("NE2000 PCI"), "ne2k_pci" );
	Network_Card_PPC << Device_Map( QObject::tr("PCnet32 PCI"), "pcnet" );
	Network_Card_PPC << Device_Map( QObject::tr("RTL8139"), "rtl8139" );
	
	Network_Card_Sparc << Device_Map( QObject::tr("Default"), "" );
	Network_Card_Sparc << Device_Map( QObject::tr("Lance"), "lance" );
	
	// Video
	Video_Card_Standart << Device_Map( QObject::tr("Default"), "" );
	Video_Card_Standart << Device_Map( QObject::tr("No Video Card"), "-nographic" );
	
	Video_Card_x86 << Device_Map( QObject::tr("Cirrus 5446 (default)"), "" );
	Video_Card_x86 << Device_Map( QObject::tr("No Video Card"), "-nographic" );
	Video_Card_x86 << Device_Map( QObject::tr("Standard VGA"), "-std-vga" );
	
	// Sound Cards
	Audio_Card_x86.Audio_PC_Speaker = true;
	Audio_Card_x86.Audio_sb16 = true;
	Audio_Card_x86.Audio_Adlib = true;
	Audio_Card_x86.Audio_es1370 = true;
	
	Audio_Card_PPC.Audio_sb16 = true;
	Audio_Card_PPC.Audio_Adlib = true;
	Audio_Card_PPC.Audio_es1370 = true;
	
	if( ver == "0.9.0" )
	{
		Averable_Devices ad;
		ad.System = Device_Map( "IBM PC 32Bit", "qemu-system-x86" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_x86;
		ad.Network_Card_List = Network_Card_x86_v090;
		ad.Video_Card_List = Video_Card_x86;
		ad.Audio_Card_List = Audio_Card_x86;
		ad.PSO_SMP = true;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = true;
		ad.PSO_Win2K_Hack = true;
		ad.PSO_Kernel_KQEMU = true;
		ad.PSO_No_ACPI = true;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "IBM PC 64Bit", "qemu-system-x86_64" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_x86;
		ad.Network_Card_List = Network_Card_x86_v090;
		ad.Video_Card_List = Video_Card_x86;
		ad.Audio_Card_List = Audio_Card_x86;
		ad.PSO_SMP = true;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = true;
		ad.PSO_Win2K_Hack = true;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = true;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "IBM PC KVM", "qemu-kvm" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_x86;
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );
		ad.Video_Card_List = Video_Card_x86;
		ad.Audio_Card_List = Audio_Card_x86;
		ad.PSO_SMP = true;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = true;
		ad.PSO_Win2K_Hack = true;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = true;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = true;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "ARM", "qemu-system-arm" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_ARM;
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "MIPS 32Bit", "qemu-system-mips" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_MIPS;
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "MIPS 32Bit EL", "qemu-system-mipsel" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_MIPS;
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "Power PC 32Bit", "qemu-system-ppc" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_PPC;
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = Audio_Card_PPC;
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = true;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "Sparc 32Bit", "qemu-system-sparc" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List << Device_Map( QObject::tr("Sun4m"), "sun4m" );
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = true;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		return true;
	}
	else if( ver == "0.9.1" || ver == "New" )
	{
		Averable_Devices ad;
		ad.System = Device_Map( "IBM PC 32Bit", "qemu-system-x86" );
		ad.CPU_List = CPU_x86;
		ad.Machine_List = Machine_x86;
		ad.Network_Card_List = Network_Card_x86;
		ad.Video_Card_List = Video_Card_x86;
		ad.Audio_Card_List = Audio_Card_x86;
		ad.PSO_SMP = true;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = true;
		ad.PSO_Win2K_Hack = true;
		ad.PSO_Kernel_KQEMU = true;
		ad.PSO_No_ACPI = true;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "IBM PC 64Bit", "qemu-system-x86_64" );
		
		QList<Device_Map> CPU_x86_64 = CPU_x86;
		CPU_x86_64.insert( 1, Device_Map(QObject::tr("qemu64"), "qemu64") );
		CPU_x86_64 << Device_Map( QObject::tr("Athlon"), "athlon" );
		ad.CPU_List = CPU_x86_64;
		
		ad.Machine_List = Machine_x86;
		ad.Network_Card_List = Network_Card_x86;
		ad.Network_Card_List << Device_Map( "E1000", "e1000" );
		ad.Network_Card_List << Device_Map( "Virtio", "virtio" );
		ad.Video_Card_List = Video_Card_x86;
		ad.Audio_Card_List = Audio_Card_x86;
		ad.Audio_Card_List.Audio_GUS = true;
		ad.Audio_Card_List.Audio_AC97 = true;
		ad.PSO_SMP = true;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = true;
		ad.PSO_Win2K_Hack = true;
		ad.PSO_Kernel_KQEMU = true;
		ad.PSO_No_ACPI = true;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "IBM PC KVM", "qemu-kvm" );
		ad.CPU_List = CPU_x86_64;
		ad.Machine_List = Machine_x86;
		ad.Network_Card_List = Network_Card_x86;
		ad.Network_Card_List << Device_Map( "E1000", "e1000" );
		ad.Network_Card_List << Device_Map( "Virtio", "virtio" );
		ad.Video_Card_List = Video_Card_x86;
		ad.Audio_Card_List = Audio_Card_x86;
		ad.Audio_Card_List.Audio_GUS = true;
		ad.Audio_Card_List.Audio_AC97 = true;
		ad.PSO_SMP = true;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = true;
		ad.PSO_Win2K_Hack = true;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = true;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = true;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "ARM", "qemu-system-arm" );
		ad.CPU_List = CPU_ARM;
		
		QList<Device_Map> Machine_ARM_0_9_1;
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Integrator/CP (ARM926EJ-S)"), "integratorcp" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Versatile/PB (ARM926EJ-S)"), "versatilepb" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Versatile/AB (ARM926EJ-S)"), "versatileab" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("RealView (ARM926EJ-S)"), "realview" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Akita PDA (PXA270)"), "akita" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Spitz PDA (PXA270)"), "spitz" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Borzoi PDA (PXA270)"), "borzoi" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Terrier PDA (PXA270)"), "terrier" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Palm Tungsten (OMAP310)"), "cheetah" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Stellaris LM3S811EVB"), "lm3s811evb" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Stellaris LM3S6965EVB"), "lm3s6965evb" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Gumstix Connex (PXA255)"), "connex" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Gumstix Verdex (PXA270)"), "verdex" );
		Machine_ARM_0_9_1 << Device_Map( QObject::tr("Mainstone II (PXA27x)"), "mainstone" );
		ad.Machine_List = Machine_ARM_0_9_1;
		
		ad.Network_Card_List = Network_Card_ARM;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "Cris", "qemu-system-cris" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List << Device_Map( QObject::tr("Bare ETRAX FS board"), "bareetraxfs" );
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "ColdFire (M68K)", "qemu-system-m68k" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );
		ad.Machine_List = Machine_M68K;
		ad.Network_Card_List = Network_Card_M68K;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "MIPS", "qemu-system-mips" );
		ad.CPU_List = CPU_MIPS;
		
		QList<Device_Map> Machine_MIPS_0_9_1 = Machine_MIPS;
		Machine_MIPS_0_9_1 << Device_Map( QObject::tr("Acer Pica 61"), "pica61" );
		Machine_MIPS_0_9_1 << Device_Map( QObject::tr("MIPS MIPSsim platform"), "mipssim" );
		ad.Machine_List = Machine_MIPS_0_9_1;
		
		ad.Network_Card_List = Network_Card_MIPS;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "MIPS EL", "qemu-system-mipsel" );
		ad.CPU_List = CPU_MIPS;
		ad.Machine_List = Machine_MIPS_0_9_1;
		ad.Network_Card_List = Network_Card_MIPS;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "MIPS64", "qemu-system-mips64" );
		
		QList<Device_Map> CPU_MIPS64_0_9_1 = CPU_MIPS;
		CPU_MIPS64_0_9_1 << Device_Map( QObject::tr("R4000"), "R4000" );
		CPU_MIPS64_0_9_1 << Device_Map( QObject::tr("VR5432"), "VR5432" );
		CPU_MIPS64_0_9_1 << Device_Map( QObject::tr("5Kc"), "5Kc" );
		CPU_MIPS64_0_9_1 << Device_Map( QObject::tr("5Kf"), "5Kf" );
		CPU_MIPS64_0_9_1 << Device_Map( QObject::tr("20Kc"), "20Kc" );
		CPU_MIPS64_0_9_1 << Device_Map( QObject::tr("MIPS64R2-generic"), "MIPS64R2-generic" );
		ad.CPU_List = CPU_MIPS64_0_9_1;
		
		ad.Machine_List = Machine_MIPS_0_9_1;
		ad.Network_Card_List = Network_Card_MIPS;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "MIPS64 EL", "qemu-system-mips64el" );
		ad.CPU_List = CPU_MIPS64_0_9_1;
		ad.Machine_List = Machine_MIPS_0_9_1;
		ad.Network_Card_List = Network_Card_MIPS;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "Power PC 32Bit", "qemu-system-ppc" );
		ad.CPU_List = CPU_PPC;
		
		QList<Device_Map> Machine_PPC_0_9_1 = Machine_PPC;
		Machine_PPC_0_9_1 << Device_Map( QObject::tr("Ref405ep"), "ref405ep" );
		Machine_PPC_0_9_1 << Device_Map( QObject::tr("Taihu"), "taihu" );
		ad.Machine_List = Machine_PPC_0_9_1;
		
		ad.Network_Card_List = Network_Card_PPC;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = Audio_Card_PPC;
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = true;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "Power PC 64Bit", "qemu-system-ppc64" );
		
		QList<Device_Map> CPU_PPC_64 = CPU_PPC;
		CPU_PPC_64 << Device_Map( "620", "620" );
		CPU_PPC_64 << Device_Map( "Trident", "Trident" );
		CPU_PPC_64 << Device_Map( "970", "970" );
		CPU_PPC_64 << Device_Map( "970fx", "970fx" );
		CPU_PPC_64 << Device_Map( "970fx_v1.0", "\"970fx_v1.0\"" );
		CPU_PPC_64 << Device_Map( "970fx_v2.0", "\"970fx_v2.0\"" );
		CPU_PPC_64 << Device_Map( "970fx_v2.1", "\"970fx_v2.1\"" );
		CPU_PPC_64 << Device_Map( "970fx_v3.0", "\"970fx_v3.0\"" );
		CPU_PPC_64 << Device_Map( "970fx_v3.1", "\"970fx_v3.1\"" );
		CPU_PPC_64 << Device_Map( "970gx", "970gx" );
		CPU_PPC_64 << Device_Map( "970mp", "970mp" );
		CPU_PPC_64 << Device_Map( "970mp_v1.0", "\"970mp_v1.0\"" );
		CPU_PPC_64 << Device_Map( "970mp_v1.1", "\"970mp_v1.1\"" );
		CPU_PPC_64 << Device_Map( "PPC64", "ppc64" );
		ad.CPU_List = CPU_PPC_64;
		
		ad.Machine_List = Machine_PPC_0_9_1;
		ad.Network_Card_List = Network_Card_PPC;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = Audio_Card_PPC;
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = true;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "Power PC EMB 32Bit", "qemu-system-ppcemb" );
		ad.CPU_List = CPU_PPC;
		ad.Machine_List = Machine_PPC_0_9_1;
		ad.Network_Card_List = Network_Card_PPC;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = Audio_Card_PPC;
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = true;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "SH4", "qemu-system-sh4" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );;
		ad.Machine_List = Machine_SH4;
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "SH4 EB", "qemu-system-sh4eb" );
		ad.CPU_List << Device_Map( QObject::tr("Default"), "" );;
		ad.Machine_List = Machine_SH4;
		ad.Network_Card_List << Device_Map( QObject::tr("Default"), "" );;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = false;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = false;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		ad = Averable_Devices();
		ad.System = Device_Map( "Sparc 32Bit", "qemu-system-sparc" );
		ad.CPU_List = CPU_Sparc;
		ad.Machine_List = Machine_Sparc;
		ad.Network_Card_List = Network_Card_Sparc;
		ad.Video_Card_List = Video_Card_Standart;
		ad.Audio_Card_List = VM::Sound_Cards();
		ad.PSO_SMP = false;
		ad.PSO_Initial_Graphic_Mode = true;
		ad.PSO_No_FB_Boot_Check = false;
		ad.PSO_Win2K_Hack = false;
		ad.PSO_Kernel_KQEMU = false;
		ad.PSO_No_ACPI = false;
		ad.PSO_PROM_ENV = true;
		ad.PSO_KVM = false;
		System_Info::VM_Computers << ad;
		
		return true;
	}
	else
	{
		AQGraphic_Error( "bool System_Info::Update_VM_Computers_List()", QObject::tr("Critical Error!"),
						 QObject::tr("Version QEMU Installed on This System Cannot Work for AQEMU!"), true );
		return false;
	}
}

bool System_Info::Check_QEMU_Version()
{
	QProcess *qemu_pr = new QProcess();
	
	qemu_pr->start( "qemu" );
	
	if( ! qemu_pr->waitForFinished(1000) )
	{
		AQError( "static bool Check_QEMU_Version()",
				 "QEMU Not Finished!" );
		delete qemu_pr;
		return false;
	}
	
	QRegExp qemu_ver = QRegExp( ".*version\\s+([\\d])[.]([\\d])[.]([\\d]).*" );
	
	bool find_done = false;
	
	for( int ix = 0; ix < 5; ++ix )
	{
		QString result = qemu_pr->readLine();
		
		if( result.isEmpty() )
		{
			AQError( "static bool Check_QEMU_Version()",
					 "Result String is Empty!" );
		}
		
		if( ! qemu_ver.exactMatch(result) )
		{
			AQError( "static bool Check_QEMU_Version()",
					 "Cannot Match RegExp!\nData: " + result );
		}
		else
		{
			find_done = true;
			break;
		}
	}
	
	delete qemu_pr;
	
	if( find_done == false )
	{
		AQError( "static bool Check_QEMU_Version()",
				 "Cannot Find QEMU Version!" );
		return false;
	}
	
	QStringList version_lines = qemu_ver.capturedTexts();
	
	int major_ver, minor_ver, bugfix_ver;
	
	bool ok1, ok2, ok3;
	
	major_ver = version_lines[1].toInt( &ok1, 10 );
	minor_ver = version_lines[2].toInt( &ok2, 10 );
	bugfix_ver = version_lines[3].toInt( &ok3, 10 );
	
	if( ! (ok1 && ok2 && ok3) )
	{
		AQError( "static bool Check_QEMU_Version()",
				 "Cannot Convert to Int!" );
		return false;
	}
	
	QSettings settings;
	
	if( major_ver == 0 && minor_ver == 9 && bugfix_ver == 0 )
	{
		settings.setValue( "QEMU_Version", "0.9.0" );
	}
	else if( major_ver == 0 && minor_ver == 9 && bugfix_ver == 1 )
	{
		settings.setValue( "QEMU_Version", "0.9.1" );
	}
	else if( major_ver == 0 && minor_ver < 9 )
	{
		settings.setValue( "QEMU_Version", "Old" );
	}
	else if( major_ver > 0 || (minor_ver == 9 && bugfix_ver > 1) )
	{
		settings.setValue( "QEMU_Version", "New" );
	}
	else
	{
		AQError( "static bool Check_QEMU_Version()",
				 "Version not Checked!" );
		return false;
	}
	
	return true;
}

bool System_Info::Check_Availability_KVM()
{
	QStringList sys_env = QProcess::systemEnvironment();
	
	if( sys_env.count() <= 0 )
	{
		AQError( "bool System_Info::Check_Availability_KVM()",
				 "Cannot Get System Environment Information!" );
		return false;
	}
	else
	{
		QStringList paths;
		
		for( int ix = 0; ix < sys_env.count(); ++ix )
		{
			if( sys_env[ix].indexOf("PATH=") >= 0 )
			{
				QString tmp = sys_env[ ix ].remove( "PATH=" );
				
				paths = tmp.split( ",", QString::SkipEmptyParts );
			}
		}
		
		if( paths.count() <= 0 )
		{
			AQError( "bool System_Info::Check_Availability_KVM()",
					 "Cannot Find PATH in System Environment Information!" );
			return false;
		}
		else
		{
			QStringList kvm_names;
			kvm_names << "qemu-kvm";
			kvm_names << "kvm";
			
			for( int kx = 0; kx < paths.count(); ++kx )
			{
				for( int nx = 0; nx < kvm_names.count(); ++nx )
				{
					if( QFile::exists( paths[kx] + "/" + kvm_names[nx] ) )
					{
						AQDebug( "bool System_Info::Check_Availability_KVM()",
								 "KVM Finded. Path: " + paths[kx] + "/" + kvm_names[nx] );
						
						QSettings settings;
						settings.setValue( "QEMU_Systems/qemu-kvm", paths[kx] + "/" + kvm_names[nx] );
						
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

bool System_Info::Get_All_Host_USB( QList<VM_USB> &usb_list )
{
	QSettings settings;
	if( settings.value("Use_USB", "no").toString() == "no" )
	{
		AQDebug( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
				 "Use USB == no" );
		return false;
	}
	
	usb_list.clear();
	
	if( ! QFile::exists("/proc/bus/usb/devices") )
	{
		AQError( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
				 "File /proc/bus/usb/devices no exists! USB information not found!" );
		return false;
	}
	
	QProcess usb_list_file;
	usb_list_file.start( "/bin/cat /proc/bus/usb/devices" );
	
	if( ! usb_list_file.waitForFinished(1000) )
	{
		AQError( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
				 "No more time for working cat!" );
		return false;
	}
	
	QList<QStringList> linux_usb_dev;
	QTextStream in( &usb_list_file );
	
	while( ! in.atEnd() )
	{
		QString line = in.readLine();
		QStringList tmp_str;
		
		if( line[0] == 'T' )
		{
			while( ! in.atEnd() )
			{
				line = in.readLine();
				
				if( line[0] == 'E' )
				{
					break;
				}
				else
				{
					if( line[0] == 'P' || line[0] == 'S' )
					{
						tmp_str << line;
					}
				}
			}
			
			linux_usb_dev << tmp_str;
		}
	}
	
	for( int ex = 0; ex < linux_usb_dev.count(); ++ex )
	{
		if( linux_usb_dev[ex].count() < 3 )
		{
			AQWarning( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
					   "linux_usb_dev[ex].count() < 3" );
		}
	}
	
	// P:  Vendor=0123 ProdID=abcd Rev= 0.01
	QRegExp idHex = QRegExp( "P:[\\s]+Vendor=([\\dabcdef]{4})[\\s]+ProdID=([\\dabcdef]{4}).+" );
	
	// S:  Manufacturer=Mega Cool Manufacturer
	QRegExp manufacturer = QRegExp( "S:[\\s]+Manufacturer=(.+)" );
	
	// S:  Product=Super USB Device
	QRegExp product = QRegExp( "S:[\\s]+Product=(.+)" );
	
	for( int ix = 0; ix < linux_usb_dev.count(); ++ix )
	{
		if( linux_usb_dev[ix].count() <= 0 )
		{
			AQWarning( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
					   "linux_usb_dev[ix].count() <= 0");
			continue;
		}
		
		QStringList idHex_list;
		QStringList manufacturer_list;
		QStringList product_list;
		
		for( int bx = 0; bx < linux_usb_dev[ix].count(); ++bx )
		{
			if( idHex_list.count() <= 0 )
			{
				if( idHex.exactMatch(linux_usb_dev[ix][bx]) )
				{
					idHex_list = idHex.capturedTexts();
					continue;
				}
				else
				{
					AQError( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
							 "Cannot Match idHex!" );
				}
			}
			
			if( manufacturer_list.count() <= 0 )
			{
				if( manufacturer.exactMatch(linux_usb_dev[ix][bx]) )
				{
					manufacturer_list = manufacturer.capturedTexts();
					continue;
				}
				else
				{
					AQError( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
							 "Cannot Match manufacturer!" );
				}
			}
			
			if( product_list.count() <= 0 )
			{
				if( product.exactMatch(linux_usb_dev[ix][bx]) )
				{
					product_list = product.capturedTexts();
					continue;
				}
				else
				{
					AQError( "bool Ports_Tab_Widget::Get_All_Host_USB( QList<VM_USB> &usb_list )",
							 "Cannot Match product!" );
				}
			}
		}
		
		// Create VM_USB
		if( idHex_list.count() > 1 )
		{
			if( idHex_list[1] != "0000" && idHex_list[2] != "0000" )
			{
				VM_USB tmp_usb;
				
				tmp_usb.Set_Vendor_ID( idHex_list[1] );
				tmp_usb.Set_Product_ID( idHex_list[2] );
				
				if( manufacturer_list.count() > 0 )
				{
					tmp_usb.Set_Manufacturer_Name( manufacturer_list[1] );
				}
				
				if( product_list.count() > 0 )
				{
					tmp_usb.Set_Product_Name( product_list[1] );
				}
				
				usb_list << tmp_usb;
			}
		}
	}
	
	return true;
}

#ifdef Q_OS_LINUX
#include <sys/sysinfo.h>

int System_Info::Get_Free_Memory_Size()
{
	struct sysinfo sys_info;
	sysinfo( &sys_info );
	
	return (int)(sys_info.freeram * sys_info.mem_unit) / 1024.0 / 1024.0;
}
#endif


#include <sys/sysctl.h>
#include <unistd.h>
int System_Info::Get_Free_Memory_Size()
{
	size_t free_ram = 0;
	size_t len = sizeof( free_ram );
	
    int page_size = getpagesize();
	
	if( (sysctlbyname("vm.stats.vm.v_free_count", &free_ram, &len, NULL, 0) == -1) || ! len )
	{
		free_ram = 0;
		AQError( "int System_Info::Get_Free_Memory_Size()",
				 "Cannot Get Information on Memory!" );
	}
	
	free_ram *= page_size;
	
	return (int)free_ram / 1024.0 / 1024.0;
}


#ifdef Q_OS_WIN32
#include <windows.h>

int System_Info::Get_Free_Memory_Size()
{
	MEMORYSTATUS mem;
	memset( (void*)&mem,0,sizeof(mem) );
	mem.dwLength = sizeof( mem );
	GlobalMemoryStatus( &mem );
	
	return (int)mem.dwAvailPhys / 1024.0 / 1024.0;
}
#endif


#include <QDir>
#include <QFileInfoList>

QStringList System_Info::Get_Host_FDD_List()
{
	// Find Floppy's
	QDir dev_dir( "/dev/" );
	QFileInfoList devices = dev_dir.entryInfoList( QStringList("fd*"), QDir::System, QDir::Name );
	
	QStringList tmp_list;
	
	for( int d = 0; d < devices.count(); ++d )
	{
		tmp_list << devices[d].absoluteFilePath();
	}
	
	return tmp_list;
}

QStringList System_Info::Get_Host_CDROM_List()
{
	// Find CD-ROM's
	QDir dev_dir( "/dev/" );
	QFileInfoList devices = dev_dir.entryInfoList( QStringList("cdrom*"), QDir::System, QDir::Name );
	
	QStringList tmp_list;
	
	for( int d = 0; d < devices.count(); ++d )
	{
		tmp_list << devices[d].absoluteFilePath();
	}
	
	return tmp_list;
}


#ifdef Q_OS_FREEBSD
#include <QDir>
#include <QFileInfoList>

QStringList System_Info::Get_Host_FDD_List()
{
	// Find Floppy's
	QDir dev_dir( "/dev/fd/" );
	QFileInfoList devices = dev_dir.entryInfoList( QStringList("*"), QDir::System, QDir::Name );
	
	QStringList tmp_list;
	
	for( int d = 0; d < devices.count(); ++d )
	{
		tmp_list << devices[d].absoluteFilePath();
	}
	
	return tmp_list;
}

QStringList System_Info::Get_Host_CDROM_List()
{
	// Find CD-ROM's
	QDir dev_dir( "/dev/" );
	QFileInfoList devices = dev_dir.entryInfoList( QStringList("acd*"), QDir::System, QDir::Name );
	
	QStringList tmp_list;
	
	for( int d = 0; d < devices.count(); ++d )
	{
		tmp_list << devices[d].absoluteFilePath();
	}
	
	return tmp_list;
}

#endif
