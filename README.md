# 📚 Sistema de Gerenciamento de Biblioteca em C

Sistema de gerenciamento de biblioteca desenvolvido em **linguagem C**, utilizando os conceitos de **programação modular**, estruturas de dados e manipulação de arquivos.

O projeto tem como objetivo simular o funcionamento de uma biblioteca, permitindo o cadastro e gerenciamento de livros, além do controle de empréstimos e devoluções.

## 🚀 Funcionalidades

- **Cadastro de livros:** permite registrar livros com código, título, autor e ano de publicação.
- **Listagem de livros:** exibe todos os livros cadastrados e sua disponibilidade.
- **Pesquisa de livros:** localiza livros por meio de um código identificador.
- **Remoção de livros:** permite excluir livros que não estejam emprestados.
- **Empréstimo de livros:** registra o nome do leitor e altera a disponibilidade do livro.
- **Devolução de livros:** finaliza o empréstimo e torna o livro disponível novamente.
- **Consulta de empréstimos:** apresenta os empréstimos ativos.
- **Persistência de dados:** salva e recupera informações automaticamente utilizando arquivos `.txt`.

## 🛠️ Tecnologias utilizadas

- **Linguagem C:** desenvolvimento do sistema.
- **GCC:** compilação do código-fonte.
- **MSYS2/MinGW:** ambiente de compilação no Windows.
- **Visual Studio Code:** ambiente de desenvolvimento.
- **Git e GitHub:** versionamento e armazenamento do projeto.

## 📂 Estrutura do projeto

```text
Sistema_Biblioteca_C/
│
├── main.c
├── livros.c
├── livros.h
├── emprestimos.c
├── emprestimos.h
├── arquivos.c
├── arquivos.h
├── README.md
└── .gitignore
```

### Organização dos módulos

| Arquivo         | Responsabilidade                                               |
| --------------- | -------------------------------------------------------------- |
| `main.c`        | Controla o menu principal e a execução do sistema.             |
| `livros.c`      | Implementa o cadastro, listagem, pesquisa e remoção de livros. |
| `livros.h`      | Declara a estrutura `Livro` e suas funções.                    |
| `emprestimos.c` | Implementa empréstimos, devoluções e consultas.                |
| `emprestimos.h` | Declara a estrutura `Emprestimo` e suas funções.               |
| `arquivos.c`    | Realiza o salvamento e carregamento dos dados.                 |
| `arquivos.h`    | Declara as funções de persistência.                            |

## 🧩 Programação modular

A programação modular consiste em dividir um sistema em módulos independentes, cada um responsável por determinadas funcionalidades.

Neste projeto, utilizamos:

- **Arquivos `.c`:** contêm a implementação das funções.
- **Arquivos `.h`:** contêm declarações de funções, estruturas e constantes.
- **`#include`:** permite utilizar declarações de outros módulos.
- **`struct`:** organiza informações relacionadas em um único tipo de dado.

Essa organização facilita a manutenção, reutilização e compreensão do código.

## 💻 Como executar o projeto

### 1. Pré-requisitos

É necessário possuir:

- Visual Studio Code instalado.
- Compilador GCC configurado.
- Git instalado, caso deseje clonar o repositório.

### 2. Clonar o repositório

Abra o terminal e execute:

```bash
git clone https://github.com/Lightis4/SistemadeBiblioteca-C.git
```

Acesse a pasta:

```bash
cd SistemadeBiblioteca-C
```

### 3. Compilar o programa

Execute:

```bash
gcc -Wall -Wextra -std=c11 main.c livros.c emprestimos.c arquivos.c -o biblioteca.exe
```

### 4. Executar o programa

No terminal PowerShell:

```powershell
.\biblioteca.exe
```

## 📋 Menu principal

```text
====================================
     SISTEMA DE BIBLIOTECA
====================================

1 - Cadastrar livro
2 - Listar livros
3 - Pesquisar livro
4 - Remover livro
5 - Emprestar livro
6 - Devolver livro
7 - Listar emprestimos
0 - Sair

Escolha uma opcao:
```

## 💾 Armazenamento dos dados

O sistema utiliza dois arquivos de texto:

- `livros.txt`: armazena os livros cadastrados.
- `emprestimos.txt`: armazena os registros de empréstimos.

Os dados são carregados quando o programa inicia e salvos após as operações de alteração.

Não é necessário utilizar um banco de dados externo.

## 📖 Conceitos aplicados

Durante o desenvolvimento, foram utilizados:

- Variáveis e tipos de dados.
- Estruturas condicionais (`if`, `else`, `switch`).
- Estruturas de repetição (`for`, `while`, `do while`).
- Funções e parâmetros.
- Arrays.
- Estruturas (`struct`).
- Ponteiros.
- Programação modular.
- Manipulação de arquivos.
- Validação de entradas.

## ⚙️ Limitações

O sistema foi desenvolvido para fins educacionais e possui algumas limitações:

- Capacidade máxima de 200 livros.
- Capacidade de 200 registros de empréstimo em memória, com reutilização dos registros encerrados.
- Interface baseada em terminal.
- Armazenamento local em arquivos de texto.
- Não possui autenticação de usuários nem histórico completo de empréstimos.

## 🎯 Objetivo do projeto

Aplicar os conhecimentos adquiridos em linguagem C, com foco na organização do código por módulos e na construção de um sistema funcional.

O projeto também busca desenvolver habilidades de lógica de programação, manipulação de dados e versionamento com Git.

## 👨‍💻 Desenvolvedor

**Pedro Henrique Barbosa Nogueira**

Estudante de Ciências da Computação.

GitHub: [Lightis4](https://github.com/Lightis4)

---

Projeto desenvolvido para fins de estudo e aperfeiçoamento em programação na linguagem C.
