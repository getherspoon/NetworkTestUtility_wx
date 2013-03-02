#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_Latest-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug_OSX
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/NetworkDlgMulticastTab.o \
	${OBJECTDIR}/NetworkDlgTCPClientTab.o \
	${OBJECTDIR}/NetworkDlgUDPTab.o \
	${OBJECTDIR}/NetworkTestUtilityDlg.o \
	${OBJECTDIR}/NetworkTestUtility_wxGUI.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_osx_cocoa_xrc-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_osx_cocoa_webview-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_osx_cocoa_qa-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_base_net-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_osx_cocoa_html-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_osx_cocoa_adv-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_osx_cocoa_core-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_base_xml-2.9.a ../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/libwx_base-2.9.a -framework WebKit -lexpat -lwxtiff-2.9 -lwxjpeg-2.9 -lwxpng-2.9 -lz -lpthread -liconv

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/NetworkDlgMulticastTab.o: NetworkDlgMulticastTab.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D_FILE_OFFSET_BITS=64 -D__WXDEBUG__ -D__WXMAC__ -D__WXOSX_COCOA__ -D__WXOSX__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/wx/include/osx_cocoa-ansi-static-2.9 -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkDlgMulticastTab.o NetworkDlgMulticastTab.cpp

${OBJECTDIR}/NetworkDlgTCPClientTab.o: NetworkDlgTCPClientTab.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D_FILE_OFFSET_BITS=64 -D__WXDEBUG__ -D__WXMAC__ -D__WXOSX_COCOA__ -D__WXOSX__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/wx/include/osx_cocoa-ansi-static-2.9 -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkDlgTCPClientTab.o NetworkDlgTCPClientTab.cpp

${OBJECTDIR}/NetworkDlgUDPTab.o: NetworkDlgUDPTab.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D_FILE_OFFSET_BITS=64 -D__WXDEBUG__ -D__WXMAC__ -D__WXOSX_COCOA__ -D__WXOSX__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/wx/include/osx_cocoa-ansi-static-2.9 -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkDlgUDPTab.o NetworkDlgUDPTab.cpp

${OBJECTDIR}/NetworkTestUtilityDlg.o: NetworkTestUtilityDlg.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D_FILE_OFFSET_BITS=64 -D__WXDEBUG__ -D__WXMAC__ -D__WXOSX_COCOA__ -D__WXOSX__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/wx/include/osx_cocoa-ansi-static-2.9 -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkTestUtilityDlg.o NetworkTestUtilityDlg.cpp

${OBJECTDIR}/NetworkTestUtility_wxGUI.o: NetworkTestUtility_wxGUI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D_FILE_OFFSET_BITS=64 -D__WXDEBUG__ -D__WXMAC__ -D__WXOSX_COCOA__ -D__WXOSX__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/wx/include/osx_cocoa-ansi-static-2.9 -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkTestUtility_wxGUI.o NetworkTestUtility_wxGUI.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D_FILE_OFFSET_BITS=64 -D__WXDEBUG__ -D__WXMAC__ -D__WXOSX_COCOA__ -D__WXOSX__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.9.4/build-cocoa-debug/lib/wx/include/osx_cocoa-ansi-static-2.9 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
