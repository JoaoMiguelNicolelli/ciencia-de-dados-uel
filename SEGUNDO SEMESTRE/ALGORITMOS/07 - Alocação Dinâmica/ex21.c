#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double coef;
    int grau;
} Termo;

typedef struct {
    Termo *termos;  
    int n;          
} Polinomio;

Polinomio ler_polinomio(void);
Polinomio somar(Polinomio a, Polinomio b);
Polinomio multiplicar(Polinomio a, Polinomio b);
void imprimir_polinomio(Polinomio p);
void liberar_polinomio(Polinomio *p);

int ehZero(double x) {
    return fabs(x) < 1e-9;
}

void adicionaTermo(Termo *termos, int *n, double coef, int grau) {
    int i, j;

    i = 0;
    while (i < *n && termos[i].grau > grau) {
        i++;
    }

    if (i < *n && termos[i].grau == grau) {
        termos[i].coef = termos[i].coef + coef;
    } else {
        for (j = *n; j > i; j--) {
            termos[j] = termos[j - 1];
        }
        termos[i].coef = coef;
        termos[i].grau = grau;
        (*n)++;
    }
}

void ajustaPolinomio(Polinomio *p) {
    int i, k;
    Termo *aux;

    k = 0;
    for (i = 0; i < p->n; i++) {
        if (!ehZero(p->termos[i].coef)) {
            p->termos[k] = p->termos[i];
            k++;
        }
    }
    p->n = k;

    if (k == 0) {
        free(p->termos);
        p->termos = NULL;
        return;
    }

    aux = (Termo *) realloc(p->termos, k * sizeof(Termo));
    if (aux != NULL) {
        p->termos = aux;
    }
}

Polinomio ler_polinomio(void) {
    Polinomio p;
    int qtd, i, grau;
    double coef;

    p.termos = NULL;
    p.n = 0;

    printf("Quantidade de termos: ");
    scanf("%d", &qtd);
    if (qtd <= 0) {
        return p;
    }

    p.termos = (Termo *) malloc(qtd * sizeof(Termo));
    if (p.termos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return p;
    }

    for (i = 0; i < qtd; i++) {
        do {
            printf("Termo %d (coeficiente grau): ", i + 1);
            scanf("%lf %d", &coef, &grau);
            if (grau < 0) {
                printf("Grau invalido.\n");
            }
        } while (grau < 0);
        adicionaTermo(p.termos, &p.n, coef, grau);
    }

    ajustaPolinomio(&p);

    return p;
}

Polinomio somar(Polinomio a, Polinomio b) {
    Polinomio s;
    int i;

    s.termos = NULL;
    s.n = 0;
    if (a.n + b.n == 0) {
        return s;
    }

    s.termos = (Termo *) malloc((a.n + b.n) * sizeof(Termo));
    if (s.termos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return s;
    }

    for (i = 0; i < a.n; i++) {
        adicionaTermo(s.termos, &s.n, a.termos[i].coef, a.termos[i].grau);
    }
    for (i = 0; i < b.n; i++) {
        adicionaTermo(s.termos, &s.n, b.termos[i].coef, b.termos[i].grau);
    }

    ajustaPolinomio(&s);

    return s;
}

Polinomio multiplicar(Polinomio a, Polinomio b) {
    Polinomio m;
    int i, j;

    m.termos = NULL;
    m.n = 0;
    if (a.n == 0 || b.n == 0) {
        return m;
    }

    m.termos = (Termo *) malloc(a.n * b.n * sizeof(Termo));
    if (m.termos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return m;
    }

    for (i = 0; i < a.n; i++) {
        for (j = 0; j < b.n; j++) {
            adicionaTermo(m.termos, &m.n, a.termos[i].coef * b.termos[j].coef, a.termos[i].grau + b.termos[j].grau);
        }
    }

    ajustaPolinomio(&m);

    return m;
}

void imprimir_polinomio(Polinomio p) {
    int i;
    double c;

    if (p.n == 0) {
        printf("0\n");
        return;
    }

    for (i = 0; i < p.n; i++) {
        c = p.termos[i].coef;
        if (i == 0) {
            if (c < 0) {
                printf("-");
            }
        } else {
            if (c < 0) {
                printf(" - ");
            } else {
                printf(" + ");
            }
        }

        c = fabs(c);
        if (p.termos[i].grau == 0 || !ehZero(c - 1)) {
            printf("%g", c);
        }
        if (p.termos[i].grau == 1) {
            printf("x");
        } else if (p.termos[i].grau > 1) {
            printf("x^%d", p.termos[i].grau);
        }
    }
    printf("\n");
}

void liberar_polinomio(Polinomio *p) {
    free(p->termos);
    p->termos = NULL;
    p->n = 0;
}

int main() {
    Polinomio a, b, soma, produto;

    printf("Polinomio A\n");
    a = ler_polinomio();
    printf("\nPolinomio B\n");
    b = ler_polinomio();

    soma = somar(a, b);
    produto = multiplicar(a, b);

    printf("\nA(x) = ");
    imprimir_polinomio(a);
    printf("B(x) = ");
    imprimir_polinomio(b);
    printf("A + B = ");
    imprimir_polinomio(soma);
    printf("A x B = ");
    imprimir_polinomio(produto);

    liberar_polinomio(&a);
    liberar_polinomio(&b);
    liberar_polinomio(&soma);
    liberar_polinomio(&produto);

    return 0;
}
