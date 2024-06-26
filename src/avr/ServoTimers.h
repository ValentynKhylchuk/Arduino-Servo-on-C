/*
  Servo.h - Interrupt driven Servo library for Arduino using 16 bit timers - Version 2
  Copyright (c) 2009 Michael Margolis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
 * Defines for 16 bit timers used with Servo library
 *
 * If _useTimerX is defined then TimerX is a 16 bit timer on the current board
 * timer16_Sequence_t enumerates the sequence that the timers should be allocated
 * _Nbr_16timers indicates how many 16 bit timers are available.
 */

/**
 * AVR Only definitions
 * --------------------
 */

// Say which 16 bit timers can be used and in what order
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)

#define _useTimer5
#define _useTimer1
#define _useTimer3
#define _useTimer4

#if !defined(_useTimer5) && !defined(_useTimer1) && !defined(_useTimer3) && !defined(_useTimer4)
  #error "No times are difined!"
#else
  typedef enum {
  #if defined(_useTimer5)
    _timer5,
  #endif
  #if defined(_useTimer1)
    _timer1,
  #endif
  #if defined(_useTimer3)
    _timer3,
  #endif
  #if defined(_useTimer4)
    _timer4,
  #endif
    _Nbr_16timers } timer16_Sequence_t;
#endif


#else  // everything else

#define _useTimer1
typedef enum { _timer1, _Nbr_16timers } timer16_Sequence_t;

#endif
