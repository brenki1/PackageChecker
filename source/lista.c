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

int inserirFim(Lista *l, char *p) {
    if (l == NULL) return 2;
    if(listaVazia(l) == 0) return inserirInicio(l, p);

    No *noLista = l->inicio;
    while(noLista->prox != NULL) noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    strcpy(no->pkg, p);
    no->prox = noLista->prox;
    noLista->prox = no;

    return 0;
}

int buscarPkg(Lista *l, char *p) {
    if (l == NULL) return 2;
    No *noLista = l->inicio;
    while((noLista != NULL)) {
        if ((strcmp(noLista->pkg, p)) == 0) {
            return 0;
        }
        noLista = noLista->prox;
    }

    return 1;
}

void MostrarLista(Lista *l) {
    if(l != NULL) {
        printf("[");
        No *noLista = l->inicio;
        
        while(noLista != NULL) {
            printf(" {%s} ", noLista->pkg);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int qtdPkgs(Lista *l) {

    int qtd = 0;

    No *noLista = l->inicio;

    while(noLista != NULL) {
        noLista = noLista->prox;
        qtd++;
    }

    return qtd;
}

int F_carregarOld(Lista *l, FILE *fl) {

    char pkgTemp[350];

    fl = fopen("pkglist.txt", "r");

    if(fl == NULL) {
        printf("Arquivo nao encontrado! Coloque 'pkglist.txt' no mesmo diretorio do executavel!\n");
        return -1;
    }

    while((fscanf(fl, "%s\n", pkgTemp)) != EOF) {
        inserirFim(l, pkgTemp);
    }

    fclose(fl);

    return 0;
}

int F_carregarAtual(Lista *l, FILE *fl) {

    char pkgTemp[350];

    fl = fopen("pkglistAtual.txt", "r");

    if(fl == NULL) {
        printf("Arquivo nao encontrado! Coloque 'pkglistAtual.txt' no mesmo diretorio do executavel!\n");
        return -1;
    }

    while((fscanf(fl, "%s\n", pkgTemp)) != EOF) {
        inserirFim(l, pkgTemp);
    }

    fclose(fl);

    return 0;
}

int F_salvarDiff(Lista *l1, Lista *l2) {

    int check; FILE *fdiff;

    fdiff = fopen("Packagediff.txt", "w+");

    No *noListaOld = l1->inicio;

    Lista *diff = Criar();

    while(noListaOld != NULL) {
        int check = (buscarPkg(l2, noListaOld->pkg));
        if(check != 0) {
            inserirFim(diff, noListaOld->pkg);
        }

        noListaOld = noListaOld->prox;
    }

    No *noListaDiff = diff->inicio;

    while(noListaDiff != NULL) {
        fprintf(fdiff, "%s\n", noListaDiff->pkg);
        noListaDiff = noListaDiff->prox;

    }

    fclose(fdiff);

    return 0;

}
