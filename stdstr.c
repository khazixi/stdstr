#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stdstr.h"

str_view str_view_create(const char* data) {
	return (str_view){strlen(data), data};
}
	
str_view str_view_from_dynamic(str_dynamic *str) {
	return (str_view){str->len, str->data};
}

void str_view_info(str_view str) {
	printf("String: %s\nLength: %zu\n", str.data, str.len);
}

str_dynamic *str_dynamic_create(char *str) {
	size_t len = strlen(str);
	str_dynamic *new_string = malloc(sizeof(str_dynamic) + len);
	strcpy(str, new_string->data);
	new_string->len = len;
	return new_string;
}

void str_dynamic_destroy(str_dynamic *str) {
	free(str);
	str = NULL;
}

void str_dynamic_reverse(str_dynamic *str) {
	char *p = &str->data[0];
	char *q = &str->data[str->len - 1];
	char *temp;

	for (size_t i = 0; i < str->len/2; i++) {	// Change the counter values so that the for loop works with addresses
		temp = p;
		p = q;
		q = temp;
		p++;
		q--;
	}
}


str_dynamic *str_dynamic_from_view(str_view str) {
	str_dynamic *new_str = malloc(sizeof(str_dynamic) + str.len);
	new_str->len = str.len;
	strcpy((char *)str.data, new_str->data);
	return new_str;
}
