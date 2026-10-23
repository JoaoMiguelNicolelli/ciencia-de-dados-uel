#include <stdio.h>

int main(){

    char nome[50];
    float salario;
    int filhos;

    float soma_um_filho = 0;
    int qtd_um_filho = 0;
    float soma_dois_filhos = 0;
    int qtd_dois_filhos = 0;

    for(int i = 0; i < 100; i++){
        printf("\nPessoa %d\n", i+1);
        printf("Nome: ");
        scanf(" %49[^\n]", nome);
        printf("Salario: ");
        scanf("%f", &salario);
        printf("Numero de filhos: ");
        scanf("%d", &filhos);

        if(filhos == 1){
            soma_um_filho += salario;
            qtd_um_filho += 1;
        }else if(filhos == 2){
            soma_dois_filhos += salario;
            qtd_dois_filhos += 1;
        }
    }

    float media_um_filho = 0;
    float media_dois_filhos = 0;

    printf("\n");

    if(qtd_dois_filhos != 0){
        media_dois_filhos = soma_dois_filhos / qtd_dois_filhos;
        printf("Salario medio de quem tem 2 filhos: %.2f\n", media_dois_filhos);
    }else{
        printf("Nenhuma pessoa com 2 filhos foi digitada.\n");
    }

    if(qtd_um_filho != 0){
        media_um_filho = soma_um_filho / qtd_um_filho;
        printf("Salario medio de quem tem 1 filho: %.2f\n", media_um_filho);
    }else{
        printf("Nenhuma pessoa com 1 filho foi digitada.\n");
    }

    if(qtd_um_filho == 0 || qtd_dois_filhos == 0){
        printf("Nao da para comparar as medias, falta um dos grupos.\n");
    }else if(media_um_filho > media_dois_filhos){
        printf("A media salarial de quem tem 1 filho eh maior.\n");
    }else if(media_dois_filhos > media_um_filho){
        printf("A media salarial de quem tem 2 filhos eh maior.\n");
    }else{
        printf("As medias salariais sao iguais.\n");
    }

    return 0;
}
