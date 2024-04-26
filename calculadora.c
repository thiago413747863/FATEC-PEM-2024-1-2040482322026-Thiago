#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define soma '+'
#define subtracao '-'
#define mutiplicacao '*'
#define divisao '/'

void obteroperacao(char* operacao) {
    printf("Digite a operação desejada (+, -, *, / ou 's' para sair): ");
    scanf("%s", operacao);
}
float realizaroperacao(float operando1, float operando2, char* operador) {
    if (strlen(operador) != 1) {
        printf("Operação inválida!\n");
        exit(EXIT_FAILURE);
    }

    switch (operador[0]) {
        case soma:
            return operando1 + operando2;
        case subtracao:
            return operando1 - operando2;
        case mutiplicacao:
            return operando1 * operando2;
        case divisao:
            if (operando2 != 0)
                return operando1 / operando2;
            else {
                printf("Erro: divisão por zero!\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Operação inválida!\n");
            exit(EXIT_FAILURE);
    }
}
int main() {
    float resultado = 0, operando;
    char operacao[2];
    char sugestoes[][50] = {"Digite o primeiro número: ", "Digite o segundo número: "};

    printf("Calculadora: Digite 's' para sair.\n");

    do {
        if (resultado != 0) {
            printf("Resultado anterior: %.2f\n", resultado);
            operando = resultado;
        } else {
            printf("%s", sugestoes[0]);
            scanf("%f", &operando);
        }
        obteroperacao(operacao);
        if (strcmp(operacao, "s") == 0) {
            printf("Fim!\n");
            break;
        }
        printf("%s", sugestoes[1]);
        scanf("%f", &resultado);
        resultado = realizaroperacao(operando, resultado, operacao);
        printf("Resultado: %.2f\n", resultado);

    } while (1);
    return 0;
}
