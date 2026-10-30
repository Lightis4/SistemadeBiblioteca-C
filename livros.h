#ifndef LIVROS_H
#define LIVROS_H

#define MAX_LIVROS 200
#define TAM_TITULO 100
#define TAM_AUTOR 100

typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int disponivel;
} Livro;

extern Livro livros[MAX_LIVROS];
extern int totalLivros;

void cadastrarLivro(void);
void listarLivros(void);
void pesquisarLivro(void);
void removerLivro(void);
int buscarIndiceLivro(int codigo);

#endif
