#ifndef BIB_P1_H_INCLUDED
#define BIB_P1_H_INCLUDED
#include <string.h>

typedef struct equipamento {
    int cod_sltc;
    char cod_equip[8];
    char nome_equip[22];
    int prioridade;
    int periodo;
}equipamento;


typedef struct no{
    int codigo_sol;
    char cod_equip[8];
    char nome_equip[22];
    int prioridade;
    int periodo;
    struct no *prox;
}no;

typedef struct lista{
    no *inicio;
}lista;

lista *inicializa_lista(lista *L) {
    L->inicio = NULL;

    return L;
}

lista *crialista(){
    lista *aux;
    aux = (lista*)malloc(sizeof(lista));
    aux -> inicio = NULL;
    return aux;
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

void exibir_lista(lista *L) {
    no *aux = L->inicio;

    while (aux != NULL) {
        printf("\nCodigo da solicitacao: %d", aux->codigo_sol);
        printf("\nCodigo do equipamento: %s", aux->cod_equip);
        printf("\nNome do equipamento: %s", aux->nome_equip);
        printf("\nPrioridade: %d", aux->prioridade);
        printf("\nPeriodo: %d\n", aux->periodo);

        aux = aux->prox;
    }
}


#endif
