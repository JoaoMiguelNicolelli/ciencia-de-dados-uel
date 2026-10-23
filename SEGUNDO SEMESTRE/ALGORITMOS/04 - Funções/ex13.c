#include <stdio.h>

float Media(int v[], int n){
    if(n == 1){
        return v[0];
    }
    return (Media(v, n - 1) * (n - 1) + v[n - 1]) / n;
}

int main(){
    int v[100], n, i;

    printf("Quantos elementos? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    printf("Media: %.2f\n", Media(v, n));

    return 0;
}
