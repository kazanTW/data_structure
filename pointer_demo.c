#include "stdio.h"

int main(void) {
	int i, *p;
	i = 0;
	p = &i;
	printf("%d\n", p);
	printf("%d\n", *p);

	return 0;
}
