#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.1415926535

float num1, num2;

void DigiteNumeros(){
    printf("\n|  1º número: ");
    scanf("%f", &num1);
    printf("|  2º número: ");
    scanf("%f", &num2);
}

float Soma(float a, float b){
    return a + b;
}

float Subtracao(float a, float b){
    return a - b;
}

float Multiplicacao(float a, float b){
    return a * b;
}

float Divisao(float a, float b){
    return a / b;
}

void periodoNum(int *inicio, int *fim){
    printf("Início do período: ");
    scanf("%d", inicio);
    printf("Fim do período: ");
    scanf("%d", fim);

    while(*fim <= *inicio){
        system("cls");
        printf("  >> ERRO!\n  Digite um período maior que o inicial\n");
        printf("\nInício do período: %d\n", *inicio);
        printf("Fim do período: ");
        scanf("%d", fim);
    }
}

void numAleatorio(int *qnt, int *num){
    int temp, j, qntDigitado = 1;
    char stringNum[256];

    printf("Para sair digite 's'");
    do{
        printf("\n%dº Digite um número inteiro: ", qntDigitado);
        scanf(" %s", stringNum);

        if(strcmp(stringNum, "s") == 0 || strcmp(stringNum, "S") == 0){
            break;
        }

        int validandoDig = 1;
        for(int j = 0; j < strlen(stringNum); j ++){
           if(!isdigit(stringNum[j])){
               system("cls");
                printf("\n  >> Entrada inválida!\n  Digite apenas números inteiros\n");
                validandoDig = 0;
                break;
           }
       }

       if(validandoDig){
           num[*qnt] = atoi(stringNum);
            (*qnt)++;
            qntDigitado ++;
       }
    }while(strcmp(stringNum, "S") != 0 && strcmp(stringNum, "s") != 0);

    for(int i = 1; i< *qnt; i++){
        for(j = 0; j < *qnt; j++){
            if(num[i] < num[j]){
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
        j = 0;
    }
}

void calcularAngulo(double *radiano){
    double angulo;

    printf("  Digite um ângulo: ");
    scanf("%lf", &angulo);
    *radiano = (PI * (angulo/180.0));
    printf("\n");
}

void calcularPotencia(){
    float base, expoente, potencia;

    printf("  Digite a base: ");
    scanf("%f", &base);
    printf("  Digite o expoente: ");
    scanf("%f", &expoente);
    potencia = pow(base, expoente);
    printf("\n  Potência = %.2f", potencia);
}

void calcularRaiz(){
    float raiz, indice, radicando;

    printf("  Digite o índice: ");
    scanf("%f", &indice);
    printf("  Digite o radicando: ");
    scanf("%f", &radicando);

    raiz = pow(radicando, 1.0/indice);
    printf("\n  Raiz = %.2f", raiz);
}

void calcularTabuada(){
    int tabuada;

    printf("  Digite a tabuada desejada: ");
    scanf("%d", &tabuada);
    printf("\n");

    for(int i = 0; i <= 10; i ++){
        printf("  %d X %d = %d\n", tabuada, i, tabuada * i);
    }
}

void geradorNumRandomicos(){
    int qnt, inicio, final, randomico;

    printf("  Quantidade de números randômicos: ");
    scanf("%d", &qnt);
    printf("  Digite o início do período: ");
    scanf("%d", &inicio);
    printf("  Digite o final do período: ");
    scanf("%d", &final);

    while(final < inicio){
        system("cls");
        printf("  >> ERRO!\n  Digite um período maior que o inicial\n");
        printf("\nInício do período: %d\n", inicio);
        printf("Fim do período: ");
        scanf("%d", &final);
    }

    srand(time(NULL));

    printf("\n >>  Número(s) randômico gerado: \n\n");
    for(int i = 1; i <= qnt; i ++){
        randomico = (inicio + (rand()% (final - inicio + 1)));
        printf("%d", randomico);
        if(i < qnt){
            printf("\t");
        }
        else if(i >= qnt){
            printf(".");
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int opcao, inicio, fim;
    int qnt = 0, num[1000];
    float randomico;
    double rad, seno, cosseno;

    do{
        printf(".__________________________________________.");
        printf("\n|                                          |");
        printf("\n|               *CALCULADORA*              |");
        printf("\n|__________________________________________|");
        printf("\n|                                          |");
        printf("\n|  1 - Operações básicas                   |");
        printf("\n|  2 - Ordenar números                     |");
        printf("\n|  3 - Seno e cosseno                      |");
        printf("\n|  4 - Potência                            |");
        printf("\n|  5 - Raiz                                |");
        printf("\n|  6 - Tabuada                             |");
        printf("\n|  7 - Números randômicos                  |");
        printf("\n|  8 - Sair                                |");
        printf("\n|__________________________________________|");
        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            while(opcao == 1){
                system("cls");
                printf(".__________________________________________.");
                printf("\n|                                          |");
                printf("\n|             OPERAÇÕES BÁSICAS            |");
                printf("\n|__________________________________________|");
                printf("\n|                                          |");
                printf("\n|  1- Soma                                 |");
                printf("\n|  2- subtração                            |");
                printf("\n|  3- multiplicação                        |");
                printf("\n|  4- divisão                              |");
                printf("\n|  5- Voltar                               |");
                printf("\n|__________________________________________|");
                printf("\n\nDigite uma opção: ");

                if(scanf("%d", &opcao) == 1){
                    switch(opcao){
                        case 1:
                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n|                    SOMA                  |");
                            printf("\n|__________________________________________|");
                            printf("\n|                                          |");
                            printf("\n|  obs: se for um decimal utilize ','      |");
                            printf("\n|                                          |");
                            DigiteNumeros();
                            Soma(num1, num2);
                            printf("|- - - - - - - - - - - - - - - - -  - - - -");
                            printf("\n|                                          |");
                            printf("\n|  Resultado: %.2f       \n", Soma(num1, num2));
                            printf("|__________________________________________|\n");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n|                SUBTRAÇÃO                 |");
                            printf("\n|__________________________________________|");
                            printf("\n|                                          |");
                            printf("\n|  obs: se for um decimal utilize ','      |");
                            printf("\n|                                          |");
                            DigiteNumeros();
                            Subtracao(num1, num2);
                            printf("|- - - - - - - - - - - - - - - - -  - - - -");
                            printf("\n|                                          |");
                            printf("\n|  Resultado: %.2f       ", Subtracao(num1, num2));
                            printf("\n|__________________________________________|\n");
                            opcao = 1;
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n|              MULTIPLICAÇÃO               |");
                            printf("\n|__________________________________________|");
                            printf("\n|                                          |");
                            printf("\n|  obs: se for um decimal utilize ','      |");
                            printf("\n|                                          |");
                            DigiteNumeros();
                            Multiplicacao(num1, num2);
                            printf("|- - - - - - - - - - - - - - - - -  - - - -");
                            printf("\n|                                          |");
                            printf("\n|  Resultado: %.2f       ", Multiplicacao(num1, num2));
                            printf("\n|__________________________________________|\n");
                            opcao = 1;
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n|                 DIVISÃO                  |");
                            printf("\n|__________________________________________|");
                            printf("\n|                                          |");
                            printf("\n|  obs: se for um decimal utilize ','      |");
                            printf("\n|                                          |");
                            DigiteNumeros();
                            Divisao(num1, num2);
                            printf("|- - - - - - - - - - - - - - - - -  - - - -");
                            printf("\n|                                          |");
                            printf("\n|  Resultado: %.2f       ", Divisao(num1, num2));
                            printf("\n|__________________________________________|\n");
                            opcao = 1;
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            break;
                        default:
                            printf("\n  >> DÍGITO INVÁLIDO!\n\n");
                            opcao = 1;
                            system("pause");
                            system("cls");
                    }
                }
                else{
                    printf("\n  >> DÍGITO INVÁLIDO!\n\n");
                    fflush(stdin);
                    system("pause");
                }
            }
        }

        else if(opcao == 2){
            while(opcao == 2){
                system("cls");
                printf(".__________________________________________.");
                printf("\n|                                          |");
                printf("\n|              ORDENAR NÚMEROS             |");
                printf("\n|__________________________________________|");
                printf("\n|                                          |");
                printf("\n|  1- Ordem crescente                      |");
                printf("\n|  2- Ordem decrescente                    |");
                printf("\n|  3- Voltar                               |");
                printf("\n|__________________________________________|");
                printf("\n\nDigite uma opção: ");

                scanf("%d", &opcao);

                if(opcao == 1){
                    while(opcao == 1){
                        system("cls");
                        printf(".__________________________________________.");
                        printf("\n|                                          |");
                        printf("\n|              ORDEM CRESCENTE             |");
                        printf("\n|__________________________________________|");
                        printf("\n|                                          |");
                        printf("\n|  1- Por período de números               |");
                        printf("\n|  2- Por n números aleatórios digitados   |");
                        printf("\n|  3- Voltar                               |");
                        printf("\n|__________________________________________|");
                        printf("\n\nDigite uma opção: ");
                        scanf("%d", &opcao);

                        if(opcao == 1){
                            printf("\n");
                            periodoNum(&inicio, &fim);

                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n  Período inicial: %d", inicio);
                            printf("\n  Período final: %d", fim);
                            printf("\n|__________________________________________|");
                            printf("\n\n >>  Número(s) em ordem crescente:           \n\n");
                            for(inicio; inicio <= fim; inicio++){
                                printf("%d", inicio);
                                if(inicio == fim){
                                    printf(".\n\n");
                                }
                                else {
                                    printf("\t");
                                }
                            }
                            system("pause");
                        }
                        else if(opcao == 2){
                            printf("\n");
                            numAleatorio(&qnt, num);

                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n  Quantidade digitado: %d", qnt);
                            printf("\n|__________________________________________|");
                            printf("\n\n >>  Número(s) em ordem crescente:           \n\n");

                            for(int l = 0; l< qnt; l++){
                                printf("%d", num[l]);
                                if(l == (qnt - 1)){
                                    printf(".\n\n");
                                }
                                else {
                                    printf("\t");
                                }
                            }
                            qnt = 0;
                            num[1000] = 0;
                            opcao = 1;
                            system("pause");
                        }
                        else if(opcao == 3){
                            opcao = 2;
                            break;
                        }
                        else{
                            printf("\n  >> DÍGITO INVÁLIDO!\n\n");
                            fflush(stdin);
                            opcao = 1;
                            system("pause");
                        }
                    }
                }
                else if(opcao == 2){
                    while(opcao == 2){
                        system("cls");
                        printf(".__________________________________________.");
                        printf("\n|                                          |");
                        printf("\n|             ORDEM DECRESCENTE            |");
                        printf("\n|__________________________________________|");
                        printf("\n|                                          |");
                        printf("\n|  1- Por período de números               |");
                        printf("\n|  2- Por n números aleatórios digitados   |");
                        printf("\n|  3- Voltar                               |");
                        printf("\n|__________________________________________|");
                        printf("\n\nDigite uma opção: ");
                        scanf("%d", &opcao);
                        if(opcao == 1){
                            printf("\n");
                            periodoNum(&inicio, &fim);
                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n  Período inicial: %d", inicio);
                            printf("\n  Período final: %d", fim);
                            printf("\n|__________________________________________|");
                            printf("\n\n >>  Número(s) em ordem decrescente:           \n\n");
                            for(fim; fim >= inicio; fim--){
                                printf("%d", fim);
                                if(inicio == fim){
                                    printf(".\n\n");
                                }
                                else {
                                    printf("\t");
                                }
                            }
                            system("pause");
                            opcao = 2;
                        }
                        else if(opcao == 2){
                            printf("\n");
                            numAleatorio(&qnt, num);

                            system("cls");
                            printf(".__________________________________________.");
                            printf("\n|                                          |");
                            printf("\n  Quantidade digitado: %d", qnt);
                            printf("\n|__________________________________________|");
                            printf("\n\n >>  Número(s) em ordem decrescente:           \n\n");

                            for(qnt; qnt > 0; qnt--){
                                printf("%d\t", num[qnt - 1]);
                            }
                            printf("\n\n");
                            qnt = 0;
                            num[1000] = 0;
                            opcao = 2;
                            system("pause");
                        }
                        else if(opcao == 3){
                            opcao = 2;
                            break;
                        }
                        else{
                            printf("\n  >> DÍGITO INVÁLIDO!\n\n");
                            fflush(stdin);
                            opcao = 2;
                            system("pause");
                        }
                    }
                }
                else if(opcao == 3){
                    break;
                }
                else{
                    printf("\n  >> DÍGITO INVÁLIDO!\n\n");
                    fflush(stdin);
                    opcao = 2;
                    system("pause");
                }
            }
        }
        else if(opcao == 3){
            while(opcao == 3){
                system("cls");
                printf(".__________________________________________.");
                printf("\n|                                          |");
                printf("\n|              SENO E COSSENO              |");
                printf("\n|__________________________________________|\n\n");
                calcularAngulo(&rad);
                seno = sin(rad);
                cosseno = cos(rad);

                printf("  Seno: %lf\n  Cosseno: %lf", seno, cosseno);

                printf("\n|__________________________________________|");
                printf("\n|                                          |");
                printf("\n|  1- Digitar outro ângulo                 |");
                printf("\n|  2- Voltar                               |");
                printf("\n|__________________________________________|");
                printf("\n\nDigite uma opção: ");
                scanf("%d", &opcao);
                if(opcao == 1){
                    opcao = 3;
                }
                else if(opcao == 2){
                    system("cls");
                    break;
                }
                else{
                    while(opcao != 1 && opcao != 2){
                        system("cls");
                        printf("\n  >> DÍGITO INVÁLIDO!\n");
                        printf(".__________________________________________.");
                        printf("\n|                                          |");
                        printf("\n|  1- Digitar outro ângulo                 |");
                        printf("\n|  2- Voltar                               |");
                        printf("\n|__________________________________________|");
                        printf("\n\nDigite uma opção: ");
                        scanf("%d", &opcao);
                    }
                    if(opcao == 1){
                        opcao = 3;
                    }
                    system("cls");
                }
            }
        }
        else if(opcao == 4){
            while(opcao == 4){
                system("cls");
                printf(".__________________________________________.");
                printf("\n|                                          |");
                printf("\n|                 POTÊNCIA                 |");
                printf("\n|__________________________________________|\n\n");
                calcularPotencia();

                printf("\n|__________________________________________|");
                printf("\n|                                          |");
                printf("\n|  1- Digitar outros valores               |");
                printf("\n|  2- Voltar                               |");
                printf("\n|__________________________________________|");
                printf("\n\nDigite uma opção: ");
                scanf("%d", &opcao);
                if(opcao == 1){
                    opcao = 4;
                }
                else if(opcao == 2){
                    system("cls");
                    break;
                }
                else{
                    while(opcao != 1 && opcao != 2){
                        system("cls");
                        printf("\n  >> DÍGITO INVÁLIDO!\n");
                        printf(".__________________________________________.");
                        printf("\n|                                          |");
                        printf("\n|  1- Digitar outros valores               |");
                        printf("\n|  2- Voltar                               |");
                        printf("\n|__________________________________________|");
                        printf("\n\nDigite uma opção: ");
                        scanf("%d", &opcao);
                    }
                    if(opcao == 1){
                        opcao = 4;
                    }
                    system("cls");
                }
            }
        }
        else if(opcao == 5){
            while(opcao == 5){
                system("cls");
                printf(".__________________________________________.");
                printf("\n|                                          |");
                printf("\n|                   RAIZ                   |");
                printf("\n|__________________________________________|\n\n");
                calcularRaiz();

                printf("\n|__________________________________________|");
                printf("\n|                                          |");
                printf("\n|  1- Digitar outros valores               |");
                printf("\n|  2- Voltar                               |");
                printf("\n|__________________________________________|");
                printf("\n\nDigite uma opção: ");
                scanf("%d", &opcao);
                if(opcao == 1){
                    opcao = 5;
                }
                else if(opcao == 2){
                    system("cls");
                    break;
                }
                else{
                    while(opcao != 1 && opcao != 2){
                        system("cls");
                        printf("\n  >> DÍGITO INVÁLIDO!\n");
                        printf(".__________________________________________.");
                        printf("\n|                                          |");
                        printf("\n|  1- Digitar outros valores               |");
                        printf("\n|  2- Voltar                               |");
                        printf("\n|__________________________________________|");
                        printf("\n\nDigite uma opção: ");
                        scanf("%d", &opcao);
                    }
                    if(opcao == 1){
                        opcao = 5;
                    }
                    system("cls");
                }
            }
        }
         else if(opcao == 6){
            while(opcao == 6){
                system("cls");
                printf(".__________________________________________.");
                printf("\n|                                          |");
                printf("\n|                 TABUADA                  |");
                printf("\n|__________________________________________|\n\n");
                calcularTabuada();

                printf("|__________________________________________|");
                printf("\n|                                          |");
                printf("\n|  1- Digitar outro valor                  |");
                printf("\n|  2- Voltar                               |");
                printf("\n|__________________________________________|");
                printf("\n\nDigite uma opção: ");
                scanf("%d", &opcao);
                if(opcao == 1){
                    opcao = 6;
                }
                else if(opcao == 2){
                    system("cls");
                    break;
                }
                else{
                    while(opcao != 1 && opcao != 2){
                        system("cls");
                        printf("\n  >> DÍGITO INVÁLIDO!\n");
                        printf(".__________________________________________.");
                        printf("\n|                                          |");
                        printf("\n|  1- Digitar outro valor                  |");
                        printf("\n|  2- Voltar                               |");
                        printf("\n|__________________________________________|");
                        printf("\n\nDigite uma opção: ");
                        scanf("%d", &opcao);
                    }
                    if(opcao == 1){
                        opcao = 6;
                    }
                    system("cls");
                }
            }
         }
         else if(opcao == 7){
            while(opcao == 7){
                system("cls");
                printf(".__________________________________________.");
                printf("\n|                                          |");
                printf("\n|            NÚMEROS RANDÔMICOS            |");
                printf("\n|__________________________________________|\n\n");
                geradorNumRandomicos();

                printf("\n|__________________________________________|");
                printf("\n|                                          |");
                printf("\n|  1- Digitar outros valores               |");
                printf("\n|  2- Voltar                               |");
                printf("\n|__________________________________________|");
                printf("\n\nDigite uma opção: ");
                scanf("%d", &opcao);
                if(opcao == 1){
                    opcao = 7;
                }
                else if(opcao == 2){
                    system("cls");
                    break;
                }
                else{
                    while(opcao != 1 && opcao != 2){
                        system("cls");
                        printf("\n  >> DÍGITO INVÁLIDO!\n");
                        printf(".__________________________________________.");
                        printf("\n|                                          |");
                        printf("\n|  1- Digitar outros valores               |");
                        printf("\n|  2- Voltar                               |");
                        printf("\n|__________________________________________|");
                        printf("\n\nDigite uma opção: ");
                        scanf("%d", &opcao);
                    }
                    if(opcao == 1){
                        opcao = 7;
                    }
                    system("cls");
                }
            }
         }
         else if(opcao == 8){
            printf("\n  >> SAINDO . . .\n");
            system("pause");
            break;
         }
        else{
            printf("\n  >> DÍGITO INVÁLIDO!\n");
            fflush(stdin);
            system("pause");
            system("cls");
        }
        system("cls");
    }while(opcao != 7);
    return 0;
}
