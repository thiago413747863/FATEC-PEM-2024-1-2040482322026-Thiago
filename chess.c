#include <stdio.h>

#define LINHAS 8
#define COLUNAS 8
int main() {
    printf("  a b c d e f g h\n");
    char tabuleiro[LINHAS][COLUNAS] = {
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'_', 'x', '_', 'x', '_', 'x', '_', 'x'},
        {'x', '_', 'x', '_', 'x', '_', 'x', '_'},
        {'_', 'x', '_', 'x', '_', 'x', '_', 'x'},
        {'x', '_', 'x', '_', 'x', '_', 'x', '_'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}
    };
    int i = 0;
    while (i < LINHAS) {
        printf("%d ", 8 - i);
        int j = 0;
        while (j < COLUNAS) {
            printf("%c ", tabuleiro[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
