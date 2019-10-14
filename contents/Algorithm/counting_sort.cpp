// C++ program for modifying Selection Sort 
// so that it becomes stable. 
#include <iostream> 
using namespace std;



void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

#define m_MIN 2
#define m_MAX 30

// Driver code 
int main(){

	int a[] = { 3,2,30, 5,2,7,10, 30 };
	int n = sizeof(a) / 4;

	int i;

	int *c = (int*)calloc(sizeof(int), (m_MAX - m_MIN + 1));
	int *res = (int*)malloc(sizeof(int)*n);

	// 1) Count the number  
	for (i = 0; i < n; i++) {
		c[a[i] - m_MIN]++;
	}

	// 2) Make a cumulative sum
	for (i = 1; i<=m_MAX - m_MIN; i++) {
		c[i] = c[i] + c[i - 1];
	}

	// 3) Make result 
	for (i = n-1; i >= 0; i--) {
		res[c[a[i] - m_MIN] - 1] = a[i];
		c[a[i] - m_MIN]--;
	}






	printArray(res, n);
	return 0;
}
