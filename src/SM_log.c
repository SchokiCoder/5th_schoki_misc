/*
 * schoki_misc
 * Copyright (C) 2022  Andy Frank Schoknecht
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not see
 * <https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>.
 */

#include <stdio.h>
#include <time.h>
#include "SM_log.h"

FILE *SM_logfile;

void SM_log_open(void)
{
	SM_logfile = fopen(SM_PATH_LOG, "a");
	setbuf(SM_logfile, NULL);
}

void SM_log_time(void)
{
	time_t t = time(NULL);
	struct tm *dt;
	dt = localtime(&t);

	fprintf(SM_logfile,
		"[%i-%02i-%02i %02i:%02i:%02i] ",
		dt->tm_year + 1900, dt->tm_mon + 1, dt->tm_mday,
		dt->tm_hour, dt->tm_min, dt->tm_sec);
}

void SM_log_err(const char *msg)
{
	SM_log_time();
	fprintf(SM_logfile, "ERROR: %s\n", msg);
}

void SM_log_warn(const char *msg)
{
	SM_log_time();
	fprintf(SM_logfile, "WARNING: %s\n", msg);
}

void SM_log_close(void)
{
	fclose(SM_logfile);
}
