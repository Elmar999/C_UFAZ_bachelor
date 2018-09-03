#include <stdio.h>
#include <stdlib.h>

void Average(int *arr, int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		result += arr[i];
	}

	printf("Summation of integers = %d\n", result);
	
	result /= n;

	printf("Average of integers = %d\n", result);

	result = 1;
	for (int i = 0; i < n; i++) {
		result *= arr[i];
	}

	printf("Product of integers = %d", result);
}

void ReturnTable(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

void ReadingTable(int *arr, int n, FILE *fPtr) {
	for (int i = 0; i < n; i++)
		fscanf(fPtr, "%d", &arr[i]);
}

void RegisterTable(int *n, int *arr, FILE *fPtr) {
	while (!feof(fPtr)) {
		int i;
		fscanf(fPtr, "%d", &i);
		*n++;
	}
	arr = (int*)malloc(*n * sizeof(int)); 
}

FILE *OpenFile(char *f) {
	if (fopen(f, "r")==NULL) {
		printf("EROOR\n");
		exit(1);
	}
	return fopen(f, "r");
}

int main() {
	FILE *fPtr;
	FILE *fPtr2;
	char *f = "int.txt";
	char *f2 = "coefficients.txt";
	fPtr = OpenFile(f);
	fPtr2 = OpenFile(f2);

	int *arr;
	int *arr2;
	int n = 0;
	int n2 = 0;
	RegisterTable(&n, arr, fPtr); 
	RegisterTable(&n2, arr2, fPtr2); 
	printf("%d %d", n, n2);

	if (n != n2) {
		printf("ERROR");
		exit(1);
	}


	ReadingTable(arr, n, fPtr);
	ReadingTable(arr2, n2, fPtr);
	
	ReturnTable(arr, n);
	ReturnTable(arr2, n2);

	Average(arr, n);

	printf("\n");
	return 0;
}
