#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuPrincipal.h"
#include "hdr/menuBusca.h"
#include "hdr/especies.h"
#include "hdr/capturas.h"
#include "hdr/individuos.h"

void escolhaMenuBusca(int option){
	system("clear");
	switch(option){
		case 1:
			printf("*** Busca de Espécie ***\n\n");
			imprimirEspecie(buscarEspecie());
			getchar();
			printf("\nENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("*** Busca de Indivíduo ***\n\n");
			imprimirIndividuo(buscarIndividuo());
			getchar();
			printf("\nENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 3:
			printf("*** Busca de Captura ***\n\n");
			imprimirCaptura(buscarCaptura());
			getchar();
			printf("\nENTER para continuar.");
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

void mostraMenuBusca(){
	int opcao = -1;
	
	system("clear");
	while (opcao!=0){
		opcao = -1;
		printf("Escolha uma opção de busca: ");
		printf("\n1 - Espécie");
		printf("\n2 - Indivíduo");
		printf("\n3 - Captura");
		printf("\n0 - VOLTAR");
		printf("\nOpção: ");
		scanf("%d", &opcao);
		getchar();
		escolhaMenuBusca(opcao);
	}
}
