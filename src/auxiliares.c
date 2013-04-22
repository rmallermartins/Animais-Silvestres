#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void verificaPasta(char *nome){
	struct stat st;
	if (stat(nome, &st) == -1)
		mkdir(nome, 0777);
}

void verificaArquivo(char *nome){
	FILE *arquivo = fopen(nome,"r");
	if (arquivo==NULL)
		arquivo=fopen(nome,"w");
	fclose(arquivo);
}

FILE *abrirArq(char *arquivo, char *tipoAbertura){
	return fopen(arquivo,tipoAbertura);
}



