#include <stdio.h>

int f (int n);
int square (int n);
float power (int n, float x); // x^0 = 1
int sumOfOdd (int n);
int units (int n);
int allButUnits (int n);
int magnitude (int n);
int reverse (int n);

int main () {
	printf ("num = ");
	int num;
	scanf ("%d", &num);
	if (num < 0)
		printf ("Error! Number cannot be less than 0 for factorial and square\n");
	else {
		printf("factorial (%d) = %d\n", num, f(num));
		printf("square (%d) = %d\n", num, square(num));
	}

	float num2;
	int pow;
	printf ("num2 = ");
	scanf ("%f", &num2);
	printf ("power = ");
	scanf ("%d", &pow);

	if (num < 0)
		printf ("Error! Number cannot be less than 0 for power\n");
	else 
		printf("power (%d, %f) = %f\n", pow, num2, power(pow, num2));
	
	if (num < 0)
		printf ("Error! Number cannot be less than 0 for sum of odd\n");
	else 
		printf("sumOfOdd(%d) = %d\n", num, sumOfOdd(num));

	printf("units(%d) = %d\n", num, units(num));

	printf("allButUnits(%d) = %d\n", num, allButUnits(num));

	if (num < 0)
		printf ("Error! Number cannot be less than 0 for magnitude\n");
	else 
		printf("magnitude(%d) = %d\n", num, magnitude(num));

	if (num < 0)
		printf ("Error! Number cannot be less than 0 for magnitude\n");
	else 
		printf("reverse(%d) = %d\n", num, reverse(num));


	return 0;
}

int f (int n) {
	int static counter = 1;
	if (counter == 1) printf("Hello World!\n");
	counter++;
	if (n == 0) return 1;
	return (n * f (n - 1));
}

int square (int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return (2 * square(n-1) - square(n-2) + 2);
}

float power (int n, float x){
	if (n == 0) return 1;
	return (x * (power(n-1, x)));
}

int sumOfOdd (int n) {
	if (n == 1) return 1;
	return 2*n - 1 + sumOfOdd(n-1);
}

int units (int n) {
	return n % 10;
}

int allButUnits (int n) {
	return n / 10;
}

int magnitude (int n) {
	if (n < 10) return 1;
	return 10 * magnitude (n / 10);
}

int reverse (int n) {
	if (n < 10) return n;
	return n % 10 * magnitude(n) + reverse (n / 10) ;
}
