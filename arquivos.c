#include <stdio.h>
#include <string.h>
#include "livros.h"
#include "emprestimo.h"
#include "arquivos.h"

void salvarDados(void) {
    FILE *arquivo = fopen("livros.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar livros!\n");
        return;
    }

    fprintf(arquivo, "%d\n", totalLivros);

    for (int i = 0; i < totalLivros; i++) {
        fprintf(arquivo, "%d\n", livros[i].codigo);
        fprintf(arquivo, "%s\n", livros[i].titulo);
        fprintf(arquivo, "%s\n", livros[i].autor);
        fprintf(arquivo, "%d\n", livros[i].ano);
        fprintf(arquivo, "%d\n", livros[i].disponivel);
    }

    fclose(arquivo);

    arquivo = fopen("emprestimos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar emprestimos!\n");
        return;
    }

    fprintf(arquivo, "%d\n", totalEmprestimos);

    for (int i = 0; i < totalEmprestimos; i++) {
        fprintf(arquivo, "%d\n",
                emprestimos[i].codigoLivro);

        fprintf(arquivo, "%s\n",
                emprestimos[i].nomeLeitor);

        fprintf(arquivo, "%d\n",
                emprestimos[i].ativo);
    }

    fclose(arquivo);
}

void carregarDados(void) {
    FILE *arquivo = fopen("livros.txt", "r");

    if (arquivo != NULL) {
        int quantidade;

        if (fscanf(arquivo, "%d\n", &quantidade) == 1 &&
            quantidade >= 0 &&
            quantidade <= MAX_LIVROS) {

            totalLivros = 0;

            for (int i = 0; i < quantidade; i++) {
                Livro livro;

                if (fscanf(arquivo, "%d\n",
                           &livro.codigo) != 1) break;

                if (fgets(livro.titulo,
                          TAM_TITULO, arquivo) == NULL) break;

                livro.titulo[
                    strcspn(livro.titulo, "\n")
                ] = '\0';

                if (fgets(livro.autor,
                          TAM_AUTOR, arquivo) == NULL) break;

                livro.autor[
                    strcspn(livro.autor, "\n")
                ] = '\0';

                if (fscanf(arquivo, "%d\n",
                           &livro.ano) != 1) break;

                if (fscanf(arquivo, "%d\n",
                           &livro.disponivel) != 1) break;

                livros[totalLivros] = livro;
                totalLivros++;
            }
        }

        fclose(arquivo);
    }

    arquivo = fopen("emprestimos.txt", "r");

    if (arquivo != NULL) {
        int quantidade;

        if (fscanf(arquivo, "%d\n", &quantidade) == 1 &&
            quantidade >= 0 &&
            quantidade <= MAX_EMPRESTIMOS) {

            totalEmprestimos = 0;

            for (int i = 0; i < quantidade; i++) {
                Emprestimo emprestimo;

                if (fscanf(arquivo, "%d\n",
                           &emprestimo.codigoLivro) != 1) break;

                if (fgets(emprestimo.nomeLeitor,
                          TAM_LEITOR, arquivo) == NULL) break;

                emprestimo.nomeLeitor[
                    strcspn(emprestimo.nomeLeitor, "\n")
                ] = '\0';

                if (fscanf(arquivo, "%d\n",
                           &emprestimo.ativo) != 1) break;

                emprestimos[totalEmprestimos] = emprestimo;
                totalEmprestimos++;
            }
        }

        fclose(arquivo);
    }
}
