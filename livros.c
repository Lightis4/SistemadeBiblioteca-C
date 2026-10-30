#include <stdio.h>
#include <string.h>
#include "livros.h"

Livro livros[MAX_LIVROS];
int totalLivros = 0;

static void limparEntrada(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

static void lerTexto(char texto[], int tamanho) {
    if (fgets(texto, tamanho, stdin) != NULL) {
        size_t pos = strcspn(texto, "\n");

        if (texto[pos] == '\n') {
            texto[pos] = '\0';
        } else {
            limparEntrada();
        }
    } else {
        texto[0] = '\0';
    }
}

int buscarIndiceLivro(int codigo) {
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void cadastrarLivro(void) {
    if (totalLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido!\n");
        return;
    }

    Livro novo;

    printf("\n=== CADASTRAR LIVRO ===\n");

    printf("Codigo: ");
    if (scanf("%d", &novo.codigo) != 1) {
        limparEntrada();
        printf("Codigo invalido!\n");
        return;
    }
    limparEntrada();

    if (novo.codigo <= 0 ||
        buscarIndiceLivro(novo.codigo) != -1) {
        printf("Codigo invalido ou ja cadastrado!\n");
        return;
    }

    printf("Titulo: ");
    lerTexto(novo.titulo, TAM_TITULO);

    printf("Autor: ");
    lerTexto(novo.autor, TAM_AUTOR);

    if (strlen(novo.titulo) == 0 ||
        strlen(novo.autor) == 0) {
        printf("Titulo e autor sao obrigatorios!\n");
        return;
    }

    printf("Ano de publicacao: ");
    if (scanf("%d", &novo.ano) != 1) {
        limparEntrada();
        printf("Ano invalido!\n");
        return;
    }
    limparEntrada();

    if (novo.ano <= 0) {
        printf("Ano invalido!\n");
        return;
    }

    novo.disponivel = 1;

    livros[totalLivros] = novo;
    totalLivros++;

    printf("Livro cadastrado com sucesso!\n");
}

void listarLivros(void) {
    printf("\n=== LISTA DE LIVROS ===\n");

    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalLivros; i++) {
        printf("\nCodigo: %d\n", livros[i].codigo);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano: %d\n", livros[i].ano);

        printf("Status: %s\n",
               livros[i].disponivel
                   ? "Disponivel"
                   : "Emprestado");
    }
}

void pesquisarLivro(void) {
    int codigo;

    printf("\nDigite o codigo do livro: ");

    if (scanf("%d", &codigo) != 1) {
        limparEntrada();
        printf("Codigo invalido!\n");
        return;
    }
    limparEntrada();

    int indice = buscarIndiceLivro(codigo);

    if (indice == -1) {
        printf("Livro nao encontrado!\n");
        return;
    }

    printf("\nTitulo: %s\n", livros[indice].titulo);
    printf("Autor: %s\n", livros[indice].autor);
    printf("Ano: %d\n", livros[indice].ano);
    printf("Status: %s\n",
           livros[indice].disponivel
               ? "Disponivel"
               : "Emprestado");
}

void removerLivro(void) {
    int codigo;

    printf("\nCodigo do livro para remover: ");

    if (scanf("%d", &codigo) != 1) {
        limparEntrada();
        printf("Codigo invalido!\n");
        return;
    }
    limparEntrada();

    int indice = buscarIndiceLivro(codigo);

    if (indice == -1) {
        printf("Livro nao encontrado!\n");
        return;
    }

    if (!livros[indice].disponivel) {
        printf("Nao e possivel remover livro emprestado!\n");
        return;
    }

    for (int i = indice; i < totalLivros - 1; i++) {
        livros[i] = livros[i + 1];
    }

    totalLivros--;

    printf("Livro removido com sucesso!\n");
}
