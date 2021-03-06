#ifndef CONFIG_H
#define CONFIG_H


//#define DEBUG
#define DEBUGMODE


#define SERIAL1ENABLED    1
#define ENABLE LOW                // 8825 stepper motor enable is active low
#define DISABLE HIGH              // 8825 stepper motor disable is active high

#define MMU2_VERSION "5.0  10/11/19"

#define STEPSPERMM  144ul           // these are the number of steps required to travel 1 mm using the extruder motor

#define S1_WAIT_TIME 10  //wait time for serial 1 (mmu<->printer)

#define FW_VERSION 90             // config.h  (MM-control-01 firmware)
#define FW_BUILDNR 168             // config.h  (MM-control-01 firmware)

#define TIMEOUT_LOAD_UNLOAD 20000

// changed from 125 to 115 (10.13.18)
#define MAXROLLERTRAVEL 125         // number of steps that the roller bearing stepper motor can travel

#define FULL_STEP  1u
#define HALF_STEP  2u
#define QUARTER_STEP 4u
#define EIGTH_STEP 8u
#define SIXTEENTH_STEP 16u

//#define DIST_MMU_EXTRUDER 890
#define DIST_MMU_EXTRUDER 690
#define DIST_EXTRUDER_BTGEAR 30


#define STEPSIZE SIXTEENTH_STEP    // setup for each of the three stepper motors (jumper settings for M0,M1,M2) on the RAMPS 1.x board

#define STEPSPERREVOLUTION 200     // 200 steps per revolution  - 1.8 degree motors are being used


#define MMU2TOEXTRUDERSTEPS STEPSIZE*STEPSPERREVOLUTION*19   // for the 'T' command
                        // quick parked


//************************************************************************************
//* this resets the selector stepper motor after the selected number of tool changes
//*************************************************************************************
#define TOOLSYNC 5                         // number of tool change (T) commands before a selector resync is performed



#define PINHIGH 10                    // how long to hold stepper motor pin high in microseconds
#define PINLOW  10                    // how long to hold stepper motor pin low in microseconds



// the MMU2 currently runs at 21mm/sec (set by Slic3r) for 2 seconds (good stuff to know)
//
// the load duration was chagned from 1 second to 1.1 seconds on 10.8.18 (as an experiment)
// increased from 1.1 to 1.5 seconds on 10.13.18 (another experiment)
//1600
#define LOAD_DURATION 1000                 // duration of 'C' command during the load process (in milliseconds)
// changed from 21 mm/sec to 30 mm/sec on 10.13.18
#define LOAD_SPEED 30                   // load speed (in mm/second) during the 'C' command (determined by Slic3r setting)
#define INSTRUCTION_DELAY 25          // delay (in microseconds) of the loop
#define FILAMENT_TO_MK3_C0_WAIT_TIME 2000

// Distance to restract the filament into the MMU 
#define UNLOAD_LENGTH_BACK_COLORSELECTOR 30
//
int IDLEROFFSET[5] = {0,0,0,0,0};
#define IDLERSTEPSIZE 25         // steps to each roller bearing



// changed position #2 to 372  (still tuning this little sucker)

#define MAXSELECTOR_STEPS   1800//1890   // maximum number of selector stepper motor (used to move all the way to the right or left
int CSOFFSET[5] = {30,30,0,-15,-30};
#define CSSTEPS 357
#define CS_RIGHT_FORCE 20
#define CS_RIGHT_FORCE_SELECTOR_0 5

//*************************************************************************************************
//  Delay values for each stepper motor
//*************************************************************************************************
#define IDLERMOTORDELAY  540     //540 useconds      (idler motor)  was at '500' on 10.13.18
#define EXTRUDERMOTORDELAY 60//50     // 150 useconds    (controls filament feed speed to the printer)
#define COLORSELECTORMOTORDELAY 60 // 60 useconds    (selector motor)
#define filamentSwitchON 0
//#define FILAMENTSWITCH_BEFORE_EXTRUDER // turn on if the filament switch is before the extruder, turn off for the mk3s-mmu filament switch
#define FILAMENTSWITCH_ON_EXTRUDER // turn on if the filament switch on is the extruder, turn on for the mk3s-mmu filament switch

#include "boards.h" 
//#define SKRMINI
//#define GT2560
#define SANGUINOLOLU_V_1_2

#ifdef SKRMINI
  #include "pins_BTT_SKR_MINI_V1_1.h"
#endif
#ifdef GT2560
  #include "pins_GT2560_V3.h"
#endif
#ifdef SANGUINOLOLU_V_1_2
  #include "pins_SANGUINOLOLU_11.h"
#endif

  #define greenLED HEATER_BED_PIN 
  
  //ex PIN X now
  // Z-Connector      
  #define colorSelectorDirPin   Z_DIR_PIN //color selector stepper motor (driven by trapezoidal screw)
  #define colorSelectorStepPin  Z_STEP_PIN 
  #define colorSelectorEnablePin  Z_ENABLE_PIN
  
  // PIN Y 
  #define idlerDirPin   Y_DIR_PIN 
  #define idlerStepPin  Y_STEP_PIN
  #define idlerEnablePin  Y_ENABLE_PIN 
  
  // PIN E
// E-Connector    
  #define extruderDirPin    E0_DIR_PIN    //  pin 48 for extruder motor direction pin
  #define extruderStepPin   E0_STEP_PIN   //  pin 48 for extruder motor stepper motor pin
  #define extruderEnablePin E0_ENABLE_PIN //14 //  pin A8 for extruder motor rst/sleep motor pin
 
  //BROWN = +5V
  //BLUE = GND
  //BLACK = SIGNAL
  // X_MIN_PIN
// Endstop X Connector
#ifndef X_STOP_PIN
    #define findaPin X_MIN_PIN   
#else
    #define findaPin  X_STOP_PIN
#endif  

  // Z_MIN_PIN
//  Endstop Z Connector 
#ifndef Z_STOP_PIN
    #define colorSelectorEnstop Z_MIN_PIN   
#else
    #define colorSelectorEnstop Z_STOP_PIN
#endif
  
  // Z_MAX_PIN
//  Endstop Y Connector 
#ifndef Y_STOP_PIN
  #define filamentSwitch Z_MAX_PIN      // this switch was added on 10.1.18 to help with filament loading (X- signal on the RAMPS board)
#else
  #define filamentSwitch Y_STOP_PIN       // this switch was added on 10.1.18 to help with filament loading (X- signal on the RAMPS board)
#endif

#endif // CONFIG_H
