#include <stdio.h>
#include "../headers/lista.h"

int main() {

    Lista *pkgOld = Criar();
    FILE *fileOld;

    Lista *pkgAtual = Criar();
    FILE *fileAtual;

    F_carregarOld(pkgOld, fileOld);
    F_carregarAtual(pkgAtual, fileAtual);
    F_salvarDiff(pkgOld, pkgAtual);

    return 0;
}