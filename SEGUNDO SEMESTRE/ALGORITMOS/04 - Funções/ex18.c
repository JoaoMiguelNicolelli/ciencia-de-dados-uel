#include <stdio.h>

int Menor(int v[], int n){
    int m;

    if(n == 1){
        return v[0];
    }
    m = Menor(v, n - 1);
    if(v[n - 1] < m){
        return v[n - 1];
    }
    return m;
}

int main(){
    int v[100], n, i;

    printf("Quantos elementos? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("Menor elemento: %d\n", Menor(v, n));

    return 0;
}
