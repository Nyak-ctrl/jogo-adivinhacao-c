#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    FILE *arquivo;
    int numero;
    int adivinha;
    int number;
    int quantidade = 0;
    int opcao;

    srand(time(NULL));
    numero = rand() % 100 + 1;

    arquivo = fopen("numero.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    if (fprintf(arquivo, "%d\n", numero) < 0) {
        printf("Erro ao escrever no arquivo!\n");
        fclose(arquivo);
        return 1;
    }

    fclose(arquivo);

    arquivo = fopen("numero.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    fscanf(arquivo, "%d", &adivinha);

    fclose(arquivo);

        printf("======================================\n");
        printf("       ESCOLHA A DIFICULDADE          \n");
        printf("======================================\n");
        printf("1. Facil (infinitas tentativas)\n");
        printf("2. Normal (10 tentativas)\n");
        printf("3. Dificil (3 tentativas)\n");
        printf("======================================\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Opcao selecionada: Facil\n");

            do{

                printf("Digite um numero de 1 a 100:\n");
                scanf("%d", &number);

                if(number > adivinha){
                    printf("O numero digitado e maior que o numero secreto\n");
                }
                else if(number < adivinha){
                    printf("O numero digitado e menor que o numero secreto\n");
                }
                else {
                    printf("Parabens! Voce acertou!\n");
                }

            }while(number != adivinha);
        }
        else if(opcao == 2){
            printf("Opcao selecionada: Normal\n");
            do{

                printf("Digite um numero de 1 a 100:\n");
                scanf("%d", &number);
                quantidade ++;

                if(number > adivinha){
                    printf("O numero digitado e maior que o numero secreto\n");
                }
                else if(number < adivinha){
                    printf("O numero digitado e menor que o numero secreto\n");
                }
                else{
                    printf("Parabens! Voce acertou!\n");
                    break;
                }
            }while(quantidade != 10);

                if(number != adivinha) {
                printf("Voce falhou em encontrar! O numero secreto era: %d\n", adivinha);
            }
        }
        else if(opcao == 3){
            printf("Opcao selecionada: Dificil\n");
            do{

                printf("Digite um numero de 1 a 100:\n");
                scanf("%d", &number);
                quantidade ++;

                if(number > adivinha){
                    printf("O numero digitado e maior que o numero secreto\n");
                }
                else if(number < adivinha){
                    printf("O numero digitado e menor que o numero secreto\n");
                }
                else{
                    printf("Parabens! Voce acertou!\n");
                    break;
                }
            }while(quantidade != 3);

            if(number != adivinha) {
            printf("Voce falhou em encontrar! O numero secreto era: %d\n", adivinha);
            }
        }

return 0;
}
