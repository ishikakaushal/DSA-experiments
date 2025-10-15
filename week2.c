//sum of n natural numbers using recursion

#include <stdio.h>
// Function to calculate sum using recursion
int sum(int n) {
 if (n == 0)
 return 0;
 else
 return n + sum(n - 1);
}
int main() {
 int n;
 printf("Enter a number: ");
 scanf("%d", &n);
 printf("Sum of first %d numbers = %d\n", n, sum(n));
 return 0;
}

// Fibonnaci series using recursion
#include <stdio.h>
// Function to generate nth Fibonacci number
int fib(int n) {
if (n == 0)
return 0;
else if (n == 1)
return 1;
else
return fib(n - 1) + fib(n - 2);
}
int main() {
int n, i;
printf("Enter number of terms: ");
scanf("%d", &n);
printf("Fibonacci sequence: ");
for (i = 0; i < n; i++) {
printf("%d ", fib(i));
}
printf("\n");
return 0;
}



//Tower of hanoi using recursion
#include <stdio.h>
// Function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
if (n == 1) {
printf("Move disk 1 from %c to %c\n", source, destination);
return;
}
towerOfHanoi(n - 1, source, destination, auxiliary);
printf("Move disk %d from %c to %c\n", n, source, destination);
towerOfHanoi(n - 1, auxiliary, source, destination);
}
int main() {
int n;
printf("Enter number of disks: ");
scanf("%d", &n);
printf("Tower of Hanoi sequence of moves:\n");
towerOfHanoi(n, 'A', 'B', 'C');
return 0;
}

