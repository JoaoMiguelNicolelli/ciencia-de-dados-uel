#include <stdio.h>

double Euler(int n){
    double e = 0, fat = 1;
    int i;

    for(i = 0; i < n; i++){
        if(i > 0){
            fat = fat * i;
        }
        e = e + 1 / fat;
    }
    return e;
}

int main(){
    int n;

    printf("Digite o numero de termos: ");
    scanf("%d", &n);

    printf("e = %.8f\n", Euler(n));

    return 0;
}
