#include <stdio.h>

int Segundos(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

int main(){
    int h, m, s;

    printf("Digite horas, minutos e segundos: ");
    scanf("%d %d %d", &h, &m, &s);

    printf("Total em segundos: %d\n", Segundos(h, m, s));

    return 0;
}
