#include <stdio.h>

int soma (int a, int b);
int sub (int a, int b);
int mult (int a, int b);
int div (int a, int b);

int main (){
int a, b, operador, resultado;
printf("digite o primeiro numero\n");
scanf ("%d", &a);
printf("digite o segundo numero\n");
scanf ("%d", &b);
printf ("qual a operacao? \n1-soma\n2-sub\n3-mult\n4-div\n");
scanf ("%d", &operador);
switch (operador){
case 1:
resultado = soma(a,b);
break;
case 2:
resultado = sub(a,b);
break;
case 3:
resultado = mult(a,b);
break;
case 4:
resultado = div(a,b);
break;
default:
printf("operacao nao definida");
break;
}
printf("Resultado: %d\n", resultado);
return 0;
}

int soma (int a, int b){
//printf ("%d , %d", &a , &b );
return a+b;
}

int sub (int a, int b){
return a-b;
}

int mult (int a, int b){
return a*b;
}

int div (int a, int b){
return a/b;
}
