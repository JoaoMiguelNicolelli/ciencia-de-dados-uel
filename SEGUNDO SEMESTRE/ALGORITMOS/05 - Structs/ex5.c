 #include <stdio.h>

 typedef struct{
    char titulo[31];
    char autor[16];
    int ano;
 } Livro;

int main (){

    Livro livros[5];

    for(int i = 0; i < 5; i++){

        printf("%d livro - Nome: ", i+1);
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
        for(int j = 0; livros[i].titulo[j] != '\0'; j++){
            if(livros[i].titulo[j] == '\n'){
                livros[i].titulo[j] = '\0';
                break;
            }
        }
    
        printf("Autor: ");
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
        for(int h = 0; livros[i].autor[h] != '\0'; h++){
            if(livros[i].autor[h] == '\n'){
                livros[i].autor[h] = '\0';
                break;
            }
        }

        printf("Ano de publicacao: ");
        scanf("%d", &livros[i].ano);
        getchar();
        printf("\n");
    }

    char procura[31];
    printf("Digite o livro que esta procurando: ");
    fgets(procura, sizeof(procura), stdin);
    for(int i = 0; i < sizeof(procura); i++){
        if(procura[i] == '\n'){
            procura[i] = '\0';
        }
    }

    int encontrado = 0;

    for(int i = 0; i < 5; i++){

        int iguais = 1;
        for(int j = 0; procura[j] != '\0' || livros[i].titulo[j] != '\0'; j++){
            if(procura[j] != livros[i].titulo[j]){
                iguais = 0;
                break;
            }
        }

        if(iguais){
            printf("\nLivro encontrado!\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano: %d\n", livros[i].ano);

            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("\nLivro nao encontrado.\n");
    }

    return 0;
}