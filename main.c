#include <stdio.h>
#include "stdstr.h"

int main(void) {
	str_view mystr = str_view_create("John");
	str_view_info(mystr);

}
