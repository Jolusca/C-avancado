#include <stdio.h>
#include <string.h>


typedef struct {
	int dia; //32 bits
	int mes; //32
	int ano; //32
}Data;

int main(void) {
    // Declaração de um ponteiro para void para permitir que ele aponte para qualquer tipo, inclusive ele mesmo
    void *ptr;

    // O ponteiro recebe o endereço dele mesmo
    ptr = &ptr;

    // Imprime o endereço do ponteiro e o valor armazenado nele (que serão iguais)
    printf("Endereço do ponteiro (&ptr): %p\n", (void*)&ptr);
    printf("Valor dentro do ponteiro (ptr): %p\n", ptr);



    int i = 10;
    int a =20;
    int *p;
    p = &i;
    *p = *p +1; //* trabalha com o conteúdo que ele aponta
    printf("teste %d\n\n", i);

    printf ("i= %p\n", &i);

    printf ("i= %p\n", &i);

    printf("\n======\n");

    int vetor[] = {10,20,30,40,50};
    //a palavra vetor sozinha já é um ponteiro
    int *p1, *p2;
    int r = 100;

    p1 = &vetor[2];
    printf("%d\n", *p1);
    p1++;
    printf("%d\n", *p1);
    p1 = p1 +1;
    printf("%d\n", *p1);




}