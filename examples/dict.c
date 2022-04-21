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
	size_t index;

	if (SM_Dict_find(dict, key, &index))
		printf("Found %s at %lu.\n", key, index);

	else
		printf("Could not find %s.\n", key);
}

int main()
{
	// dict
	SM_Dict dict = SM_Dict_new(4);

	// dict add
	SM_Dict_add(&dict, "key1", "val1");

	// dict find
	find_print(&dict, "key1");
	find_print(&dict, "not-there");

	// dict save

	// dict load

	// dict get (from loaded)

	// dict clear
	SM_Dict_clear(&dict);

	return 0;
}
