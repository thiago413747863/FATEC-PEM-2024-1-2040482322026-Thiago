#include <stdio.h>

void inicializa_tabuleiro(char tabuleiro[8][8][4]);
void inicializa_colunas(char colunas[8][4]);
void imprime_tabuleiro(char tabuleiro[8][8][4], char colunas[8][4]);
void realiza_movimento(char tabuleiro[8][8][4], int linha, int coluna, char peca, char cor, char num);

int main() {
    char tabuleiro[8][8][4];
    char colunas[8][4];
    inicializa_tabuleiro(tabuleiro);
    inicializa_colunas(colunas);

    printf("Jogada 1:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Segunda jogada
    realiza_movimento(tabuleiro, 3, 4, 'P', 'B', '5');
    realiza_movimento(tabuleiro, 4, 4, 'P', 'P', '5');
    realiza_movimento(tabuleiro, 1, 4, ' ', ' ', ' ');
    realiza_movimento(tabuleiro, 6, 4, ' ', ' ', ' ');

    printf("Jogada 2:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Terceira jogada
    realiza_movimento(tabuleiro, 3, 2, 'B', 'B', '6');
    realiza_movimento(tabuleiro, 5, 2, 'c', 'P', '2');
    realiza_movimento(tabuleiro, 0, 5, ' ', ' ', ' ');
    realiza_movimento(tabuleiro, 7, 1, ' ', ' ', ' ');

    printf("Jogada 3:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Quarta jogada
    realiza_movimento(tabuleiro, 4, 7, 'D', 'B', '6');
    realiza_movimento(tabuleiro, 5, 5, 'c', 'P', '7');
    realiza_movimento(tabuleiro, 0, 3, ' ', ' ', ' ');
    realiza_movimento(tabuleiro, 7, 6, ' ', ' ', ' ');

    printf("Jogada 4:\n");
    imprime_tabuleiro(tabuleiro, colunas);

    // Quinta jogada
    realiza_movimento(tabuleiro, 5, 5, 'D', 'B', '6');
    realiza_movimento(tabuleiro, 4, 7, ' ', ' ', ' ');
    printf("Jogada 5:\n");
    imprime_tabuleiro(tabuleiro, colunas);
    return 0;
}
void inicializa_tabuleiro(char tabuleiro[8][8][4]) {
    char pecas[8] = {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'};
    char peoes = 'P';
    char pecaspretas[8] = {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'};
    char peoespretos = 'P';

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tabuleiro[i][j][0] = ' ';
            tabuleiro[i][j][1] = ' ';
            tabuleiro[i][j][2] = ' ';
            tabuleiro[i][j][3] = ' ';
        }
    }
    for (int j = 0; j < 8; j++) {
        tabuleiro[0][j][0] = pecas[j];
        tabuleiro[0][j][1] = 'B';
        tabuleiro[0][j][2] = '0' + (j + 1);
    }
    for (int j = 0; j < 8; j++) {
        tabuleiro[1][j][0] = peoes;
        tabuleiro[1][j][1] = 'B';
        tabuleiro[1][j][2] = '0' + (j + 1);
    }
    for (int j = 0; j < 8; j++) {
        tabuleiro[6][j][0] = peoespretos;
        tabuleiro[6][j][1] = 'P';
        tabuleiro[6][j][2] = '0' + (j + 1);
    }
    for (int j = 0; j < 8; j++) {
        tabuleiro[7][j][0] = pecaspretas[j];
        tabuleiro[7][j][1] = 'P';
        tabuleiro[7][j][2] = '0' + (j + 1);
    }
}

void inicializa_colunas(char colunas[8][4]) {
    char letras[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < 8; i++) {
        colunas[i][0] = ' ';
        colunas[i][1] = letras[i];
        colunas[i][2] = ' ';
        colunas[i][3] = ' ';
    }
}
void imprime_tabuleiro(char tabuleiro[8][8][4], char colunas[8][4]) {
    printf("  ");
    for (int j = 0; j < 8; j++) {
        printf("%c%c%c%c ", colunas[j][0], colunas[j][1], colunas[j][2], colunas[j][3]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c%c%c%c ", tabuleiro[i][j][0], tabuleiro[i][j][1], tabuleiro[i][j][2], tabuleiro[i][j][3]);
        }
        printf("\n");
    }
    printf("\n");
}
void realiza_movimento(char tabuleiro[8][8][4], int linha, int coluna, char peca, char cor, char num) {
    tabuleiro[linha][coluna][0] = peca;
    tabuleiro[linha][coluna][1] = cor;
    tabuleiro[linha][coluna][2] = num;
}