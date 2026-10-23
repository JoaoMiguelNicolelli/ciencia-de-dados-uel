#include <stdio.h>

int Potencia(int x, int y){
    if(y == 0){
        return 1;
    }
    return x * Potencia(x, y - 1);
}

int main(){
    int x, y;

    printf("Digite x e y: ");
    scanf("%d %d", &x, &y);

    printf("%d elevado a %d = %d\n", x, y, Potencia(x, y));

    return 0;
}
