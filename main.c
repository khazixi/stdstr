#include <stdio.h>
#include "stdstr.h"

int main(void) {
	str_dynamic *mystr = str_dynamic_create("like");
	str_dynamic *mystr_2 = str_dynamic_create("like like like like like like ");
	puts(mystr->data);
	puts(mystr_2->data);
	printf("%d\n", str_dynamic_count(mystr_2, mystr));
	str_dynamic_destroy(mystr);
	str_dynamic_destroy(mystr_2);
}
