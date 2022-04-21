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
#include "SM_crypto.h"
#include "SM_dict.h"

SM_DictPair SM_DictPair_new( const char *restrict key, const char *restrict value )
{
	SM_DictPair result = {
		.key_djb2 = SM_djb2_encode(key),
		.key = SM_String_from(key),
		.value = SM_String_from(value),
	};

	return result;
}

void SM_DictPair_clear( SM_DictPair *dictpair )
{
	SM_String_clear(&dictpair->key);
	SM_String_clear(&dictpair->value);
}

void SM_Dict_grow( SM_Dict *dict )
{
	dict->size *= 2;
	dict->data = realloc(dict->data, sizeof(SM_DictPair) * dict->size);
}

void SM_Dict_ensure_size( SM_Dict *dict, size_t size )
{
	while (dict->size < size)
    	SM_Dict_grow(dict);
}

SM_Dict SM_Dict_new( const size_t inital_size )
{
	SM_Dict result = {
		.len = 0,
		.size = inital_size,
		.data = malloc(sizeof(SM_DictPair) * inital_size),
	};

	return result;
}

SM_Dict SM_Dict_from_file( const char *filepath )
{
	return;
}

void SM_Dict_add( SM_Dict *dict, const char *restrict key, const char *restrict value )
{
	SM_Dict_ensure_size(dict, dict->len + 1);

	dict->data[dict->len] = SM_DictPair_new(key, value);

	dict->len++;
}

SM_bool SM_Dict_find( const SM_Dict *dict, const char *key, size_t *index )
{
	const uint32_t key_djb2 = SM_djb2_encode(key);

	for (size_t i = 0; i < dict->len; i++)
	{
		if (dict->data[i].key_djb2 == key_djb2)
		{
			*index = i;
			return SM_TRUE;
		}
	}

	return SM_FALSE;
}

void SM_Dict_write( SM_Dict *dict )
{
	return my_implementation;
}

void SM_Dict_clear( SM_Dict *dict )
{
	for (size_t i = 0; i < dict->len; i++)
		SM_DictPair_clear(&dict->data[i]);

	free(dict->data);

	dict->size = 0;
	dict->len = 0;
}
