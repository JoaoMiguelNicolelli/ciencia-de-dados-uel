#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 30

void liberaNomes(char **nomes, int linhas) {
    int i;
    for (i = 0; i < linhas; i++) {
        free(nomes[i]);
    }
    free(nomes);
}

char **alocaNomes(int maxNomes) {
    int i;
    char **nomes;

    nomes = (char **) malloc(maxNomes * sizeof(char *));
    if (nomes == NULL) {
        return NULL;
    }

    for (i = 0; i < maxNomes; i++) {
        nomes[i] = (char *) malloc(TAM_NOME * sizeof(char));
        if (nomes[i] == NULL) {
            liberaNomes(nomes, i);
            return NULL;
        }
        nomes[i][0] = '\0';
    }

    return nomes;
}

int buscaNome(char **nomes, int maxNomes, char *nome) {
    int i;
    for (i = 0; i < maxNomes; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}

int leLinha(int maxNomes) {
    int linha;
    printf("Linha (0 a %d): ", maxNomes - 1);
    scanf("%d", &linha);
    if (linha < 0 || linha >= maxNomes) {
        printf("Linha invalida.\n");
        return -1;
    }
    return linha;
}

void mostraNomes(char **nomes, int maxNomes) {
    int i;
    for (i = 0; i < maxNomes; i++) {
        if (nomes[i][0] == '\0') {
            printf("[%d] (vazia)\n", i);
        } else {
            printf("[%d] %s\n", i, nomes[i]);
        }
    }
}

int main() {
    int maxNomes, opcao, linha;
    char nome[TAM_NOME];
    char **nomes;

    printf("Digite o numero maximo de nomes: ");
    scanf("%d", &maxNomes);
    if (maxNomes <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    nomes = alocaNomes(maxNomes);
    if (nomes == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    do {
        printf("\n1 - Gravar um nome em uma linha\n");
        printf("2 - Apagar o nome de uma linha\n");
        printf("3 - Procurar um nome e substituir por outro\n");
        printf("4 - Procurar um nome e apagar\n");
        printf("5 - Mostrar todos os nomes\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                linha = leLinha(maxNomes);
                if (linha != -1) {
                    printf("Nome: ");
                    scanf(" %29[^\n]", nomes[linha]);
                }
                break;
            case 2:
                linha = leLinha(maxNomes);
                if (linha != -1) {
                    nomes[linha][0] = '\0';
                }
                break;
            case 3:
                printf("Nome a procurar: ");
                scanf(" %29[^\n]", nome);
                linha = buscaNome(nomes, maxNomes, nome);
                if (linha == -1) {
                    printf("Nome nao encontrado.\n");
                } else {
                    printf("Novo nome: ");
                    scanf(" %29[^\n]", nomes[linha]);
                }
                break;
            case 4:
                printf("Nome a apagar: ");
                scanf(" %29[^\n]", nome);
                linha = buscaNome(nomes, maxNomes, nome);
                if (linha == -1) {
                    printf("Nome nao encontrado.\n");
                } else {
                    nomes[linha][0] = '\0';
                    printf("Nome apagado da linha %d.\n", linha);
                }
                break;
            case 5:
                mostraNomes(nomes, maxNomes);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    liberaNomes(nomes, maxNomes);

    return 0;
}
