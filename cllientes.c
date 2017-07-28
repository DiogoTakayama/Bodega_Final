#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include "produtos.h"

void clientes(){

    system("color 1f");
    setlocale(LC_ALL, "Portuguese");
    int codprod=0, i, j, k, dia, mes, ano, menuprod, menuexcluir, opcoes;
    int numprodcarrinho=0;
    float valorp;
    char ccodprod[25], excluir[20], nome[30];
    char txt[12]="Produtos.txt";
    int menus;
    FILE *pont;


    typedef struct{
    int dia;
    int mes;
    int ano;
    }DATA;

    typedef struct{
    char categoria[10];
    int codigo;
    float valor;
    char descricao[30];
    char fornecedor[10];
    int validade[3];
    int corredor;
    int prateleira;
    float estoque;
    }PRODUTO;


    PRODUTO prod[100];
    PRODUTO carrinho[100];
    PRODUTO temp;

    void lerprodutos(){
        pont=fopen(txt,"r");

    for(codprod=0;(fscanf(pont,"%s\n%d\n%f\n%s\n%s\n%d/%d/%d\n%d %d\n%f\n", prod[codprod].descricao, &prod[codprod].codigo, &prod[codprod].valor,
        prod[codprod].categoria, prod[codprod].fornecedor, &prod[codprod].validade[0], &prod[codprod].validade[1], &prod[codprod].validade[2], &prod[codprod].corredor, &prod[codprod].prateleira,
        &prod[codprod].estoque))!=EOF;codprod++){
            fscanf(pont,"\n\n    Nome: %s\nCodigo: %d\nValor: %.2f\nCategoria: %s\nFornecedor: %s\nValidade: %d/%d/%d\nLocalizacao: Corredor: %d Prateleira: %d\nQtdade em estoque: %.2f\n", prod[codprod].descricao, &prod[codprod].codigo, &prod[codprod].valor,
                prod[codprod].categoria, prod[codprod].fornecedor, &prod[codprod].validade[0], &prod[codprod].validade[1], &prod[codprod].validade[2], &prod[codprod].corredor, &prod[codprod].prateleira,
                &prod[codprod].estoque);
    }
    fclose(pont);


    }

    void salvartodos(){
        pont=fopen(txt,"w");
        for(i=0;i<codprod;i++){
            fprintf(pont,"%s\n%d\n%f\n%s\n%s\n%d/%d/%d\n%d %d\n%f\n\n", prod[i].descricao, prod[i].codigo, prod[i].valor, prod[i].categoria,
                    prod[i].fornecedor, prod[i].validade[0], prod[i].validade[1], prod[i].validade[2], prod[i].corredor, prod[i].prateleira,
                    prod[i].estoque);
        }
        fclose(pont);

    }

    void entrarprodarq(){
        char arquivo[15];
        printf("Digite o nome do arquivo a ser lido.(com a extensão)\n");
        scanf("%s", &arquivo);
        pont=fopen(arquivo,"r");
        if (pont==NULL){
                system("cls");
                printf("Ocorreu um erro na abertura do arquivo.\n\n");
                system("pause");
                return;
        }
        else{
        fscanf(pont,"%s\n%d\n%f\n%s\n%s\n%d/%d/%d\n%d %d\n%f\n\n", prod[0].descricao, &prod[0].codigo, &prod[0].valor,
                prod[0].categoria, prod[0].fornecedor, &prod[0].validade[0], &prod[0].validade[1], &prod[0].validade[2], &prod[0].corredor, &prod[0].prateleira,
                &prod[0].estoque);
        prod[0].codigo=codprod;
        fclose(pont);

        pont = fopen(txt,"a+"); /*salvando o produto no arquivo */
        if (pont==NULL){
                system("cls");
                printf("Ocorreu um erro na geração do arquivo.\n\n");
                return;
        }
        else{
            fprintf(pont,"%s\n%d\n%f\n%s\n%s\n%d/%d/%d\n%d %d\n%f\n\n", prod[0].descricao, prod[0].codigo, prod[0].valor, prod[0].categoria,
                prod[0].fornecedor, prod[0].validade[0], prod[0].validade[1], prod[0].validade[2], prod[0].corredor, prod[0].prateleira,
                prod[0].estoque);
            fclose(pont);


            lerprodutos();                               /*lendo do arquivo para o vetor */
            printf("PRODUTO SALVO COM SUCESSO!!\n\n");
            system("pause");
            main();
        }
        }
    }

    void ordenacodigo(PRODUTO *prod , int N){
        int i, continua, fim=N;
        PRODUTO aux;
        do{
            continua =0;
            for(i=0; i<fim-1; i++){
                if(prod[i].codigo>prod[i+1].codigo){
                    aux=prod[i];
                    prod[i]=prod[i+1];
                    prod[i+1]=aux;
                    continua=i;
                }
            }
            fim--;
        }while(continua!=0);
    }

    void ordenavalor(PRODUTO *prod , int N){
        int i, continua, fim=N;
        PRODUTO aux;
        do{
            continua =0;
            for(i=0; i<fim-1; i++){
                if(prod[i].valor>prod[i+1].valor){
                    aux=prod[i];
                    prod[i]=prod[i+1];
                    prod[i+1]=aux;
                    continua=i;
                }
            }
            fim--;
        }while(continua!=0);
    }

    void ordenaestoque(PRODUTO *prod , int N){
        int i, continua, fim=N;
        PRODUTO aux;
        do{
            continua =0;
            for(i=0; i<fim-1; i++){
                if(prod[i].estoque>prod[i+1].estoque){
                    aux=prod[i];
                    prod[i]=prod[i+1];
                    prod[i+1]=aux;
                    continua=i;
                }
            }
            fim--;
        }while(continua!=0);
    }

    void scanprod(PRODUTO *x){
    printf("Digite a categoria do produto: ");
    scanf("%s", (*x).categoria);
    printf("\nO codigo do produto será: %d", codprod);
    (*x).codigo=codprod;
    printf("\nDigite o valor do produto: ");
    scanf("%f", &(*x).valor);
    printf("\nDigite a descricao do produto: ");
    scanf("%s", (*x).descricao);
    printf("\nDigite o fornecedor do produto: ");
    scanf("%s", (*x).fornecedor);
    printf("\nDigite a validade do produto: \n");
    printf("dia: ");
    scanf("%d", &(*x).validade[0]);
    printf("\nmes: ");
    scanf("%d", &(*x).validade[1]);
    printf("\nano: ");
    scanf("%d", &(*x).validade[2]);
    printf("\nDigite o corredor do produto: \n");
    scanf("%d", &(*x).corredor);
    printf("\nDigite a prateleira do produto: \n");
    scanf("%d", &(*x).prateleira);
    printf("\nDigite a quantidade de entrada no estoque: \n");
    scanf("%f", &(*x).estoque);
    system("clear||cls");
    printf("\n                 PRODUTO CADASTRADO COM SUCESSO !!\n\n\n");
    }

    void printprod(PRODUTO x){
    printf("\n\n         PRODUTO %s           ", x.descricao);
    printf("\n\n");
    printf("Categoria.: %s\n", x.categoria);
    printf("Codigo....: %d\n", x.codigo);
    printf("Valor.....: R$%.2f\n", x.valor);
    printf("Descricao.: %s\n", x.descricao);
    printf("Fornecedor: %s\n", x.fornecedor);
    printf("Validade..: %d/", x.validade[0]);
    printf("%d/", x.validade[1]);
    printf("%d\n", x.validade[2]);
    printf("Corredor..: %d\n", x.corredor);
    printf("Prateleira: %d\n", x.prateleira);
    printf("Quantidade em estoque: %.2f\n", x.estoque);
    }

    void salvarprod(){
    scanprod(&prod[0]);
    pont = fopen(txt,"a+");
    if (pont==NULL){
                system("cls");
                printf("Ocorreu um erro na geração do arquivo.\n\n");
                return;
    }
    else{
                fprintf(pont,"%s\n%d\n%f\n%s\n%s\n%d/%d/%d\n%d %d\n%f\n\n", prod[0].descricao, prod[0].codigo, prod[0].valor, prod[0].categoria,
                    prod[0].fornecedor, prod[0].validade[0], prod[0].validade[1], prod[0].validade[2], prod[0].corredor, prod[0].prateleira,
                    prod[0].estoque);
                fclose(pont);


                lerprodutos();
                printf("PRODUTO SALVO COM SUCESSO!!\n\n");
                system("pause");
                main();
    }

    }

    void entrarestoque(){
        int codentrada;
        float quantentrada;
        printf("Digite o codigo do produto que deseja registrar entrada.\n");
        scanf("%d", &codentrada);
        if(prod[codentrada].valor==0){
            printf("\n\nPRODUTO NAO SE ENCONTRA CADASTRADO NO SISTEMA!!\n\n");
            system("pause");
            system("clear||cls");
            main();
        }
        printf("\nDigite a quantidade da entrada do produto.\n");
        scanf("%f", &quantentrada);
        prod[codentrada].estoque = prod[codentrada].estoque + quantentrada;
        salvartodos();
    }

    void imprimirtodos(){
        for(i=0;i<codprod;i++){
                if(prod[i].valor!=0)printprod(prod[i]);
        }
    system("pause");
    }

    void apagarprodcod(){
        int a;
        printf("Digite o codigo do produto que deseja excluir: ");
        scanf("%d",&a);
        for(i=0; i<codprod; i++){
            if(a==prod[i].codigo){
                prod[i]=prod[0];
                prod[i].codigo=i;
                salvartodos();
            }
        }

        lerprodutos();
    }

    void pesquisaprodcod(){
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &k);
        for(i=0; i<codprod; i++){
            if(k==prod[i].codigo){
                printprod(prod[i]);
            }
        }
    }

    void pesquisaprodnome(){
        printf("\nDigite o nome do produto: ");
        scanf("%s", &nome);
            for(i=0; i<50; i++){
                if(strcmp(nome, prod[i].descricao)==0){
                    printprod(prod[i]);
                }
            }
    }

    void pesquisaprodfornecedor(){
        printf("\nDigite o nome do fornecedor: ");
        scanf("%s", &nome);
            for(i=0; i<50; i++){
                if(strcmp(nome, prod[i].fornecedor)==0){
                    printprod(prod[i]);
                }
            }
    }

    void pesquisaprodcategoria(){
        printf("\nDigite a categoria a ser pesquisada: ");
        scanf("%s", &nome);
            for(i=0; i<50; i++){
                if(strcmp(nome, prod[i].categoria)==0){
                    printprod(prod[i]);
                }
            }
    }

    void pesquisavencdia(){
        printf("\nDigite o dia do vencimento: ");
        scanf("%d", &dia);
        printf("\nDigite o mês do vencimento: ");
        scanf("%d", &mes);
        printf("\nDigite o ano do vencimento: ");
        scanf("%d", &ano);
        for(i=0; i<50; i++){
            if(dia==prod[i].validade[0] && mes==prod[i].validade[1] && ano==prod[i].validade[2] ){
                printprod(prod[i]);
            }
        }
    }

    void pesquisavencmes(){
        printf("\nDigite o mês do vencimento: ");
        scanf("%d", &mes);
        printf("\nDigite o ano do vencimento: ");
        scanf("%d", &ano);
        for(i=0; i<50; i++){
            if(mes==prod[i].validade[1] && ano==prod[i].validade[2] ){
                printprod(prod[i]);
            }
        }
    }

    void pesquisavencano(){
        printf("\nDigite o ano do vencimento: ");
        scanf("%d", &ano);
        for(i=0; i<50; i++){
            if(ano==prod[i].validade[2]){
                printprod(prod[i]);
            }
        }
    }

    void pesquisavalorex(){
        printf("\nDigite o valor a ser pesquisado: ");
        scanf("%f", &valorp);
        for(i=0; i<50; i++){
            if(valorp==prod[i].valor){
                printprod(prod[i]);
            }
        }
    }

    void pesquisavalormenor(){
        printf("\nDigite o valor a ser pesquisado: ");
        scanf("%f", &valorp);
        for(i=0; i<codprod; i++){
            if(valorp>prod[i].valor && prod[i].valor!=0){
                printprod(prod[i]);
            }
        }
    }

    void pesquisavalormaior(){
        printf("\nDigite o valor a ser pesquisado: ");
        scanf("%f", &valorp);
        for(i=0; i<codprod; i++){
            if(valorp<prod[i].valor){
                printprod(prod[i]);
            }
        }
    }

    void pesquisaestoque(){
        float pestoque;
        printf("\nDigite o valor de estoque a ser pesquisado: ");
        scanf("%f", &pestoque);
        for(i=0; i<codprod; i++){
            if(pestoque==prod[i].estoque && prod[i].valor!=0){
                printprod(prod[i]);
            }
        }

    }

    void pesquisaestoquemenorq(){
        float pestoque;
        printf("\nDigite o valor a ser pesquisado: ");
        scanf("%f", &pestoque);
        for(i=0; i<codprod; i++){
            if(pestoque>prod[i].estoque && prod[i].valor!=0){
                printprod(prod[i]);
            }
        }
    }

    void pesquisaestoquemaiorq(){
        float pestoque;
        printf("\nDigite o valor a ser pesquisado: ");
        scanf("%f", &pestoque);
        for(i=0; i<codprod; i++){
            if(pestoque<prod[i].estoque && prod[i].valor!=0){
                printprod(prod[i]);
            }
        }
    }

    void conferirestoque(){
        for(i=0; i<codprod; i++){
            if(prod[i].estoque < 5 && prod[i].valor!=0){
                printf("\n");
                break;
            }
        }
    }

    void imprimirtodoscarrinho(){
        for(i=0;i<numprodcarrinho;i++){
                if(carrinho[i].valor!=0)printprod(carrinho[i]);
        }
    system("pause");
    }

    void menucarrinho(){
        system("clear||cls");
        printf("\n\t\t\tSistema Budega IMD\n");
		printf( "_____________________________________________________________________________\n" );
        printf("\n\t\t\tCARRINHO DE COMPRAS\n\n");


        int codnovoproduto, menucarrinho, a;
        float quantidade, b;

        printf("*Para evitar enganos com nomes dos produtos, os mesmos \n");
        printf("serão adicionados no carrinho pelos seus códigos.*\n\n");
        system("pause");
        printf("\n\n");
        printf("1-Adicionar novo produto.\n2-Modificar quantidade de produtos já adicionados.\n3-Mostrar produtos no carrinho.\n\n");
        scanf("%d", &menucarrinho);
        switch(menucarrinho){
            case 1:
                printf("Digite o código de um produto a ser adicionado ao carrinho de compras:\n");
                scanf("%d", &codnovoproduto);
                printf("\nDigite a quantidade desejada do produto:\n");
                scanf("%f", &quantidade);
                for(i=0; i<codprod; i++){
                    if(codnovoproduto==prod[i].codigo){
                        carrinho[numprodcarrinho]=prod[i];
                        carrinho[numprodcarrinho].estoque = quantidade;
                        numprodcarrinho++;
                        printf("\nProduto adicionado com sucesso.");
                    }
                }
                break;

            case 2:
                printf("Digite o código do produto a ser modificado:\n");
                scanf("%d", &a);
                printf("Digite a nova quantidade desejada para o produto:\n");
                scanf("%f", &b);
                for(i=0; i<numprodcarrinho; i++){
                    if(a==carrinho[i].codigo){
                        carrinho[i].estoque=b;
                        printprod(carrinho[i]);
                        printf("Quantidade modificada.\n");
                    }
                }

            case 3:
                imprimirtodoscarrinho();


        }

    }

 fclose(pont);


    void menucliente(){
        system("clear||cls");
        printf("\n\t\t\tSistema Budega IMD\n");
		printf( "_____________________________________________________________________________\n" );
        printf("\n\t\t\tMENU DO CLIENTE\n\n");
        printf( "------------------------------------------------------------------------------\n" );
        printf("Escolha uma das opções a seguir.");
        printf("\n1-Pesquisar.\n2-Mostrar todos.\n3-Carrinho de compras.\n");
        printf( "------------------------------------------------------------------------------\n" );
        printf("\n\t\t\t4-Sair.\n");
        printf( "_____________________________________________________________________________\n" );
        conferirestoque();
        scanf("%d", &menus);
        switch(menus){

            case 1:
                system("clear||cls");
                printf("\n\t\t\tSistema Budega IMD\n");
                printf( "_____________________________________________________________________________\n" );
                printf("\n1-Pesquisar produto por código.\n2-Pesquisar produto por nome.\n3-Pesquisar produto por fornecedor.\n");
                printf("4-Pesquisar produto por categoria.\n5-Pesquisar produto por validade.\n6-Pesquisar produto por valor.\n");
                printf("7-Pesquisar produto por estoque.\n8-Voltar.\n\n");
                scanf("%d", &j);
                if(j==1){
                    pesquisaprodcod();
                }
                else if(j==2){
                    pesquisaprodnome();
                }
                else if(j==3){
                    pesquisaprodfornecedor();
                }
                else if(j==4){
                    pesquisaprodcategoria();
                }
                else if(j==5){
                    printf("Escolha a precisão da pesquisa:\n1-Vencimento exato.\n1-Mês de vencimento.\n3-Ano de vencimento.\n\n");
                    scanf("%d", &k);
                    if(k==1){pesquisavencdia();
                    }
                    else if(k==2){
                        pesquisavencmes();
                    }
                    else if(k==3){
                            pesquisavencano();
                    }
                    else printf("Comando inválido!");
                        system("pause");
                        system("clear||cls");
                        return main();
                }
                else if(j==6){
                    printf("\n1-Pesquisar por valor exato.\n2-Pesquisar por valores maiores que:\n3-Pesquisar por valores menores que:\n");
                    scanf("%d", &k);
                    if(k==1){pesquisavalorex();}
                    else if(k==2){
                    ordenavalor(&prod, codprod);
                    pesquisavalormaior();
                    ordenacodigo(&prod, codprod);
                    }
                    else if(k==3){
                      ordenavalor(&prod, codprod);
                      pesquisavalormenor();
                     ordenacodigo(&prod, codprod);
                     }
                    else printf("Comando inválido!");
                        system("pause");
                        system("clear||cls");
                        return main();
                }
                else if(j==7){
                    printf("\n1-Pesquisar por valor exato.\n2-Pesquisar por valores maiores que:\n3-Pesquisar por valores menores que:\n");
                    scanf("%d", &k);
                    if(k==1){
                    pesquisaestoque();
                    return main();
                    }
                    else if(k==2){
                    ordenaestoque(&prod, codprod);
                    pesquisaestoquemaiorq();
                    ordenacodigo(&prod, codprod);}
                    else if(k==3){
                    ordenaestoque(&prod, codprod);
                    pesquisaestoquemenorq();
                    ordenacodigo(&prod, codprod);
                    }

                }
                else if(j==8){return menucliente();}
                else printf("Comando inválido!");
                 system("pause");
                 system("clear||cls");
                  return main();

                break;
            case 2:
                system("clear||cls");
                printf("\n\t\t\tSistema Budega IMD\n");
                printf( "_____________________________________________________________________________\n" );
                printf("\n\n1-Mostrar produtos ordenados por codigo.\n2-Mostrar produtos ordenados por preço.");
                printf("\n3-Mostrar produtos ordenados por qtdade em estoque.\n4-Voltar.\n\n");
                scanf("%d", &k);
                if(k==1){imprimirtodos(); system("pause");system("clear||cls");
                    return main();
                    }
                    else if(k==2){
                            ordenavalor(&prod, codprod);
                    imprimirtodos();
                    ordenacodigo(&prod, codprod);}
                    else if(k==3){
                    ordenaestoque(&prod, codprod);
                     imprimirtodos();
                    ordenacodigo(&prod, codprod);
                    }
                    else if(k==4)
                    {
                        return
                        menucliente();
                    }


                else printf("Comando inválido!\n\n");
                 system("pause");
                 system("clear||cls");
                  return main();


            case 3:menucarrinho();

            case 4: system("clear||cls");
             return main();

        }

    }



    lerprodutos();


    menucliente();

    return 0;
}
