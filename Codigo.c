#include <stdio.h>

void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}


char verificarVencedor(char tabuleiro[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]) {
            return tabuleiro[i][0];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i]) {
            return tabuleiro[0][i];
        }
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    return ' ';
}

int main() {
    char tabuleiro[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int linha, coluna;
    char jogador = 'X';
    int jogadas = 0;
    char vencedor;

    // Loop principal do jogo
    while (jogadas < 9) {
        imprimirTabuleiro(tabuleiro);

        printf("Jogador %c, digite a linha (1 a 3) e a coluna (1 a 3): ", jogador);
        scanf("%d %d", &linha, &coluna);

        // Verificar se a posição está livre
        if (tabuleiro[linha - 1][coluna - 1] != 'X' && tabuleiro[linha - 1][coluna - 1] != 'O') {
            tabuleiro[linha - 1][coluna - 1] = jogador;
            jogadas++;

            // Verificar se há um vencedor
            vencedor = verificarVencedor(tabuleiro);
            if (vencedor == 'X' || vencedor == 'O') {
                imprimirTabuleiro(tabuleiro);
                printf("Parabéns, jogador %c! Você venceu!\n", vencedor);
                break;
            }

            // Trocar o jogador
            jogador = (jogador == 'X') ? 'O' : 'X';
        } else {
            printf("Posição ocupada. Tente novamente.\n");
        }
    }

    // Verificar empate
    if (jogadas == 9 && vencedor == ' ') {
        imprimirTabuleiro(tabuleiro);
        printf("Empate! O jogo terminou sem vencedores.\n");
    }

    return 0;
}
