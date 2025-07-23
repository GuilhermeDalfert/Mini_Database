#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int id;
    int turma;
    float nota;
    char nome [100];
} Aluno;

extern Aluno * alunos;
extern int tamanho;
extern int capacidade;

int existeAluno (int id);
void listaAlunos ();
void insereAluno (int id, int turma, float nota, const char * nome);
void deletaAluno (int id);
void atualizaNota (int id, float novaNota);
Aluno buscaAluno (int id);
void atualizaDados(const char nomeArquivo []);

#endif