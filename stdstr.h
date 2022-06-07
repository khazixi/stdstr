#ifndef STDSTR_H
#define STDSTR_H

#include <stddef.h>

typedef struct str_view {
	size_t len;
	const char *data;	// Cannot be a VLA because the view must be allocated
} str_view;

typedef struct str_dynamic {
	size_t len;
	char data[];		// VLA is used here to ensure that the string holds the entire struct
} str_dynamic;

extern str_view		str_view_create(const char *);		// String View Constructor
extern str_view		str_view_from_dynamic(str_dynamic *); 	// Converts a dynamic string to a string view
extern void		str_view_info(str_view); 		// Prints the attributes of string view

extern str_dynamic	*str_dynamic_create(char *); 		// creates a dynamic string using malloc
extern void		str_dynamic_reverse(str_dynamic *);	// reverses a dynamic string
extern str_dynamic	*str_dynamic_from_view(str_view);	// Converts a string view to a dynamic string
extern void		str_dynamic_destroy(str_dynamic *);	// frees a dynamic string and points it to NULL

#endif	// STDSTR_H
