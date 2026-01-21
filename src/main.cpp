#include <Arduino.h>

#include "USB.h"
#include "USBHIDGamepad.h"
USBHIDGamepad Gamepad;

// ===== ピン定義 =====
#define MStart1 42

#define LX 18
#define LY 17
#define RX 15
#define RY 16

#define LB 39
#define RB 40

#define UP 3
#define RIGHT 9
#define DOWN 10
#define LEFT 11

#define ZL 35
#define ZR 36
#define L 2
#define R 1

#define PLUS 38
#define MINUS 37

#define BTN_B 5
#define BTN_A 4
#define BTN_X 7
#define BTN_Y 6

int16_t readAxe(int pin){
  return map(analogRead(pin), 0, 4095, 0, 32767);
}

void setup() {
  int pins[] = {
    MStart1, LB, RB,
    UP, RIGHT, DOWN, LEFT,
    ZL, ZR, L, R,
    PLUS, MINUS,
    BTN_A, BTN_B, BTN_X, BTN_Y
  };
  for(int p : pins) pinMode(p, INPUT_PULLUP);

  Gamepad.begin();
  USB.begin();
}

void loop() {
  Gamepad.leftStick(readAxe(LX), readAxe(LY));
}
