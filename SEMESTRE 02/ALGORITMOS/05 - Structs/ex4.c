//Fiz usando vetor e for pra revisar pra prova e pra prova de EDI, dai englobou muita coisa (for/if, ponteiro, matriz, struct)

#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
} Horario;


typedef struct{
    char nome[50];
    Horario chegada;
    int urgente;
} Paciente;

int main (){

    Paciente pacientes[7];
    Paciente temp;

    for(int i = 0; i < 7; i++){

        printf("Paciente %d, digite seu nome: ");
        fgets(pacientes[i].nome, sizeof(pacientes[i].nome), stdin);
        for(int j = 0; j < sizeof(pacientes[i].nome); j++){
            if(pacientes[i].nome[j] == '\n'){
                pacientes[i].nome[j] = '\0';
                break;
            }
        }

        printf("Horario de chegada (Formato HH MM, ex: 08 30): ");
        scanf("%d %d", &pacientes[i].chegada.hora, &pacientes[i].chegada.minuto);

        printf("Eh caso urgente? (1 para Sim / 0 para Nao): ");
        scanf("%d", &pacientes[i].urgente);
        getchar();
    }

    //ordenacao por boubLle sorte
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7 - i - 1; j++){ //-1 pro [j+1] nao chegar a 7 e estourar o codigo || -i pra diminuir quantas comparações devem ser feitas

            int min_atual = (pacientes[j].chegada.hora * 60) + pacientes[j].chegada.minuto;
            int min_proximo = (pacientes[j+1].chegada.hora * 60) + pacientes[j+1].chegada.minuto;

            int troca = 0;
            if(pacientes[j+1].urgente > pacientes[j].urgente){
                troca = 1;
            }else if(pacientes[j+1].urgente == pacientes[j].urgente){
                if(min_proximo < min_atual){
                    troca = 1;
                }
            }

            if(troca){
                temp = pacientes[j];
                pacientes[j] = pacientes[j+1];
                pacientes[j+1] = temp;
            }

        }
    }

    char *status[7]; //cada elemento de status é um ponteiro para char
    for(int i = 0; i < 7; i++){
        if(pacientes[i].urgente == 1){ //pacientes[i] e não *pacientes[i] pq eh inteiro
            status[i] = "[URGENTE]"; //status[i] e não *status[i] pq queremos guardar no ponteiro o endereço da string, *status[i] é um unico char (primeiro caractere)
        }else{
            status[i] = "[NORMAL]";
        }
    }

    printf("\nFila De Atendimento\n\n");
    for(int i = 0; i < 7; i++){
        printf("%d - Nome: %s\tHorario Chegada: %02d:%02d\tUrgente: %s\n", i+1, pacientes[i].nome, pacientes[i].chegada.hora, pacientes[i].chegada.minuto, status[i]);
    }

    return 0;
}