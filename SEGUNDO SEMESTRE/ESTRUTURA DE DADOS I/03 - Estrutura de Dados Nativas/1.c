#include <stdio.h>

int main() {
    int tam, quantidade = 0;
    printf("Tamanho da lista: ");
    scanf("%d", &tam);

    int v[tam], soma = 0, cont = 0;
    for(int i = 0; i < tam; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &v[i]);

        cont += 1;
        soma += v[i];
    }
    
    double media;
    media = (double) soma / cont;

   int cont_maiores = 0;
   for(int i = 0; i < tam; i++){
    if(v[i] > media){
        cont_maiores += 1;
    }
   }
    
    printf("Media: %.2f\n", media);
    printf("Quantidade maiores que a media: %d\n", cont_maiores);

    return 0;
}