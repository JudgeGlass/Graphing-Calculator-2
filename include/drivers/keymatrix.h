#ifndef __KEYMATRIX_H__
#define __KEYMATRIX_H__

#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <screen.hpp>

#define ROW_COUNT 7
#define COL_COUNT 5

static uint cols[5] = {0, 1, 2, 3, 4};
static uint rows[7] = {5, 6, 7, 8, 9, 10, 11};

static char matrix[7][5] = {
  {'a', 'b', 'c', 'd', 'e'},
  {'f', 'g', 'h', 'i', 'j'},
  {'k', 'l', 'm', 'n', 'o'},
  {'p', 'q', 'r', 's', 't'},
  {'u', 'v', 'w', 'x', 'y'},
  {'z', '0', '1', '2', '3'},
  {'4', '5', '6', '7', '8'}
};

static char currentKey;

void pico_keypad_init();

char pico_keypad_get_key(Screen *s);

void pico_keypad_update();
#endif