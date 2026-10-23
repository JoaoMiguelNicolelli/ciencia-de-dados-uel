#include <stdio.h>

int main() {
    char a, b;

    printf("Escolha do jogador A (R - pedra / P - papel / S - tesoura): ");
    scanf(" %c", &a);
    printf("Escolha do jogador B (R - pedra / P - papel / S - tesoura): ");
    scanf(" %c", &b);

    if (b != 'R' && b != 'P' && b != 'S') {
        printf("Escolha invalida do jogador B\n");
        return 1;
    }

    switch (a) {
        case 'R':
            if (b == 'R') {
                printf("Empate\n");
            } else if (b == 'S') {
                printf("Jogador A venceu\n");
            } else {
                printf("Jogador B venceu\n");
            }
            break;
        case 'P':
            if (b == 'P') {
                printf("Empate\n");
            } else if (b == 'R') {
                printf("Jogador A venceu\n");
            } else {
                printf("Jogador B venceu\n");
            }
            break;
        case 'S':
            if (b == 'S') {
                printf("Empate\n");
            } else if (b == 'P') {
                printf("Jogador A venceu\n");
            } else {
                printf("Jogador B venceu\n");
            }
            break;
        default:
            printf("Escolha invalida do jogador A\n");
            return 1;
    }

    return 0;
}
