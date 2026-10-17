#ifndef BIB_P1_H_INCLUDED
#define BIB_P1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct equipamento {
    int cod_sltc;
    char cod_equip[8];
    char nome_equip[22];
    int prioridade;
    int periodo;
} equipamento;

char * obter_periodo(int p){

    if( p == 1 ){
        return "entre 1 e 7 dias";
    }

    if( p == 2 ){
        return "entre 1 e 15 dias";
    }

    if( p == 3){
        return "entre 1 e 20 dias";
    }
    return "período inválido";
}

typedef struct no{
    int codigo_sol;
    char cod_equip[8];
    char nome_equip[22];
    int prioridade;
    int periodo;
    struct no *prox;
} no;

typedef struct lista{
    no *inicio;
} lista;

lista *inicializa_lista(lista *L) {
    if (L != NULL) {
        L->inicio = NULL;
    }
    return L;
}

lista *crialista(){
    lista *aux;
    aux = (lista*)malloc(sizeof(lista));
    if (aux != NULL) {
        aux -> inicio = NULL;
    }
    return aux;
}

no *consultar_solicitacao_silencioso(lista *L, int cod_sltc) {
    if (L == NULL || L->inicio == NULL) return NULL;
    no *aux = L->inicio;
    while (aux != NULL) {
        if (aux->codigo_sol == cod_sltc) return aux;
        aux = aux->prox;
    }
    return NULL;
}

lista *liberar_lista(lista *L) {
    if (L == NULL) return NULL;
    no *aux = L->inicio;
    while (aux != NULL) {
        no *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    L->inicio = NULL;
    free(L);
    return NULL;
}

int ler_codigo_solicitacao(const char *mensagem) {
    int codigo = 0;
    int flag = 0;

    do {
        printf("%s", mensagem);
        flag = scanf("%d", &codigo);

        if (flag != 1) {
            printf("Valor invalido! Digite um numero inteiro.\n\n");
            while (getchar() != '\n');
            flag = 0;
        } else if (codigo < 1000 || codigo > 9999) {
            printf("O codigo deve ter exatamente 4 digitos (1000 a 9999).\n\n");
            flag = 0;
        }
    } while (flag != 1);

    return codigo;
}

lista *InsereNovaSol(lista *L, equipamento novo_equip) {
    no *aux, *ant = NULL;

    aux = L->inicio;

    while (aux != NULL && novo_equip.cod_sltc < aux->codigo_sol) {
        ant = aux;
        aux = aux->prox;
    }

    no *novo = (no*)malloc(sizeof(no));

    novo->codigo_sol = novo_equip.cod_sltc;
    strcpy(novo->cod_equip, novo_equip.cod_equip);
    strcpy(novo->nome_equip, novo_equip.nome_equip);
    novo->prioridade = novo_equip.prioridade;
    novo->periodo = novo_equip.periodo;

    novo->prox = aux;

    if (ant == NULL) {
        L->inicio = novo;
    } else {
        ant->prox = novo;
    }

    return L;
}

lista *remove_solicitacao(lista *L, int cod_sltc) {
    if (L == NULL || L->inicio == NULL) {
        printf("A lista esta vazia ou invalida!\n");
        return L;
    }

    no *aux = L->inicio;
    no *ant = NULL;

    while (aux != NULL && aux->codigo_sol != cod_sltc) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Solicitacao com o codigo %d nao foi encontrada.\n", cod_sltc);
        return L;
    }

    if (ant == NULL) {
        L->inicio = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    free(aux);
    printf("Solicitacao %d removida com sucesso!\n", cod_sltc);

    return L;
}

void consultar_solicitacao(lista *L, int cod_sltc) {
    if (L == NULL || L->inicio == NULL) {
        printf("A lista esta vazia ou invalida!\n");
    } else {
        no *aux = L->inicio;

        while (aux != NULL && aux->codigo_sol != cod_sltc) {
            aux = aux->prox;
        }

        if (aux != NULL) {
            printf("Codigo da Solicitacao : %d \n", aux->codigo_sol);
            printf("Codigo do Equipamento : %s \n", aux->cod_equip);
            printf("Nome do Equipamento   : %s \n", aux->nome_equip);
            printf("Prioridade            : %d \n", aux->prioridade);
            printf("Periodo               : %d dias (%s) \n", aux->periodo, obter_periodo(aux->prioridade));
        } else {
            printf("\nSolicitacao com o codigo %d nao foi encontrada.\n", cod_sltc);
        }
    }
}

int validar_periodo(int prioridade, int periodo) {
    if (prioridade == 1 && (periodo >= 1 && periodo <= 7)) return 1;
    if (prioridade == 2 && (periodo >= 1 && periodo <= 15)) return 1;
    if (prioridade == 3 && (periodo >= 1 && periodo <= 20)) return 1;
    return 0;
}

void alterar_prioridade_periodo(lista *L, int cod_sltc) {
    if (L == NULL || L->inicio == NULL) {
        printf("\nA lista esta vazia ou invalida!\n");
    } else {
        no *aux = L->inicio;

        while (aux != NULL && aux->codigo_sol != cod_sltc) {
            aux = aux->prox;
        }

        if (aux == NULL) {
            printf("\nSolicitacao com o codigo %d nao foi encontrada.\n", cod_sltc);
        } else {
            printf("\nSolicitacao: %d | Equipamento: %s", aux->codigo_sol, aux->nome_equip);
            printf("\nPrioridade Atual: %d | Período Atual: %d dias", aux->prioridade, aux->periodo);

            int nova_prioridade = 0;
            int novo_periodo = 0;
            int flag = 0;

            do {
                printf("Digite a nova prioridade (1 - Alta | 2 - Média | 3 - Baixa): ");
                if (scanf("%d", &nova_prioridade) != 1 || nova_prioridade < 1 || nova_prioridade > 3) {
                    printf("Valor invalido! Digite um numero entre 1 e 3.\n\n");
                    while (getchar() != '\n');
                    flag = 0;
                } else {
                    flag = 1;
                }
            } while (flag != 1);

            do {
                printf("A nova prioridade e %d (%s).\n", nova_prioridade, obter_periodo(nova_prioridade));
                printf("Digite o novo periodo em dias: ");

                if (scanf("%d", &novo_periodo) != 1 || !validar_periodo(nova_prioridade, novo_periodo)) {
                    printf("Periodo fora do limite permitido para esta prioridade!\n\n");
                    while (getchar() != '\n');
                    flag = 0;
                } else {
                    flag = 1;
                }
            } while (flag != 1);

            aux->prioridade = nova_prioridade;
            aux->periodo = novo_periodo;

            printf("\nPrioridade e periodo atualizados com sucesso!\n");
        }
    }
}

no *auxinsere_ordem_manutencao(no *inicio, no *origem) {
    no *novo = (no*)malloc(sizeof(no));
    if (novo == NULL) return inicio;

    novo->codigo_sol = origem->codigo_sol;
    strcpy(novo->cod_equip, origem->cod_equip);
    strcpy(novo->nome_equip, origem->nome_equip);
    novo->prioridade = origem->prioridade;
    novo->periodo = origem->periodo;
    novo->prox = NULL;

    no *aux = inicio;
    no *ant = NULL;

    while (aux != NULL) {

        if (novo->prioridade < aux->prioridade) {
            break;
        }
        else if (novo->prioridade == aux->prioridade) {

            if (novo->periodo < aux->periodo) {
                break;
            }
            else if (novo->periodo == aux->periodo) {

                if (novo->codigo_sol < aux->codigo_sol) {
                    break;
                }
            }
        }
        ant = aux;
        aux = aux->prox;
    }

    if (ant == NULL) {
        novo->prox = inicio;
        return novo;
    } else {
        novo->prox = aux;
        ant->prox = novo;
        return inicio;
    }
}

void exibir_ordem_manutencao(lista *L) {
    if (L == NULL || L->inicio == NULL) {
        printf("A lista de solicitacoes esta vazia.\n");
    } else {
        lista *lista_temp = crialista();
        no *aux_origem = L->inicio;

        while (aux_origem != NULL) {
            lista_temp->inicio = auxinsere_ordem_manutencao(lista_temp->inicio, aux_origem);
            aux_origem = aux_origem->prox;
        }

        printf(" Ordem de realização de Manutenções:");

        no *aux_temp = lista_temp->inicio;
        int ordem = 1;

        while (aux_temp != NULL) {
            printf("\n %dº a ser atendido:", ordem++);
            printf("\n    Codigo Solicitacao : %d", aux_temp->codigo_sol);
            printf("\n    Equipamento        : %s (%s)", aux_temp->nome_equip, aux_temp->cod_equip);
            printf("\n    Prioridade         : %d | Periodo: %d dias", aux_temp->prioridade, aux_temp->periodo);
            printf("\n");
            aux_temp = aux_temp->prox;
        }
        printf("\n");
        liberar_lista(lista_temp);
    }
}

void exibir_lista(lista *L) {
    if (L == NULL || L->inicio == NULL) {
        printf("A lista de solicitacoes esta vazia.\n");
    } else {
        no *aux = L->inicio;
        int contador = 1;

        while (aux != NULL) {
            printf("\n Solicitacao #%d:", contador++);
            printf("\n    Codigo da Solicitacao : %d", aux->codigo_sol);
            printf("\n    Codigo do Equipamento : %s", aux->cod_equip);
            printf("\n    Nome do Equipamento   : %s", aux->nome_equip);
            printf("\n    Prioridade            : %d (%s)", aux->prioridade, obter_periodo(aux->prioridade));
            printf("\n    Periodo               : %d dias", aux->periodo);
            printf("\n");

            aux = aux->prox;
        }
        printf("\n");
    }
}

#endif
