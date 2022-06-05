#include <stdio.h>
#include <string.h>
#include "stdstr.h"

str_view str_view_create(const char* data) {
	return (str_view){.data=data, .len=strlen(data)};
}

void str_view_info(str_view str) {
	printf("String: %s\nLength: %zu\n", str.data, str.len);
}
