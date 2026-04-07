#include <stdio.h>

//#define DEBUG
int main(void) {
#ifdef DEBUG
printf("DEBUG\nDescricao detalhada: ...\n");
#else
printf("NORMAL\nNenhuma descricao\n");
#endif
}
