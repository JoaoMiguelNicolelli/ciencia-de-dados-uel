#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char *nome;
    float peso;
} Animal;

int buscaAnimal(Animal *animais, int qtd, int codigo) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (animais[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void inserirAnimal(Animal **animais, int *qtd, int *capacidade) {
    int codigo;
    char aux[100];
    Animal *novo;

    printf("Codigo: ");
    scanf("%d", &codigo);
    if (buscaAnimal(*animais, *qtd, codigo) != -1) {
        printf("Ja existe um animal com esse codigo.\n");
        return;
    }

    if (*qtd == *capacidade) {
        novo = (Animal *) realloc(*animais, 2 * (*capacidade) * sizeof(Animal));
        if (novo == NULL) {
            printf("Erro ao alocar memoria.\n");
            return;
        }
        *animais = novo;
        *capacidade = 2 * (*capacidade);
    }

    printf("Nome: ");
    scanf(" %99[^\n]", aux);
    (*animais)[*qtd].nome = (char *) malloc((strlen(aux) + 1) * sizeof(char));
    if ((*animais)[*qtd].nome == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    strcpy((*animais)[*qtd].nome, aux);

    (*animais)[*qtd].codigo = codigo;
    printf("Peso: ");
    scanf("%f", &(*animais)[*qtd].peso);

    (*qtd)++;
    printf("Animal inserido.\n");
}

void removerAnimal(Animal **animais, int *qtd, int *capacidade) {
    int codigo, pos, i, novaCapacidade;
    Animal *novo;

    printf("Codigo do animal a remover: ");
    scanf("%d", &codigo);
    pos = buscaAnimal(*animais, *qtd, codigo);
    if (pos == -1) {
        printf("Animal nao encontrado.\n");
        return;
    }

    free((*animais)[pos].nome);
    for (i = pos; i < *qtd - 1; i++) {
        (*animais)[i] = (*animais)[i + 1];
    }
    (*qtd)--;
    printf("Animal removido.\n");

    if (*qtd * 4 < *capacidade) {
        novaCapacidade = *capacidade / 2;
        if (novaCapacidade < 2) {
            novaCapacidade = 2;
        }
        if (novaCapacidade < *capacidade) {
            novo = (Animal *) realloc(*animais, novaCapacidade * sizeof(Animal));
            if (novo != NULL) {
                *animais = novo;
                *capacidade = novaCapacidade;
            }
        }
    }
}

void alterarNome(Animal *animais, int qtd) {
    int codigo, pos;
    char aux[100];
    char *novoNome;

    printf("Codigo do animal: ");
    scanf("%d", &codigo);
    pos = buscaAnimal(animais, qtd, codigo);
    if (pos == -1) {
        printf("Animal nao encontrado.\n");
        return;
    }

    printf("Nome atual: %s\n", animais[pos].nome);
    printf("Novo nome: ");
    scanf(" %99[^\n]", aux);

    novoNome = (char *) realloc(animais[pos].nome, (strlen(aux) + 1) * sizeof(char));
    if (novoNome == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    animais[pos].nome = novoNome;
    strcpy(animais[pos].nome, aux);
    printf("Nome alterado.\n");
}

void listarAnimais(Animal *animais, int qtd, int capacidade) {
    int i;
    printf("Quantidade: %d | Capacidade: %d\n", qtd, capacidade);
    for (i = 0; i < qtd; i++) {
        printf("Codigo: %d | Nome: %s | Peso: %.2f\n", animais[i].codigo, animais[i].nome, animais[i].peso);
    }
}

void liberarCadastro(Animal *animais, int qtd) {
    int i;
    for (i = 0; i < qtd; i++) {
        free(animais[i].nome);
    }
    free(animais);
}

int main() {
    int qtd = 0, capacidade = 2, opcao;
    Animal *animais;

    animais = (Animal *) malloc(capacidade * sizeof(Animal));
    if (animais == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    do {
        printf("\n1 - Inserir animal\n");
        printf("2 - Remover animal\n");
        printf("3 - Alterar nome\n");
        printf("4 - Listar animais\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirAnimal(&animais, &qtd, &capacidade);
                break;
            case 2:
                removerAnimal(&animais, &qtd, &capacidade);
                break;
            case 3:
                alterarNome(animais, qtd);
                break;
            case 4:
                listarAnimais(animais, qtd, capacidade);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    liberarCadastro(animais, qtd);

    return 0;
}
