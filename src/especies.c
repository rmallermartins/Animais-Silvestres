#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/especies.h"
#include "hdr/auxiliares.h"

void inserirEspecie(){
	int id;
	char nomeCientifico[50];
	char nomePopular[50];
	char descricao[1000];
	
	printf("\nID: ");
	scanf("%d",&id);
	getchar();
	printf("\nNome Cientifico da Espécie: ");
	scanf("%[^\n]s", nomeCientifico);
	setbuf(stdin, NULL);
	printf("\nNome Popular da Espécie: ");
	scanf("%[^\n]s", nomePopular);
	setbuf(stdin, NULL);
	printf("\nDe uma breve descrição sobre o animal: ");
	scanf("%[^\n]s", descricao);
	setbuf(stdin, NULL);

	
	int indice = verificaIdEspecie(id);
	if (indice != -1){
		FILE *arquivo = abrirArq(especie,"r+");
        	fseek(arquivo,0,SEEK_END);
		fprintf(arquivo,"id = %d\nnome cientifico = %s\nnome popular = %s\ndescrição = %s\n#\n",id,nomeCientifico,nomePopular,descricao);
		fclose(arquivo);

		FILE *arquivoIndice = abrirArq(especieIndice,"r+");
		fseek(arquivoIndice,0,SEEK_END);
		fprintf(arquivoIndice,"%d NORMAL\n",indice);
		fclose(arquivoIndice);
	}
	else printf("Id ja existe. Retornando\n");
}

int buscarEspecie(){
	int id;
	char linha[50];
	FILE *arquivo = abrirArq(especie,"r");
	FILE *arquivoIndice = abrirArq(especieIndice,"r");

	printf("ID: ");
	scanf("%d",&id);
	while (fgets(linha,50,arquivoIndice)!=NULL){
		int indice;
		char comparacao[50];
		int id2;
		sscanf(linha,"%d %s",&indice,comparacao);
		fseek(arquivo,indice,SEEK_SET);
		fgets(linha,50,arquivo);
		sscanf(linha,"%*[^0-9] %d",&id2);
		if (id == id2 && strcmp(comparacao,"REMOVIDO")!=0){
			fclose(arquivo);
			fclose(arquivoIndice);
			return indice;
		}
	}
	fclose(arquivo);
	fclose(arquivoIndice);
	printf("Espécie não encontrada.\n");
	return -1;
}

void removerEspecie(){
	int id;
	int indice;
	printf("ID: ");
	scanf("%d",&id);
	indice = buscarEspecie(id);
	if (indice != -1){
		char linha[50];
		FILE *arquivoIndice = abrirArq(especieIndice,"r+");
		int achou = 0;
		while (!achou){
			int indice2;
			int posArqIndice = ftell(arquivoIndice);
			fgets(linha,50,arquivoIndice);
			sscanf(linha,"%d",&indice2);
			if(indice == indice2){
				fseek(arquivoIndice,posArqIndice,SEEK_SET);
				fprintf(arquivoIndice,"%d REMOVIDO",indice);
				printf("Especie Removida.\n");
			}
		}
		fclose(arquivoIndice);
	}
	else printf("Espécie não encontrada.\n");
}

void imprimirEspecie(int indice){
	if (indice != -1){
		char linha[50];
		FILE *arquivo = abrirArq(especie,"r");
		fseek(arquivo,indice,SEEK_SET);
		fgets(linha,50,arquivo);
		while (strcmp(linha,"#\n")!=0){
			fprintf(stdout,"%s",linha);
			fgets(linha,50,arquivo);
		}
		fclose(arquivo);
	}
}

int verificaIdEspecie(int id){
        char linha[50];
	int indice;
        FILE *arquivo = abrirArq(especie,"r");
        FILE *arquivoIndice = abrirArq(especieIndice,"r");

        while (fgets(linha,50,arquivoIndice)!=NULL){
                char comparacao[50];
                int id2;
                sscanf(linha,"%d %s",&indice,comparacao);
                fseek(arquivo,indice,SEEK_SET);
                fgets(linha,50,arquivo);
                sscanf(linha,"%*[^0-9] %d",&id2);
                if (id == id2 && strcmp(comparacao,"REMOVIDO")!=0){
                        fclose(arquivo);
                        fclose(arquivoIndice);
                        return -1;
                }
		return indice;
        }
        fclose(arquivo);
        fclose(arquivoIndice);
	return 0;
}
