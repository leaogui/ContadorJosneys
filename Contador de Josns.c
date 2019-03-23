#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int processo(int josney, char aux, FILE* arq)
{

    if (aux == 'N' || aux == 'n') {
    	
    	int temp;

        printf("\nDigite o número para ser adicionado: ");
	
		fflush(stdin);
	
        scanf("%d", &temp);

        josney += temp;
    }
    else {

        josney++;
    }
    
     system("cls");

    return (josney);
}

void controlador(int josney, FILE* arq)
{

    char aux;

    puts("Bem vindo ao contador de Josneys\n");

    while (2 > 1) {

        printf("\nO número de Josneys até agora é: %d\n\n", josney);

        puts("Digite enter ou um dígito diferente dos próximos para adicionar 1 no contador, N para adicionar um número maior, S para salvar e X para salvar e sair.\n");

        printf("Escolha: ");

		fflush(stdin);

        scanf("%c", &aux);

        if (aux == 'x' || aux == 'X') {

			arq = fopen("Contador.xml", "w+");
				
			fprintf(arq,"%d", josney);
			
			system("cls");

            break;
        }
        else {
        	
			if(aux == 's' || aux == 'S'){		
				
				
				arq = fopen("Contador.xml", "w+");
				
				fprintf(arq,"%d", josney);
				
				 system("cls");
				
				puts("O número foi salvo no txt!\n");
				
				
				}
				
				else{
				

            josney = processo(josney, aux, arq);
            
            
			}
        }

       
    }
}




int main(void)
{

    FILE* arq;

    setlocale(LC_ALL, "portuguese");

    int josney;

    arq = fopen("Contador.xml", "r+");
    

	fflush(stdin);

    fscanf(arq, "%d", &josney);

    controlador(josney, arq);

    puts("\n\n                    Obrigado por utilizar o programa!!!\n\n                    Os Josneys foram salvos no arquivo Josneys.txt.\n\n");

    fclose(arq);

    system("pause");
    
    return 0;
}



