#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=lib/hw/AnalogPin.cpp lib/core/Delay.cpp lib/core/CircularBuffer.cpp lib/hw/Port.cpp lib/hw/SerialPort.cpp lib/hw/DigitalPin.cpp lib/io/Key.cpp lib/io/TextDisplay.cpp lib/io/Led.cpp lib/io/Keypad.cpp lib/io/IncrementalEncoder.cpp ../main.cpp lib/io/I2CMaster.cpp lib/core/settings.cpp lib/io/SPI.cpp lib/hw/LTC2604.cpp lib/io/I2C.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/lib/hw/AnalogPin.o ${OBJECTDIR}/lib/core/Delay.o ${OBJECTDIR}/lib/core/CircularBuffer.o ${OBJECTDIR}/lib/hw/Port.o ${OBJECTDIR}/lib/hw/SerialPort.o ${OBJECTDIR}/lib/hw/DigitalPin.o ${OBJECTDIR}/lib/io/Key.o ${OBJECTDIR}/lib/io/TextDisplay.o ${OBJECTDIR}/lib/io/Led.o ${OBJECTDIR}/lib/io/Keypad.o ${OBJECTDIR}/lib/io/IncrementalEncoder.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/lib/io/I2CMaster.o ${OBJECTDIR}/lib/core/settings.o ${OBJECTDIR}/lib/io/SPI.o ${OBJECTDIR}/lib/hw/LTC2604.o ${OBJECTDIR}/lib/io/I2C.o
POSSIBLE_DEPFILES=${OBJECTDIR}/lib/hw/AnalogPin.o.d ${OBJECTDIR}/lib/core/Delay.o.d ${OBJECTDIR}/lib/core/CircularBuffer.o.d ${OBJECTDIR}/lib/hw/Port.o.d ${OBJECTDIR}/lib/hw/SerialPort.o.d ${OBJECTDIR}/lib/hw/DigitalPin.o.d ${OBJECTDIR}/lib/io/Key.o.d ${OBJECTDIR}/lib/io/TextDisplay.o.d ${OBJECTDIR}/lib/io/Led.o.d ${OBJECTDIR}/lib/io/Keypad.o.d ${OBJECTDIR}/lib/io/IncrementalEncoder.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/lib/io/I2CMaster.o.d ${OBJECTDIR}/lib/core/settings.o.d ${OBJECTDIR}/lib/io/SPI.o.d ${OBJECTDIR}/lib/hw/LTC2604.o.d ${OBJECTDIR}/lib/io/I2C.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/lib/hw/AnalogPin.o ${OBJECTDIR}/lib/core/Delay.o ${OBJECTDIR}/lib/core/CircularBuffer.o ${OBJECTDIR}/lib/hw/Port.o ${OBJECTDIR}/lib/hw/SerialPort.o ${OBJECTDIR}/lib/hw/DigitalPin.o ${OBJECTDIR}/lib/io/Key.o ${OBJECTDIR}/lib/io/TextDisplay.o ${OBJECTDIR}/lib/io/Led.o ${OBJECTDIR}/lib/io/Keypad.o ${OBJECTDIR}/lib/io/IncrementalEncoder.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/lib/io/I2CMaster.o ${OBJECTDIR}/lib/core/settings.o ${OBJECTDIR}/lib/io/SPI.o ${OBJECTDIR}/lib/hw/LTC2604.o ${OBJECTDIR}/lib/io/I2C.o

# Source Files
SOURCEFILES=lib/hw/AnalogPin.cpp lib/core/Delay.cpp lib/core/CircularBuffer.cpp lib/hw/Port.cpp lib/hw/SerialPort.cpp lib/hw/DigitalPin.cpp lib/io/Key.cpp lib/io/TextDisplay.cpp lib/io/Led.cpp lib/io/Keypad.cpp lib/io/IncrementalEncoder.cpp ../main.cpp lib/io/I2CMaster.cpp lib/core/settings.cpp lib/io/SPI.cpp lib/hw/LTC2604.cpp lib/io/I2C.cpp


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lib/hw/AnalogPin.o: lib/hw/AnalogPin.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/AnalogPin.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/AnalogPin.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/AnalogPin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/AnalogPin.o.d" -o ${OBJECTDIR}/lib/hw/AnalogPin.o lib/hw/AnalogPin.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/core/Delay.o: lib/core/Delay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/core 
	@${RM} ${OBJECTDIR}/lib/core/Delay.o.d 
	@${RM} ${OBJECTDIR}/lib/core/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/core/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/core/Delay.o.d" -o ${OBJECTDIR}/lib/core/Delay.o lib/core/Delay.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/core/CircularBuffer.o: lib/core/CircularBuffer.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/core 
	@${RM} ${OBJECTDIR}/lib/core/CircularBuffer.o.d 
	@${RM} ${OBJECTDIR}/lib/core/CircularBuffer.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/core/CircularBuffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/core/CircularBuffer.o.d" -o ${OBJECTDIR}/lib/core/CircularBuffer.o lib/core/CircularBuffer.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/Port.o: lib/hw/Port.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/Port.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/Port.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/Port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/Port.o.d" -o ${OBJECTDIR}/lib/hw/Port.o lib/hw/Port.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/SerialPort.o: lib/hw/SerialPort.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/SerialPort.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/SerialPort.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/SerialPort.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/SerialPort.o.d" -o ${OBJECTDIR}/lib/hw/SerialPort.o lib/hw/SerialPort.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/DigitalPin.o: lib/hw/DigitalPin.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/DigitalPin.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/DigitalPin.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/DigitalPin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/DigitalPin.o.d" -o ${OBJECTDIR}/lib/hw/DigitalPin.o lib/hw/DigitalPin.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/Key.o: lib/io/Key.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/Key.o.d 
	@${RM} ${OBJECTDIR}/lib/io/Key.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/Key.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/Key.o.d" -o ${OBJECTDIR}/lib/io/Key.o lib/io/Key.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/TextDisplay.o: lib/io/TextDisplay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/TextDisplay.o.d 
	@${RM} ${OBJECTDIR}/lib/io/TextDisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/TextDisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/TextDisplay.o.d" -o ${OBJECTDIR}/lib/io/TextDisplay.o lib/io/TextDisplay.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/Led.o: lib/io/Led.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/Led.o.d 
	@${RM} ${OBJECTDIR}/lib/io/Led.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/Led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/Led.o.d" -o ${OBJECTDIR}/lib/io/Led.o lib/io/Led.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/Keypad.o: lib/io/Keypad.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/Keypad.o.d 
	@${RM} ${OBJECTDIR}/lib/io/Keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/Keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/Keypad.o.d" -o ${OBJECTDIR}/lib/io/Keypad.o lib/io/Keypad.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/IncrementalEncoder.o: lib/io/IncrementalEncoder.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/IncrementalEncoder.o.d 
	@${RM} ${OBJECTDIR}/lib/io/IncrementalEncoder.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/IncrementalEncoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/IncrementalEncoder.o.d" -o ${OBJECTDIR}/lib/io/IncrementalEncoder.o lib/io/IncrementalEncoder.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/I2CMaster.o: lib/io/I2CMaster.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/I2CMaster.o.d 
	@${RM} ${OBJECTDIR}/lib/io/I2CMaster.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/I2CMaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/I2CMaster.o.d" -o ${OBJECTDIR}/lib/io/I2CMaster.o lib/io/I2CMaster.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/core/settings.o: lib/core/settings.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/core 
	@${RM} ${OBJECTDIR}/lib/core/settings.o.d 
	@${RM} ${OBJECTDIR}/lib/core/settings.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/core/settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/core/settings.o.d" -o ${OBJECTDIR}/lib/core/settings.o lib/core/settings.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/SPI.o: lib/io/SPI.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/SPI.o.d 
	@${RM} ${OBJECTDIR}/lib/io/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/SPI.o.d" -o ${OBJECTDIR}/lib/io/SPI.o lib/io/SPI.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/LTC2604.o: lib/hw/LTC2604.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/LTC2604.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/LTC2604.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/LTC2604.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/LTC2604.o.d" -o ${OBJECTDIR}/lib/hw/LTC2604.o lib/hw/LTC2604.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/I2C.o: lib/io/I2C.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/I2C.o.d 
	@${RM} ${OBJECTDIR}/lib/io/I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/I2C.o.d" -o ${OBJECTDIR}/lib/io/I2C.o lib/io/I2C.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
else
${OBJECTDIR}/lib/hw/AnalogPin.o: lib/hw/AnalogPin.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/AnalogPin.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/AnalogPin.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/AnalogPin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/AnalogPin.o.d" -o ${OBJECTDIR}/lib/hw/AnalogPin.o lib/hw/AnalogPin.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/core/Delay.o: lib/core/Delay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/core 
	@${RM} ${OBJECTDIR}/lib/core/Delay.o.d 
	@${RM} ${OBJECTDIR}/lib/core/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/core/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/core/Delay.o.d" -o ${OBJECTDIR}/lib/core/Delay.o lib/core/Delay.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/core/CircularBuffer.o: lib/core/CircularBuffer.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/core 
	@${RM} ${OBJECTDIR}/lib/core/CircularBuffer.o.d 
	@${RM} ${OBJECTDIR}/lib/core/CircularBuffer.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/core/CircularBuffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/core/CircularBuffer.o.d" -o ${OBJECTDIR}/lib/core/CircularBuffer.o lib/core/CircularBuffer.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/Port.o: lib/hw/Port.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/Port.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/Port.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/Port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/Port.o.d" -o ${OBJECTDIR}/lib/hw/Port.o lib/hw/Port.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/SerialPort.o: lib/hw/SerialPort.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/SerialPort.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/SerialPort.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/SerialPort.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/SerialPort.o.d" -o ${OBJECTDIR}/lib/hw/SerialPort.o lib/hw/SerialPort.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/DigitalPin.o: lib/hw/DigitalPin.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/DigitalPin.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/DigitalPin.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/DigitalPin.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/DigitalPin.o.d" -o ${OBJECTDIR}/lib/hw/DigitalPin.o lib/hw/DigitalPin.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/Key.o: lib/io/Key.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/Key.o.d 
	@${RM} ${OBJECTDIR}/lib/io/Key.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/Key.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/Key.o.d" -o ${OBJECTDIR}/lib/io/Key.o lib/io/Key.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/TextDisplay.o: lib/io/TextDisplay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/TextDisplay.o.d 
	@${RM} ${OBJECTDIR}/lib/io/TextDisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/TextDisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/TextDisplay.o.d" -o ${OBJECTDIR}/lib/io/TextDisplay.o lib/io/TextDisplay.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/Led.o: lib/io/Led.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/Led.o.d 
	@${RM} ${OBJECTDIR}/lib/io/Led.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/Led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/Led.o.d" -o ${OBJECTDIR}/lib/io/Led.o lib/io/Led.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/Keypad.o: lib/io/Keypad.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/Keypad.o.d 
	@${RM} ${OBJECTDIR}/lib/io/Keypad.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/Keypad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/Keypad.o.d" -o ${OBJECTDIR}/lib/io/Keypad.o lib/io/Keypad.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/IncrementalEncoder.o: lib/io/IncrementalEncoder.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/IncrementalEncoder.o.d 
	@${RM} ${OBJECTDIR}/lib/io/IncrementalEncoder.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/IncrementalEncoder.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/IncrementalEncoder.o.d" -o ${OBJECTDIR}/lib/io/IncrementalEncoder.o lib/io/IncrementalEncoder.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/I2CMaster.o: lib/io/I2CMaster.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/I2CMaster.o.d 
	@${RM} ${OBJECTDIR}/lib/io/I2CMaster.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/I2CMaster.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/I2CMaster.o.d" -o ${OBJECTDIR}/lib/io/I2CMaster.o lib/io/I2CMaster.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/core/settings.o: lib/core/settings.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/core 
	@${RM} ${OBJECTDIR}/lib/core/settings.o.d 
	@${RM} ${OBJECTDIR}/lib/core/settings.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/core/settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/core/settings.o.d" -o ${OBJECTDIR}/lib/core/settings.o lib/core/settings.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/SPI.o: lib/io/SPI.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/SPI.o.d 
	@${RM} ${OBJECTDIR}/lib/io/SPI.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/SPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/SPI.o.d" -o ${OBJECTDIR}/lib/io/SPI.o lib/io/SPI.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/hw/LTC2604.o: lib/hw/LTC2604.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/hw 
	@${RM} ${OBJECTDIR}/lib/hw/LTC2604.o.d 
	@${RM} ${OBJECTDIR}/lib/hw/LTC2604.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/hw/LTC2604.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/hw/LTC2604.o.d" -o ${OBJECTDIR}/lib/hw/LTC2604.o lib/hw/LTC2604.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
${OBJECTDIR}/lib/io/I2C.o: lib/io/I2C.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/lib/io 
	@${RM} ${OBJECTDIR}/lib/io/I2C.o.d 
	@${RM} ${OBJECTDIR}/lib/io/I2C.o 
	@${FIXDEPS} "${OBJECTDIR}/lib/io/I2C.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -O1 -I"../" -I"lib/boards" -I"lib/hw" -I"lib/io" -I"lib/core" -MMD -MF "${OBJECTDIR}/lib/io/I2C.o.d" -o ${OBJECTDIR}/lib/io/I2C.o lib/io/I2C.cpp   -fthread-jumps            -fcaller-saves            -fcrossjumping            -fcse-follow-jumps  -fcse-skip-blocks            -fdelete-null-pointer-checks            -fexpensive-optimizations            -fgcse  -fgcse-lm             -finline-small-functions            -findirect-inlining            -fipa-sra            -foptimize-sibling-calls            -fpeephole2            -freorder-functions            -frerun-cse-after-loop             -fsched-interblock  -fsched-spec            -fschedule-insns  -fschedule-insns2            -fstrict-aliasing -fstrict-overflow            -ftree-switch-conversion           -ftree-pre            
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,--defsym=_min_heap_size=3072,-Map="TpTestKitPic32.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=3072,-Map="TpTestKitPic32.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/PIC32_Cpp.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
