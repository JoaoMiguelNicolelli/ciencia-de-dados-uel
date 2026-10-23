#include <stdio.h>

float Media(float n1, float n2, float n3, char letra){
    if(letra == 'A' || letra == 'a'){
        return (n1 + n2 + n3) / 3;
    }
    return (n1 * 5 + n2 * 3 + n3 * 2) / 10;
}

int main(){
    float n1, n2, n3;
    char letra;

    printf("Digite as tres notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    printf("Digite A (aritmetica) ou P (ponderada): ");
    scanf(" %c", &letra);

    printf("Media: %.2f\n", Media(n1, n2, n3, letra));

    return 0;
}
