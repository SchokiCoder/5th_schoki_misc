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

#include "SM_crypto.h"

uint32_t SM_djb2_encode( const char *str )
{
	// credits to Daniel J. Bernstein for this algorithm
	uint32_t result = 5381;
	char temp;

	while ((temp = *(str++)))
		result += ((result << 5) + result) + temp;

	return result;
}
