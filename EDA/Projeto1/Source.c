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
    int areaNefasta = 0;

    printf("Qual a área nefasta das antenas: ");
    scanf("%d", &areaNefasta);

    ED *head = NULL; // Head of the linked list

    // Read the file line by line.
    // For each character in the line, create a new antenna.
    // Print the frequency, latitude and longitude of the antenna.
    while (fgets(line, sizeof(line), file)) {
        for (int col = 0; line[col] != '\0'; col++) {
            if (line[col] != '\n') {
                ED *a = (ED *)malloc(sizeof(ED));

                // Check if the memory allocation was successful.
                // If not, print an error message and exit the program.
                if (a == NULL) {
                    perror("Memory allocation failed");
                    fclose(file);
                    exit(EXIT_FAILURE);
                }

                a = CriarAntena(line[col], row, col);3
                

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
            int lineSearch = -areaNefasta ;

            while(lineSearch <= areaNefasta){
                int colSearch = -areaNefasta;
                while(colSearch <= areaNefasta){
                    ED *antenaEncontrada = ProcurarAntena(  head, 
                                                            aux->frequency, 
                                                            aux->coords.linha + lineSearch, 
                                                            aux->coords.coluna + colSearch);

                    if( antenaEncontrada != NULL && 
                        (antenaEncontrada->coords.linha != aux->coords.linha || 
                        antenaEncontrada->coords.coluna != aux->coords.coluna)) {

                        ED *antenaNefasta = ProcurarAntena( head, 
                                                            '.', 
                                                            aux->coords.linha + (2 * lineSearch), 
                                                            aux->coords.coluna + (2 * colSearch));
                
                        if(antenaNefasta != NULL) {
                            antenaNefasta->isNefasto = true;
                        }
                    }
                    colSearch++;
                }
                lineSearch++;

            }
            // ED *antenaEncontradaNorte = ProcurarAntena(head, aux->frequency, aux->coords.linha - 2, aux->coords.coluna);
            // ED *antenaEncontradaNordeste = ProcurarAntena(head, aux->frequency, aux->coords.linha - 2, aux->coords.coluna - 2);
            // ED *antenaEncontradaNoroeste = ProcurarAntena(head, aux->frequency, aux->coords.linha - 2, aux->coords.coluna + 2);
            // ED *antenaEncontradaSul = ProcurarAntena(head, aux->frequency, aux->coords.linha + 2, aux->coords.coluna);
            // ED *antenaEncontradaSudeste = ProcurarAntena(head, aux->frequency, aux->coords.linha + 2, aux->coords.coluna - 2);
            // ED *antenaEncontradaSudoeste = ProcurarAntena(head, aux->frequency, aux->coords.linha + 2, aux->coords.coluna + 2);
            // ED *antenaEncontradaEste = ProcurarAntena(head, aux->frequency, aux->coords.linha, aux->coords.coluna - 2);
            // ED *antenaEncontradaOeste = ProcurarAntena(head, aux->frequency, aux->coords.linha, aux->coords.coluna + 2);

            // if(antenaEncontradaNorte != NULL) {
            //     ED *antenaNefastaNorte = ProcurarAntena(head, '.', aux->coords.linha - 4, aux->coords.coluna);
                
            //     if(antenaNefastaNorte != NULL) {
            //         antenaNefastaNorte->isNefasto = true;
            //     }
            // }
            // if(antenaEncontradaNordeste != NULL) {
            //     ED *antenaNefastaNordeste = ProcurarAntena(head, '.', aux->coords.linha - 4, aux->coords.coluna - 4);
                
            //     if(antenaNefastaNordeste != NULL) {
            //         antenaNefastaNordeste->isNefasto = true;
            //     }
            // }
            // if(antenaEncontradaNoroeste != NULL) {
            //     ED *antenaNefastaNoroeste = ProcurarAntena(head, '.', aux->coords.linha - 4, aux->coords.coluna + 4);
                
            //     if(antenaNefastaNoroeste != NULL) {
            //         antenaNefastaNoroeste->isNefasto = true;
            //     }
            // }
            // if(antenaEncontradaSul != NULL) {
            //     ED *antenaNefastaSul = ProcurarAntena(head, '.', aux->coords.linha + 4, aux->coords.coluna);
                
            //     if(antenaNefastaSul != NULL) {
            //         antenaNefastaSul->isNefasto = true;
            //     }
            // }
            // if(antenaEncontradaSudeste != NULL) {
            //     ED *antenaNefastaSudeste = ProcurarAntena(head, '.', aux->coords.linha + 4, aux->coords.coluna - 4);
                
            //     if(antenaNefastaSudeste != NULL) {
            //         antenaNefastaSudeste->isNefasto = true;
            //     }
            // }
            // if(antenaEncontradaSudoeste != NULL) {
            //     ED *antenaNefastaSudoeste = ProcurarAntena(head, '.', aux->coords.linha + 4, aux->coords.coluna + 4);
                
            //     if(antenaNefastaSudoeste != NULL) {
            //         antenaNefastaSudoeste->isNefasto = true;
            //     }
            // }
            // if(antenaEncontradaEste != NULL) {
            //     ED *antenaNefastaEste = ProcurarAntena(head, '.', aux->coords.linha, aux->coords.coluna - 4);

            //     if(antenaNefastaEste != NULL) {
            //         antenaNefastaEste->isNefasto = true;
            //     }
            // }
            // if(antenaEncontradaOeste != NULL) {
            //     ED *antenaNefastaOeste = ProcurarAntena(head, '.', aux->coords.linha, aux->coords.coluna + 4);

            //     if(antenaNefastaOeste != NULL) {
            //         antenaNefastaOeste->isNefasto = true;
            //     }
            // }
        }

        aux = aux->next;
    }


    // Print the antennas.
    aux = head;
    int previousRow = 0;
    while(aux != NULL) {

        if (previousRow != aux->coords.linha) {
            printf("\n");
            previousRow = aux->coords.linha;
        }

        printf("%c", !aux->isNefasto ? aux->frequency : '#');

        // Set a new aux variable so we can free the memory of the current antenna.
        ED *aux2 = aux;
        aux = aux2->next;

        // Free the memory of the current antenna.
        // free(aux2);
    }

    return;
}