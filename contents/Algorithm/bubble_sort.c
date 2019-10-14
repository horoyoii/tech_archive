#include<stdio.h>





int main(void) {


	int arr[] = { 1,4,2,6,10,22,40,2,-1 };
	int m_size = sizeof(arr) / sizeof(int);
	int i, j, tmp;
	
	// Bubble Sort
	for (i = m_size - 1; i > 0 ; i--) {

		for (j = 0; j < i; j++) {

			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}


	}


	for (int i = 0; i < m_size; i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}
