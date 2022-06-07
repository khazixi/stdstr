#include <stdio.h>
#include "stdstr.h"
#include "strops.h"

int main(void) {
	str_view mystr = str_view_create("John");
	str_view_info(mystr);

	char *str = "I like to eat eat eat apples and bananas";
	char *newstr = str_replace(str, "like", "red");
	printf("%s\n", newstr);
}
