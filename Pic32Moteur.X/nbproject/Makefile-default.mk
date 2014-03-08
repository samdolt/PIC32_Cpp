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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../SK32MX795F512L.cpp ../TextDisplay.cpp ../main.cpp ../Delay.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ${OBJECTDIR}/_ext/1472/TextDisplay.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/Delay.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d ${OBJECTDIR}/_ext/1472/TextDisplay.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/Delay.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ${OBJECTDIR}/_ext/1472/TextDisplay.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/Delay.o

# Source Files
SOURCEFILES=../SK32MX795F512L.cpp ../TextDisplay.cpp ../main.cpp ../Delay.cpp


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX775F512L
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
${OBJECTDIR}/_ext/1472/SK32MX795F512L.o: ../SK32MX795F512L.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" -o ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ../SK32MX795F512L.cpp  
	
${OBJECTDIR}/_ext/1472/TextDisplay.o: ../TextDisplay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/TextDisplay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TextDisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TextDisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/TextDisplay.o.d" -o ${OBJECTDIR}/_ext/1472/TextDisplay.o ../TextDisplay.cpp  
	
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp  
	
${OBJECTDIR}/_ext/1472/Delay.o: ../Delay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/Delay.o.d" -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.cpp  
	
else
${OBJECTDIR}/_ext/1472/SK32MX795F512L.o: ../SK32MX795F512L.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/SK32MX795F512L.o.d" -o ${OBJECTDIR}/_ext/1472/SK32MX795F512L.o ../SK32MX795F512L.cpp  
	
${OBJECTDIR}/_ext/1472/TextDisplay.o: ../TextDisplay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/TextDisplay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TextDisplay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TextDisplay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/TextDisplay.o.d" -o ${OBJECTDIR}/_ext/1472/TextDisplay.o ../TextDisplay.cpp  
	
${OBJECTDIR}/_ext/1472/main.o: ../main.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.cpp  
	
${OBJECTDIR}/_ext/1472/Delay.o: ../Delay.cpp  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CPPC} $(MP_EXTRA_CC_PRE)  -g -x c++ -c -mprocessor=$(MP_PROCESSOR_OPTION)  -frtti -fexceptions -fno-check-new -fenforce-eh-specs -I"../../../../../../../../Program Files (x86)/Microchip/xc32/v1.31/pic32mx/include/proc" -I"../../../../../Applications/microchip/xc32/v1.30/pic32mx/include/proc" -I"../../../../../../../../Program Files/Microchip/xc32/v1.31/pic32mx/include/proc" -MMD -MF "${OBJECTDIR}/_ext/1472/Delay.o.d" -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.cpp  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,--defsym=_min_heap_size=1024,-Map="TpTestKitPic32.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CPPC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,-Map="TpTestKitPic32.map"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Pic32Moteur.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
