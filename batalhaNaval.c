#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NUM_NAVIOS 4

// Função para verificar se uma posição está livre
int posicaoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] == 0;
}

// Função para verificar se todas as posições de um navio estão livres
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int linha_inicio, int coluna_inicio,
                        int dir_linha, int dir_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linha_inicio + i * dir_linha;
        int coluna = coluna_inicio + i * dir_coluna;

        // Verificar se está dentro dos limites
        if (linha < 0 || linha >= TAMANHO_TABULEIRO ||
            coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
            return 0;
        }

        // Verificar se a posição está livre
        if (!posicaoLivre(tabuleiro, linha, coluna)) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha_inicio, int coluna_inicio,
                     int dir_linha, int dir_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linha_inicio + i * dir_linha;
        int coluna = coluna_inicio + i * dir_coluna;
        tabuleiro[linha][coluna] = 3;
    }
}

int main() {
    // 1. Criar Tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionar Quatro Navios

    // Navio 1: Horizontal (linha 1, coluna 2)
    if (podePosicionarNavio(tabuleiro, 1, 2, 0, 1)) {
        posicionarNavio(tabuleiro, 1, 2, 0, 1);
        printf("Navio 1 (horizontal) posicionado em [1,2] -> [1,4]\n");
    }

    // Navio 2: Vertical (linha 4, coluna 7)
    if (podePosicionarNavio(tabuleiro, 4, 7, 1, 0)) {
        posicionarNavio(tabuleiro, 4, 7, 1, 0);
        printf("Navio 2 (vertical) posicionado em [4,7] -> [6,7]\n");
    }

    // Navio 3: Diagonal principal (linha 3, coluna 0)
    if (podePosicionarNavio(tabuleiro, 3, 0, 1, 1)) {
        posicionarNavio(tabuleiro, 3, 0, 1, 1);
        printf("Navio 3 (diagonal principal) posicionado em [3,0] -> [5,2]\n");
    }

    // Navio 4: Diagonal secundária (linha 2, coluna 7)
    if (podePosicionarNavio(tabuleiro, 2, 7, 1, -1)) {
        posicionarNavio(tabuleiro, 2, 7, 1, -1);
        printf("Navio 4 (diagonal secundaria) posicionado em [2,7] -> [4,5]\n");
    }

    printf("\n");

    // 3. Exibir o Tabuleiro
    printf("Tabuleiro do Batalha Naval (%dx%d)\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);
    printf("0 = Agua | 3 = Navio\n\n");

    // Imprimir números das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Imprimir linha separadora
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

    // Legenda dos navios
    printf("\nLegenda dos Navios:\n");
    printf("- Navio 1 (Horizontal): Linha 1, Colunas 2-4\n");
    printf("- Navio 2 (Vertical): Coluna 7, Linhas 4-6\n");
    printf("- Navio 3 (Diagonal Principal): [3,0]-[4,1]-[5,2]\n");
    printf("- Navio 4 (Diagonal Secundaria): [2,7]-[3,6]-[4,5]\n");

    return 0;
}