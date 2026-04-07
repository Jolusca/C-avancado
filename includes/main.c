#include <stdio.h>
#define SOMA(a,b) a + b

int main(void){
int i = 10 , j=20 , k;
float f = 3.5 , g = 2.3 , h;
k= SOMA(i,j);
h = SOMA(f,g);

printf("k=%d,\n f=%f", k, f);
}
