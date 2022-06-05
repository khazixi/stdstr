#ifndef STDSTR_H
#define STDSTR_H

#include <stddef.h>

typedef struct str_view {
	size_t len;
	const char *data;
} str_view;

typedef struct str_dynamic {
	size_t len;
	char data[];
} str_dynamic;

extern str_view		str_view_create(const char*);	/* String View Constructor */
extern str_view		str_view_from_dynamic(str_dynamic); /* Converts a dynamic string to a string view */
extern void		str_view_info(str_view); /* Prints the attributes of string view */

extern str_dynamic	*str_dynamic_create(const char*); /* creates a dynamic string */
extern void		str_dynamic_reverse(str_dynamic*);
extern void		str_dynamic_destroy(str_dynamic*);

#endif	// STDSTR_H
