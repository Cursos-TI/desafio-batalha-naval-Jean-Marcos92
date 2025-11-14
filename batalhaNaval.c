#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define TAMANHO_NAVIO 3

// Funções para criar as matrizes de habilidade
void criarHabilidadeZone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    printf("Criando habilidade ZONE (Cone):\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Forma de cone: expande da linha 0 para baixo
            if (j >= i && j < TAMANHO_HABILIDADE - i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    printf("Criando habilidade CRUZ:\n");
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Forma de cruz: linha central + coluna central
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeOctandro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    printf("Criando habilidade OCTANDRO (Losango):\n");
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Forma de losango: distância Manhattan do centro <= raio
            int dist_linha = abs(i - centro);
            int dist_coluna = abs(j - centro);
            if (dist_linha + dist_coluna <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para exibir uma matriz de habilidade
void exibirHabilidade(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para aplicar habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                      int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                      int centro_linha, int centro_coluna) {
    
    int offset = TAMANHO_HABILIDADE / 2;
    
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int tab_linha = centro_linha - offset + i;
            int tab_coluna = centro_coluna - offset + j;
            
            // Verificar se está dentro dos limites do tabuleiro
            if (tab_linha >= 0 && tab_linha < TAMANHO_TABULEIRO &&
                tab_coluna >= 0 && tab_coluna < TAMANHO_TABULEIRO) {
                
                // Se a posição da habilidade é 1, marcar no tabuleiro
                if (habilidade[i][j] == 1) {
                    tabuleiro[tab_linha][tab_coluna] = 5;
                }
            }
        }
    }
}

// Função para inicializar o tabuleiro com navios
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Inicializar com água
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Posicionar navios
    // Navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[2][1 + i] = 3;
    }
    
    // Navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[5 + i][8] = 3;
    }
    
    // Navio diagonal principal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[7 + i][2 + i] = 3;
    }
    
    // Navio diagonal secundária
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[1 + i][7 - i] = 3;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n=== TABULEIRO DO BATALHA NAVAL ===\n");
    printf("Legenda: 0=Agua | 3=Navio | 5=Habilidade\n\n");
    
    // Cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Linha separadora
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n");
    
    // Tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int zone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octandro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    
    // 1. Inicializar tabuleiro com navios
    inicializarTabuleiro(tabuleiro);
    
    // 2. Criar matrizes de habilidade
    criarHabilidadeZone(zone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctandro(octandro);
    
    // Exibir as habilidades
    printf("=== MATRIZES DE HABILIDADE ===\n\n");
    
    printf("ZONE (Cone):\n");
    exibirHabilidade(zone);
    
    printf("CRUZ:\n");
    exibirHabilidade(cruz);
    
    printf("OCTANDRO (Losango):\n");
    exibirHabilidade(octandro);
    
    // 3. Aplicar habilidades ao tabuleiro
    printf("=== APLICANDO HABILIDADES AO TABULEIRO ===\n");
    
    // Aplicar ZONE no centro [4,4]
    printf("Aplicando ZONE em [4,4]\n");
    aplicarHabilidade(tabuleiro, zone, 4, 4);
    
    // Aplicar CRUZ em [7,2]
    printf("Aplicando CRUZ em [7,2]\n");
    aplicarHabilidade(tabuleiro, cruz, 7, 2);
    
    // Aplicar OCTANDRO em [2,7]
    printf("Aplicando OCTANDRO em [2,7]\n");
    aplicarHabilidade(tabuleiro, octandro, 2, 7);
    
    // 4. Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);
    
    // Legenda das habilidades aplicadas
    printf("\n=== LEGENDA DAS HABILIDADES ===\n");
    printf("- ZONE (Cone): Centro em [4,4]\n");
    printf("- CRUZ: Centro em [7,2]\n");
    printf("- OCTANDRO (Losango): Centro em [2,7]\n");
    printf("- Valor 5 representa área afetada por habilidades\n");
    
    return 0;
}