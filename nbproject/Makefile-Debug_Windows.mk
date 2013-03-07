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
CND_CONF=Debug_Windows
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/NetworkDlgTCPClientTab.o \
	${OBJECTDIR}/NetworkPane_Multicast.o \
	${OBJECTDIR}/NetworkPane_UDP.o \
	${OBJECTDIR}/NetworkPanel_Base.o \
	${OBJECTDIR}/NetworkTabDialog.o \
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
LDLIBSOPTIONS=-L../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib -L../../Libraries/Third_Party/Boost/lib -L../../Libraries/SENTEL/EthernetComms/lib -lboost_system-mgw47-mt-sd-1_53 -lboost_thread-mgw47-mt-sd-1_53 ../EthernetCommsLibrary/dist/Debug_MinGW_Static/MinGW_Latest-Windows/libEthernetComms_D.a -lws2_32 -mthreads -Wl,--subsystem,windows -mwindows ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_mswd_richtext-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_mswd_aui-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_mswd_xrc-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_mswd_qa-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_mswd_html-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_mswd_adv-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_mswd_core-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_based_xml-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_based_net-2.8.a ../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/libwx_based-2.8.a -lwxregexd-2.8 -lwxexpatd-2.8 -lwxtiffd-2.8 -lwxjpegd-2.8 -lwxpngd-2.8 -lwxzlibd-2.8 -lrpcrt4 -loleaut32 -lole32 -luuid -lwinspool -lwinmm -lshell32 -lcomctl32 -lcomdlg32 -lctl3d32 -ladvapi32 -lwsock32 -lgdi32 -static

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx.exe: ../EthernetCommsLibrary/dist/Debug_MinGW_Static/MinGW_Latest-Windows/libEthernetComms_D.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/NetworkDlgTCPClientTab.o: NetworkDlgTCPClientTab.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkDlgTCPClientTab.o NetworkDlgTCPClientTab.cpp

${OBJECTDIR}/NetworkPane_Multicast.o: NetworkPane_Multicast.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkPane_Multicast.o NetworkPane_Multicast.cpp

${OBJECTDIR}/NetworkPane_UDP.o: NetworkPane_UDP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkPane_UDP.o NetworkPane_UDP.cpp

${OBJECTDIR}/NetworkPanel_Base.o: NetworkPanel_Base.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkPanel_Base.o NetworkPanel_Base.cpp

${OBJECTDIR}/NetworkTabDialog.o: NetworkTabDialog.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkTabDialog.o NetworkTabDialog.cpp

${OBJECTDIR}/NetworkTestUtilityDlg.o: NetworkTestUtilityDlg.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkTestUtilityDlg.o NetworkTestUtilityDlg.cpp

${OBJECTDIR}/NetworkTestUtility_wxGUI.o: NetworkTestUtility_wxGUI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/NetworkTestUtility_wxGUI.o NetworkTestUtility_wxGUI.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DBOOST_DISABLE_ASSERTS -DBOOST_ENABLE_ASSERT_HANDLER -DBOOST_THREAD_USE_LIB -DNO_MFC -D_DEBUG -D__WXDEBUG__ -D__WXMSW__ -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/build-static-debug-gcc4.7.2/lib/wx/include/msw-ansi-debug-static-2.8 -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/include -I../../Libraries/Third_Party/wxWidgets/wxWidgets-2.8.12/contrib/include -I../../Libraries/Third_Party/Boost/include/boost_1_53_0 -I../../Libraries/SENTEL/EthernetComms/include -I../../Libraries/SENTEL/EthernetComms/include/BoostAsioConnections -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../EthernetCommsLibrary && ${MAKE}  -f Makefile CONF=Debug_MinGW_Static

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/networktestutility_wx.exe

# Subprojects
.clean-subprojects:
	cd ../EthernetCommsLibrary && ${MAKE}  -f Makefile CONF=Debug_MinGW_Static clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
