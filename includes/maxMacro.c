#include <stdio.h>

#define MAX2(x,y) (x>y? x:y)
#define MAX3(x,y,z) (MAX2(x,y)>z? MAX2(x,y):z)
#define MAX4(x,y,z,w) (MAX2(x,y)>MAX2(z,w)? MAX2(x,y):MAX2(z,w))
// colocando o MAX2 como um dos fatores das outras macros, podemos utilizar de forma recursiva

int main(void){

printf("max3: %d\n", MAX3(3,4,5));
printf("max4 teste 6: %d\n", MAX4(3,4,5,6));
printf("max4 teste 10: %d\n", MAX4(7,8,9,10));

return 0;
}

