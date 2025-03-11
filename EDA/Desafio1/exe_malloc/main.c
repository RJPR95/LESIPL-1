#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    int num;
    char nome[20]; // char *nome; ?
} Aluno;

struct Aluno x;

struct Aluno *p = &x;

int main(){
    p->num = 10;
    p->nome = "Joao"; 
    printf("Numero novo: %d\n", p->num);
    printf("Nome novo: %s\n", p->nome);
    return 0;
}