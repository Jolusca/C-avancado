#include <stdio.h>

void inc(int *n) {
  (*n) += 1;
  //(*n)++;
}

int main(void) {

  void (*fp) (int *n); // function pointer

  fp = inc; // fp points to inc
  
  int a = 0;
  printf("a vale %d\r\n", a);

  inc(&a); // call the normal function inc
  printf("a vale %d\r\n", a);

  fp(&a); // call using the function pointer
  printf("a vale %d\r\n", a);

  return 0;
}

// um ponteiro de função só pode apontar para funções que tenham o mesmo
// protótipo (assinatura) com o qual o ponteiro foi declarado.
