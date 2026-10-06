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

no auxinsere_qualquer(no *antigo,int v,int pos){
    no * nova,* aux = NULL, *aux1;
    int cont;
    nova = (no*)malloc(sizeof(no));
    nova -> info = v;
    nova -> prox = NULL;
    aux1 = antigo;
    cont = 1;

while((aux1!=NULL)&&(cont<pos)){
    aux=aux1;
    aux1 = aux1 -> prox;
    cont++;
}

if(aux==NULL){
    novo -> prox = antigo;
    return novo;
}
    novo -> prox = aux1;
    aux -> prox = novo;
    return antigo;
}

void insere_qualquer(lista *velho,int valor,int pos){
    velho -> inicio = auxinsere_qualquer(velho -> inicio,valor,pos);
}

no *auxremove_qualquer(no *antigo, int pos) {

    no *aux = NULL, *aux1;
    int cont = 1;

    aux1 = antigo;

    while ((aux1 != NULL) && (cont < pos)) {

        aux = aux1;
        aux1 = aux1->prox;
        cont++;
    }

    if (aux1 == NULL) {
        return antigo;
    }

    if (aux == NULL) {
        antigo = antigo->prox;
        free(aux1);
        return antigo;
    }

    aux->prox = aux1->prox;
    free(aux1);
    return antigo;
}

void remove_qualquer(lista *velho, int pos) {
    if(velho == NULL){
        printf("A lista não existe");
    }
    if(velho -> inicio == NULL){
        printf("A lista está vazia");
    }

    if(pos<=0){
        printf("A posição não existe");
    }
    velho->inicio = auxremove_qualquer(velho->inicio, pos);
}

no *auxlocaliza(no *inicio, int valor) {
    no *aux1 = inicio;

    while (aux1 != NULL) {

        if (aux1->info == valor) {
                return aux1;
        }
        aux1 = aux1->prox;
    }
}
// arrumar o localiza
no *localiza(lista *velho, int valor) {
    if (velho == NULL) {
        return NULL;
    }
    return auxlocaliza(velho->inicio, valor);
}

// arrumar ordenado
no *auxinsere_ordenado(no *inicio, int v) {
    no *nova, *aux = NULL, *aux1;

    nova = (no*)malloc(sizeof(no));
    nova->info = v;
    nova->prox = NULL;

    aux1 = inicio;

    while ((aux1 != NULL) && (aux1->info < v)) {
        aux = aux1;
        aux1 = aux1->prox;
    }

    if (aux == NULL) {
        nova->prox = inicio;
        return nova;
    }

    nova->prox = aux1;
    aux->prox = nova;
    return inicio;
}

lista *ordena_lista(lista *velho) {
    if (velho == NULL) {
        return NULL;
    }

    lista *nova_lista = crialista();
    no *aux1 = velho->inicio;

    while (aux1 != NULL) {
        nova_lista->inicio = auxinsere_ordenado(nova_lista->inicio, aux1->info);
        aux1 = aux1->prox;
    }

    return nova_lista;
}

void auxexibir(no *inicio) {
    no *aux1 = inicio;
    int pos = 1;

    if (aux1 == NULL) {
        printf("A lista de solicitacoes esta vazia.\n");
        return;
    }

    printf("\n Lista de Solicitações de Manutenção:\n");
    while (aux1 != NULL) {

        printf("Elemento %d -> Info: %d\n", pos, aux1->info);

        aux1 = aux1->prox;
        pos++;
    }
}

void exibir_lista(lista *velho) {
    if (velho == NULL) {
        printf("A lista informada e invalida (NULL).\n");
        return;
    }
    auxexibir(velho->inicio);
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
