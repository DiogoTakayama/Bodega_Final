
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "produtos.h"
#include "clientes.h"

    int main (){

    int codprod=0, i, j, menuprod, menuexcluir, opcoes;
    char ccodprod[25], excluir[20], nome[30];
    int menus;
    FILE *pont;

    system("color 1f");
    setlocale(LC_ALL, "Portuguese");
    int opcao;


        printf("\n\t\t\tSistema Bodega IMD\n");
		printf( "_____________________________________________________________________________\n" );
		printf( "\n\t\t\tMENU PRINCIPAL\n\n" );
		printf( "-----------------------------------------------------------------------------\n" );
		printf(" Escolha uma das seguintes opções:\n\n" );
		printf("  1.Clientes\n");
		printf("  2.Funcionário\n");
		printf( "-----------------------------------------------------------------------------\n" );
		printf( "\t\t\t\tS - Sair\n" );
		printf( "_____________________________________________________________________________\n" );

    scanf("%d",&opcao);

    system("clear||cls");



    switch (opcao){

      case 1://senhacli();
          clientes();

      case 2://senhaf();
          produtos();
      default: printf("Programa finalizado\n\n");
      system("pause");
      system("exit");


    }
}

