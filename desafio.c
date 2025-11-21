#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5

struct territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    struct territorio territorios[MAX_TERRITORIOS];

    printf("===============================\n");
    printf("Cadastro de 5 territórios\n");
    printf("===============================\n\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {

        printf("Cadastrando território %d:\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(territorios[i].nome, 30, stdin);

        printf("Digite a cor do exército: ");
        fgets(territorios[i].cor, 10, stdin);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada();

        // Remove \n
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0;
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;

        printf("-------------------------------\n");
    }

    // ================================
    // EXIBIR TODOS OS TERRITÓRIOS
    // ================================
    printf("\n===== TERRITÓRIOS CADASTRADOS =====\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome:   %s\n", territorios[i].nome);
        printf("Cor:    %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
