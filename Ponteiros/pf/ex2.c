#include <stdio.h>
#include <string.h>

// Função que aplica uma transformação em todos os
// caracteres de uma string.
//
// Parâmetros:
// - func: ponteiro para função que recebe um int
//         e retorna um int
// - str : string que será modificada
void aplica(int (*func)(int), char *str) {

  // Percorre a string até encontrar o caractere '\0'
  // que marca o final da string em C.
  for (int i = 0; str[i] != '\0'; i++) {

    // Aplica a função ao caractere atual.
    //
    // (unsigned char) evita problemas com caracteres
    // negativos em algumas arquiteturas.
    //
    // O resultado é convertido novamente para char
    // e armazenado na própria string.
    str[i] = (char) func((unsigned char) str[i]);
  }
}

// Converte letra minúscula para maiúscula.
//
// Exemplo:
// 'a' -> 'A'
int my_toupper(int c) {

  // Verifica se o caractere está entre 'a' e 'z'
  if (c >= 'a' && c <= 'z') {

    // Na tabela ASCII:
    // 'a' = 97
    // 'A' = 65
    //
    // Diferença = 32
    return c - 32;
  }

  // Se não for minúscula, retorna o caractere original
  return c;
}

// Converte letra maiúscula para minúscula.
//
// Exemplo:
// 'A' -> 'a'
int my_tolower(int c) {

  // Verifica se o caractere está entre 'A' e 'Z'
  if (c >= 'A' && c <= 'Z') {

    // Soma 32 para converter para minúscula
    return c + 32;
  }

  // Retorna o caractere original caso não seja maiúsculo
  return c;
}

// Substitui a letra 'a' por '-'
int tira_vogal_a(int c) {

  // Verifica se o caractere é 'a'
  if (c == 'a') {

    // Retorna '-'
    return '-';
  }

  // Caso contrário, mantém o caractere original
  return c;
}

int main(void) {

  // Vetor de caracteres para armazenar a frase.
  //
  // O tamanho máximo é:
  // 127 caracteres + '\0'
  char frase[128];

  // Copia a string para o vetor "frase"
  strcpy(frase, "Uma frase com MAIUSCULAS e minusculas");

  // Mostra a frase original
  printf("Frase original : %s\n", frase);

  // Converte todos os caracteres para maiúsculo
  aplica(my_toupper, frase);

  // Exibe o resultado
  printf("Maiusculas      : %s\n", frase);

  // Converte todos os caracteres para minúsculo
  aplica(my_tolower, frase);

  // Exibe o resultado
  printf("Minusculas      : %s\n", frase);

  // Substitui todas as letras 'a' por '-'
  aplica(tira_vogal_a, frase);

  // Exibe o resultado
  printf("Sem letra 'a'   : %s\n", frase);

  // Indica que o programa terminou corretamente
  return 0;
}
