#include <stdio.h>

// ***************************************************
// O typedef a seguir cria um tipo chamado 'TipoFuncao' que define um
// tipo de dado que é uma função.
// O que determina o tipo, neste caso é:
// - o tipo de retorno da função;
// - os parâmetros usados na função. Leva-se em conta a quantidade,
//	 a ordem e o tipo destes parâmetros
typedef int TipoFuncao(void);// 32bit
typedef int TipoFuncao2(int a, int b);//32 + 32 + 32

// ***************************************************
// As três funções a seguir são do mesmo tipo de 'TipoFuncao'
// ***************************************************

int test(int a, int b){
  sudo nano /boot/loader/loader.conf
}

int Load(void) {
  // Veja o que significa a macro __FUNCTION__ em
  // https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html#Standard-Predefined-Macros
  printf("function called = %s\n", __FUNCTION__);
  return 10;
}

int Print(void) {
  printf("function called = %s\n", __func__);
  return 20;
}

int Quit(void) {
  printf("function called = %s\n", __func__);
  return 30;
}
// ***************************************************
//	Funcao que recebe um ponteiro para uma função
//	'PonteiroParaUmaFuncao' e uma variável que irá
//	armazenar o valor deste ponteiro 'GuardaEnderecoDeUmaFuncao'
// ***************************************************
/*void SetCallbackFunc(TipoFuncao **GuardaEnderecoDeUmaFuncao,
                     TipoFuncao *PonteiroParaUmaFuncao) {
  *GuardaEnderecoDeUmaFuncao = PonteiroParaUmaFuncao;
}*/

int main() {
  int opcao, retorno;
  // Cria 3 ponteiros que irão apontar para funções do programa
  TipoFuncao *ptrF; // int func(void)
  TipoFuncao2 *ptr2F; // 
  int *ptrInt;
  
  retorno = Load();
  // Faz cada um dos ponteiros apontar para uma função diferente
  printf("Address(Load): %p\r\n", &Load);
  printf("Address(Print): %p\r\n", &Print);
  printf("Address(Quit): %p\r\n", &Quit);

  ptrF = Load;
  
  do {
    printf("Digite sua opcao(1,2,3) :");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      ptrF = Load;
      break;
    case 2:
      ptrF = Print;
      break;
    case 3:
      //SetCallbackFunc(&ptrF, Quit);
      ptrF = Quit;
      break;
    }
    printf("function address = %p\r\n", *ptrF);
    retorno = (*ptrF)(); // chama uma função a partir de ptrF
                         // e obtem o retorno
    printf("Retorno da função: %d\n\n", retorno);
  } while (opcao != 3);
}
