#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[50];
    float nota;
}Aluno;

void printar(Aluno a1){

    printf("Matricula: %d\n", a1.matricula);
    printf("Nome: %s\n", a1.nome);
    printf("Nota: %.2f\n", a1.nota);

}

// Aluno set_aluno(Aluno a1){
//     a1.matricula = 123;
//     strcpy(a1.nome, "Joao");
//     a1.nota = 8.5;
//     return a1;
// }


void set_aluno(Aluno *a1){
    a1->matricula = 123;
    strcpy(a1->nome, "Joao");
    a1->nota = 8.5;

}

int main() {
    Aluno a1;
    Aluno *pa1;

    pa1 = &a1;

    set_aluno(&a1);
    printar(a1);
    return 0;
}
