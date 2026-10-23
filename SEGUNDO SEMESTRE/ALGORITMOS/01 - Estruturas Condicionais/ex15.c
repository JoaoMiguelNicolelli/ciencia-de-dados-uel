#include <stdio.h>

int main(){

    int hora_chegada, minuto_chegada, hora_partida, minuto_partida;
    printf("Horario de chegada (hora minuto): ");
    scanf("%d %d", &hora_chegada, &minuto_chegada);
    printf("Horario de partida (hora minuto): ");
    scanf("%d %d", &hora_partida, &minuto_partida);

    if (hora_chegada < 0 || hora_chegada > 23 || minuto_chegada < 0 || minuto_chegada > 59 || hora_partida < 0 || hora_partida > 23 || minuto_partida < 0 || minuto_partida > 59) {
        printf("Horario invalido!\n");
        return 1;
    }

    int chegada_em_minutos = hora_chegada * 60 + minuto_chegada;
    int partida_em_minutos = hora_partida * 60 + minuto_partida;

    if (partida_em_minutos < chegada_em_minutos) {
        partida_em_minutos = partida_em_minutos + 24 * 60;
    }

    int tempo_total = partida_em_minutos - chegada_em_minutos;
    int horas = tempo_total / 60;
    if (tempo_total % 60 != 0) {
        horas = horas + 1;
    }

    float preco;
    if (horas <= 2) {
        preco = horas * 1.00f;
    }
    else if (horas <= 4) {
        preco = 2 * 1.00f + (horas - 2) * 1.40f;
    }
    else {
        preco = 2 * 1.00f + 2 * 1.40f + (horas - 4) * 2.00f;
    }

    printf("Horas cobradas: %d\n", horas);
    printf("Preco do estacionamento: R$ %.2f\n", preco);

    return 0;
}
