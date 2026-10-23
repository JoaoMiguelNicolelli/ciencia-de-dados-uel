#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    double preco;
    int estoque;
} Produto;

double valorInvestido(Produto p){
    return p.preco * p.estoque;
}

Produto reajuste(Produto p, double percentual){
    p.preco = p.preco * (1 + percentual / 100);
    return p;
}

void exibeProduto(Produto p){
    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Preco unitario: R$ %.2f\n", p.preco);
    printf("Estoque: %d\n", p.estoque);
    printf("Valor total investido: R$ %.2f\n", valorInvestido(p));
}

int main(){

    Produto p;
    printf("Codigo: ");
    scanf("%d", &p.codigo);
    getchar();
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("Preco unitario: ");
    scanf("%lf", &p.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &p.estoque);

    double percentual;
    printf("Percentual de reajuste: ");
    scanf("%lf", &percentual);

    printf("\n-Antes do reajuste-\n");
    exibeProduto(p);

    Produto atualizado = reajuste(p, percentual);

    printf("\n-Depois do reajuste-\n");
    exibeProduto(atualizado);

    return 0;
}
