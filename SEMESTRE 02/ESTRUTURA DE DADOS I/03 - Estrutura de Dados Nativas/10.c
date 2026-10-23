#include <stdio.h>

// Retorna 'X' ou 'O' se houver vencedor, ou ' ' se nao houver
char vencedor(char tab[3][3]){

    for(int i = 0; i < 3; i++){
        // linhas
        if(tab[i][0] != ' ' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]){
            return tab[i][0];
        }
        // colunas
        if(tab[0][i] != ' ' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]){
            return tab[0][i];
        }
    }

    // diagonal principal
    if(tab[0][0] != ' ' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]){
        return tab[0][0];
    }

    // diagonal secundaria
    if(tab[0][2] != ' ' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]){
        return tab[0][2];
    }

    return ' ';
}

int main(){

    char tabuleiro[3][3] = {
        {'X', 'O', ' '},
        {'O', 'X', ' '},
        {'O', ' ', 'X'}
    };

    printf("-Tabuleiro-\n");
    for(int i = 0; i < 3; i++){
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if(i < 2){
            printf("---+---+---\n");
        }
    }

    char v = vencedor(tabuleiro);

    if(v == ' '){
        printf("\nNao ha vencedor.\n");
    }else{
        printf("\nVencedor: %c\n", v);
    }

    return 0;
}
