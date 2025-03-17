/**
 * @file Source.c
 * @brief Declares the source code.
 * @date 2025-03-14
 */

#include "Dados.h"
#include <stdio.h>
#include <malloc.h>		//funcao malloc()
#include <string.h>

void main() {
    Elemento* a;
}

Elemento* insereInicio(Elemento* a, Elemento* n){
    if(n==NULL) return a;

    n->next = a;
    a = n;
    return a;
}