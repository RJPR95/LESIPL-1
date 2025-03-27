#include "Dados.h"

/**
 * @brief Creates a new antenna.
 * @param freq The frequency of the antenna.
 * @param linha The line of the antenna.
 * @param coluna The column of the antenna.
 * @return The antenna.
 */
ED* CriarAntena(char freq, int linha, int coluna);

/**
 * @brief Searches for an antenna.
 * @param head The head of the linked list.
 * @param linha The line of the antenna.
 * @param coluna The column of the antenna.
 * @return The antenna.
 */
ED* ProcurarAntena(ED* head, char frequency, int linha, int coluna);