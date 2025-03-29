#include "Dados.h"

/**
 * @brief Creates a new antenna.
 * @param freq The frequency of the antenna.
 * @param line The line of the antenna.
 * @param col The column of the antenna.
 * @return The antenna.
 */
ED* CreateAntenna(char freq, int line, int col);

/**
 * @brief Removes an antenna.
 * @param head The head of the linked list.
 * @param line The line of the antenna.
 * @param col The column of the antenna.
 */
void removeAntenna(ED* head, int line, int col);

/**
 * @brief Searches for an antenna.
 * @param head The head of the linked list.
 * @param line The line of the antenna.
 * @param col The column of the antenna.
 * @return The antenna.
 */
ED* SearchAntennaByFrequency(ED* head, char frequency, int line, int col);
ED* SearchAntenna(ED* head, int line, int col);