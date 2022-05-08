/*
	schoki_misc
	Copyright (C) 2022	Andy Frank Schoknecht

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef SM_TYPES_H
#define SM_TYPES_H

#include <stdint.h>

typedef enum bool_t
{
	FALSE = 0,
	TRUE = 1
} bool_t ;

typedef int8_t			s8_t;
typedef uint8_t			u8_t;
typedef int_fast8_t		sl8_t;
typedef uint_fast8_t	ul8_t;
typedef int16_t			s16_t;
typedef uint16_t		u16_t;
typedef int_fast16_t	sl16_t;
typedef uint_fast16_t	ul16_t;
typedef int32_t			s32_t;
typedef uint32_t		u32_t;
typedef int_fast32_t	sl32_t;
typedef uint_fast32_t	ul32_t;
typedef int64_t			s64_t;
typedef uint64_t		u64_t;

#endif // SM_TYPES_H
