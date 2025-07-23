#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno * alunos = NULL;      
int tamanho = 0;           
int capacidade = 10; 

int existeAluno (int id)
{
    int sim = 1;
    int não = 0;
    for (int i = 0; i < tamanho ; i++)
    {
        if(alunos[i].id == id)
        {
            return sim;
        }
    }
    return não;
}

void listaAlunos ()
{
    for (int i = 0; i < tamanho ; i++)
    {
        printf("Aluno: %s, Turma: %d, Nota: %.2f, ID: %d.\n", alunos[i].nome, alunos[i].turma, alunos[i].nota, alunos[i].id);
    }
}

void insereAluno (int id, int turma, float nota, const char * nome)
{
    Aluno aluno;
    aluno.id = id;
    aluno.turma = turma;
    aluno.nota = nota;
    strcpy(aluno.nome, nome);
    
    if (existeAluno(id) == 1)
    {
        printf("Aluno com id (%d) já existe. Tente com outro.\n", id);
    }
    else 
    {
        alunos[tamanho] = aluno;
        tamanho++;
        if (tamanho == capacidade)
        {
            capacidade *= 2;
            Aluno * aux = realloc(alunos, capacidade * sizeof(Aluno));
            if (aux == NULL) 
            {
                printf("Erro na realocação de memória\n");
                exit(1);
            }
            else 
            {
                alunos = aux;
            }
        }
    }
}

void deletaAluno (int id)
{
    for (int i = 0; i < tamanho ; i++)
    {
        if(alunos[i].id == id)
        {
            for (int j = i; j < tamanho - 1; j++)
            {
                alunos[ j ] = alunos [j + 1];
            }
            tamanho--;
            break;
        }
    }
}

void atualizaNota (int id, float novaNota)
{
    for (int i = 0; i < tamanho ; i++)
    {
        if(alunos[i].id == id)
        {
            alunos[i].nota = novaNota;
            break;
        }
    }
}

Aluno buscaAluno (int id)
{
    for (int i = 0; i < tamanho ; i++)
    {
        if(alunos[i].id == id)
        {
            return alunos[i];
        }
    }
}

void atualizaDados (const char nomeArquivo [])
{
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }
    for (int i = 0; i < tamanho ; i++)
    {
        fprintf(arquivo, "Aluno: %s, Turma: %d, Nota: %.2f, ID: %d.\n", alunos[i].nome, alunos[i].turma, alunos[i].nota, alunos[i].id);
    }
    fclose(arquivo);
}