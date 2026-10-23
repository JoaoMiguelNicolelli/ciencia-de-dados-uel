#include <stdio.h>
#include <string.h>

struct Pessoa{

    char nome [50];
    char endereco [100];
    int idade;

};

int main(){

    struct Pessoa pessoa;

    printf("Nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

    printf("Endereco: ");
    fgets(pessoa.endereco, sizeof(pessoa.endereco), stdin);
    pessoa.endereco[strcspn(pessoa.endereco, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &pessoa.idade);
    getchar();

    printf("\nNome: %s\n", pessoa.nome);
    printf("Endereco: %s\n", pessoa.endereco);
    printf("Idade: %d", pessoa.idade);

    return 0;
}