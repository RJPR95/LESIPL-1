/**
 * @file Functions.c
 * @brief Implements the functions for managing antennas.
 * @author Raul Ribeiro
 * @date 2025-03-18
 */

#include "Dados.h"

#pragma region "Antenna Management"
    /**
     * @brief Create a new antenna.
     * @param freq The frequency of the antenna.
     * @param line The line of the antenna.
     * @param col The column of the antenna.
     * @return A pointer to the new antenna.
     */
    ED* CreateAntenna(char freq, int line, int col) {
        ED* new_antena = (ED*)malloc(sizeof(ED));
        new_antena->frequency = freq;
        new_antena->coords.line = line;
        new_antena->coords.col = col;
        new_antena->next = NULL;

        return new_antena;
    }

    /**
     * @brief Search for an antenna by coordinates.
     * @param head The head of the linked list.
     * @param line The line of the antenna to search for.
     * @param col The column of the antenna to search for.
     * @return A pointer to the found antenna, or NULL if not found.
     */
    ED* SearchAntenna(ED* head, int line, int col) {
        ED* aux = head;
        while (aux) {
            if (aux->coords.line == line && aux->coords.col == col) {
                return aux;
            }
            aux = aux->next;
        }
        return NULL;
    }

    /**
     * @brief Search for an antenna by frequency and coordinates.
     * @param head The head of the linked list.
     * @param frequency The frequency of the antenna to search for.
     * @param line The line of the antenna to search for.
     * @param col The column of the antenna to search for.
     * @return A pointer to the found antenna, or NULL if not found.
     */
    ED* SearchAntennaByFrequency(ED* head, char frequency, int line, int col) {
        ED* aux = head;
        while (aux) {
            if (aux->coords.line == line && aux->coords.col == col && aux->frequency == frequency) {
                return aux;
            }
            aux = aux->next;
        }
        return NULL;
    }

    /**
     * @brief Add an antenna to the linked list at the specified coordinates.
     * @param head The head of the linked list.
     * @param freq The frequency of the antenna.
     * @param line The line of the antenna.
     * @param col The column of the antenna.
     * @return True if the antenna was added successfully, false otherwise.
     */
    bool AddAntennaToCoords(ED* head, char freq, int line, int col) {
        // Check if the coordinates are valid
        if (line < 0 || line >= N_LINES || col < 0 || col >= N_COLS) {
            printf("\n-- ERROR: Invalid coordinates! --\n\n");
            return false;
        }

        // Check if the coordinates are already occupied
        ED* occupiedAntenna = SearchAntenna(head, line, col);
        if (occupiedAntenna != NULL) {
            printf("\n-- ERROR: Coordinates already occupied! --\n\n");
            return false;
        }
        // Create a new antenna and add it to the linked list
        ED* new_antena = CreateAntenna(freq, line, col);
        if (head == NULL) {
            head = new_antena;
        } else {
            ED* aux = head;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = new_antena;
        }

        return true;
    }

    /**
     * @brief Remove an antenna from the linked list.
     * @param head The head of the linked list.
     * @param line The line of the antenna to remove.
     * @param col The column of the antenna to remove.
     * @return true if the antenna was removed successfully, false otherwise.
     */
    bool RemoveAntenna(ED* head, int line, int col) {
        ED* aux = head;
        ED* prev = NULL;

        while (aux != NULL) {
            if (aux->coords.line == line && aux->coords.col == col) {
                if (prev == NULL) {
                    head = aux->next;
                } else {
                    prev->next = aux->next;
                }

                free(aux);

                return true;
            }
            prev = aux;
            aux = aux->next;
        }

        return false;
    }

    /**
     * @brief Get nefarious areas based on the antennas.
     * @param head The head of the linked list.
     */
    ED* GetNefariousAreas(ED* head) {
        // Initialize the nefarious linked list.
        nefariousHead = NULL;

        int nefariousArea = 0;

        printf("What is the nefarious area around the antennas: ");
        scanf("%d", &nefariousArea);

        system("clear");
        
        ED *aux = head;
        while(aux != NULL) {
            if(aux->frequency != '.'){
                int lineSearch = -nefariousArea ;

                while(lineSearch <= nefariousArea){
                    int colSearch = -nefariousArea;
                    while(colSearch <= nefariousArea){
                        ED *foundAntenna = SearchAntennaByFrequency(
                            head, 
                            aux->frequency, 
                            aux->coords.line + lineSearch, 
                            aux->coords.col + colSearch);

                        if(foundAntenna != NULL && 
                            (foundAntenna->coords.line != aux->coords.line || 
                                foundAntenna->coords.col != aux->coords.col)) {

                            ED *nefariousAntenna = SearchAntenna( nefariousHead, 
                                                                aux->coords.line + (2 * lineSearch), 
                                                                aux->coords.col + (2 * colSearch));
                    
                            if(nefariousAntenna != NULL) {
                                nefariousAntenna->isNefarious = true;
                            } else {
                                nefariousAntenna = CreateAntenna('.', 
                                                                aux->coords.line + (2 * lineSearch), 
                                                                aux->coords.col + (2 * colSearch));
                                nefariousAntenna->isNefarious = true;
                                nefariousAntenna->next = nefariousHead;
                                nefariousHead = nefariousAntenna;
                            }
                        }
                        colSearch++;
                    }
                    lineSearch++;

                }
            }

            aux = aux->next;
        }
        return NULL;
    }

#pragma endregion

#pragma region "File Operations"
    /**
     * @brief Get antennas from a file and store them in a linked list.
     * @param fileName The name of the file to read the antennas from.
     * @return true if the antennas were read successfully, false otherwise.
     */
    bool GetAntennasFromFile(char* fileName) {
        // Open the file.
        FILE *file = fopen(fileName, "rb");

        // Check if the file was opened successfully.
        // If not, print an error message and exit the program.
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }

        // Temporary variable to hold data read from the file.
        EDFile auxElement;

        // Read the file until the end.
        while (fread(&auxElement, sizeof(EDFile), 1, file)) {
            // Create a new antenna using the data read from the file.
            ED *a = CreateAntenna(auxElement.frequency, auxElement.coords.line, auxElement.coords.col);

            // Add the antenna to the linked list.
            if (head == NULL) {
                head = a;
            } else {
                ED *aux = head;
                while (aux->next != NULL) {
                    aux = aux->next;
                }
                aux->next = a;
            }
        }

        fclose(file);

        // Get nefarious areas.
        GetNefariousAreas(head);

        return true;
    }

    /**
     * @brief Save the antennas to a file.
     * @param fileName The name of the file to save the antennas to.
     * @param head The head of the linked list of antennas.
     * @return true if the file was saved successfully, false otherwise.
     */
    bool SaveFile(char* fileName, ED* head) {
        FILE* fp;

        if (head == NULL) return false;
        if ((fp = fopen(fileName, "wb")) == NULL) return false;

        // Write all nodes of the list to the file
        ED* aux = head;
        EDFile auxElement; // Auxiliary struct for writing to the file
        while (aux) { // while (aux != NULL)
            // Copy the data from the memory struct to the file struct
            auxElement.frequency = aux->frequency;
            auxElement.coords.line = aux->coords.line;
            auxElement.coords.col = aux->coords.col;

            fwrite(&auxElement, sizeof(EDFile), 1, fp);
            aux = aux->next;
        }
        fclose(fp);

        return true;
    }
#pragma endregion

#pragma region "Output Functions"
    #pragma region "Menu Functions"
        /**
         * @brief Print the antennas in the linked list.
         * @param head The head of the linked list.
         */
        void MenuPrintAntennas(ED* head) {
            printf("    1  2  3  4  5  6  7  8  9  10 11 12  \n");
            for(int i = 0; i < N_LINES; i++) {
                if(i < 9) {
                    printf(" %d ", i + 1);
                } else {
                    printf("%d ", i + 1);
                }

                for(int j = 0; j < N_COLS; j++) {
                    ED *foundAntenna = SearchAntenna(head, i, j);
        
                    if(foundAntenna != NULL) {
                        printf(" %c ", foundAntenna->frequency);
                    } else {
                        ED *nefariousAntenna = SearchAntenna(nefariousHead, i, j);
        
                        if(nefariousAntenna != NULL) {
                            printf("\033[1;31m # \033[0m");
                        } else {
                            printf("\033[2m . \033[0m");
                        }
                    }
                }
                printf("\n");
            }

            // Asks for the nefarious area correction.
            // AskForNefariousAreaCorrection(head);

            printf("\n\n");
        }

        /**
         * @brief Add an antenna to the linked list.
         */
        void MenuAddAntenna() {
            printf("=========== Add Antenna ===========\n");
            
            int line;
            int col;
            char freq;

            // Print the antennas in the linked list.
            MenuPrintAntennas(head);
            
            // Ask for the coordinates and frequency of the antenna to add.
            printf("Antenna frequency: ");
            scanf(" %c", &freq);
            printf("Antenna line: ");
            scanf("%d", &line);
            printf("Antenna column: ");
            scanf("%d", &col);
            
            system("clear");

            // Check if the antenna was added successfully.
            bool wasAdded = AddAntennaToCoords(head, freq, line - 1, col - 1);

            // If the antenna was added successfully, print a success message.
            if(wasAdded) {
                printf("\n-- Antenna added successfully! --\n\n");
                SaveFile("antenas", head);
                GetNefariousAreas(head);
            }
        }

        /**
         * @brief Remove an antenna from the linked list.
         */
        void MenuRemoveAntenna() {
            printf("============ Remove Antenna ============\n");

            int line;
            int col;

            // Print the antennas in the linked list.
            MenuPrintAntennas(head);

            // Ask for the coordinates of the antenna to remove.
            printf("Antenna line: ");
            scanf("%d", &line);
            printf("Antenna column: ");
            scanf("%d", &col);
            
            system("clear");

            // Remove the antenna from the linked list.
            // If the antenna is found, remove it.
            // Otherwise, print an error message.
            if(RemoveAntenna(head, line - 1, col - 1)) {
                printf("\n-- Antenna removed successfully! --\n\n");
                SaveFile("antenas", head);
                GetNefariousAreas(head);
            } else {
                printf("\n-- ERROR: Antenna not found! --\n\n");
            }
        }
    
        /**
         * @brief Show the menu for managing antennas.
         */
        void ShowMenu() {
            int option;

            while(option != 4) {
                printf("1. Add Antenna\n");
                printf("2. Remove Antenna\n");
                printf("3. Show Antennas\n");
                printf("4. Exit\n");
                printf("Choose an option (1, 2, 3 or 4): ");
                scanf("%d", &option);

                system("clear");

                switch(option) {
                    case 1:
                        MenuAddAntenna();
                        break;
                    case 2:
                        MenuRemoveAntenna();
                        break;
                    case 3:
                        system("clear");
                        printf("============ Show Antennas ===========\n");
                        MenuPrintAntennas(head);
                        break;
                    case 4:
                        exit(0);
                    default:
                        printf("\n-- ERROR: Invalid Option! --\n\n");
                }
            }
        }

    #pragma endregion

    /**
     * @brief Ask the user for the nefarious area correction.
     * @param head The head of the linked list.
     */
    void AskForNefariousAreaCorrection(ED* head) {
        while(nefariousHead != NULL){
            ED* aux = head;
            int row = 0;
            int col = 0;

            int option;
            
            printf("\n");
            printf(("Parece que existem áreas nefasta(s) na rede.\n"));
            printf("As áreas nefastas são:\n");
            aux = nefariousHead;
            while(aux != NULL) {
                if(aux->coords.line >= 0 && aux->coords.col >= 0) {
                    printf("Linha: %d, Coluna: %d\n", aux->coords.line, aux->coords.col);
                }
                aux = aux->next;
            }
            printf("\n");
            printf("Deseja remover alguma antena para tentar resolver as áreas nefastas? (1 - Sim, 0 - Não)\n");
            scanf("%d", &option);

            // Check if the user wants to remove an antenna.
            if(option == 0) {
                system("clear");
                break;
            }
            if(option != 1) {
                printf("-- Opção inválida! --\n\n");
                continue;
            }

            // Ask for the coordinates of the antenna to remove.
            printf("----------------------------\n");
            printf("\nQual a antena que deseja remover para tentar resolver as áreas nefastas?\n");
            printf("Linha: ");
            scanf("%d", &row);
            printf("Coluna: ");
            scanf("%d", &col);

            // Remove 1 from the coordinates to match the array index.
            row--;
            col--;

            // Search for the antenna in the linked list.
            ED *foundAntenna = SearchAntenna(head, row, col);

            // If the antenna is found, remove it.
            // Otherwise, print an error message.
            if(foundAntenna != NULL) {
                RemoveAntenna(head, row, col);
                printf("Antena removida com sucesso!\n");

                SaveFile("antenas", head);
                GetAntennasFromFile("antenas");
            } else {
                printf("Antena não encontrada!\n");
            }

            printf("----------------------------\n\n");
        }
    }

#pragma endregion
