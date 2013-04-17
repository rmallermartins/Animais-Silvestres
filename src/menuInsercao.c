#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuPrincipal.h"
#include "hdr/menuInsercao.h"
#include "hdr/especies.h"
#include "hdr/individuos.h"
#include "hdr/capturas.h"

void escolhaMenuInsercao(int option){
	system("clear");
	switch(option){
		case 1:
			printf("*** Inserção de Espécie ***\n\n");
			//inserirEspecie();
			printf("Especie inserida com Sucesso. ENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("*** Inserção de Indivíduo ***\n\n");
			//inserirIndividuo();
			printf("Indivíduo inserido com Sucesso. ENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 3:
			printf("*** Inserção de Captura ***\n\n");
			//inserirCaptura();
			printf("Captura inserida com Sucesso. ENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 0:
			printf("Voltando... \n");
			mostraMenuPrincipal();
			break;
		default:
			printf("Opção invalida, digite novamente... \n");
			break;
	}
}

void mostraMenuInsercao(){
	int opcao;
	
	system("clear");
	while (opcao!=0){
		opcao=-1;
		printf("Escolha uma opção de inserção: ");
		printf("\n1 - Espécie");
		printf("\n2 - Indivíduo");
		printf("\n3 - Captura");
		printf("\n0 - VOLTAR");
		printf("Opção: ");
		scanf("%d", &opcao);
		escolhaMenuInsercao(opcao);
	}
}
