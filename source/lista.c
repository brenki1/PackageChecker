#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/lista.h"

typedef struct no {
    char pkg[350];
    struct no *prox;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *Criar() {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if(l->inicio == NULL) return 0;

    return 1;
}

int inserirInicio(Lista *l, char *p) {
    if (l == NULL) return 2;

    No *no = (No*)malloc(sizeof(No));
    strcpy(no->pkg, p);
    no->prox = l->inicio;
    l->inicio = no;

    return 0;
}

