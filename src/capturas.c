#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/capturas.h"
#include "hdr/auxiliares.h"

void inserirCaptura(){
	int id;
	int idIndividuo;
	int comprimento;
	int largura;
	int peso;
	char data[10];
	char local[50];

	printf("\nID: ");
	scanf("%d",&id);
	printf("\nID do individuo: ");
	scanf("%d",&idIndividuo);
	printf("\nComprimento: ");
	scanf("%d",&comprimento);
	printf("\nLargura: ");
	scanf("%d",&largura);
	printf("\nPeso: ");
	scanf("%d",&peso);
	printf("\nData(dd/mm/aa): ");
	scanf("%s",data);
	printf("\nLocal: ");
	scanf("%[^\n]s", local);
	setbuf(stdin, NULL);

	int indice = verificaIdCaptura(id);
	if (indice != -1){
		FILE *arquivo = abrirArq(captura,"r+");
		fseek(arquivo,0,SEEK_END);
		fprintf(arquivo,"id da captura = %d\nid do individuo = %d\ncomprimento = %d\nlargura = %d\npeso = %d\ndata = %s\nlocal = %s\n#\n",id,idIndividuo,comprimento,largura,peso,data,local);
		fclose(arquivo);
	
		FILE *arquivoIndice = abrirArq(capturaIndice,"r+");
		fseek(arquivoIndice,0,SEEK_END);
		fprintf(arquivoIndice,"%d NORMAL\n",indice);
		fclose(arquivoIndice);
	}
	else printf("Id ja existe. Retornando\n");
}

int buscarCaptura(){
	int id;
	char linha[50];
	FILE *arquivo = abrirArq(captura,"r");
	FILE *arquivoIndice = abrirArq(capturaIndice,"r");
	
	printf("ID: ");
	scanf("%d",&id);
	while (fgets(linha,50,arquivoIndice)!=NULL){
		int indice;
		char comparacao[50];
		int id2;
		sscanf(linha,"%d %s",&indice,comparacao);
		fseek(arquivo,indice,SEEK_SET);
		fgets(linha,50,arquivo);
		sscanf(linha,"%*[0-9] %d",&id2);
		if (id == id2 && strcmp(comparacao,"REMOVIDO")!=0){
			fclose(arquivo);
			fclose(arquivoIndice);
			return indice;
		}
	}
	fclose(arquivo);
	fclose(arquivoIndice);
	printf("Captura não encontrada.\n");
	return -1;
}

void removerCaptura(){
	int id;
	int indice;
	printf("ID: ");
	scanf("%d",&id);
	indice = buscarCaptura(id);
	if (indice != -1){
		char linha[50];
		FILE *arquivoIndice = abrirArq(capturaIndice,"r+");
		int achou = 0;
		while (!achou){
			int indice2;
			int posArqIndice = ftell(arquivoIndice);
			fgets(linha,50,arquivoIndice);
			sscanf(linha,"%d",&indice2);
			if (indice == indice2){
				fseek(arquivoIndice,posArqIndice,SEEK_SET);
				fprintf(arquivoIndice,"%d REMOVIDO",indice);
				printf("Captura Removida.\n");
			}
		}
		fclose(arquivoIndice);
	}	
	else printf("Captura não encontrada.\n");
}

void imprimirCaptura(int indice){
	if (indice != -1){
		FILE *arquivo = abrirArq(captura,"r");
		char linha[50];
		fseek(arquivo,indice,SEEK_SET);
		fgets(linha,50,arquivo);
        	while (strcmp(linha,"#\n")!=0){
			fprintf(stdout,"%s",linha);
			fgets(linha,50,arquivo);
		}
		fclose(arquivo);
	}
}

int verificaIdCaptura(int id){
        char linha[50];
	int indice;
        FILE *arquivo = abrirArq(captura,"r");                          
        FILE *arquivoIndice = abrirArq(capturaIndice,"r");              
                
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


void historicoIndividuo(){
	int id;
        char linha[50];
        FILE *arquivo = abrirArq(captura,"r");
        FILE *arquivoIndice = abrirArq(capturaIndice,"r");

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
                        imprimirCaptura(indice);
			printf("#\n");
                }
        }
}

void historicoEspecie(){
	int id;
	int idIndividuo;
	char linha[50];
	FILE *arquivo = abrirArq(individuo,"r");
	FILE *arquivoIndice = abrirArq(individuoIndice,"r");
	
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
			fgets(linha,50,arquivo);
			scanf(linha,"%*[^0-9] %d",&idIndividuo);
			imprimeHistoricoEspecie(idIndividuo);
		}
	}
	fclose(arquivo);
	fclose(arquivoIndice);
}

void imprimeHistoricoEspecie(int id){
        char linha[50];
        FILE *arquivo = abrirArq(captura,"r");
        FILE *arquivoIndice = abrirArq(capturaIndice,"r");

        while (fgets(linha,50,arquivoIndice)!=NULL){
                int indice;
                char comparacao[50];
                int id2;
                sscanf(linha,"%d %s",&indice,comparacao);
                fseek(arquivo,indice,SEEK_SET);
                fgets(linha,50,arquivo);
                sscanf(linha,"%*[^0-9] %d",&id2);
                if (id == id2 && strcmp(comparacao,"REMOVIDO")!=0){
                        imprimirCaptura(indice);
                        printf("#\n");
                }
        }
	fclose(arquivo);
	fclose(arquivoIndice);
}

int ultimaCaptura(){
	int id;
	int ultimoIndice;
        char linha[50];
        FILE *arquivo = abrirArq(captura,"r");
        FILE *arquivoIndice = abrirArq(capturaIndice,"r");

        printf("ID: ");
        scanf("%d",&id);
        while (fgets(linha,50,arquivoIndice)!=NULL){
                char comparacao[50];
                int id2;
		int indice;
                sscanf(linha,"%d %s",&indice,comparacao);
                fseek(arquivo,indice,SEEK_SET);
                fgets(linha,50,arquivo);
                sscanf(linha,"%*[0-9] %d",&id2);
                if (id == id2 && strcmp(comparacao,"REMOVIDO")!=0){
			ultimoIndice = indice;	
                }
        }
        fclose(arquivo);
        fclose(arquivoIndice);
	return ultimoIndice;
}
