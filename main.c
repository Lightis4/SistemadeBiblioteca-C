#include <stdio.h>
#include "livros.h"
#include "emprestimo.h"
#include "arquivos.h"

int main(void) {
    int opcao;

    carregarDados();

    do {
        printf("\n====================================\n");
        printf("     SISTEMA DE BIBLIOTECA\n");
        printf("====================================\n");

        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Pesquisar livro\n");
        printf("4 - Remover livro\n");
        printf("5 - Emprestar livro\n");
        printf("6 - Devolver livro\n");
        printf("7 - Listar emprestimos\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            int c;

            if (feof(stdin)) {
                salvarDados();
                break;
            }

            while ((c = getchar()) != '\n' && c != EOF) {
            }

            printf("Opcao invalida!\n");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }

        switch (opcao) {
            case 1:
                cadastrarLivro();
                salvarDados();
                break;

            case 2:
                listarLivros();
                break;

            case 3:
                pesquisarLivro();
                break;

            case 4:
                removerLivro();
                salvarDados();
                break;

            case 5:
                emprestarLivro();
                salvarDados();
                break;

            case 6:
                devolverLivro();
                salvarDados();
                break;

            case 7:
                listarEmprestimos();
                break;

            case 0:
                salvarDados();
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
