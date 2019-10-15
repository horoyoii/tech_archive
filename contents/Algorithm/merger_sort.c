#include<stdio.h>
#include<stdlib.h>


int *sorted;

void merge(int arr[], int left, int mid, int right) {

	int i = left;
	int j = mid+1;
	int k = left;

	while (i <= mid && j <= right) {

		if (arr[i] <= arr[j]) // 단지 비교연산자 < 만 있다면 not stable 
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];

	}

	int tmp = i > mid ? j : i;

	while (k <= right) 
		sorted[k++] = arr[tmp++];
	

	for (i = left; i <= right; i++)
		arr[i] = sorted[i];




}

void partition(int arr[], int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		partition(arr, left, mid);
		partition(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}

}

int  main(void) {

	int arr[] = { 1,4,2, 5, 2 };
		
	sorted = (int*)malloc(sizeof(arr) / sizeof(int));

	partition(arr, 0, sizeof(arr) / sizeof(int)-1 );
	

	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}



	return 0;
}
