#include <stdio.h>
int j = 1;
// se mantém estático se for declarado fora da função, ou com o static
void incrementa(void){
	int i = 1;
	//static int j = 1; 
	// caso existir 2 declarações, ele prioriza a declaração interna e salva a externa para uso fora da função
	i++;
	j++;
	printf("Valor de i = %d, valor de j = %d\n", i, j);
	/*
	for (int j=0; j<5;j++){
		printf("Deti ");
	}*/
}

int main(){
	for (int i = 0; i<10;i++){
		//j++;
		incrementa();
	}
}
