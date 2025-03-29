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
    
    // Open the file.
    FILE *file = fopen("antenas.txt", "r");

    // Check if the file was opened successfully.
    // If not, print an error message and exit the program.
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int row = 0;
    int nefariousArea = 0;

    printf("Qual a área nefasta das antenas: ");
    scanf("%d", &nefariousArea);

    ED *head = NULL; // Head of the linked list
    ED *nefariousHead = NULL; // Head of the nefarious linked list

    // Read the file line by line.
    // For each character in the line, create a new antenna.
    // Print the frequency, latitude and longitude of the antenna.
    while (fgets(line, sizeof(line), file)) {
        for (int col = 0; line[col] != '\0'; col++) {
            if (line[col] != '.' && line[col] != '\n') {
                ED *a = (ED *)malloc(sizeof(ED));

                // Check if the memory allocation was successful.
                // If not, print an error message and exit the program.
                if (a == NULL) {
                    perror("Memory allocation failed");
                    fclose(file);
                    exit(EXIT_FAILURE);
                }

                a = CreateAntenna(line[col], row, col);

                // Add the antenna to the linked list.
                // If the linked list is empty, set the head to the new antenna.
                // Otherwise, iterate through the linked list until the last element is reached and set the next element to the new antenna.
                if(head == NULL) {
                    head = a;
                } else {
                    ED *aux = head;
                    while(aux->next != NULL) {
                        aux = aux->next;
                    }
                    aux->next = a;
                }
            }
        }
        row++;
    }

    fclose(file);

    // Print the antennas.
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


    // Print the antennas.
    aux = head;
    row = 0;
    int col = 0;
    int previousRow = 0;

    for(int i = 0; i < N_LINES; i++) {
        for(int j = 0; j < N_COLS; j++) {
            ED *foundAntenna = SearchAntenna(head, i, j);

            if(foundAntenna != NULL) {
                printf("%c", foundAntenna->frequency);
            } else {
                ED *nefariousAntenna = SearchAntenna(nefariousHead, i, j);

                if(nefariousAntenna != NULL) {
                    printf("#");
                } else {
                    printf(".");
                }
            }
        }
        printf("\n");
    }

    if(nefariousHead != NULL) {
        printf(("Parece que existem áreas nefasta(s) na rede.\n"));
        printf("As áreas nefastas são:\n");
        aux = nefariousHead;
        while(aux != NULL) {
            if(aux->coords.line >= 0 && aux->coords.col >= 0) {
                printf("Linha: %d, Coluna: %d\n", aux->coords.line, aux->coords.col);
            }
            aux = aux->next;
        }
        printf("\nQual a antena que deseja remover para tentar resolver as áreas nefastas?\n");
        printf("Linha: ");
        scanf("%d", &row);
        printf("Coluna: ");
        scanf("%d", &col);
        ED *foundAntenna = SearchAntenna(head, row, col);
        if(foundAntenna != NULL) {
            removeAntenna(head, row, col);
            printf("Antena removida com sucesso!\n");
        } else {
            printf("Antena não encontrada!\n");
        }
    }
    
    return;
}