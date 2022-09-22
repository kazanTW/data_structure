#include <stdio.h>
#include <stdlib.h>

int binSearch(int arr[], int target, int left, int right);
int compare(int x, int y);

int main(void) {
	int arr_size, target;
	scanf("%d", &arr_size);
	int* list = malloc(sizeof *list * arr_size);
	
	for(int i = 0; i < arr_size; i++) {
		scanf("%d", (list + i));
	}
	scanf("%d", &target);

	int tar_index = binSearch(list, target, 0, arr_size - 1);
	printf("%d\n", tar_index);

	return 0;
}

int compare(int x, int y) {
	if (x < y) {
		return -1;
	} else if (x == y) {
		return 0;
	} else {
		return 1;
	}
}

int binSearch(int arr[], int target, int left, int right) {
	int middle = (left + right) / 2;

	printf("%d %d %d\n", left, middle, right);
	printf("%d %d %d\n", arr[left], arr[middle], arr[right]);

	if (left <= right) {
		switch (compare(arr[middle], target)) {
			case -1:
				return binSearch(arr, target, middle + 1, right);
			case 0:
				return middle;
			case 1:
				return binSearch(arr, target, left, middle - 1);
		}
	}

	return -1;
}
