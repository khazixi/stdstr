#include <ctype.h>
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

bool str_view_compare(str_view a, str_view b) {
	if (a.len != b.len) return false;
	for(size_t i = 0; i < a.len; i++)
		if (a.data[i] != b.data[i]) return false;
	return true;
}

uint str_view_count(str_view target, str_view comparison) {
	uint count = 0;
	for (uint i = 0; i < target.len - comparison.len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target.data[i] == comparison.data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target.data[i], &comparison.data[0], comparison.len) == 0)
				count++;
	return count;
}

void str_view_info(str_view str) {
	printf("String: %s\nLength: %zu\n", str.data, str.len);
}

str_range str_view_find(str_view target, str_view comparison) {
	for (uint i = 0; i < target.len - comparison.len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target.data[i] == comparison.data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target.data[i], &comparison.data[0], comparison.len) == 0)
				return (str_range){.valid_range={i, i+comparison.len - 1}};
	return (str_range){.valid_range={-1, -1}};
}

str_dynamic *str_dynamic_create(const char *str) {
	size_t len = strlen(str);
	str_dynamic *new_string = malloc(sizeof(str_dynamic) + len + 1);
	strcpy(new_string->data, str);
	new_string->len = len;
	return new_string;
}

void str_dynamic_destroy(str_dynamic *str) {
	free(str);
	str = NULL;
}

void str_dynamic_reverse(str_dynamic *str) {
	char temp[str->len + 1];
	strcpy(temp, str->data);
	size_t j = 0;
	size_t i = str->len - 1;
	while (j < str->len) {
		str->data[j] = temp[i];
		j++;
		i--;
	}
}

void str_dynamic_upper(str_dynamic *str) {
	for(size_t i = 0; i < str->len; i++)
		if(islower(str->data[i]))
			str->data[i] = toupper(str->data[i]);
}

void str_dynamic_lower(str_dynamic *str) {
	for(size_t i = 0; i < str->len; i++)
		if(isupper(str->data[i]))
			str->data[i] = tolower(str->data[i]);
}

bool str_dynamic_compare(str_dynamic *a, str_dynamic *b) {
	if (a->len != b->len) return false;
	for(size_t i = 0; i < a->len; i++)
		if (a->data[i] != b->data[i])
			return false;
	return true;
}

str_dynamic *str_dynamic_from_view(str_view str) {
	str_dynamic *new_str = malloc(sizeof(str_dynamic) + str.len);
	new_str->len = str.len;
	strcpy(new_str->data, str.data);
	return new_str;
}

str_dynamic *str_dynamic_concatenate(str_dynamic *first, str_dynamic *second) {
	str_dynamic *dummy = malloc(sizeof *first + first->len + second->len + 1);
	memcpy(dummy, first, (sizeof *first + first->len + 1));
	strcat(dummy->data, second->data);
	return dummy;
}

uint str_dynamic_count(str_dynamic *target, str_dynamic *comparison) {
	uint count = 0;
	for (uint i = 0; i < target->len - comparison->len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target->data[i] == comparison->data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target->data[i], &comparison->data[0], comparison->len) == 0)
				count++;
	return count;
}

str_range str_dynamic_find(str_dynamic *target, str_dynamic *comparison) {
	for (uint i = 0; i < target->len - comparison->len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target->data[i] == comparison->data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target->data[i], &comparison->data[0], comparison->len) == 0)
				return (str_range){.valid_range={i, i+comparison->len - 1}};
	return (str_range){.valid_range={-1, -1}};
}
