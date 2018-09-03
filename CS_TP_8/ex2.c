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
	fscanf(fPtr, "%d", n);
	arr = (int*)malloc(*n * sizeof(int)); 
}

FILE *OpenFile(char *f, FILE *fPtr) {
	return fopen(f, "r");
}

int main() {
	FILE *fPtr;
	char *f = "int.txt";
	fPtr = OpenFile(f, fPtr);

	int *arr;
	int n;
	RegisterTable(&n, arr, fPtr); 

	ReadingTable(arr, n, fPtr);
	
	ReturnTable(arr, n);

	Average(arr, n);

	printf("\n");
	return 0;
}
