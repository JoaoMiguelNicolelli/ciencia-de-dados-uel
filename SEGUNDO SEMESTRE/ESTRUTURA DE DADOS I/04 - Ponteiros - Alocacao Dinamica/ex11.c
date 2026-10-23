#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int matricula;
    double nota1;
    double nota2;
} Aluno;

double media(const Aluno *a){
    return (a->nota1 + a->nota2) / 2;
}

Aluno *melhorAluno(Aluno *v, int n){

    if(n <= 0) return NULL;

    Aluno *melhor = &v[0];

    for(int i = 1; i < n; i++){
        if(media(&v[i]) > media(melhor)){
            melhor = &v[i]; 
        }
    }

    return melhor;
}

Aluno *aprovados(const Aluno *v, int n, int *qtd){

    *qtd = 0;

    for(int i = 0; i < n; i++){
        if(media(&v[i]) >= 6.0){
            (*qtd)++;
        }
    }

    if(*qtd == 0) return NULL;

    Aluno *novo = malloc((*qtd) * sizeof(Aluno));

    if(novo == NULL){
        *qtd = 0;
        return NULL;
    }

    int k = 0;
    for(int i = 0; i < n; i++){
        if(media(&v[i]) >= 6.0){
            novo[k] = v[i];
            k++;
        }
    }

    return novo;
}

int main(){

    int n;
    printf("Quantidade de alunos: ");
    scanf("%d", &n);

    Aluno *alunos = malloc(n * sizeof(Aluno));

    if(alunos == NULL){
        printf("Memoria insuficiente\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("\n-Aluno %d-\n", i+1);
        getchar(); 
        printf("Nome: ");
        fgets(alunos[i].nome, 50, stdin);

        for(char *p = alunos[i].nome; *p != '\0'; p++){
            if(*p == '\n'){
                *p = '\0';
            }
        }

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nota 1: ");
        scanf("%lf", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%lf", &alunos[i].nota2);
    }

    Aluno *melhor = melhorAluno(alunos, n);

    if(melhor != NULL){ 
        printf("\nMelhor aluno: %s (%d) - media %.2f\n",
               melhor->nome, melhor->matricula, media(melhor));
    }

    int qtd;
    Aluno *lista = aprovados(alunos, n, &qtd);

    printf("\n-Aprovados (%d)-\n", qtd);
    for(int i = 0; i < qtd; i++){
        printf("%s (%d) - media %.2f\n",
               lista[i].nome, lista[i].matricula, media(&lista[i]));
    }

    free(lista);
    free(alunos);

    lista = NULL;
    alunos = NULL;

    return 0;
}
