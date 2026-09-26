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
