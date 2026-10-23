#include <stdio.h>

int main(){

    int n, m;

    printf("Digite n: ");
    scanf("%d", &n);
    printf("Digite m: ");
    scanf("%d", &m);

    int x = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            x += i + j;
        }
    }

    printf("x = %d\n", x);

    return 0;
}
