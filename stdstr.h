#ifndef STDSTR_H
#define STDSTR_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct str_view str_view;
typedef struct str_range str_range;
typedef struct str_dynamic str_dynamic;

struct str_view {
	size_t len;
	const char *data;	// Cannot be a VLA because the view must be allocated
};

struct str_dynamic {
	size_t len;
	char data[];		// VLA is used here to ensure that the string holds the entire struct
};

struct str_range {		// This struct is a workaround for C not being able to return arrays
	int start;
	int end;
};

str_view	 str_view_create(const char *);		// String View Constructor
str_view	 str_view_from_dynamic(str_dynamic *); 	// Converts a dynamic string to a string view
bool		 str_view_compare(str_view, str_view);
unsigned int 	 str_view_count(str_view, str_view);
str_range	 str_view_find(str_view, str_view);	// Takes a string and finds it

str_dynamic	*str_dynamic_create(const char *); 		// creates a dynamic string using malloc
void		 str_dynamic_reverse(str_dynamic *);	// reverses a dynamic string
void 		 str_dynamic_upper(str_dynamic *);	// makes a dynamic string all uppercased
void 		 str_dynamic_lower(str_dynamic *);	// makes a dynamic string all lowercased
str_dynamic	*str_dynamic_concatenate(str_dynamic *, str_dynamic *);	// Concatenates a string with or without a space
bool		 str_dynamic_compare(str_dynamic *, str_dynamic *);	// checks 2 strings to ensure they are equal
str_dynamic	*str_dynamic_from_view(str_view);	// Converts a string view to a dynamic string
void		 str_dynamic_destroy(str_dynamic *);	// frees a dynamic string and points it to NULL
unsigned int 	 str_dynamic_count(str_dynamic *, str_dynamic *);
// extern str_dynamic	*str_dynamic_replace(str_dynamic *, str_dynamic *, str_dynamic *);	// TODO: Final function I will add

#ifdef STDSTR_IMPLIMENTATION_H

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

unsigned int str_view_count(str_view target, str_view comparison) {
	unsigned int count = 0;
	for (unsigned int i = 0; i < target.len - comparison.len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target.data[i] == comparison.data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target.data[i], &comparison.data[0], comparison.len) == 0)
				count++;
	return count;
}

str_range str_view_find(str_view target, str_view comparison) {
	for (unsigned int i = 0; i < target.len - comparison.len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target.data[i] == comparison.data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target.data[i], &comparison.data[0], comparison.len) == 0)
				return (str_range){.start = i, .end = i + comparison.len - 1};
	return (str_range){.start = -1, .end = -1};
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

unsigned int str_dynamic_count(str_dynamic *target, str_dynamic *comparison) {
	unsigned int count = 0;
	for (unsigned int i = 0; i < target->len - comparison->len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target->data[i] == comparison->data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target->data[i], &comparison->data[0], comparison->len) == 0)
				count++;
	return count;
}

str_range str_dynamic_find(str_dynamic *target, str_dynamic *comparison) {
	for (unsigned int i = 0; i < target->len - comparison->len + 1; i++) 	// +1 is to ensure that strings of the same length can be compared
		if (target->data[i] == comparison->data[0]) 		// This is here to lower memcmp calls
			if(strncmp(&target->data[i], &comparison->data[0], comparison->len) == 0)
				return (str_range){.start = i, .end = i + comparison->len - 1};
	return (str_range){.start = -1, .end = -1};
}

#endif // STDSTR_IMPLIMENTATION_H

#endif // STDSTR_H
