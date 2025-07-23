# Banco de Dados de Alunos em C

Este projeto é um sistema rudimentar de banco de dados programado em linguagem C, que permite manipular informações de alunos armazenadas em um arquivo de texto (`dados.txt`).

## Funcionalidades

- Adicionar alunos
- Remover alunos
- Atualizar a nota de alunos
- Buscar alunos por ID

## Estrutura

- `main.c` — Interface principal para executar as funcionalidades.
- `aluno.c` — Implementação das operações do banco de dados.
- `aluno.h` — Cabeçalho com as declarações das funções.
- `dados.txt` — Arquivo onde os dados dos alunos são salvos de forma persistente.

## Como Compilar

Use no terminal para compilar:
- gcc main.c aluno.c -o programa

Para Executar:
- ./programa

## Observações

- O programa utiliza alocação dinâmica de memória com malloc e realloc.
- As strings são manipuladas com strcpy para evitar atribuições diretas de arrays.
- O arquivo dados.txt é recriado a cada alteração nos dados (adição, remoção ou atualização).
- As funções seguem uma estrutura modular, separando a lógica de manipulação dos dados (aluno.c) da interface principal (main.c).