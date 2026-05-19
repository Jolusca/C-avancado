#include <stdio.h>
#include <string.h>

typedef union data {
    char c1;
    char c2;
} Data;

// Correção na sintaxe do atributo packed e da definição do tipo
typedef struct __attribute__((__packed__)) {
    unsigned char a:4;
    unsigned int b:8;
    unsigned char c:4;
} Example6;

int main (void){
    Data test;
    Example6 example;
    printf("Sizeof de test= %lu\n", sizeof(example));

    test.c1 = 9;

    printf ("valor de test.c1 = %d\n", test.c1);

    printf ("valor de test.c2 = %d\n", test.c2);
}