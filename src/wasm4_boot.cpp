#include "arduino.h"
#include "abw4lib.h"

uint8_t bootMode = 0;
unsigned int bootTicks = 0;

#define BOOT_MODE_COUNT 2

const FunctionPointer bootModes[BOOT_MODE_COUNT] = {
  wasm4Logo,
  jgLogo
};


bool stillBooting() {
    if (bootMode < BOOT_MODE_COUNT) {
        bootModes[bootMode]();
    }
    return bootMode < BOOT_MODE_COUNT;
}


void wasm4Logo() {
  bootTicks++;

  const uint8_t logo[1024] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xaa,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xaa,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xaa,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xaa,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xaa,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xaa,0xaa,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x40,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x01,0x50,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x01,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x05,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x05,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x15,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x15,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x15,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x05,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x40,0x00,0x00,0x00,0x05,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

  PALETTE[0] = 0x000;
  PALETTE[1] = 0x668f31;
  PALETTE[2] = 0xd3e6bb;
  PALETTE[3] = 0xff0000;

  *DRAW_COLORS = 0x1032;
  blit(logo, 48, 48, 64, 64, BLIT_2BPP);
  if (bootTicks>100)
    bootMode++;
}


void jgLogo() {
  bootTicks++;

  const uint8_t joshgoebel[1024] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x50,0x00,0x00,0x00,0x00,0x54,0x00,0x00,0x05,0x40,0x00,0x00,0x00,0x03,0xc0,0x05,0x40,0x3c,0x00,0xf0,0x01,0x50,0x0f,0x00,0x15,0x00,0xf0,0x00,0x00,0x03,0xc0,0x15,0x00,0x3c,0x00,0xf0,0x05,0x40,0x0f,0x00,0x54,0x00,0xf0,0x00,0x00,0x00,0x00,0x54,0x00,0x00,0x00,0x00,0x15,0x00,0x00,0x01,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x80,0x00,0x02,0xaa,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x80,0x00,0x2a,0xaa,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x80,0x02,0xaa,0x00,0x02,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x80,0x0a,0xa0,0x00,0x00,0x2a,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x80,0x2a,0x00,0x00,0x00,0x02,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x80,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x82,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x82,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x8a,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x02,0xaa,0xaa,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x02,0xaa,0xaa,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x02,0xaa,0xaa,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0xa0,0x00,0x00,0x02,0x80,0x00,0x00,0x00,0x0a,0x2a,0x00,0x00,0x00,0x00,0x00,0x02,0xa0,0x00,0x00,0x02,0x80,0x00,0x00,0x00,0x0a,0x0a,0x00,0x00,0x00,0x00,0x00,0x02,0x80,0x00,0x00,0x02,0x80,0x00,0x00,0x00,0x0a,0x0a,0x80,0x00,0x00,0x00,0x00,0x0a,0x80,0x00,0x00,0x02,0xa0,0x00,0x00,0x00,0x2a,0x02,0x80,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0xa0,0x00,0x00,0x00,0x28,0x02,0xa0,0x00,0x00,0x00,0x00,0x2a,0x00,0x00,0x00,0x00,0xa8,0x00,0x00,0x00,0xa8,0x00,0xa8,0x00,0x00,0x00,0x00,0xa8,0x00,0x00,0x00,0x00,0x2a,0x00,0x00,0x02,0xa0,0x00,0x2a,0x00,0x00,0x00,0x02,0xa0,0x00,0x00,0x00,0x00,0x0a,0x80,0x00,0x0a,0x80,0x00,0x0a,0xa0,0x00,0x00,0x2a,0x80,0x00,0x00,0x00,0x00,0x02,0xa8,0x00,0xaa,0x00,0x00,0x02,0xaa,0x00,0x02,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xaa,0xa8,0x00,0x00,0x00,0x2a,0xaa,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xaa,0x80,0x00,0x00,0x00,0x02,0xaa,0xaa,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x50,0x00,0x00,0x00,0x00,0x00,0x01,0x50,0x05,0x40,0x15,0x00,0x00,0x00,0x0f,0x00,0x54,0x00,0xf0,0x03,0xc0,0x0f,0x00,0x54,0x01,0x50,0x05,0x40,0x00,0x00,0x0f,0x00,0x15,0x00,0xf0,0x03,0xc0,0x0f,0x00,0x15,0x00,0x54,0x01,0x50,0x00,0x00,0x00,0x00,0x05,0x40,0x00,0x00,0x00,0x00,0x00,0x05,0x40,0x15,0x00,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

  PALETTE[0] = 0x000;
  PALETTE[1] = 0xccff00;
  PALETTE[2] = 0xffffff;
  PALETTE[3] = 0x333333;

  *DRAW_COLORS = 0x1;
  rect(0,0,159,159);
  *DRAW_COLORS = 0x4320;

  blit(joshgoebel, 48, 48, 64, 64, BLIT_2BPP);

  if (bootTicks>200)
      bootMode++;
}


