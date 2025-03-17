/**
 * @file Source.c
 * @brief Declares the source code.
 * @date 2025-03-11
 */

#include "Dados.h"
#include <stdio.h>
#include <malloc.h>		//funcao malloc()
#include <string.h>

void main() {
    Elemento x;

    x.num = 12;
    x.next = NULL;

    Elemento y;
    y.num = 27;
    y.next = NULL;

    x.next = &y;

    Elemento *pt;
    pt = (Elemento*)malloc(sizeof(Elemento));

    pt->next = &x;

    printf("Num x: %d\n", x.num);
    printf("Num y: %d\n", y.num);
    printf("Num y a partir de x: %d\n", x.next->num);
    printf("Num x a partir de pt: %d\n", pt->next->num);
    printf("Num y a partir de pt: %d\n\n", pt->next->next->num);

    Elemento* aux; // Variável auxiliar para percorrer a lista.
    aux = &x; // Inicializa a variável auxiliar com o endereço do primeiro elemento da lista.
    while(aux != NULL) { // Enquanto a variável auxiliar não for nula.
        printf("Num: %d\n", aux->num); // Imprime o número do elemento.
        aux = aux->next; // Avança para o próximo elemento.
    }

    free(pt);
}