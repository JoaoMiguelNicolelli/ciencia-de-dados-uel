#ifndef FRACAO_H
#define FRACAO_H

typedef struct Fracao Fracao;

Fracao* criarFracao(int numerador, int denominador); //Existe uma funcao chamada 'criarFuncao' que retorna um ponteiro para uma Fracao
//Fracao* é o tipo que a funcao RETORNA
void destruirFracao(Fracao* f); //f é o nome de uma variavel
//f é uma variavel que guarda o endereco de uma Fracao
//le-se "Existe uma função chamada destruirFracao, que recebe um ponteiro para uma Fracao e não retorna nenhum valor"

Fracao* somarFracoes(Fracao* f1, Fracao* f2);
//funcao somarFracoes retorna um ponteiro para Fracao e recebe dois ponteiros para Fracao: f1 e f2"
Fracao* multiplicarFracoes(Fracao* f1, Fracao* f2);

void exibirFracao(Fracao* f);

#endif