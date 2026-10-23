#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

struct Fracao{
    int numerador;
    int denominador;
};

int MDC(int a, int b){
    if(a<0){
        a = -a;
    }

    if(b<0){
        b = -b;
    }

    while(b != 0){
        int resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

Fracao* criarFracao(int numerador, int denominador){
    if(denominador == 0){
        return NULL;
    }

    if(denominador < 0){
        numerador = -numerador;
        denominador = -denominador;
    }

    Fracao* f = malloc(sizeof(Fracao));
    int divisor = mdc(numerador, denominador);

    f -> numerador = numerador / divisor;
    f -> denominador = denominador / divisor;

    return f;
}