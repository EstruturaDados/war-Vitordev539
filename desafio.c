#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERRITORIOS 5

struct territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void atacar(struct territorio *atacante, struct territorio *defensor)
{
    srand(time(NULL));
    int ataque = rand() % 7; // simula um ataque de valor entre 0 e 6
    int defesa = rand() % 7; // simula uma defesa de valor entre 0 e 6
    printf("o ataque de %s : %d\n", atacante->nome, ataque);
    printf("a defesa de %s : %d\n", defensor->nome, defesa);

    printf("%s está atacando %s!\n", atacante->nome, defensor->nome);
    // Simples lógica de ataque: se o atacante tiver mais tropas, ele vence
    if (ataque > defesa)
    {
        printf("%s venceu o ataque!\n", atacante->nome);
        defensor->tropas -= 1;// defensor perde uma tropa
        if(defensor->tropas == 0);
        strcpy(defensor->cor, atacante->cor); // O defensor muda de cor para a do atacante
    }
    else
    {
        printf("%s defendeu com sucesso!\n", defensor->nome);
        atacante->tropas -= 1; // Atacante perde uma tropa
        if (atacante->tropas < 0)
            atacante->tropas = 0; // evita tropas negativas
    }
}

int main()
{

    struct territorio *territorios;

    territorios = (struct territorio *)malloc(MAX_TERRITORIOS * sizeof(struct territorio));

    printf("===============================\n");
    printf("Cadastro de 5 territórios\n");
    printf("===============================\n\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {

        printf("Cadastrando território %d:\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);

        printf("Digite a cor do exército: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);

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

    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {
        printf("%d. ", i + 1);
        printf("(%s ", territorios[i].nome);
        printf("Exercito %s, ", territorios[i].cor);
        printf("Tropas: %d)\n", territorios[i].tropas);
    }
    int opcaoAtaque, atacante, defensor;

while (1)
{
    printf("===============================\n");
    printf("       FASE DE ATAQUE\n");
    printf("===============================\n");
    printf("1 - Realizar ataque\n");
    printf("0 - Sair da fase de ataque\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoAtaque);
    limparBufferEntrada();

    if (opcaoAtaque == 0)
        break;

    if (opcaoAtaque != 1)
    {
        printf("Opção inválida!\n");
        continue;
    }

    // Mostrar territórios a cada turno
    printf("\n===== ESTADO ATUAL DOS TERRITÓRIOS =====\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {
        printf("%d. (%s - Exército %s, Tropas: %d)\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }

    printf("\nEscolha o território atacante (1-%d): ", MAX_TERRITORIOS);
    scanf("%d", &atacante);
    limparBufferEntrada();

    printf("Escolha o território defensor (1-%d): ", MAX_TERRITORIOS);
    scanf("%d", &defensor);
    limparBufferEntrada();

    atacar(&territorios[atacante - 1], &territorios[defensor - 1]);

    printf("\nAtaque concluído!\n");

    printf("\n===== TERRITÓRIOS ATUALIZADOS =====\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++)
    {
        printf("%d. (%s - Exército %s, Tropas: %d)\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }

    printf("\nPressione ENTER para continuar para o próximo turno...");
    getchar(); // <-- Agora funciona!
}
    
    
    
   
    
    free(territorios);

    return 0;
}
