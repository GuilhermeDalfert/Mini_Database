#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main() 
{
    alunos = malloc(capacidade * sizeof(Aluno));
    if (alunos == NULL) 
    {
        printf("Erro na alocação de memória\n");
        exit(1);
    }
        
    insereAluno(1, 30, 8.7, "Fabiano Costa");
    insereAluno(2, 30, 9.7, "Cláudia Menez");
    insereAluno(3, 31, 9.1, "Renato Cariani");

    atualizaDados("dados.txt");

    free(alunos);
    alunos = NULL;

    return 0;
}