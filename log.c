#include "log.h"

#include <stdarg.h>
#include <stdio.h>

void stats_log(const char *format, ...) {
	va_list args;
	char buffer[MAX_LOG_SIZE];

	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	fprintf(stderr, "\n");
}