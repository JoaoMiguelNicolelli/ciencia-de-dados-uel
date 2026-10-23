#include <stdio.h>
#include <stdlib.h>

struct produto {
    int codigo;
    char nome[51];
    int quantidade;
    float preco;
};

void lerProdutos(struct produto *produtos, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %50[^\n]", produtos[i].nome);
        printf("Quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
        printf("Preco de venda: ");
        scanf("%f", &produtos[i].preco);
    }
}

int maiorPreco(struct produto *produtos, int n) {
    int i, maior = 0;
    for (i = 1; i < n; i++) {
        if (produtos[i].preco > produtos[maior].preco) {
            maior = i;
        }
    }
    return maior;
}

int maiorQuantidade(struct produto *produtos, int n) {
    int i, maior = 0;
    for (i = 1; i < n; i++) {
        if (produtos[i].quantidade > produtos[maior].quantidade) {
            maior = i;
        }
    }
    return maior;
}

void mostraProduto(struct produto p) {
    printf("Codigo: %d\n", p.codigo);
    printf("Nome: %s\n", p.nome);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Preco: %.2f\n", p.preco);
}

int main() {
    int n, pos;
    struct produto *produtos;

    printf("Digite a quantidade de produtos: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    produtos = (struct produto *) malloc(n * sizeof(struct produto));
    if (produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    lerProdutos(produtos, n);

    pos = maiorPreco(produtos, n);
    printf("\nProduto com o maior preco de venda:\n");
    mostraProduto(produtos[pos]);

    pos = maiorQuantidade(produtos, n);
    printf("\nProduto com a maior quantidade em estoque:\n");
    mostraProduto(produtos[pos]);

    free(produtos);

    return 0;
}
