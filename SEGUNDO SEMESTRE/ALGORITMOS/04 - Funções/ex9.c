#include <stdio.h>

int Arredonda(float x){
    if(x >= 0){
        return (int)(x + 0.5);
    }
    return (int)(x - 0.5);
}

int main(){
    float x;

    printf("Digite um valor: ");
    scanf("%f", &x);

    printf("Arredondado: %d\n", Arredonda(x));

    return 0;
}
