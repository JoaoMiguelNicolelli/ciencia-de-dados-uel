#include <stdio.h>

float Serie(int n){
    if(n == 1){
        return 2;
    }
    return (1.0 + n * n) / n + Serie(n - 1);
}

int main(){
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    printf("S = %.4f\n", Serie(n));

    return 0;
}
