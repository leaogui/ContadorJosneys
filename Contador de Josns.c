#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


int processo(int josney){
	
	char stat;
	
	puts("Digite enter para adicionar 1 no contador, um n�mero de 0 at� 9 para adicionar/diminuir, N para adicionar um n�mero maior, S para salvar e X para salvar e sair.\n");	
	
	printf("Escolha: ");
	
	scanf("%c", &stat);
	
	return josney;
}

void controlador(int josney){
	
	
	
	puts("Bem vindo ao contador de Josneys\n");
	
	while (aux != 999){
	
	printf("O n�mero de Josneys at� agora �: %d\n", josney);
	
	processo(josney);
	
	system("cls");
	
	}

}



int main (void){
	
	
	setlocale(LC_ALL, "portuguese");
	
	int josney;
	
	FILE *arq;
	
	arq = fopen("Contador.txt", "r+");
	
	fscanf(arq,"%d",&josney);
	
	controlador(josney);
	

	
	fclose(arq);
	
	
	system("pause");
	return 0;
}



