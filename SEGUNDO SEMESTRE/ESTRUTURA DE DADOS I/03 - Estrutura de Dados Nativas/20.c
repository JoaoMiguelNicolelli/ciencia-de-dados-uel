#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    char cargo[50];
    double salario;
    Data admissao;
} Funcionario;

int comparaDatas(Data d1, Data d2){
    if(d1.ano != d2.ano){
        return d1.ano - d2.ano;
    }
    if(d1.mes != d2.mes){
        return d1.mes - d2.mes;
    }
    return d1.dia - d2.dia;
}

int main(){

    int n;
    printf("Quantidade de funcionarios: ");
    scanf("%d", &n);

    Funcionario f[n];

    for(int i = 0; i < n; i++){
        printf("\n-Funcionario %d-\n", i+1);
        getchar(); // remove o enter deixado pelo scanf
        printf("Nome: ");
        fgets(f[i].nome, 50, stdin);
        f[i].nome[strcspn(f[i].nome, "\n")] = '\0';
        printf("Cargo: ");
        fgets(f[i].cargo, 50, stdin);
        f[i].cargo[strcspn(f[i].cargo, "\n")] = '\0';
        printf("Salario: ");
        scanf("%lf", &f[i].salario);
        printf("Data de admissao (dd mm aaaa): ");
        scanf("%d %d %d", &f[i].admissao.dia, &f[i].admissao.mes, &f[i].admissao.ano);
    }

    Data limite;
    printf("\nInforme uma data (dd mm aaaa): ");
    scanf("%d %d %d", &limite.dia, &limite.mes, &limite.ano);

    printf("\n-Admitidos antes de %02d/%02d/%04d-\n", limite.dia, limite.mes, limite.ano);
    for(int i = 0; i < n; i++){
        if(comparaDatas(f[i].admissao, limite) < 0){
            printf("%s - %s - R$ %.2f - %02d/%02d/%04d\n", f[i].nome, f[i].cargo, f[i].salario,
                   f[i].admissao.dia, f[i].admissao.mes, f[i].admissao.ano);
        }
    }

    int maisAntigo = 0;
    for(int i = 1; i < n; i++){
        if(comparaDatas(f[i].admissao, f[maisAntigo].admissao) < 0){
            maisAntigo = i;
        }
    }

    printf("\nFuncionario mais antigo: %s - %s (admitido em %02d/%02d/%04d)\n",
           f[maisAntigo].nome, f[maisAntigo].cargo,
           f[maisAntigo].admissao.dia, f[maisAntigo].admissao.mes, f[maisAntigo].admissao.ano);

    return 0;
}
