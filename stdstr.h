#ifndef STDSTR_H
#define STDSTR_H

#include <stddef.h>
#include <stdbool.h>
#include <inttypes.h>

typedef unsigned int uint;
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
	int8_t valid_range[2];
};

extern str_view		str_view_create(const char *);		// String View Constructor
extern str_view		str_view_from_dynamic(str_dynamic *); 	// Converts a dynamic string to a string view
extern void		str_view_info(str_view); 		// Prints the attributes of string view
extern bool		str_view_compare(str_view, str_view);
extern uint 		str_view_count(str_view, str_view);
extern str_range	str_view_find(str_view, str_view);	// Takes a string and finds it

extern str_dynamic	*str_dynamic_create(const char *); 		// creates a dynamic string using malloc
extern void		str_dynamic_reverse(str_dynamic *);	// reverses a dynamic string
extern void 		str_dynamic_upper(str_dynamic *);	// makes a dynamic string all uppercased
extern void 		str_dynamic_lower(str_dynamic *);	// makes a dynamic string all lowercased
extern str_dynamic	*str_dynamic_concatenate(str_dynamic *, str_dynamic *);	// Concatenates a string with or without a space
extern bool		str_dynamic_compare(str_dynamic *, str_dynamic *);	// checks 2 strings to ensure they are equal
extern str_dynamic	*str_dynamic_from_view(str_view);	// Converts a string view to a dynamic string
extern void		str_dynamic_destroy(str_dynamic *);	// frees a dynamic string and points it to NULL
extern uint 		str_dynamic_count(str_dynamic *, str_dynamic *);
extern str_dynamic	*str_dynamic_replace(str_dynamic *, str_dynamic *, str_dynamic *);	// TODO: Final function I will add

#endif	// STDSTR_H
