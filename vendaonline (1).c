#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int estoque;
} Produto;

void inserirProduto(Produto *produtos, int *quantidadeProdutos);
void comprarProduto(Produto *produtos, int quantidadeProdutos);
void listarProdutos(Produto *produtos, int quantidadeProdutos);
void bubblesort(Produto *produtos, int quantidadeProdutos);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidadeProdutos = 0;
    int escolha;

    while (1) {
        printf("\n1 - Inserir novo produto\n");
        printf("2 - Comprar produto\n");
        printf("3 - Listar produtos disponíveis\n");
        printf("4 - Finalizar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inserirProduto(produtos, &quantidadeProdutos);
                break;
            case 2:
                comprarProduto(produtos, quantidadeProdutos);
                break;
            case 3:
                listarProdutos(produtos, quantidadeProdutos);
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}

void inserirProduto(Produto *produtos, int *quantidadeProdutos) {
    if (*quantidadeProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto *p = &produtos[*quantidadeProdutos];
    printf("ID do produto: ");
    scanf("%d", &p->id);
    printf("Nome do produto: ");
    scanf(" %[^\n]%*c", p->nome);
    printf("Descrição do produto: ");
    scanf(" %[^\n]%*c", p->descricao);
    printf("Preço unitário: ");
    scanf("%f", &p->preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &p->estoque);

    (*quantidadeProdutos)++;
    printf("Produto inserido com sucesso!\n");
}

void comprarProduto(Produto *produtos, int quantidadeProdutos) {
    if (quantidadeProdutos == 0) {
        printf("Nenhum produto disponível para compra!\n");
        return;
    }

    int id, quantidade, escolha;
    while (1) {
        printf("ID do produto que deseja comprar: ");
        scanf("%d", &id);

        int encontrado = 0;
        for (int i = 0; i < quantidadeProdutos; i++) {
            if (produtos[i].id == id) {
                encontrado = 1;
                while (1) {
                    printf("Quantidade que deseja comprar: ");
                    scanf("%d", &quantidade);
                    if (quantidade <= produtos[i].estoque) {
                        produtos[i].estoque -= quantidade;
                        printf("Compra realizada com sucesso!\n");
                        printf("Produto: %s\n", produtos[i].nome);
                        printf("Quantidade: %d\n", quantidade);
                        printf("Preço total: %.2f\n", produtos[i].preco * quantidade);
                        printf("1: Finalizar compra\n2: Continuar comprando\n3: Cancelar e voltar para a seleção de ID\n");
                        scanf("%d", &escolha);
                        if (escolha == 1) {
                            return;
                        } else if (escolha == 2) {
                            break;
                        } else if (escolha == 3) {
                            return;
                        } else {
                            printf("Opção inválida! Retornando à seleção de ID.\n");
                        }
                    } else {
                        printf("Quantidade insuficiente em estoque!\n");
                    }
                }
                break;
            }
        }
        if (!encontrado) {
            printf("ID do produto inexistente!\n");
        }
    }
}

void listarProdutos(Produto *produtos, int quantidadeProdutos) {
    if (quantidadeProdutos == 0) {
        printf("Nenhum produto disponível!\n");
        return;
    }

    bubblesort(produtos, quantidadeProdutos);

    printf("Produtos disponíveis:\n");
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Preço unitário: %.2f\n", produtos[i].preco);
        printf("Quantidade em estoque: %d\n\n", produtos[i].estoque);
    }
}

void bubblesort(Produto *produtos, int quantidadeProdutos) {
    for (int i = 0; i < quantidadeProdutos - 1; i++) {
        for (int j = 0; j < quantidadeProdutos - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}
