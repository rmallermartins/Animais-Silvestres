#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <stdio.h>

#define arquivos "Arquivos/"

#define especie arquivos"especies.txt"
#define especieIndice arquivos"especiesIndice.txt"

#define individuo arquivos"individuos.txt"
#define individuoIndice arquivos"individuosIndice.txt"

#define captura arquivos"capturas.dat"
#define capturaIndice arquivos"capturasIndice.txt"

void verificaPasta(char *nome);

void verificaArquivo(char *nome);

FILE *abrirArq(char *arquivo, char *tipoAbertura);

#endif
