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
#include "SM_string.h"
#include "SM_log.h"

typedef SM_String String;

int main()
{
	// log
	SM_log_open();
	SM_log_warn("Oh no, i don't have a string yet.");

	// string from, contain, append
	String str_from = SM_String_from("my new teeny tiny itsy bitsy string");
	String str_contain = SM_String_contain(", i like it");

    if (str_from.len < 40)
    	SM_log_warn("My string is so small, is funny to me.");

    SM_String_append(&str_from, &str_contain);

    if (str_from.len > 40)
		SM_log_warn(str_from.str);

	SM_String_clear(&str_from);

	// string copy
	String str_copy = SM_String_new(8);
	String str_tocopy = SM_String_contain("i got copied");
	SM_String_copy(&str_copy, &str_tocopy);

	SM_log_warn(str_copy.str);

    SM_String_clear(&str_copy);

    // copy cstring
    const char *cstr = "my cstring";
    String copy_cstr = SM_String_new(8);

    SM_String_copy_cstr(&copy_cstr, cstr);

    SM_log_warn(copy_cstr.str);

    SM_String_clear(&copy_cstr);

    // append cstring
    String append_cstr = SM_String_from("SM_string now with ");

    SM_String_append_cstr(&append_cstr, cstr);

    SM_log_warn(append_cstr.str);

    SM_String_clear(&append_cstr);

    // string empty
    String empty_str = SM_String_from("lots jibberish, like what am i even doing here, so crazy");

    SM_String_empty(&empty_str);

    SM_String_copy_cstr(&empty_str, "copy");
    SM_String_append_cstr(&empty_str, " and append on empty str");

    SM_log_warn(empty_str.str);

    SM_String_clear(&empty_str);

    // string equal
    SM_String str_a, str_b, str_c;

    str_a = SM_String_contain("my str");
    str_b = SM_String_contain("my str");
    str_c = SM_String_contain("ur str");

    printf("should be 1: %i\n", SM_String_equal(&str_a, &str_b));
    printf("should be 0: %i\n", SM_String_equal(&str_a, &str_c));

    // djb2 hash
    const char *djb2_str = "Thanks Mr. Bernstein";
    char djb2_result[20];

    usize djb2_hash = SM_djb2_encode(djb2_str);
    sprintf(djb2_result, "%u", djb2_hash);

    SM_log_warn(djb2_result);

    // end
    SM_log_close();

	return 0;
}
