#include <stdio.h>

typedef struct {
    int codigo;
    char nome[16];
    float preco;
    int quantidade;
} Produto;

int main(){

    Produto produtos[5];
    for(int i = 0; i < 5; i++){
        printf("PRODUTO %d\n", i+1);

        printf("Codigo do produto: ");
        scanf("%d", &produtos[i].codigo);
        getchar();

        printf("Nome: ");
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        for(int j = 0; produtos[i].nome[j] != '\0'; j++){
            if(produtos[i].nome[j] == '\n'){
                produtos[i].nome[j] = '\0';
                break;
            }
        }

        printf("Quantidade no estoque: ");
        scanf("%d", &produtos[i].quantidade);
        getchar();

        printf("Valor: R$");
        scanf("%f", &produtos[i].preco);
        getchar();
    }

    int cod; 
    int qtd;

    do{

        printf("Codigo do produto desejado: ");
        scanf("%d", &cod);
        
        if(cod != 0){

            printf("Quantidade que levara: ");
            scanf("%d", &qtd);

            int encontrado = 0;

            for(int i = 0; i < 5; i++){
                if(produtos[i].codigo == cod){
                    encontrado = 1;
                    if(qtd <= produtos[i].quantidade){
                        float valorFinal = (float) produtos[i].preco * qtd;
                        printf("Produto %s encontrado! Ao levar %d, voce paga RS%.2f", produtos[i].nome, qtd, valorFinal);
                        produtos[i].quantidade -= qtd;
                    }else{
                        printf("Quantidade desejada maior do que a existente no estoque!\n");
                    }
                    break;
                }

            }

            if(!encontrado){
                printf("Codigo de produto invalido!\n");
            }
        }

    }while(cod != 0);

    return 0;
}
