#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#define MAX_EMPRESTIMOS 200
#define TAM_LEITOR 100

typedef struct {
    int codigoLivro;
    char nomeLeitor[TAM_LEITOR];
    int ativo;
} Emprestimo;

extern Emprestimo emprestimos[MAX_EMPRESTIMOS];
extern int totalEmprestimos;

void emprestarLivro(void);
void devolverLivro(void);
void listarEmprestimos(void);
int buscarEmprestimoAtivo(int codigoLivro);

#endif
