#ifndef BIB_P1_H_INCLUDED
#define BIB_P1_H_INCLUDED


typedef struct no{
int info;
struct no *prox;
}no;

typedef struct lista{
no *inicio;

}lista;

lista *inicializa_lista{
return NULL;
}

lista *crialista(){
lista *aux;
aux = (lista*)malloc(sizeof(lista));
aux -> inicio = NULL;
return aux;
}

no auxinsere_qualquer(no *antigo,int v,int pos){
no * nova,* aux = NULL, *aux1;
int cont
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
    int cont;

    if (antigo == NULL) {
        return NULL;
    }

    aux1 = antigo;
    cont = 1;

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

    return NULL;
}

no *localiza(lista *velho, int valor) {
    if (velho == NULL) {
        return NULL;
    }
    return auxlocaliza(velho->inicio, valor);
}

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
}


#endif
