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
			inserirEspecie();
			getchar();
			printf("\nENTER para continuar.\n");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("*** Inserção de Indivíduo ***\n\n");
			inserirIndividuo();
			getchar();
			printf("\nENTER para continuar.\n");
			while (getchar()!='\n');
			system("clear");
			break;
		case 3:
			printf("*** Inserção de Captura ***\n\n");
			inserirCaptura();
			getchar();
			printf("\nENTER para continuar.\n");
			while (getchar()!='\n');
			system("clear");
			break;
		case 0:
			break;
		default:
			printf("Opção invalida, digite novamente... \n");
			break;
	}
}

void mostraMenuInsercao(){
	int opcao = -1;

	system("clear");
	while (opcao!=0){
		opcao = -1;
		printf("\nEscolha uma opção de inserção: ");
		printf("\n1 - Espécie");
		printf("\n2 - Indivíduo");
		printf("\n3 - Captura");
		printf("\n0 - VOLTAR");
		printf("\nOpção: ");
		scanf("%d", &opcao);
		escolhaMenuInsercao(opcao);
	}
}
