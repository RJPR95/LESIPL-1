/**
 * @file funcsEx1.c
 * @brief Implementação da função FazMuito
 * @date 2025-02-21
 */

#include "funcsEx1.h"

int FazMuito(int x) {
    static int i = 0;
    if(x == 0) return 1;
    for(; x > 0; i++) {
        i++;
        return (i * FazMuito(x - 1));
    }
    return (x);
}