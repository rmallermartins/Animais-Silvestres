#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/individuos.h"
#include "hdr/auxiliares.h"

void inserirIndividuo(){
	int idEspecie;
	int id;
	char sexo;

	printf("\nID da espécie: ");
	scanf("%d",&idEspecie);
	getchar();
	printf("\nID do indivíduo: ");
	scanf("%d",&id);
	getchar();	
	printf("\nSexo do indivíduo: ");
	scanf("%c",&sexo);
	
	int indice = verificaIdIndividuo(id);
	if (indice != -1){
		FILE *arquivo = abrirArq(individuo,"r+");
		fseek(arquivo,0,SEEK_END);
		fprintf(arquivo,"id da espécie = %d\nid do indivíduo = %d\nsexo = %c\n#\n",idEspecie,id,sexo);
		fclose(arquivo);

		FILE *arquivoIndice = abrirArq(individuoIndice,"r+");
		fseek(arquivoIndice,0,SEEK_END);
		fprintf(arquivoIndice,"%d NORMAL\n",indice);
		fclose(arquivoIndice);
	} else printf("Id ja existe. Retornando\n");
}

int buscarIndividuo(){
	int id;
	char linha[50];
	FILE *arquivo = abrirArq(individuo,"r");
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
	printf("Individuo não encontrado.\n");
	return -1;
}

void removerIndividuo(){
	int id;
	int indice;
	printf("ID: ");
	scanf("%d",&id);
	indice = buscarIndividuo(id);
	if (indice != 1){
		char linha[50];
		FILE *arquivoIndice = abrirArq(especieIndice,"r+");
		int achou = 0;
		while (!achou){
			int indice2;
			int posArqIndice = ftell(arquivoIndice);
			fgets(linha,50,arquivoIndice);
			sscanf(linha,"%d",&indice2);
			if (indice == indice2){
				fseek(arquivoIndice,posArqIndice,SEEK_SET);
				fprintf(arquivoIndice,"%d REMOVIDO",indice);
				printf("Especie Removida\n");
			}
		}
		fclose(arquivoIndice);
	}
	else printf("Espécie não encontrada.\n");
}

void imprimirIndividuo(int indice){
	if (indice != -1){
		char linha[50];
		FILE *arquivo = abrirArq(individuo,"r");
		fseek(arquivo,indice,SEEK_SET);
		fgets(linha,50,arquivo);
		while (strcmp(linha,"#\n")!=0){
			fprintf(stdout,"%s",linha);
			fgets(linha,50,arquivo);
		}
		fclose(arquivo);
	}
}

int verificaIdIndividuo(int id){
        char linha[50];
	int indice;
        FILE *arquivo = abrirArq(individuo,"r");                          
        FILE *arquivoIndice = abrirArq(individuoIndice,"r");              
                
        while (fgets(linha,50,arquivoIndice)!=NULL){
                char comparacao[50];
                int id2;
                sscanf(linha,"%d %s",&indice,comparacao);               
                fseek(arquivo,indice,SEEK_SET);                         
                fgets(linha,50,arquivo); 
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

