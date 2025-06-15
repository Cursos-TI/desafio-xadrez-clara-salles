#include <stdio.h>
#include <string.h>

// Biblioteca padrão para entrada/saída

// Função para movimentar a torre.
void movimentar_torre() {
    char direcao[10]; // Variável para armazenar a direção do movimento.
    int vezes;        // Quantidade de casas que a torre será movida.

    // Solicita entrada do usuário
    printf("Movimentar torre para qual lado? (Direita, Esquerda, Cima, Baixo)\n");
    scanf("%s", direcao);

    printf("Movimentar torre quantas vezes? (Máximo 5 casas)\n");
    scanf("%d", &vezes);

    // Validação de entrada
    if (vezes > 5) {
        printf("Número de vezes excede o máximo permitido (5).\n");
        return;
    }

    // Loop para exibir os movimentos da torre
    for (int i = 0; i < vezes; i++) {
        printf("(%d) Torre movida para %s\n", i + 1, direcao);
    }
}

// Função para movimentar o bispo.
void movimentar_bispo() {
    char diagonal[15]; // Armazena a direção do movimento diagonal
    int vezes;         // Quantidade de casas que o bispo será movido

    printf("Movimentar bispo para qual diagonal? (DireitaCima, EsquerdaCima, DireitaBaixo, EsquerdaBaixo)\n");
    scanf("%s", diagonal);

    printf("Movimentar bispo quantas vezes? (Máximo 5 casas)\n");
    scanf("%d", &vezes);

    // Validação de entrada
    if (vezes > 5) {
        printf("Número de vezes excede o máximo permitido (5).\n");
        return;
    }

    // Loop para exibir os movimentos do bispo
    for (int i = 0; i < vezes; i++) {
        printf("(%d) Bispo movido para %s\n", i + 1, diagonal);
    }
}

// Função para movimentar a rainha.
void movimentar_rainha() {
    char direcao[15];      // Armazena a direção do movimento
    int vezes;             // Número de casas que a rainha será movida
    char tipo_movimento[15]; // Tipo de movimento (diagonal, horizontal, vertical)

    printf("Movimentar rainha para diagonal, vertical ou horizontal?\n");
    scanf("%s", tipo_movimento);

    // Determinar a direção com base no tipo de movimento
    if (strcmp(tipo_movimento, "diagonal") == 0) {
        printf("Movimentar rainha para qual diagonal? (DireitaCima, EsquerdaCima, DireitaBaixo, EsquerdaBaixo)\n");
    } else if (strcmp(tipo_movimento, "vertical") == 0 || strcmp(tipo_movimento, "horizontal") == 0) {
        printf("Movimentar rainha para qual lado? (Direita, Esquerda, Cima, Baixo)\n");
    } else {
        printf("Movimento inválido!\n");
        return;
    }
    scanf("%s", direcao);

    printf("Movimentar rainha quantas vezes? (Máximo 8 casas)\n");
    scanf("%d", &vezes);

    // Validação de entrada
    if (vezes > 8) {
        printf("Número de vezes excede o máximo permitido (8).\n");
        return;
    }

    // Loop para exibir os movimentos da rainha
    for (int i = 0; i < vezes; i++) {
        printf("(%d) Rainha movida para %s %s\n", i + 1, tipo_movimento, direcao);
    }
}

// Função para movimentar o cavalo (Agora com loops aninhados)
void movimentar_cavalo() {
    char direcao_vertical[15], direcao_horizontal[15];
    int contador = 0;

    printf("Movimentar cavalo para baixo ou para cima?\n");
    scanf("%s", direcao_vertical);

    printf("Movimentar cavalo para esquerda ou direita?\n");
    scanf("%s", direcao_horizontal);

    // Estrutura de repetição while controlando o loop externo
    while (contador < 1) {
        // Estrutura de repetição for para o movimento vertical (duas casas)
        for (int i = 0; i < 2; i++) {
            printf("Cavalo se movimentou para %s\n", direcao_vertical);
        }
        // Movimento horizontal (uma casa)
        printf("Cavalo se movimentou para %s\n", direcao_horizontal);

        contador++; // Incrementa o contador para sair do loop while
    }
}

// Função principal do jogo.
int main() {
    int escolha; // Variável para armazenar a escolha do jogador

    printf("Bem-vindo ao Xadrez - Mate Check!\n\n");

    // Loop para exibição do menu e controle das jogadas
    do {
        printf("\n[1] Movimentar Torre\n");
        printf("[2] Movimentar Bispo\n");
        printf("[3] Movimentar Rainha\n");
        printf("[4] Movimentar Cavalo\n");
        printf("[5] Sair do jogo\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                movimentar_torre();
                break;
            case 2:
                movimentar_bispo();
                break;
            case 3:
                movimentar_rainha();
                break;
            case 4:
                movimentar_cavalo();
                break;
            case 5:
                printf("Adeus! Até a próxima.\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (escolha != 5);

    return 0;
}