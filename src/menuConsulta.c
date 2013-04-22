#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hdr/menuPrincipal.h"
#include "hdr/menuConsulta.h"
#include "hdr/capturas.h"

void escolhaMenuConsulta(int option){
	system("clear");
	switch(option){
		case 1:
			printf("*** Histórico de Monitoramento de um Indivíduo ***\n\n");
			historicoIndividuo();
			getchar();
			printf("Histórico buscado com sucesso. ENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 2:
			printf("*** Histórico de Monitoramento de uma Espécie ***\n\n");
			historicoEspecie();
			getchar();
			printf("Histórico buscado com sucesso. ENTER para continuar.");
			while (getchar()!='\n');
			system("clear");
			break;
		case 3:
			printf("*** Dados da ultima Captura de um Indivíduo ***\n\n");
			imprimirCaptura(ultimaCaptura());
			getchar();
			printf("Dados da captura buscado com sucesso. ENTER para continuar.");
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

void mostraMenuConsulta(){
	int opcao = -1;
	
	system("clear");
	while (opcao!=0){
		opcao = -1;
		printf("Escolha uma opção de consulta: ");
		printf("\n1 - Histórico de Monitoramento de um Indivíduo");
		printf("\n2 - Histórico de Monitoramento de uma Espécie");
		printf("\n3 - Dados da ultima Captura de um Indivíduo");
		printf("\n0 - VOLTAR");
		printf("\nOpção: ");
		scanf("%d", &opcao);
		escolhaMenuConsulta(opcao);
	}
}
