#include <stdio.h>

int Inverte(int n, int inv){
    if(n == 0){
        return inv;
    }
    return Inverte(n / 10, inv * 10 + n % 10);
}

int main(){
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("Invertido: %d\n", Inverte(n, 0));

    return 0;
}
