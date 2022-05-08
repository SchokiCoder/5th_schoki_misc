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

#include <stdio.h>
#include "SM_dict.h"

void find_print( SM_Dict *dict, const char *key )
{
	ul32_t index;

	if (SM_Dict_find(dict, key, &index))
		printf("Found key \"%s\" at %lu.\n", key, index);

	else
		printf("Could not find key \"%s\".\n", key);
}

void get_print( SM_Dict *dict, const char *key )
{
	ul32_t index;

	if (SM_Dict_find(dict, key, &index))
    	printf("Dict <\"%s\" : \"%s\">\n", key, dict->data[index].value.str);

	else
		printf("ERROR: Could not find key \"%s\".\n", key);
}

int main()
{
	// dict
	SM_Dict dict = SM_Dict_new(1);
	SM_Dict loaded_dict;

	// dict add
	SM_Dict_add(&dict, "key1", "val1");
	SM_Dict_add(&dict, "key2", "i-must-sneeze-hard");
	SM_Dict_add(&dict, "key3", "seriously-help-me");

	// dict find
	find_print(&dict, "key1");
	find_print(&dict, "not-there");

	// dict save
	printf("File saved: %i\n", SM_Dict_write(&dict, "my_dict"));

	// dict load
	loaded_dict = SM_Dict_from_file("my_dict");

	if (loaded_dict.invalid)
		printf("ERROR: Dict could not be read from file.\n");

	// dict get (from loaded)
	get_print(&loaded_dict, "key2");

	// dict clear
	SM_Dict_clear(&dict);
	SM_Dict_clear(&loaded_dict);

	return 0;
}
