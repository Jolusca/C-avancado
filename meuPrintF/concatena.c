#include <stdarg.h>   // va_list, va_start, va_arg, va_end
#include <stdio.h>    // puts()
#include <stdlib.h>   // malloc(), free()
#include <string.h>   // strlen(), strcpy(), strcat()

// Função que concatena várias strings
char *concat(const char *s, ...) {

  va_list args;   // Variável que percorre os argumentos
  char *tmp;      // String temporária
  char *res;      // Resultado final

  // Começa com o tamanho da primeira string
  size_t len = strlen(s);

  // Inicializa a lista de argumentos
  va_start(args, s);

  // Imprime a primeira string
  const char *ptr = s;

  while (*ptr) {
    putchar(*ptr);
    ptr++;
  }
  putchar('\n');


  // Soma o tamanho das demais strings
  // até encontrar NULL
  while ((tmp = va_arg(args, char *))) {
    len += strlen(tmp);
  }

  // Finaliza o uso da lista
  va_end(args);

  // Reserva memória para a string final
  // +1 para o caractere '\0'
  res = malloc(len + 1);

  if (!res)
    return NULL;

  // Copia a primeira string
  strcpy(res, s);

  // Reinicia a leitura dos argumentos
  va_start(args, s);

  // Concatena cada string recebida
  while ((tmp = va_arg(args, char *))) {
    strcat(res, tmp);
  }

  // Finaliza novamente a lista
  va_end(args);

  return res;
}

int main() {

  char *s = concat(
      "Hello",
      " ",
      "New ",
      "world",
      "!!!!",
      "from DETI",
      NULL);   // Marca o fim da lista

  puts(s);

  free(s);

  return 0;
}
