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
#include "SM_string.h"

size_t SM_strlen( const char *cstr )
{
	size_t result = 0;

	while (cstr[result] != '\0')
		result++;

	return result;
}

void SM_strcpy( char *restrict dest, const char *restrict src, size_t len )
{
	for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }

    dest[len] = '\0';
}

SM_bool SM_strequal( const char *restrict a, const char *restrict b )
{
	const size_t a_len = SM_strlen(a);
	const size_t b_len = SM_strlen(b);

	if (a_len != b_len)
		return SM_FALSE;

	for (size_t i = 0; i < a_len; i++)
    	if (a[i] != b[i])
    		return SM_FALSE;

	return SM_TRUE;
}

void SM_String_grow( SM_String *str )
{
	str->size *= 2;
	str->str = realloc(str->str, str->size);
}

void SM_String_ensure_size( SM_String *str, size_t size )
{
	while (str->size < size)
    	SM_String_grow(str);
}

SM_String SM_String_new( const size_t inital_size )
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
	const size_t strlen = SM_strlen(cstr);

	SM_String temp = {
		.str = (char*) cstr,
		.len = strlen,
		.size = strlen
	};

	SM_String_copy(&result, &temp);

	return result;
}

SM_String SM_String_contain( const char *cstr )
{
    const size_t strlen = SM_strlen(cstr);
    const SM_String result = {
    	.len = strlen,
    	.size = strlen,
    	.str = (char*) cstr
    };

    return result;
}

void SM_String_copy( SM_String *restrict dest, SM_String *restrict src )
{
	SM_String_ensure_size(dest, src->len + 1);

	SM_strcpy(dest->str, src->str, src->len);

    dest->len = src->len;
}

void SM_String_append( SM_String *restrict dest, SM_String *restrict addendum )
{
	SM_String_ensure_size(dest, dest->len + addendum->len + 1);

	SM_strcpy(&dest->str[dest->len], addendum->str, addendum->len);

	dest->len += addendum->len;
}

void SM_String_copy_cstr( SM_String *restrict dest, const char *restrict src )
{
	const size_t strlen = SM_strlen(src);
	SM_String_ensure_size(dest, strlen);

	SM_strcpy(dest->str, src, strlen);

	dest->len = strlen;
}

void SM_String_append_cstr( SM_String *restrict dest, const char *restrict addendum )
{
	const size_t strlen = SM_strlen(addendum);
	SM_String_ensure_size(dest, dest->len + strlen);

	SM_strcpy(&dest->str[dest->len], addendum, strlen);

	dest->len += strlen;
}

SM_bool SM_String_equal( const SM_String *restrict a, const SM_String *restrict b )
{
	if (a->len != b->len)
		return SM_FALSE;

	for (size_t i = 0; i < a->len; i++)
		if (a->str[i] != b->str[i])
			return SM_FALSE;

	return SM_TRUE;
}

void SM_String_empty( SM_String *str )
{
	str->str[0] = '\0';
    str->len = 0;
}

void SM_String_clear( SM_String *str )
{
	free(str->str);
	str->len = 0;
	str->size = 0;
}
