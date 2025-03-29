#include "Dados.h"

ED* CreateAntenna(char freq, int line, int col) {
    ED* new_antena = (ED*)malloc(sizeof(ED));
    new_antena->frequency = freq;
    new_antena->coords.line = line;
    new_antena->coords.col = col;
    new_antena->next = NULL;

    return new_antena;
}

void removeAntenna(ED* head, int line, int col) {
    ED* aux = head;
    ED* prev = NULL;

    while (aux != NULL) {
        if (aux->coords.line == line && aux->coords.col == col) {
            if (prev == NULL) {
                head = aux->next;
            } else {
                prev->next = aux->next;
            }
            free(aux);
            return;
        }
        prev = aux;
        aux = aux->next;
    }
}

ED* SearchAntenna(ED* head, int line, int col) {
    ED* aux = head;
    while (aux) {
        if (aux->coords.line == line && aux->coords.col == col) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

ED* SearchAntennaByFrequency(ED* head, char frequency, int line, int col) {
    ED* aux = head;
    while (aux) {
        if (aux->coords.line == line && aux->coords.col == col && aux->frequency == frequency) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}