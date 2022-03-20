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

#include "string.h"
#include "log.h"

typedef SM_String String;

int main()
{
	SM_logfile = fopen(SM_PATH_LOG, "a");

	SM_log_warn("Oh no, i don't have a string yet.");

	String str = SM_String_from("my new teeny tiny itsy bitsy string");
	String addendum = SM_String_from(", i like it");

    if (str.len < 40)
    	SM_log_err("My string is so small, is funny to me.");

    SM_String_append(&str, &addendum);

    if (str.len > 40)
    	SM_log_warn(str.str);

    fclose(SM_logfile);

	return 0;
}
