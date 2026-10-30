#include <stdio.h>
#include <string.h>
#include "livros.h"
#include "emprestimo.h"

Emprestimo emprestimos[MAX_EMPRESTIMOS];
int totalEmprestimos = 0;

static void limparEntrada(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int buscarEmprestimoAtivo(int codigoLivro) {
    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].codigoLivro == codigoLivro &&
            emprestimos[i].ativo == 1) {
            return i;
        }
    }

    return -1;
}

void emprestarLivro(void) {
    int codigo;

    printf("\n=== EMPRESTAR LIVRO ===\n");
    printf("Codigo do livro: ");

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

    if (livros[indice].disponivel == 0) {
        printf("Livro ja esta emprestado!\n");
        return;
    }

    // Reutiliza uma posicao de emprestimo encerrado.
    int posicao = -1;

    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].ativo == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        if (totalEmprestimos >= MAX_EMPRESTIMOS) {
            printf("Limite de emprestimos atingido!\n");
            return;
        }

        posicao = totalEmprestimos;
        totalEmprestimos++;
    }

    Emprestimo novo;
    novo.codigoLivro = codigo;
    novo.ativo = 1;

    printf("Nome do leitor: ");

    if (fgets(novo.nomeLeitor, TAM_LEITOR, stdin)
        == NULL) {
        printf("Erro ao ler o nome!\n");
        return;
    }

    size_t pos = strcspn(novo.nomeLeitor, "\n");

    if (novo.nomeLeitor[pos] == '\n') {
        novo.nomeLeitor[pos] = '\0';
    } else {
        limparEntrada();
    }

    if (strlen(novo.nomeLeitor) == 0) {
        printf("Nome do leitor obrigatorio!\n");
        return;
    }

    emprestimos[posicao] = novo;
    livros[indice].disponivel = 0;

    printf("Emprestimo realizado com sucesso!\n");
}

void devolverLivro(void) {
    int codigo;

    printf("\n=== DEVOLVER LIVRO ===\n");
    printf("Codigo do livro: ");

    if (scanf("%d", &codigo) != 1) {
        limparEntrada();
        printf("Codigo invalido!\n");
        return;
    }
    limparEntrada();

    int indiceLivro = buscarIndiceLivro(codigo);
    int indiceEmprestimo = buscarEmprestimoAtivo(codigo);

    if (indiceLivro == -1 || indiceEmprestimo == -1) {
        printf("Emprestimo ativo nao encontrado!\n");
        return;
    }

    emprestimos[indiceEmprestimo].ativo = 0;
    livros[indiceLivro].disponivel = 1;

    printf("Livro devolvido com sucesso!\n");
}

void listarEmprestimos(void) {
    int encontrados = 0;

    printf("\n=== EMPRESTIMOS ATIVOS ===\n");

    for (int i = 0; i < totalEmprestimos; i++) {
        if (emprestimos[i].ativo == 1) {
            printf("\nCodigo do livro: %d\n",
                   emprestimos[i].codigoLivro);

            printf("Leitor: %s\n",
                   emprestimos[i].nomeLeitor);

            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum emprestimo ativo.\n");
    }
}
