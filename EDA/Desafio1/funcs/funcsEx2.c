/**
 * @file funcsEx2.c
 * @brief Implementação das funções de cálculo de soma, subtração, divisão e valor absoluto.
 * @date 2025-02-21
 */

#include <stdio.h>
#include "funcsEx2.h"

int Soma(int a, int b) {
    return (a + b);
}

int Subtracao(int a, int b) {
    return (a - b);
}

int Divisao(int a, int b) {
    return (a / b);
}

int ValorAbsoluto(int a, int b) {
    int diff = a - b;
    return (diff < 0) ? -diff : diff;
}

void StartCalculator() {
    int a, b;
    printf("Vamos à matemática agora. Insira os numeros que quer calcular: \n");
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);

    printf("Soma: %d\n", Soma(a, b));
    printf("Subtração: %d\n", Subtracao(a, b));
    printf("Divisão: %d\n", Divisao(a, b));
    printf("Valor Absoluto: %d\n", ValorAbsoluto(a, b));
}

