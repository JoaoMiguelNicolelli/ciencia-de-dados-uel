#include <stdio.h>

void mm(int *v, int n, int *min, int *max){
    int *p = v;
    int *fim = v + n;

    *min = *p;
    *max = *p;

    while (p < fim) {
        if (*p < *min) {
            *min = *p;
        }
        if (*p > *max) {
            *max = *p;
        }
        p++;
    }
}

int main(){
    int n, min, max;

    printf("Quantos elementos? ");
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }

    mm(vetor, n, &min, &max);

    printf("\nMenor valor: %d\n", min);
    printf("Maior valor: %d\n", max);

    return 0;
}
