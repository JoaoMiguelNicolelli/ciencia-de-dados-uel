#include <stdio.h>

void IniciaTabuleiro(char t[3][3]){
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            t[i][j] = ' ';
        }
    }
}

void MostraTabuleiro(char t[3][3]){
    int i;

    printf("\n     1   2   3\n");
    for(i = 0; i < 3; i++){
        printf("  %d  %c | %c | %c\n", i + 1, t[i][0], t[i][1], t[i][2]);
        if(i < 2){
            printf("    ---+---+---\n");
        }
    }
    printf("\n");
}

int JogadaValida(char t[3][3], int l, int c){
    if(l < 0 || l > 2 || c < 0 || c > 2){
        return 0;
    }
    return t[l][c] == ' ';
}

int Venceu(char t[3][3], char s){
    int i;

    for(i = 0; i < 3; i++){
        if(t[i][0] == s && t[i][1] == s && t[i][2] == s){
            return 1;
        }
        if(t[0][i] == s && t[1][i] == s && t[2][i] == s){
            return 1;
        }
    }
    if(t[0][0] == s && t[1][1] == s && t[2][2] == s){
        return 1;
    }
    if(t[0][2] == s && t[1][1] == s && t[2][0] == s){
        return 1;
    }
    return 0;
}

int main(){
    char t[3][3], jogador = 'X';
    int l, c, jogadas = 0;

    IniciaTabuleiro(t);

    while(1){
        MostraTabuleiro(t);
        printf("Jogador %c, digite linha e coluna (1 a 3): ", jogador);
        scanf("%d %d", &l, &c);

        if(!JogadaValida(t, l - 1, c - 1)){
            printf("Posicao invalida ou ocupada! Tente novamente.\n");
            continue;
        }

        t[l - 1][c - 1] = jogador;
        jogadas++;

        if(Venceu(t, jogador)){
            MostraTabuleiro(t);
            printf("Jogador %c venceu!\n", jogador);
            break;
        }
        if(jogadas == 9){
            MostraTabuleiro(t);
            printf("Empate!\n");
            break;
        }

        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    return 0;
}
