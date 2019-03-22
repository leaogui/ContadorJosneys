#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


int processo(int josney, char aux){
	
	
	if(aux = 'N' || aux = 'n'){
		
		printf("Digite o número para ser adicionado: ");
		
		scanf("%d",josney);
		
		josney += aux;
		
		
	}else{
		
			josney++;
			
		}
	}
	
	
	return josney;
}

void controlador(int josney){
	
	char aux;
	
	puts("Bem vindo ao contador de Josneys\n");
	
	while (2>1){
	
	printf("O número de Josneys até agora é: %d\n", josney);
	
	puts("Digite enter ou um dígito diferente dos próximos para adicionar 1 no contador, N para adicionar um número maior, S para salvar e X para salvar e sair.\n");	
	
	printf("Escolha: ");
	
	scanf("%c", &aux);
	
	if(aux != 'x' || aux != 'X'){
		
		josney = processo(josney, aux);
		
	}else{
		
		system("cls");
		
		break;
	}
	
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



