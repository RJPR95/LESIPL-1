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

/**
 * @brief The number of lines and columns.
 */
#define N_LINES 12
#define N_COLS 12

/**
 * @brief The coordinates.
 * @param line The line of the coordinates.
 * @param col The column of the coordinates.
 */
typedef struct Coords {
    int line;
    int col;
} Coords;

/**
 * @brief The antenna structure.
 * @param frequency The frequency of the antenna.
 * @param coords The coordinates of the antenna.
 * @param next The next antenna.
 * @param isNefarious The antenna is nefasta.
 */
typedef struct ED {
    char frequency;
    struct Coords coords;
    struct ED* next;
    bool isNefarious;
} ED;

/**
 * @brief The antenna file structure.
 * @param frequency The frequency of the antenna.
 * @param coords The coordinates of the antenna.
 */
typedef struct EDFile {
	char frequency;
    struct Coords coords;
}EDFile;

/**
 * @brief Declares the antennas and nefarious areas heads.
 */
extern ED *head; // Head of the linked list
extern ED *nefariousHead; // Head of the nefarious linked list