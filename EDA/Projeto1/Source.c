/**
 * @file Source.c
 * @brief Declares the source code.
 * @author Raul Ribeiro
 * @date 2025-03-18
 * @version 1.0
 */

#include "Dados.h"
#include "Functions.h"

void main() {

    // Reads the antennas from the file.
    GetAntennasFromFile("antenas");

    // Shows the menu.
    ShowMenu();
    
    return;
}