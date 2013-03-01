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
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug_Windows
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
LDLIBSOPTIONS=-L../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib -static

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/NetworkDlgMulticastTab.o: NetworkDlgMulticastTab.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__WXDEBUG__ -D__WXMSW__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/contrib/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkDlgMulticastTab.o NetworkDlgMulticastTab.cpp

${OBJECTDIR}/NetworkDlgTCPClientTab.o: NetworkDlgTCPClientTab.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__WXDEBUG__ -D__WXMSW__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/contrib/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkDlgTCPClientTab.o NetworkDlgTCPClientTab.cpp

${OBJECTDIR}/NetworkDlgUDPTab.o: NetworkDlgUDPTab.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__WXDEBUG__ -D__WXMSW__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/contrib/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkDlgUDPTab.o NetworkDlgUDPTab.cpp

${OBJECTDIR}/NetworkTestUtilityDlg.o: NetworkTestUtilityDlg.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__WXDEBUG__ -D__WXMSW__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/contrib/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkTestUtilityDlg.o NetworkTestUtilityDlg.cpp

${OBJECTDIR}/NetworkTestUtility_wxGUI.o: NetworkTestUtility_wxGUI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__WXDEBUG__ -D__WXMSW__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/contrib/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkTestUtility_wxGUI.o NetworkTestUtility_wxGUI.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__WXDEBUG__ -D__WXMSW__ -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/include -I../../Third_Party/Libraries/wxWidgets/wxWidgets-2.8.12/contrib/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
