#include <stdio.h>
#include <string.h>
#include "stdstr.h"

int main(void) {
	str_dynamic *mystr = str_dynamic_create("like");
	str_dynamic *mystr_2 = str_dynamic_create("john");
	str_dynamic *mystr_3 = str_dynamic_create("like");

	str_view a_1 = str_view_create("Jill");
	str_view a_2 = str_view_create("i");

	str_range b = str_view_find(a_1, a_2);
	// puts(mystr->data);
	// puts(mystr_2->data);
	// printf("%d\n", str_dynamic_count(mystr_2, mystr));
	// printf("%d\n", str_dynamic_count(mystr_3, mystr));
	str_dynamic_destroy(mystr);
	str_dynamic_destroy(mystr_2);
	str_dynamic_destroy(mystr_3);
}
