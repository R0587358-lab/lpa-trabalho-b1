#include <stdio.h>

/* FUNCOES DE LEITURA E VALIDACAO */

float lerDistancia() {
    float distancia;

    do {
        printf("Digite a distancia em km: ");
        scanf("%f", &distancia);

        if (distancia <= 0) {
            printf("Distancia invalida! Digite novamente.\n");
        }

    } while (distancia <= 0);

    return distancia;
}
float lerPeso() {
    float peso;

    do {
        printf("Digite o peso em kg: ");
        scanf("%f", &peso);

        if (peso <= 0) {
            printf("Peso invalido! Digite novamente.\n");
        }

    } while (peso <= 0);

    return peso;
}

int lerModalidade() {
    int modalidade;

    do {
        printf("\nEscolha a modalidade:\n");
        printf("1 - Economica\n");
        printf("2 - Expressa\n");
        printf("3 - Prioritaria\n");
        printf("Opcao: ");
        scanf("%d", &modalidade);

        if (modalidade < 1 || modalidade > 3) {
            printf("Modalidade invalida!\n");
        }

    } while (modalidade < 1 || modalidade > 3);

    return modalidade;
}

int lerProtecao() {
    int protecao;

    do {
        printf("Deseja contratar protecao? (1-Sim / 0-Nao): ");
        scanf("%d", &protecao);

        if (protecao != 0 && protecao != 1) {
            printf("Opcao invalida!\n");
        }

    } while (protecao != 0 && protecao != 1);

    return protecao;
}
