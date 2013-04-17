#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuPrincipal.h"
#include "hdr/menuConsulta.h"

void escolhaMenuConsulta(int option){
	int id;
	
	system("clear");
	switch(option){
		case 1:
			printf("*** Histórico de Monitoramento de um Indivíduo ***\n\n");
			printf("ID: ");
			scanf("%d",&id);
			//historicoIndividuo(id);
			printf("Histórico buscado com sucesso. ENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("*** Histórico de Monitoramento de uma Espécie ***\n\n");
			printf("ID: ");
			scanf("%d",&id);
			//historicoEspecie(id);
			printf("Histórico buscado com sucesso. ENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 3:
			printf("*** Dados da ultima Captura de um Indivíduo ***\n\n");
			printf("ID: ");
			scanf("%d",&id);
			//dadosUltimaCaptura(id);
			printf("Dados da captura buscado com sucesso. ENTER para continuar.");
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

void mostraMenuConsulta(){
	int opcao;
	
	system("clear");
	while (opcao!=0){
		opcao=-1;
		printf("Escolha uma opção de consulta: ");
		printf("\n1 - Histórico de Monitoramento de um Indivíduo");
		printf("\n2 - Histórico de Monitoramento de uma Espécie");
		printf("\n3 - Dados da ultima Captura de um Indivíduo");
		printf("\n0 - VOLTAR");
		printf("Opção: ");
		scanf("%d", &opcao);
		escolhaMenuPrincipal(opcao);
	}
}
