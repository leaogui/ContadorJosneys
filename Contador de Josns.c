#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int bk;

int processo(int josney, char aux)
{
    FILE* arqbk;

    arqbk = fopen("Backup.xml", "w+");

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

    fprintf(arqbk, "%d", josney);

    fclose(arqbk);

    return (josney);
}

void controlador(int josney, FILE* arq)
{

    char aux;

    puts("Bem vindo ao contador de Josneys\n");

    while (2 > 1) {

        printf("\nO número de Josneys até agora é: %d\n\n", josney);

        puts("Digite enter ou um dígito diferente dos próximos para adicionar 1 no contador, N para adicionar um número maior, S para salvar, I para informações adicionais do programa, B para fazer um backup e X para salvar e sair.\n");

        printf("Escolha: ");

        fflush(stdin);

        scanf("%c", &aux);

        if (aux == 'i' || aux == 'I') {

            system("cls");

            puts("\n\n Este programa conta o número de Josneys que ocorreram até o momento.\n Sempre que um Josney é contado o programa faz um backup, assim como quando ele é terminado pelo X. \n Programa para descontrair feito por Guilherme Leão. @guivsthewold\n\n");

            system("pause");

            system("cls");
        }
        else {

            if (aux == 'b' || aux == 'B') {

                system("cls");

                FILE* bkarq;

                int temp;

                char auxbk;

                bkarq = fopen("Backup.xml", "r+");

                fflush(stdin);

                fscanf(bkarq, "%d", &temp);

                printf("O número de Josneys no backup é de: %d, deseja mesmo fazer o backup?\n", temp);

                printf("S para sim, N para não: ");

                fflush(stdin);

                scanf("%c", &auxbk);

                if (auxbk == 's' || auxbk == 'S') {

                    josney = temp;

                    system("cls");

                    puts("\nO backup foi feito.\n\n");

                    fclose(bkarq);
                }
                else {

                    system("cls");

                    puts("\nO backup não foi feito.\n\n");

                    fclose(bkarq);
                }
            }
            else {
                if (aux == 'x' || aux == 'X') {

                    FILE* arqtxt;

                    arq = fopen("Contador.xml", "w+");

                    arqtxt = fopen("Josneys.txt", "w+");

                    fprintf(arq, "%d", josney);

                    fprintf(arqtxt, "O número de Josneys até agora é: %d\n", josney);

                    fclose(arq);

                    fclose(arqtxt);

                    system("cls");

                    bk = josney;

                    break;
                }
                else {

                    if (aux == 's' || aux == 'S') {

                        FILE* arqtxt;

                        arq = fopen("Contador.xml", "w+");

                        arqtxt = fopen("Josneys.txt", "w+");

                        fprintf(arq, "%d", josney);

                        fprintf(arqtxt, "O número de Josneys até agora é: %d\n", josney);

                        system("cls");

                        puts("O número foi salvo no txt!\n");

                        fclose(arq);

                        fclose(arqtxt);

                        bk = josney;
                    }

                    else {

                        josney = processo(josney, aux);
                    }
                }
            }
        }
    }
}

int main(void)
{

    FILE *arq, *arqbk;

    setlocale(LC_ALL, "portuguese");

    int josney;

    arq = fopen("Contador.xml", "r");

    fflush(stdin);

    fscanf(arq, "%d", &josney);

    fclose(arq);

    controlador(josney, arq);

    arqbk = fopen("backup.xml", "w+");

    fprintf(arqbk, "%d", bk);

    fclose(arqbk);

    puts("\n\n                    Obrigado por utilizar o programa!!!\n\n                    Os Josneys foram salvos no arquivo Josneys.txt e um backup foi feito.\n\n");

    fclose(arq);

    system("pause");

    return 0;
}

