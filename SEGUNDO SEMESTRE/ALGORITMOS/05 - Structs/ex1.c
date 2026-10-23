#include <stdio.h>

struct Pessoa{

    char nome [50];
    char endereco [100];
    int idade;

};

int main(){

    struct Pessoa a = {"Joao Miguel", "Rua jose garla 161", 18};

    printf("Nome: %s\n", a.nome);
    printf("Endereco: %s\n", a.endereco);
    printf("Idade: %d\n", a.idade);


    return 0;
}