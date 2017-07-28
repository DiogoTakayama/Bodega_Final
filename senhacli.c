/*essa função e apenas para criar uma senha com o padrao 12345*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void senhacli(){

char login [10], senha[5];
int x, a=1, b=1;

for (x=0;x<3;x++){

    printf("Login:");
    fflush(stdin);
    gets(login);
    a=strcmp(login,"cliente");

    char string[5];
	printf ("\n Digite a senha de 5 digitos: ");
	string[0] = getch();
	printf ("*");
	string[1] = getch();
	printf ("*");
	string[2] = getch();
	printf ("*");
	string[3] = getch();
	printf ("*");
	string[4] = getch();
	printf ("*");




if((string[0] == '1') && (string[1] == '2') && (string[2] == '3') && (string[3] == '4') && (string[4] == '5') && (a==0)) {



        printf("\nBem-vindo\n");
        break;
    }
    else printf("\nTente novamente....");
}
    getche();
}
