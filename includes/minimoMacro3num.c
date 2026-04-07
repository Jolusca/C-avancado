#include <stdio.h>
// Function-like Macro definition
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
// Driver Code
int main(void){
// Given two number a and b
int a = 18;
int b = 76;
int c = 10;
printf("Minimum value between %d and %d is %d\n", a, b, MIN(MIN(a,c), b));
return 0;
}
