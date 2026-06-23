#include <stdio.h>

void EscolhendoProduto(void);
void InserindoCredito(void);
void EntregandoProduto(void);
void CancelarCompra(void);
void DevolvendoTroco(void);

// Ponteiro global que armazena qual o estado atual da maquina
void (*PonteiroDeFuncao)(void);

// Tabela de precos dos produtos
// Cola     c   R$ 3,00
// Guaraná  g   R$ 4,00
// Laranja  l   R$ 5,00

int valorInserido = 0;
int valorProduto = 0;

// Funcoes auxiliares para leitura de dados via teclado
char LerTeclaProduto(void)
{
    char tecla;
    printf("Escolha um produto (c - Cola, g - Guaraná, l - Laranja) ou x para cancelar: ");
    scanf(" %c", &tecla); 
    return tecla;
}

char LerTeclaDinheiro(void)
{
    char tecla;
    printf("Escolha um valor (1 - R$ 1,00, 2 - R$ 2,00) ou x para cancelar: ");
    scanf(" %c", &tecla); 
    return tecla;
}

// Estado Inicial: Identifica o produto selecionado e define o preco
void EscolhendoProduto(void)
{
    char TeclaLida = LerTeclaProduto();

    switch (TeclaLida)
    {
        case 'c':
            printf("Produto escolhido: Cola. Preço: R$ 3,00\n");
            valorProduto = 3;
            PonteiroDeFuncao = InserindoCredito;
            break;
        case 'g':
            printf("Produto escolhido: Guaraná. Preço: R$ 4,00\n");
            valorProduto = 4;
            PonteiroDeFuncao = InserindoCredito;
            break;
        case 'l':
            printf("Produto escolhido: Laranja. Preço: R$ 5,00\n");
            valorProduto = 5;
            PonteiroDeFuncao = InserindoCredito;
            break;
        case 'x':
            PonteiroDeFuncao = CancelarCompra;
            break;
        default:
            printf("Produto inválido. Escolha novamente.\n");
            break;
    }
}

// Estado de Inserindo Crédito: Soma os creditos ate atingir ou passar o valor do produto
void InserindoCredito(void)
{
    char TeclaLida = LerTeclaDinheiro();
    switch (TeclaLida)
    {
        case '1':
            printf("Crédito inserido: R$ 1,00\n");
            valorInserido += 1;
            printf("Total de crédito inserido: R$ %d,00\n", valorInserido);
            if (valorInserido >= valorProduto)
            {
                PonteiroDeFuncao = EntregandoProduto;
                break;
            }
            break;
        case '2':
            printf("Crédito inserido: R$ 2,00\n");
            valorInserido += 2;
            printf("Total de crédito inserido: R$ %d,00\n", valorInserido);
            if (valorInserido >= valorProduto)
            {
                PonteiroDeFuncao = EntregandoProduto;
                break;
            }
            break;
        case 'x':
            printf("Cancelando a compra. Devolvendo o troco.\n");
            PonteiroDeFuncao = DevolvendoTroco;
            break;
        default:
            printf("Valor de crédito inválido, tente novamente\n");
            break;
    }
}

// Estado de Cancelamento: Devolve todo o dinheiro inserido e reinicia
void CancelarCompra(void)
{
    printf("Compra cancelada. Devolvendo o troco.\n");
    printf("Devolvendo: R$ %d,00\n", valorInserido);
    valorInserido = 0;
    PonteiroDeFuncao = EscolhendoProduto;
}

// Estado de Entrega: Libera o produto e chama a função de devolução de troco
void EntregandoProduto(void)
{
    printf("Entregando o produto. Obrigado pela compra!\n");
    PonteiroDeFuncao = DevolvendoTroco;
}

// Estado de Troco: Calcula a diferenca, devolve ao usuario se houver e limpa o saldo
void DevolvendoTroco(void)
{
    int troco = valorInserido - valorProduto;
    if (troco > 0)
    {
        printf("Devolvendo troco: R$ %d,00\n", troco);
    }
    else
    {
        printf("Sem troco a devolver.\n");
    }
    valorInserido = 0;
    PonteiroDeFuncao = EscolhendoProduto;
}

int main(void)
{
    // Define por qual estado a maquina deve comecar
    PonteiroDeFuncao = EscolhendoProduto;

    // Loop infinito que executa o estado que estiver ativo no momento
    while (1)
    {
        PonteiroDeFuncao();
        printf("\n");
    }