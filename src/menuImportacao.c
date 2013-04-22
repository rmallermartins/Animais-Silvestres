#include <stdio.h>
#include <stdlib.h>
#include "hdr/auxiliares.h"
#include "hdr/menuImportacao.h"
#include "hdr/capturas.h"
#include "hdr/menuPrincipal.h"

void escolhaMenuImportacao(int option){
	system("clear");
	switch(option){
		case 1:
			printf("*** Importacao de Dados no Fim do Arquivo ***\n\n");
			//importaCapturaFinal();
			printf("Importação Concluida. ENTER para continuar.\n");
			while (getchar()!='\n');
			break;
		case 2:
			printf("*** Importacao de dados Reescrevendo o Arquivo ***\n\n");
			//importaCapturaReescreve();
			printf("Importacao Concluida. ENTER para continuar.\n");
			break;
		case 0:
			printf("Voltando... \n");
			break;
		default:
			printf("Opção invalida, digite novamente... \n");
	}
} 

void mostraMenuImportacao(){
	int opcao = -1;
	
	system("clear");
	while (opcao!=0){
		opcao = -1;
		printf("\nEscolha uma opção de Importação: ");
		printf("\n1 - No final do arquivo");
		printf("\n2 - Reescrever o arquivo");
		printf("\n0 - VOLTAR");
		printf("\nOpção: ");
		scanf("%d",&opcao);
		escolhaMenuImportacao(opcao);
	}
}
