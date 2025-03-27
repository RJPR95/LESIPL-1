#include "Dados.h"

ED* CriarAntena(char freq, int linha, int coluna) {
    ED* new_antena = (ED*)malloc(sizeof(ED));
    new_antena->frequency = freq;
    new_antena->coords.linha = linha;
    new_antena->coords.coluna = coluna;
    new_antena->next = NULL;

    return new_antena;
}

ED* ProcurarAntena(ED* head, char frequency, int linha, int coluna) {
    ED* aux = head;
    while (aux) {
        // printf("Frequency: %d | %d\n", linha, aux->coords.linha);
        if (aux->coords.linha == linha && aux->coords.coluna == coluna && aux->frequency == frequency) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}