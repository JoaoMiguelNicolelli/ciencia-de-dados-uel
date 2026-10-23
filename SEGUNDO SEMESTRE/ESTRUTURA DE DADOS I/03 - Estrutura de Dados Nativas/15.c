#include <stdio.h>
#include <string.h>

int main(){

    int n;
    printf("Quantidade de nomes: ");
    scanf("%d", &n);
    getchar(); // remove o enter deixado pelo scanf

    char nomes[n][50];

    for(int i = 0; i < n; i++){
        printf("Nome %d: ", i+1);
        fgets(nomes[i], 50, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }

    int maisLongo = 0, primeiro = 0;
    for(int i = 1; i < n; i++){
        if(strlen(nomes[i]) > strlen(nomes[maisLongo])){
            maisLongo = i;
        }
        if(strcmp(nomes[i], nomes[primeiro]) < 0){
            primeiro = i;
        }
    }

    printf("\nNome mais longo: %s\n", nomes[maisLongo]);
    printf("Primeiro em ordem alfabetica: %s\n", nomes[primeiro]);

    return 0;
}
