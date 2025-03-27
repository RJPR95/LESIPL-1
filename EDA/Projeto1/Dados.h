/**
 * @file Dados.h
 * @brief Declares the dados.
 * @author Raul Ribeiro
 * @date 2025-03-18
 * @version 1.0
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINHAS 10
#define MAX_COLUNAS 10

/**
 * @brief The coordinates.
 * @param linha The line.
 * @param coluna The column.
 */
typedef struct Coords {
    int linha;
    int coluna;
} Coords;

/**
 * @brief The antenna.
 * @param frequency The frequency of the antenna.
 * @param coords The coordinates of the antenna.
 * @param next The next antenna.
 */
typedef struct ED {
    char frequency;
    struct Coords coords;
    struct ED* next;
    bool isNefasto;
} ED;