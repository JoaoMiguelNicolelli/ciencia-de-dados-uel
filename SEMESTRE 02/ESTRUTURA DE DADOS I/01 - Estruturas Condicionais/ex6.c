#include <stdio.h>

int main() {
    int d1, m1, a1, d2, m2, a2;

    printf("Primeira data (dia mes ano): ");
    scanf("%d %d %d", &d1, &m1, &a1);
    printf("Segunda data (dia mes ano): ");
    scanf("%d %d %d", &d2, &m2, &a2);

    if (a1 < a2 || (a1 == a2 && m1 < m2) || (a1 == a2 && m1 == m2 && d1 < d2)) {
        printf("A primeira data (%02d/%02d/%04d) ocorreu primeiro\n", d1, m1, a1);
    } else if (a1 == a2 && m1 == m2 && d1 == d2) {
        printf("As datas sao iguais\n");
    } else {
        printf("A segunda data (%02d/%02d/%04d) ocorreu primeiro\n", d2, m2, a2);
    }

    return 0;
}
