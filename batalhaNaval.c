#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Representação do Tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializar todas as posições com 0 = água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Posicionamento dos Navios
    // Vetores para representar os navios
    int navio_horizontal[TAMANHO_NAVIO];
    int navio_vertical[TAMANHO_NAVIO];
    
    // Inicializar os vetores dos navios com valor 3
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        navio_horizontal[i] = 3;
        navio_vertical[i] = 3;
    }
    
    // Posicionar navio horizontal linha 2, coluna 3
    int linha_horizontal = 2;
    int coluna_horizontal = 3;
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }
    
    // Posicionar navio vertical linha 5, coluna 7
    int linha_vertical = 5;
    int coluna_vertical = 7;
    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }
    
    // Exibir o Tabuleiro
    printf("Tabuleiro do Batalha Naval (%dx%d)\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);
    printf("0 = Agua | 3 = Navio\n\n");
    
    // Imprimir números das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Imprimir linhas separadoras
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n");
    
    // Imprimir o tabuleiro com os valores
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}