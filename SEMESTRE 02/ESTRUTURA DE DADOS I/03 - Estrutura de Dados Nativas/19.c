#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    double nota1;
    double nota2;
} Aluno;

double media(Aluno a){
    return (a.nota1 + a.nota2) / 2;
}

int main(){

    int n;
    printf("Quantidade de alunos: ");
    scanf("%d", &n);

    Aluno alunos[n];

    for(int i = 0; i < n; i++){
        printf("\n-Aluno %d-\n", i+1);
        getchar(); // remove o enter deixado pelo scanf
        printf("Nome: ");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nota 1: ");
        scanf("%lf", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%lf", &alunos[i].nota2);
    }

    printf("\n-Medias-\n");
    for(int i = 0; i < n; i++){
        printf("%s (%d): %.2f\n", alunos[i].nome, alunos[i].matricula, media(alunos[i]));
    }

    printf("\n-Aprovados-\n");
    for(int i = 0; i < n; i++){
        if(media(alunos[i]) >= 6.0){
            printf("%s\n", alunos[i].nome);
        }
    }

    int melhor = 0;
    for(int i = 1; i < n; i++){
        if(media(alunos[i]) > media(alunos[melhor])){
            melhor = i;
        }
    }

    printf("\nMaior media: %s (%.2f)\n", alunos[melhor].nome, media(alunos[melhor]));

    return 0;
}
