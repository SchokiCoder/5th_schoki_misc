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
#include <time.h>
#include "log.h"

FILE *SM_logfile;

void SM_log_time( void )
{
    time_t t = time(NULL);
    struct tm *dt;
    dt = localtime(&t);

	fprintf(
		SM_logfile,
		"[%i-%02i-%02i %02i:%02i:%02i] ",
		dt->tm_year + 1900, dt->tm_mon + 1, dt->tm_mday,
		dt->tm_hour, dt->tm_min, dt->tm_sec);
}

void SM_log_err( const char *msg )
{
	SM_log_time();
	fprintf(SM_logfile, "ERROR: %s\n", msg);
}

void SM_log_warn( const char *msg )
{
	SM_log_time();
	fprintf(SM_logfile, "WARNING: %s\n", msg);
}
