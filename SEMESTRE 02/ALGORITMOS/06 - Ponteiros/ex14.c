#include <stdio.h>

void converte_tempo(int total, int *horas, int *minutos, int *segundos){
    *horas = total / 3600;
    *minutos = (total % 3600) / 60;
    *segundos = total % 60;
}

int main(){
    int total, h, m, s;

    printf("Total de segundos: ");
    scanf("%d", &total);

    converte_tempo(total, &h, &m, &s);

    printf("Horario: %02d:%02d:%02d\n", h, m, s);

    return 0;
}
