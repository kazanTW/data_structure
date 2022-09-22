#include "stdio.h"

int main(void) {
	int i, *p;
	i = 0;
	p = &i;
	printf("%p\n", &p);
	printf("%d\n", *p);

	return 0;
}
