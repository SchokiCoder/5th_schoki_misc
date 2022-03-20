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

#include <stdlib.h>
#include <stdint.h>
#include "string.h"

static const uint32_t SM_STRING_IMPLICIT_INITIAL_SIZE = 4;

void SM_String_grow( SM_String *str )
{
	str->size *= 2;
	str->str = realloc(str->str, str->size);
}

SM_String SM_String_new( size_t inital_size )
{
	SM_String result = {
		.len = 0,
		.str = malloc(inital_size),
		.size = inital_size
	};

	return result;
}

SM_String SM_String_from( const char *cstr )
{
	SM_String result = SM_String_new(SM_STRING_IMPLICIT_INITIAL_SIZE);
	uint_fast32_t strlen = 0;

	// get strlen
	for (uint_fast32_t i = 0; cstr[i] != '\0'; i++)
	{
		strlen++;
	}

	SM_String temp = {
		.str = (char*) cstr,
		.len = strlen,
		.size = strlen
	};

	// copy string
	SM_String_copy(&result, &temp);

	return result;
}

void SM_String_copy( SM_String *restrict dest, SM_String *restrict src )
{
	// as long as dest has not enough size, grow
    while (src->len > dest->size)
    	SM_String_grow(dest);

    // copy
    for (uint_fast32_t i = 0; i < src->len; i++)
    {
        dest->str[i] = src->str[i];
    }

    // update len
    dest->len = src->len;
}

void SM_String_append( SM_String *restrict dest, SM_String *restrict addendum )
{
	// as long as dest has not enough size, grow
	while (dest->size < (dest->len + addendum->len))
		SM_String_grow(dest);

	// copy to end of src
	for (uint_fast32_t i = 0; i < addendum->len; i++)
	{
		dest->str[dest->len + i] = addendum->str[i];
	}

	// update len
	dest->len += addendum->len;
}

void SM_String_clear( SM_String *str )
{
	free(str->str);
	str->len = 0;
	str->size = 0;
}
