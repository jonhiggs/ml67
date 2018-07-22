/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* IMPORTANT: TMK columns are Filco rows due to the direction of the diodes in
 * the circuit board.

  | Filco | Teensy |
  |-------|--------|
  | R0    | F0     |
  | R1    | F1     |
  | R2    | F4     |
  | R3    | F5     |
  | R4    | F6     |
  | R5    | F7     |
  | R6    | B6     |
  | R7    | B5     |

  | FOOT  | TEENSY |
  |-------|--------|
  | R8    | D4     |
*/

static void  init_cols(void)
{
    DDRF  &= ~0b11110011;
    PORTF |=  0b11110011;
    DDRB  &= ~0b01100000;
    PORTB |=  0b01100000;
    DDRD  &= ~0b00010000;
    PORTD |=  0b00010000;
}

static matrix_row_t read_cols(void)
{
    return (PINF&(1<<0) ? 0 : (1<<0) ) |
           (PINF&(1<<1) ? 0 : (1<<1) ) |
           (PINF&(1<<4) ? 0 : (1<<2) ) |
           (PINF&(1<<5) ? 0 : (1<<3) ) |
           (PINF&(1<<6) ? 0 : (1<<4) ) |
           (PINF&(1<<7) ? 0 : (1<<5) ) |
           (PINB&(1<<6) ? 0 : (1<<6) ) |
           (PINB&(1<<5) ? 0 : (1<<7) ) |
           (PIND&(1<<4) ? 0 : (1<<8) ) ;
}

/* IMPORTANT: TMK rows are Filco columns due to the direction of the diodes in
 * the circuit board.

Row| Filco  | Teensy |
---|--------|--------|
0  | C1/C12 | B0     |
1  | C2/C14 | B1     |
2  | C3/C0  | B2     |
3  | C4     | B3     |
4  | C5     | B7     |
5  | C6     | D0     |
6  | C7/C13 | D1     |
7  | C8     | D2     |
8  | C9     | D3     |
9  | C10    | C6     |
10 | C11    | C7     |
11 | C15    | D5     |

   | FOOT  | TEENSY |
   |-------|--------|
   | C16   | E6     |
   | C17   | F5     |
*/

static void unselect_rows(void)
{
    DDRB  &= ~0b10001111;
    PORTB &= ~0b10001111;
    DDRE  &= ~0b01000000;
    PORTE &= ~0b01000000;
    DDRD  &= ~0b00101111;
    PORTD &= ~0b00101111;
    DDRC  &= ~0b11000000;
    PORTC &= ~0b11000000;
}

static void select_row(uint8_t row)
{
    switch (row) {
        case 0:
            DDRB  |= (1<<0);
            PORTB &= ~(1<<0);
            break;
        case 1:
            DDRB  |= (1<<1);
            PORTB &= ~(1<<1);
            break;
        case 2:
            DDRB  |= (1<<2);
            PORTB &= ~(1<<2);
            break;
        case 3:
            DDRB  |= (1<<3);
            PORTB &= ~(1<<3);
            break;
        case 4:
            DDRB  |= (1<<7);
            PORTB &= ~(1<<7);
            break;
        case 5:
            DDRD  |= (1<<0);
            PORTD &= ~(1<<0);
            break;
        case 6:
            DDRD  |= (1<<1);
            PORTD &= ~(1<<1);
            break;
        case 7:
            DDRD  |= (1<<2);
            PORTD &= ~(1<<2);
            break;
        case 8:
            DDRD  |= (1<<3);
            PORTD &= ~(1<<3);
            break;
        case 9:
            DDRC  |= (1<<6);
            PORTC &= ~(1<<6);
            break;
        case 10:
            DDRC  |= (1<<7);
            PORTC &= ~(1<<7);
            break;
        case 11:
            DDRD  |= (1<<5);
            PORTD &= ~(1<<5);
            break;
        case 12:
            DDRE  |= (1<<6);
            PORTE &= ~(1<<6);
            break;
    }
}
