#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
    int segundo;
} Horario;

int paraSegundos(Horario h){
    return h.hora * 3600 + h.minuto * 60 + h.segundo;
}

Horario paraHorario(int totalSegundos){
    Horario h;
    h.hora = totalSegundos / 3600;
    h.minuto = (totalSegundos % 3600) / 60;
    h.segundo = totalSegundos % 60;
    return h;
}

void exibeHorario(Horario h){
    printf("%02d:%02d:%02d\n", h.hora, h.minuto, h.segundo);
}

int main(){

    Horario h;
    printf("Hora: ");
    scanf("%d", &h.hora);
    printf("Minuto: ");
    scanf("%d", &h.minuto);
    printf("Segundo: ");
    scanf("%d", &h.segundo);

    printf("\nHorario digitado: ");
    exibeHorario(h);

    int total = paraSegundos(h);
    printf("Segundos desde a meia-noite: %d\n", total);

    int seg;
    printf("\nDigite um total de segundos: ");
    scanf("%d", &seg);

    Horario convertido = paraHorario(seg);
    printf("Horario: ");
    exibeHorario(convertido);

    return 0;
}
