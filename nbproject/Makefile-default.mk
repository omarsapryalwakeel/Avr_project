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
FINAL_IMAGE=${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Mai.c Source/GPIO.c Source/EXTINTERRUPT.c Source/Timer.c Source/SPI.c Source/I2C.c Source/AnalogCompare.c Source/ADC.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Mai.o ${OBJECTDIR}/Source/GPIO.o ${OBJECTDIR}/Source/EXTINTERRUPT.o ${OBJECTDIR}/Source/Timer.o ${OBJECTDIR}/Source/SPI.o ${OBJECTDIR}/Source/I2C.o ${OBJECTDIR}/Source/AnalogCompare.o ${OBJECTDIR}/Source/ADC.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Mai.o.d ${OBJECTDIR}/Source/GPIO.o.d ${OBJECTDIR}/Source/EXTINTERRUPT.o.d ${OBJECTDIR}/Source/Timer.o.d ${OBJECTDIR}/Source/SPI.o.d ${OBJECTDIR}/Source/I2C.o.d ${OBJECTDIR}/Source/AnalogCompare.o.d ${OBJECTDIR}/Source/ADC.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Mai.o ${OBJECTDIR}/Source/GPIO.o ${OBJECTDIR}/Source/EXTINTERRUPT.o ${OBJECTDIR}/Source/Timer.o ${OBJECTDIR}/Source/SPI.o ${OBJECTDIR}/Source/I2C.o ${OBJECTDIR}/Source/AnalogCompare.o ${OBJECTDIR}/Source/ADC.o

# Source Files
SOURCEFILES=Mai.c Source/GPIO.c Source/EXTINTERRUPT.c Source/Timer.c Source/SPI.c Source/I2C.c Source/AnalogCompare.c Source/ADC.c



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
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega48PA
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Mai.o: Mai.c  .generated_files/flags/default/acc486d3cb6005f67bcb0ad3ee94154163b78b5b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mai.o.d 
	@${RM} ${OBJECTDIR}/Mai.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Mai.o.d" -MT "${OBJECTDIR}/Mai.o.d" -MT ${OBJECTDIR}/Mai.o -o ${OBJECTDIR}/Mai.o Mai.c 
	
${OBJECTDIR}/Source/GPIO.o: Source/GPIO.c  .generated_files/flags/default/438553a159ad24b5cdf2065aa4a16a915ef55317 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/GPIO.o.d 
	@${RM} ${OBJECTDIR}/Source/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/GPIO.o.d" -MT "${OBJECTDIR}/Source/GPIO.o.d" -MT ${OBJECTDIR}/Source/GPIO.o -o ${OBJECTDIR}/Source/GPIO.o Source/GPIO.c 
	
${OBJECTDIR}/Source/EXTINTERRUPT.o: Source/EXTINTERRUPT.c  .generated_files/flags/default/c65d4542ac21d90dd20197d740af7f63f6916bca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/EXTINTERRUPT.o.d 
	@${RM} ${OBJECTDIR}/Source/EXTINTERRUPT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/EXTINTERRUPT.o.d" -MT "${OBJECTDIR}/Source/EXTINTERRUPT.o.d" -MT ${OBJECTDIR}/Source/EXTINTERRUPT.o -o ${OBJECTDIR}/Source/EXTINTERRUPT.o Source/EXTINTERRUPT.c 
	
${OBJECTDIR}/Source/Timer.o: Source/Timer.c  .generated_files/flags/default/fd0bd907fb62ca6dbad7d14393b70375e39faa7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/Timer.o.d 
	@${RM} ${OBJECTDIR}/Source/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/Timer.o.d" -MT "${OBJECTDIR}/Source/Timer.o.d" -MT ${OBJECTDIR}/Source/Timer.o -o ${OBJECTDIR}/Source/Timer.o Source/Timer.c 
	
${OBJECTDIR}/Source/SPI.o: Source/SPI.c  .generated_files/flags/default/2bc10376883171cc16244950eb187f7548b3136e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/SPI.o.d 
	@${RM} ${OBJECTDIR}/Source/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/SPI.o.d" -MT "${OBJECTDIR}/Source/SPI.o.d" -MT ${OBJECTDIR}/Source/SPI.o -o ${OBJECTDIR}/Source/SPI.o Source/SPI.c 
	
${OBJECTDIR}/Source/I2C.o: Source/I2C.c  .generated_files/flags/default/ea790d6e21f369ae9f6503cc8fe3da0d8bd1cbc0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/I2C.o.d 
	@${RM} ${OBJECTDIR}/Source/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/I2C.o.d" -MT "${OBJECTDIR}/Source/I2C.o.d" -MT ${OBJECTDIR}/Source/I2C.o -o ${OBJECTDIR}/Source/I2C.o Source/I2C.c 
	
${OBJECTDIR}/Source/AnalogCompare.o: Source/AnalogCompare.c  .generated_files/flags/default/58f2193a9f44683d406e4fe7bcb82de86c8cebdb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/AnalogCompare.o.d 
	@${RM} ${OBJECTDIR}/Source/AnalogCompare.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/AnalogCompare.o.d" -MT "${OBJECTDIR}/Source/AnalogCompare.o.d" -MT ${OBJECTDIR}/Source/AnalogCompare.o -o ${OBJECTDIR}/Source/AnalogCompare.o Source/AnalogCompare.c 
	
${OBJECTDIR}/Source/ADC.o: Source/ADC.c  .generated_files/flags/default/5bae37da03ada1a8be7d069124199813f1749c79 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/ADC.o.d 
	@${RM} ${OBJECTDIR}/Source/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/ADC.o.d" -MT "${OBJECTDIR}/Source/ADC.o.d" -MT ${OBJECTDIR}/Source/ADC.o -o ${OBJECTDIR}/Source/ADC.o Source/ADC.c 
	
else
${OBJECTDIR}/Mai.o: Mai.c  .generated_files/flags/default/c837b66c8f559897243156d9cdccfe65949f8dcc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Mai.o.d 
	@${RM} ${OBJECTDIR}/Mai.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Mai.o.d" -MT "${OBJECTDIR}/Mai.o.d" -MT ${OBJECTDIR}/Mai.o -o ${OBJECTDIR}/Mai.o Mai.c 
	
${OBJECTDIR}/Source/GPIO.o: Source/GPIO.c  .generated_files/flags/default/1aa76d17efb367e8d5ea94f3005f0c97d52e0b51 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/GPIO.o.d 
	@${RM} ${OBJECTDIR}/Source/GPIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/GPIO.o.d" -MT "${OBJECTDIR}/Source/GPIO.o.d" -MT ${OBJECTDIR}/Source/GPIO.o -o ${OBJECTDIR}/Source/GPIO.o Source/GPIO.c 
	
${OBJECTDIR}/Source/EXTINTERRUPT.o: Source/EXTINTERRUPT.c  .generated_files/flags/default/7119df43dd71ac03121b79b875348264a2e3bf10 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/EXTINTERRUPT.o.d 
	@${RM} ${OBJECTDIR}/Source/EXTINTERRUPT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/EXTINTERRUPT.o.d" -MT "${OBJECTDIR}/Source/EXTINTERRUPT.o.d" -MT ${OBJECTDIR}/Source/EXTINTERRUPT.o -o ${OBJECTDIR}/Source/EXTINTERRUPT.o Source/EXTINTERRUPT.c 
	
${OBJECTDIR}/Source/Timer.o: Source/Timer.c  .generated_files/flags/default/99ad30509630a9c1afdde251e70d09fb2c2faf5b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/Timer.o.d 
	@${RM} ${OBJECTDIR}/Source/Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/Timer.o.d" -MT "${OBJECTDIR}/Source/Timer.o.d" -MT ${OBJECTDIR}/Source/Timer.o -o ${OBJECTDIR}/Source/Timer.o Source/Timer.c 
	
${OBJECTDIR}/Source/SPI.o: Source/SPI.c  .generated_files/flags/default/6a57757f1c0c85efa0e3237b08ca8f029281f2e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/SPI.o.d 
	@${RM} ${OBJECTDIR}/Source/SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/SPI.o.d" -MT "${OBJECTDIR}/Source/SPI.o.d" -MT ${OBJECTDIR}/Source/SPI.o -o ${OBJECTDIR}/Source/SPI.o Source/SPI.c 
	
${OBJECTDIR}/Source/I2C.o: Source/I2C.c  .generated_files/flags/default/13e6c5e0ae88bc208c510240f85871a2a077f15b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/I2C.o.d 
	@${RM} ${OBJECTDIR}/Source/I2C.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/I2C.o.d" -MT "${OBJECTDIR}/Source/I2C.o.d" -MT ${OBJECTDIR}/Source/I2C.o -o ${OBJECTDIR}/Source/I2C.o Source/I2C.c 
	
${OBJECTDIR}/Source/AnalogCompare.o: Source/AnalogCompare.c  .generated_files/flags/default/1bd0af5a4957a69e7ebe7bb0ae97d2c70f8df6b9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/AnalogCompare.o.d 
	@${RM} ${OBJECTDIR}/Source/AnalogCompare.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/AnalogCompare.o.d" -MT "${OBJECTDIR}/Source/AnalogCompare.o.d" -MT ${OBJECTDIR}/Source/AnalogCompare.o -o ${OBJECTDIR}/Source/AnalogCompare.o Source/AnalogCompare.c 
	
${OBJECTDIR}/Source/ADC.o: Source/ADC.c  .generated_files/flags/default/d40f923ecc170ddff3e88b415fffad18912f756d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/Source" 
	@${RM} ${OBJECTDIR}/Source/ADC.o.d 
	@${RM} ${OBJECTDIR}/Source/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/Source/ADC.o.d" -MT "${OBJECTDIR}/Source/ADC.o.d" -MT ${OBJECTDIR}/Source/ADC.o -o ${OBJECTDIR}/Source/ADC.o Source/ADC.c 
	
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1
	@${RM} ${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/atmega48API.X.${IMAGE_TYPE}.hex"
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
