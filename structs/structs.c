#include <stdio.h>
#include <string.h>

//passando uma região de memória onde o objeto sabe qual parte é para cada trecho

typedef struct {
	int dia; //32 bits
	int mes; //32
	int ano; //32
}Data;

typedef struct {
	char nome[31];
	char fone[21];
	Data nascimento;
}Pessoa;


int main (void) {
	Data data;
	data.dia = 28;
	data.mes = 4;
	data.ano = 2026;

	Pessoa p;
	strcpy(p.nome, "Lucas");
	strcpy(p.fone, "085");
	p.nascimento.dia = 19;
	p.nascimento.mes = 11;
	p.nascimento.ano = 2002;
	printf ("Pessoa %s nasceu dia %d\n", p.nome, p.nascimento.dia);
	//printf ("Hoje eh: %d/%d/%d  \n" , data.dia, data.mes, data.ano);
	Pessoa aluno;
	// printf("digite o nome:\n");
	// scanf("%s", aluno.nome);
	// printf("digite o dia do nascimento:\n");
	// scanf("%d", &aluno.nascimento.dia);

	printf ("Pessoa cadastrada\nNome:%s \nDia: %d\n", aluno.nome, aluno.nascimento.dia);
	//printf ("Pessoa %s nasceu dia %d\n", p.nome, p.nascimento.dia);
	
	Pessoa listaAlunos[2];
    int i;

    for (i = 0; i < 2; i++) {
        printf("Preenchendo dados do aluno %d:\n", i + 1);
        
        printf("Nome: \n");
        scanf(" %s", listaAlunos[i].nome);
        
        printf("Telefone:\n ");
        scanf(" %s", listaAlunos[i].fone);
        
        printf("Data de nascimento (dia mes ano): \n");
        scanf("%d %d %d", &listaAlunos[i].nascimento.dia, 
                          &listaAlunos[i].nascimento.mes, 
                          &listaAlunos[i].nascimento.ano);
        
        printf("\n");
    }

    // Exemplo de exibicao dos dados preenchidos
    for (i = 0; i < 2; i++) {
        printf("Aluno %d: %s | Tel: %s | Nasc: %02d/%02d/%d\n", 
               i + 1, 
               listaAlunos[i].nome, 
               listaAlunos[i].fone, 
               listaAlunos[i].nascimento.dia, 
               listaAlunos[i].nascimento.mes, 
               listaAlunos[i].nascimento.ano);
    }

    return 0;

}
