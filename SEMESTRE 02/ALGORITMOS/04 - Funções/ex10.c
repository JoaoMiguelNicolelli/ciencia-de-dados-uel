#include <stdio.h>

int ContaDigitos(int n, int d){
    int cont = 0;

    while(n > 0){
        if(n % 10 == d){
            cont++;
        }
        n = n / 10;
    }
    return cont;
}

int main(){
    int a, b, d, permutacao = 1;

    printf("Digite a e b: ");
    scanf("%d %d", &a, &b);

    for(d = 1; d <= 9; d++){
        if(ContaDigitos(a, d) != ContaDigitos(b, d)){
            permutacao = 0;
        }
    }

    if(permutacao){
        printf("%d e permutacao de %d\n", a, b);
    }else{
        printf("%d nao e permutacao de %d\n", a, b);
    }

    return 0;
}
