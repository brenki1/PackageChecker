#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
typedef struct lista Lista;

// Funcoes basicas de lista
Lista *Criar();
void MostrarLista();
int qtdPkgs(Lista *l);
int listaVazia(Lista *l);
int inserirInicio(Lista *l, char *p);
int inserirFim(Lista *l, char *p);
int buscarPkg(Lista *l, char *p);

// FILE

int F_carregar(Lista *l, FILE *fl);
int F_salvarDiff(Lista *l, FILE *f1);

#endif // LISTA_H_INCLUDED