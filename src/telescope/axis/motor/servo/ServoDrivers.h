// -----------------------------------------------------------------------------------
// servo driver control
#pragma once

#include <Arduino.h>
#include "../../../../Common.h"

// the various microsteps for different driver models, with the bit modes for each
#define DRIVER_SERVO_MODEL_COUNT 2

#include "../Drivers.h"
#include "Servo.defaults.h"

#ifdef SERVO_DRIVER_PRESENT

#pragma pack(1)
#define StepDriverSettingsSize 15
typedef struct ServoDriverSettings {
  int16_t model;
  int16_t p;
  int16_t i;
  int16_t d;
  int8_t  status;
} ServoDriverSettings;
#pragma pack()

typedef struct ServoDriverPins {
  int16_t in1;
  uint8_t inState1;
  int16_t in2;
  uint8_t inState2;
  int16_t enable;
  uint8_t enabledState;
  int16_t fault;
} ServoDriverPins;

class ServoDriver {
  public:
    // constructor
    ServoDriver(uint8_t axisNumber, const ServoDriverPins *Pins, const ServoDriverSettings *Settings);

    // decodes driver model/microstep mode into microstep codes (bit patterns or SPI)
    // and sets up the pin modes
    void init();

    // update status info. for driver
    // this is a required method for the Axis class
    void updateStatus();

    // get status info.
    // this is a required method for the Axis class
    DriverStatus getStatus();

    // secondary way to power down not using the enable pin
    // this is a required method for the Axis class, even if it does nothing
    void power(bool state);

    // get the microsteps goto
    // this is a required method for the Axis class, even if it only ever returns 1
    inline int getSubdivisionsGoto() { return 1; }

    // power level to the motor (-AnalogRange to AnalogRange, negative for reverse)
    void setMotorPower(int power);

    ServoDriverSettings settings;

  private:
    // motor direction (DIR_FORMWARD or DIR_REVERSE)
    void setMotorDirection(Direction dir);

    void update();

    int axisNumber;
    bool powered = false;

    int motorPwr = 0;
    Direction motorDir = DIR_FORWARD;

    DriverStatus status = {{false, false}, {false, false}, false, false, false, false};

    const ServoDriverPins *Pins;
};

#ifdef AXIS1_DRIVER_SERVO
  extern ServoDriver servoDriver1;
#endif
#ifdef AXIS2_DRIVER_SERVO
  extern ServoDriver servoDriver2;
#endif
#ifdef AXIS3_DRIVER_SERVO
  extern ServoDriver servoDriver3;
#endif
#ifdef AXIS4_DRIVER_SERVO
  extern ServoDriver servoDriver4;
#endif
#ifdef AXIS5_DRIVER_SERVO
  extern ServoDriver servoDriver5;
#endif
#ifdef AXIS6_DRIVER_SERVO
  extern ServoDriver servoDriver6;
#endif
#ifdef AXIS7_DRIVER_SERVO
  extern ServoDriver servoDriver7;
#endif
#ifdef AXIS8_DRIVER_SERVO
  extern ServoDriver servoDriver8;
#endif
#ifdef AXIS9_DRIVER_SERVO
  extern ServoDriver servoDriver9;
#endif

#endif
