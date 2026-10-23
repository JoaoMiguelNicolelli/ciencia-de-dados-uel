#include <stdio.h>

int Duracao(int hi, int mi, int hf, int mf){
    int inicio = hi * 60 + mi;
    int fim = hf * 60 + mf;

    if(fim <= inicio){
        fim = fim + 24 * 60;
    }
    return fim - inicio;
}

int main(){
    int hi, mi, hf, mf;

    printf("Hora e minuto de inicio: ");
    scanf("%d %d", &hi, &mi);

    printf("Hora e minuto de termino: ");
    scanf("%d %d", &hf, &mf);

    printf("Duracao do jogo: %d minutos\n", Duracao(hi, mi, hf, mf));

    return 0;
}
