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

#ifndef SM_LOG_H
#define SM_LOG_H

#include <stdio.h>

#define SM_PATH_LOG "log.txt"

extern FILE *SM_logfile;

void SM_log_open(void);

void SM_log_err(const char *msg);

void SM_log_warn(const char *msg);

void SM_log_close(void);

#endif				// SM_LOG_H
