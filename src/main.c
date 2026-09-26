#include <stdio.h>

#define TARIFA_POR_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA_ADICIONAL 4.00

float lerDistancia(void);
float lerPeso(void);
int lerModalidade(void);
int lerProtecao(void);
int lerTentativasAdicionais(void);
int lerOpcaoContinuar(void);

float obterValorBase(float distancia);
float calcularSubtotal(float distancia);
float calcularAdicionalPeso(float peso, float subtotal);
float calcularAdicionalModalidade(int modalidade, float subtotal);
float calcularValorFinal(float subtotal, float adicionalPeso,
                         float adicionalModalidade, int protecao,
                         int tentativas);

void exibirResultadoEntrega(float valorFinal);
void exibirResumoFinal(int totalEntregas, float valorTotal,
                       int qtdEconomica, int qtdExpressa,
                       int qtdPrioritaria, float maiorValor,
                       float menorValor);

int main(void) {

    int totalEntregas = 0;
    float valorTotal = 0.0;
    int qtdEconomica = 0;
    int qtdExpressa = 0;
    int qtdPrioritaria = 0;
    float maiorValor = 0.0;
    float menorValor = 0.0;
    int continuar;

    printf("===== SIMULADOR DE ENTREGAS =====\n\n");

    do {

        float distancia = lerDistancia();
        float peso = lerPeso();
        int modalidade = lerModalidade();
        int protecao = lerProtecao();
        int tentativas = lerTentativasAdicionais();

        float subtotal = calcularSubtotal(distancia);
        float adicionalPeso = calcularAdicionalPeso(peso, subtotal);
        float adicionalModalidade =
            calcularAdicionalModalidade(modalidade, subtotal);

        float valorFinal = calcularValorFinal(
            subtotal,
            adicionalPeso,
            adicionalModalidade,
            protecao,
            tentativas
        );

        exibirResultadoEntrega(valorFinal);

        totalEntregas = totalEntregas + 1;
        valorTotal = valorTotal + valorFinal;

        if (modalidade == 1) {
            qtdEconomica = qtdEconomica + 1;
        } else if (modalidade == 2) {
            qtdExpressa = qtdExpressa + 1;
        } else {
            qtdPrioritaria = qtdPrioritaria + 1;
        }

        if (totalEntregas == 1) {
            maiorValor = valorFinal;
            menorValor = valorFinal;
        } else {

            if (valorFinal > maiorValor) {
                maiorValor = valorFinal;
            }

            if (valorFinal < menorValor) {
                menorValor = valorFinal;
            }
        }

        continuar = lerOpcaoContinuar();

    } while (continuar == 1);

    exibirResumoFinal(
        totalEntregas,
        valorTotal,
        qtdEconomica,
        qtdExpressa,
        qtdPrioritaria,
        maiorValor,
        menorValor
    );

    return 0;
}

float lerDistancia(void) {

    float distancia;

    do {

        printf("Informe a distancia da entrega (em km): ");
        scanf("%f", &distancia);

        if (distancia <= 0) {
            printf("Distancia invalida. Digite um valor maior que zero.\n");
        }

    } while (distancia <= 0);

    return distancia;
}

float lerPeso(void) {

    float peso;

    do {

        printf("Informe o peso da entrega (em kg): ");
        scanf("%f", &peso);

        if (peso <= 0) {
            printf("Peso invalido. Digite um valor maior que zero.\n");
        }

    } while (peso <= 0);

    return peso;
}

int lerModalidade(void) {

    int modalidade;

    do {

        printf("Escolha a modalidade (1-Economica, 2-Expressa, 3-Prioritaria): ");
        scanf("%d", &modalidade);

        if (modalidade < 1 || modalidade > 3) {
            printf("Modalidade invalida. Digite 1, 2 ou 3.\n");
        }

    } while (modalidade < 1 || modalidade > 3);

    return modalidade;
}

int lerProtecao(void) {

    int protecao;

    do {

        printf("Deseja contratar o servico de protecao? (1-Sim, 0-Nao): ");
        scanf("%d", &protecao);

        if (protecao != 0 && protecao != 1) {
            printf("Valor invalido. Digite 0 ou 1.\n");
        }

    } while (protecao != 0 && protecao != 1);

    return protecao;
}

int lerTentativasAdicionais(void) {

    int tentativas;

    do {

        printf("Quantidade de tentativas adicionais: ");
        scanf("%d", &tentativas);

        if (tentativas < 0) {
            printf("Valor invalido. Digite um numero maior ou igual a zero.\n");
        }

    } while (tentativas < 0);

    return tentativas;
}

int lerOpcaoContinuar(void) {

    int opcao;

    do {

        printf("\nDeseja processar outra entrega? (1-Sim, 0-Nao): ");
        scanf("%d", &opcao);

        if (opcao != 0 && opcao != 1) {
            printf("Valor invalido. Digite 0 ou 1.\n");
        }

    } while (opcao != 0 && opcao != 1);

    return opcao;
}

float obterValorBase(float distancia) {

    float valorBase;

    if (distancia <= 5.0) {
        valorBase = 8.00;
    } else if (distancia <= 15.0) {
        valorBase = 12.00;
    } else if (distancia <= 30.0) {
        valorBase = 18.00;
    } else {
        valorBase = 25.00;
    }

    return valorBase;
}

float calcularSubtotal(float distancia) {

    float valorBase = obterValorBase(distancia);
    float subtotal = valorBase + (distancia * TARIFA_POR_KM);

    return subtotal;
}

float calcularAdicionalPeso(float peso, float subtotal) {

    float percentual;

    if (peso <= 2.0) {
        percentual = 0.00;
    } else if (peso <= 5.0) {
        percentual = 0.05;
    } else if (peso <= 10.0) {
        percentual = 0.10;
    } else {
        percentual = 0.20;
    }

    return subtotal * percentual;
}

float calcularAdicionalModalidade(int modalidade, float subtotal) {

    float percentual;

    if (modalidade == 1) {
        percentual = 0.00;
    } else if (modalidade == 2) {
        percentual = 0.15;
    } else {
        percentual = 0.30;
    }

    return subtotal * percentual;
}

float calcularValorFinal(float subtotal, float adicionalPeso,
                         float adicionalModalidade, int protecao,
                         int tentativas) {

    float valorFinal = subtotal + adicionalPeso + adicionalModalidade;

    if (protecao == 1) {
        valorFinal = valorFinal + VALOR_PROTECAO;
    }

    valorFinal = valorFinal + (tentativas * VALOR_TENTATIVA_ADICIONAL);

    return valorFinal;
}

void exibirResultadoEntrega(float valorFinal) {

    printf("\nValor final da entrega: R$ %.2f\n", valorFinal);
}

void exibirResumoFinal(int totalEntregas, float valorTotal,
                       int qtdEconomica, int qtdExpressa,
                       int qtdPrioritaria, float maiorValor,
                       float menorValor) {

    printf("\n===== RESUMO DA SESSAO =====\n");
    printf("Total de entregas processadas: %d\n", totalEntregas);

    if (totalEntregas > 0) {

        float valorMedio = valorTotal / totalEntregas;

        printf("Valor total das entregas: R$ %.2f\n", valorTotal);
        printf("Valor medio das entregas: R$ %.2f\n", valorMedio);
        printf("Entregas Economicas: %d\n", qtdEconomica);
        printf("Entregas Expressas: %d\n", qtdExpressa);
        printf("Entregas Prioritarias: %d\n", qtdPrioritaria);
        printf("Maior valor de entrega: R$ %.2f\n", maiorValor);
        printf("Menor valor de entrega: R$ %.2f\n", menorValor);

    } else {

        printf("Nenhuma entrega foi processada nesta sessao.\n");
    }
}
