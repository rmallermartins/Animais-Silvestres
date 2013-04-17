#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuPrincipal.h"
#include "hdr/menuInsercao.h"

void escolhaMenuPrincipal(int option){
	system("clear");
	switch(option){
		case 1:
			mostraMenuInsercao();
			break;
		case 2:
			//mostraMenuBusca();
			break;
		case 3:
			//mostraMenuRemocao();
			break;
		case 4:
			//mostraMenuConsultas();
			break;
			
		case 5:
			//mostraMenuImportação();
			break;
		case 0:
			printf("Saindo do Programa... \n");
			break;
		default:
			printf("Opção invalida, digite novamente... \n");
			break;
	}
}

void mostraMenuPrincipal(){
	int opcao;
	
	system("clear");
	while (opcao!=0){
		opcao=-1;
		printf("Escolha uma opção: ");
		printf("\n1 - Inserção");
		printf("\n2 - Busca");
		printf("\n3 - Remoção");
		printf("\n4 - Consultas");
		printf("\n5 - Importação de Capturas");
		printf("\n0 - SAIR");
		printf("Opção: ");
		scanf("%d", &opcao);
		escolhaMenuPrincipal(opcao);
	}
}
