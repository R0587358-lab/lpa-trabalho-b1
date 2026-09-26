#include <stdio.h>

/* FUNCOES DE LEITURA E VALIDACAO */

float lerDistancia() {
    float distancia;
    int resultado;

    do {
        printf("Digite a distancia em km: ");
        resultado = scanf("%f", &distancia);

        if (resultado != 1) {
            printf("Entrada invalida! Digite um numero.\n");
   
            while (getchar() != '\n');
            distancia = 0;
           }else if (distancia <= 0) {
            printf("Distancia invalida! Digite novamente.\n");
        }
    } while (distancia <= 0);

    return distancia;
}
float lerPeso() {
    float peso;
    int resultado;

    do {
        printf("Digite o peso da entrega em kg: ");
        resultado = scanf("%f", &peso);

        if (resultado != 1) {
            printf("Entrada invalida! Digite um numero.\n");

            while (getchar() != '\n');
            peso = 0;

        } else if (peso <= 0) {
            printf("Peso invalido! Digite novamente.\n");
        }

    } while (peso <= 0);

    return peso;
}

int lerModalidade() {
    int modalidade;
     int resultado;
    do {
        printf("\n===== MODALIDADES DE ENTREGA =====\n");
        printf("1 - Economica (sem adicional)\n");
        printf("2 - Expressa (15%% de adicional)\n");
        printf("3 - Prioritaria (30%% de adicional)\n");
        printf("Escolha uma opcao: ");
        resultado = scanf("%d", &modalidade);

        if (resultado != 1) {

            printf("Entrada invalida! Digite 1, 2 ou 3.\n");

            while (getchar() != '\n');

            modalidade = 0;

        } else if (modalidade < 1 || modalidade > 3) {

            printf("Opcao invalida! Escolha 1, 2 ou 3.\n");

        }

    } while (modalidade < 1 || modalidade > 3);

    return modalidade;
}

int lerProtecao() {
int protecao;
int resultado;

do {
    printf("Deseja protecao? (1 - Sim / 0 - Nao): ");
    resultado = scanf("%d", &protecao);

    if (resultado != 1) {
        printf("Entrada invalida! Digite 1 ou 0.\n");

        while (getchar() != '\n');
        protecao = -1;

    } else if (protecao != 0 && protecao != 1) {
        printf("Opcao invalida! Digite 1 ou 0.\n");
    }

} while (protecao != 0 && protecao != 1);

return protecao;
}

int lerTentativasAdicionais() {
    int tentativas;

    int resultado;

do {
    printf("Digite a quantidade de tentativas adicionais: ");
    resultado = scanf("%d", &tentativas);

    if (resultado != 1) {
        printf("Entrada invalida! Digite um numero inteiro.\n");

        while (getchar() != '\n');
        tentativas = -1;

    } else if (tentativas < 0) {
        printf("Quantidade invalida! Digite zero ou um numero positivo.\n");
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

void exibirResumoFinal(int quantidade, float valorTotal,
                       int economica, int expressa,
                       int prioritaria, float maiorValor,
                       float menorValor) {
    float media;

    printf("\n===== RESUMO FINAL =====\n");
    printf("Quantidade de entregas: %d\n", quantidade);
    printf("Valor total: R$ %.2f\n", valorTotal);

    if (quantidade > 0) {
        media = valorTotal / quantidade;
        printf("Media por entrega: R$ %.2f\n", media);
        printf("Maior entrega: R$ %.2f\n", maiorValor);
        printf("Menor entrega: R$ %.2f\n", menorValor);
    }

    printf("Economicas: %d\n", economica);
    printf("Expressas: %d\n", expressa);
    printf("Prioritarias: %d\n", prioritaria);
}
/* FUNCAO PRINCIPAL */

int main() {
    float distancia;
    float peso;
    float subtotal;
    float adicionalPeso;
    float adicionalModalidade;
    float valorFinal;

    float valorTotal = 0.0;
    float maiorValor = 0.0;
    float menorValor = 0.0;

    int modalidade;
    int protecao;
    int tentativas;
    int continuar;

    int quantidade = 0;
    int economica = 0;
    int expressa = 0;
    int prioritaria = 0;

    printf("==================================\n");
    printf("     SIMULADOR DE ENTREGAS\n");
    printf("==================================\n");

    do {
        printf("\n--- NOVA ENTREGA ---\n");

        distancia = lerDistancia();
        peso = lerPeso();
        modalidade = lerModalidade();
        protecao = lerProtecao();
        tentativas = lerTentativasAdicionais();

        subtotal = calcularSubtotal(distancia);

        adicionalPeso = calcularAdicionalPeso(peso, subtotal);

        adicionalModalidade =
            calcularAdicionalModalidade(modalidade, subtotal);

        valorFinal = calcularValorFinal(
            subtotal,
            adicionalPeso,
            adicionalModalidade,
            protecao,
            tentativas
        );

        quantidade++;
        valorTotal = valorTotal + valorFinal;

        if (quantidade == 1) {
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

        switch (modalidade) {
            case 1:
                economica++;
                break;

            case 2:
                expressa++;
                break;

            case 3:
                prioritaria++;
                break;
        }

        exibirResultadoEntrega(quantidade, valorFinal);

        continuar = lerOpcaoContinuar();

    } while (continuar == 1);

    exibirResumoFinal(
        quantidade,
        valorTotal,
        economica,
        expressa,
        prioritaria,
        maiorValor,
        menorValor
    );

    return 0;
}
