Trabalho B1 - Lógica de Programação e Algoritmos

Descrição

Este trabalho é um simulador de entregas em linguagem C, executado no terminal. O programa permite informar os dados de cada entrega, como distância, peso, modalidade, proteção e tentativas adicionais. Com essas informações, calcula o valor de cada entrega e, ao final, apresenta um resumo com os valores e as quantidades de entregas realizadas.

Funcionalidades

* Cadastro de várias entregas em uma mesma execução.
* Validação dos dados informados pelo usuário.
* Cálculo do valor de cada entrega considerando:
* Valor-base conforme a distância.
* Valor por quilômetro rodado.
* Adicional de peso.
* Adicional de modalidade.
* Proteção adicional.
* Tentativas adicionais de entrega.
* Exibição do valor final de cada entrega.
* Resumo final com quantidade total, valor total, valor médio, quantidade por modalidade, maior e menor valor.

Organização da solução

O código foi organizado em funções para facilitar a leitura e a realização das tarefas do programa.

As funções de leitura e validação são responsáveis por receber os dados informados pelo usuário e verificar se os valores são válidos.

As funções de cálculo são responsáveis por calcular o valor-base, o subtotal, os adicionais de peso e modalidade e o valor final da entrega.

As funções de apresentação mostram o resultado de cada entrega e o resumo final da sessão.

A função main coordena o funcionamento do programa, controla a repetição das entregas e mantém os valores utilizados no resumo final.

Compilação

No terminal, dentro da pasta src, compile com:

gcc main.c -o main

Execução

Depois de compilar, execute com:

./main

No Windows, o executável normalmente é main.exe, que pode ser executado com:

main.exe

O programa solicita os dados de cada entrega e pergunta se o usuário deseja processar outra. Ao digitar 0, a sessão é encerrada e o resumo final é exibido.

Uso de Inteligência Artificial
Durante o desenvolvimento deste trabalho, utilizei o ChatGPT para esclarecer dúvidas sobre programação em C e entender melhor alguns erros que apareceram no código.

Quando tinha dúvidas sobre como fazer alguma parte do programa, pedia ajuda para entender como poderia resolver. Também utilizei a ferramenta para identificar erros no código e entender por que eles aconteciam.


Fontes consultadas

* Material e orientações disponibilizados pelo professor.
* ChatGPT, utilizado para esclarecer dúvidas sobre programação em C e entender os erros no código.

