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

int lerTentativasAdicionais() {
    int tentativas;

    do {
        printf("Quantidade de tentativas adicionais: ");
        scanf("%d", &tentativas);

        if (tentativas < 0) {
            printf("Quantidade invalida!\n");
        }

    } while (tentativas < 0);

    return tentativas;
}

int lerOpcaoContinuar() {
    int continuar;

    do {
        printf("\nDeseja registrar outra entrega? (1-Sim / 0-Nao): ");
        scanf("%d", &continuar);

        if (continuar != 0 && continuar != 1) {
            printf("Opcao invalida!\n");
        }

    } while (continuar != 0 && continuar != 1);

    return continuar;
}

/* FUNCOES DE CALCULO */

float obterValorBase(float distancia) {
    if (distancia <= 5) {
        return 8.0;
    } else if (distancia <= 15) {
        return 12.0;
    } else if (distancia <= 30) {
        return 18.0;
    } else {
        return 25.0;
    }
}

float calcularSubtotal(float distancia) {
    float valorBase;
    float valorPorKm;
    float subtotal;

    valorBase = obterValorBase(distancia);
    valorPorKm = distancia * 1.20;

    subtotal = valorBase + valorPorKm;

    return subtotal;
}
float calcularAdicionalPeso(float peso, float subtotal) {
    float percentual;

    if (peso <= 2) {
        percentual = 0.0;
    } else if (peso <= 5) {
        percentual = 0.05;
    } else if (peso <= 10) {
        percentual = 0.10;
    } else {
        percentual = 0.20;
    }

    return subtotal * percentual;
}

float calcularAdicionalModalidade(int modalidade, float subtotal) {
    float percentual;

    switch (modalidade) {
        case 1:
            percentual = 0.0;
            break;

        case 2:
            percentual = 0.15;
            break;

        case 3:
            percentual = 0.30;
            break;

        default:
            percentual = 0.0;
    }

    return subtotal * percentual;
}

float calcularValorFinal(float subtotal, float adicionalPeso,
                         float adicionalModalidade, int protecao,
                         int tentativas) {
    float valorProtecao;
    float valorTentativas;
    float valorFinal;

    valorProtecao = 0.0;

    if (protecao == 1) {
        valorProtecao = 7.50;
    }

    valorTentativas = tentativas * 4.00;

    valorFinal = subtotal + adicionalPeso
                 + adicionalModalidade
                 + valorProtecao
                 + valorTentativas;

    return valorFinal;
}

/* FUNCOES DE APRESENTACAO */

void exibirResultadoEntrega(int numeroEntrega, float valorFinal) {
    printf("\n------------------------------\n");
    printf("Entrega numero: %d\n", numeroEntrega);
    printf("Valor final: R$ %.2f\n", valorFinal);
    printf("------------------------------\n");
}
