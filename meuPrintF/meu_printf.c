#include <stdarg.h> // va_list, va_start, va_arg, va_end
#include <stdio.h>  // putchar()

// Versão simplificada do printf
// Suporta apenas %d para números de 0 a 9
void meu_printf(const char *fmt, ...)
{
    // Estrutura utilizada para percorrer
    // os argumentos variáveis da função
    va_list args;

    // Inicializa a lista de argumentos
    // fmt é o último parâmetro fixo da função
    va_start(args, fmt);

    // Percorre a string de formato
    // até encontrar o caractere '\0'
    while (*fmt) {

        // Verifica se encontrou "%d"
        //
        // *fmt       -> caractere atual
        // *(fmt + 1)-> próximo caractere
        //
        // Exemplo:
        // "Nota = %d"
        //
        if (*fmt == '%' && *(fmt + 1) == 'd') {

            // Obtém o próximo argumento inteiro
            // passado para a função
            int valor = va_arg(args, int);

            // Converte o número para caractere ASCII
            //
            // Exemplo:
            // valor = 8
            //
            // '0' possui código ASCII 48
            // 48 + 8 = 56
            // ASCII 56 corresponde ao caractere '8'
            //
            putchar(valor + '0');
            // printf("%d", valor);

            // Avança uma posição extra para
            // pular o caractere 'd'
            fmt++;
            fmt++;


        }
        if (*fmt == '%' && *(fmt + 1) == 's') {

            // Obtém o próximo argumento string
            // passado para a função
            char *str = va_arg(args, char *);

            // Imprime a string caractere por caractere
            while (*str) {
                putchar(*str);
                str++;
            }

            // Avança uma posição extra para
            // pular o caractere 's'
            fmt++;
            fmt++;


        }

        if (*fmt == '%' && *(fmt + 1) == 'c') {
            // Obtém o próximo argumento string
            // passado para a função
            char *str = va_arg(args, char *);

            // Imprime a string caractere por caractere

            putchar(*str);

            // Avança uma posição extra para
            // pular o caractere 's'
            fmt++;



        }

        else {

            // Se não encontrou "%d",
            // imprime o caractere normalmente
            putchar(*fmt);
        }

        // Avança para o próximo caractere
        fmt++;
    }

    // Finaliza o uso da lista variádica
    va_end(args);
}

int main()
{
    // Chamada da função
    //
    // fmt = "Nota = %d\n"
    // argumento inteiro = 8
    //
    //meu_printf("Nota = %d\n %s\n %c\n", 'a', "Hello, World!", 'A');
    //meu_printf("Nota = %d\n", 8);
    meu_printf("Hello, %s!\n", "Alice");
    meu_printf("Letra: %c\n", "Z");
    return 0;
}
