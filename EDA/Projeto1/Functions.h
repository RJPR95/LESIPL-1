/**
 * @file Functions.h
 * @brief Declares the functions.
 * @author Raul Ribeiro
 * @date 2025-03-18
 * @version 1.0
 */

#include "Dados.h"

#pragma once

#pragma region "Antenna Management"
    /**
     * @brief Create a new antenna.
     * @param freq The frequency of the antenna.
     * @param line The line of the antenna.
     * @param col The column of the antenna.
     * @return A pointer to the new antenna.
     */
    ED* CreateAntenna(char freq, int line, int col);

    /**
     * @brief Search for an antenna by coordinates.
     * @param head The head of the linked list.
     * @param line The line of the antenna to search for.
     * @param col The column of the antenna to search for.
     * @return A pointer to the found antenna, or NULL if not found.
     */
    ED* SearchAntenna(ED* head, int line, int col);

    /**
     * @brief Search for an antenna by frequency and coordinates.
     * @param head The head of the linked list.
     * @param frequency The frequency of the antenna to search for.
     * @param line The line of the antenna to search for.
     * @param col The column of the antenna to search for.
     * @return A pointer to the found antenna, or NULL if not found.
     */
    ED* SearchAntennaByFrequency(ED* head, char frequency, int line, int col);

    /**
     * @brief Add an antenna to the linked list at the specified coordinates.
     * @param head The head of the linked list.
     * @param freq The frequency of the antenna.
     * @param line The line of the antenna.
     * @param col The column of the antenna.
     * @return True if the antenna was added successfully, false otherwise.
     */
    bool AddAntennaToCoords(ED* head, char freq, int line, int col);

    /**
     * @brief Remove an antenna from the linked list.
     * @param head The head of the linked list.
     * @param line The line of the antenna to remove.
     * @param col The column of the antenna to remove.
     * @return true if the antenna was removed successfully, false otherwise.
     */
    bool RemoveAntenna(ED* head, int line, int col);

    /**
     * @brief Get nefarious areas based on the antennas.
     * @param head The head of the linked list.
     */
    ED* GetNefariousAreas(ED* head);

#pragma endregion

#pragma region "File Operations"
    /**
     * @brief Get antennas from a file and store them in a linked list.
     * @param fileName The name of the file to read the antennas from.
     * @return true if the antennas were read successfully, false otherwise.
     */
    bool GetAntennasFromFile(char* fileName);

    /**
     * @brief Save the antennas to a file.
     * @param fileName The name of the file to save the antennas to.
     * @param head The head of the linked list of antennas.
     * @return true if the file was saved successfully, false otherwise.
     */
    bool SaveFile(char* fileName, ED* head);
#pragma endregion

#pragma region "Output Functions"
    #pragma region "Menu Functions"
        /**
         * @brief Print the antennas in the linked list.
         * @param head The head of the linked list.
         */
        void MenuPrintAntennas(ED* head);

        /**
         * @brief Add an antenna to the linked list.
         */
        void MenuAddAntenna();

        /**
         * @brief Remove an antenna from the linked list.
         */
        void MenuRemoveAntenna();

        /**
         * @brief Show the menu for managing antennas.
         */
        void ShowMenu();
    #pragma endregion

    /**
     * @brief Ask the user for the nefarious area correction.
     * @param head The head of the linked list.
     */
    void AskForNefariousAreaCorrection(ED* head);

#pragma endregion
