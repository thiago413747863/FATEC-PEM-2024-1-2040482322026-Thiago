#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50

typedef struct {
    char nome[50];
    double nota;
} Aluno;

int incluiraluno(Aluno alunos[], int nalunos);
void listaralunos(Aluno alunos[], int nalunos);
void bubbleSort(Aluno alunos[], int nalunos);

int main() {
    Aluno alunos[MAX_ALUNOS];
    int nalunos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                nalunos = incluiraluno(alunos, nalunos);
                break;
            case 2:
                bubbleSort(alunos, nalunos);
                listaralunos(alunos, nalunos);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        }
    } while (opcao != 3);

    return 0;
}

int incluiraluno(Aluno alunos[], int nalunos) {
    if (nalunos < MAX_ALUNOS) {
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", alunos[nalunos].nome);
        printf("Digite a nota do aluno (de 0 a 10): ");
        scanf("%lf", &alunos[nalunos].nota);

        nalunos++;
    } else {
        printf("Limite máximo de alunos atingido.\n");
    }
    return nalunos;
}

void listaralunos(Aluno alunos[], int nalunos) {
    printf("\nLista de alunos:\n");
    printf("Nome\t\tNota\tSituação\n");
    for (int i = 0; i < nalunos; i++) {
        printf("%-15s\t%.2lf\t", alunos[i].nome, alunos[i].nota);
        if (alunos[i].nota >= 6) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }
}

void bubbleSort(Aluno alunos[], int nalunos) {
    int i, j;
    Aluno temp;

    for (i = 0; i < nalunos - 1; i++) {
        for (j = 0; j < nalunos - i - 1; j++) {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

