#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
typedef struct lista Lista;

// Funcoes basicas de lista
Lista *Criar();
void MostrarLista(Lista *l);
int qtdPkgs(Lista *l);
int listaVazia(Lista *l);
int inserirInicio(Lista *l, char *p);
int inserirFim(Lista *l, char *p);
int buscarPkg(Lista *l, char *p);

// FILE

int F_carregarOld(Lista *l, FILE *fl);
int F_carregarAtual(Lista *l, FILE *fl);
int F_salvarDiff(Lista *l1, Lista *l2);

#endif // LISTA_H_INCLUDED