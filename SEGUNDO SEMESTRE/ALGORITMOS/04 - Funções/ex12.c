#include <stdio.h>

int SomaCubos(int n){
    if(n == 0){
        return 0;
    }
    return n * n * n + SomaCubos(n - 1);
}

int main(){
    int n;

    printf("Digite n: ");
    scanf("%d", &n);

    printf("Soma dos cubos: %d\n", SomaCubos(n));

    return 0;
}
