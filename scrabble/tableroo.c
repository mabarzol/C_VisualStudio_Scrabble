#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <windows.h>
#include "dicc.h"

#define SALIR 3
#define DIM 15 

int premios[DIM][DIM]=
{ // Tablero SCRABBLE tradicional
{30,0,0,2,0,0,0,30,0,0,0,2,0,0,30},
{0,20,0,0,0,3,0,0,0,3,0,0,0,20,0},
{0,0,20,0,0,0,2,0,2,0,0,0,20,0,0},
{2,0,0,20,0,0,0,2,0,0,0,20,0,0,2},
{0,0,0,0,20,0,0,0,0,0,20,0,0,0,0},
{0,3,0,0,0,3,0,0,0,3,0,0,0,3,0},
{0,0,2,0,0,0,2,0,2,0,0,0,2,0,0},
{30,0,0,2,0,0,0,20,0,0,0,2,0,0,30},
{0,0,2,0,0,0,2,0,2,0,0,0,2,0,0},
{0,3,0,0,0,3,0,0,0,3,0,0,0,3,0},
{0,0,0,0,20,0,0,0,0,0,20,0,0,0,0},
{2,0,0,20,0,0,0,2,0,0,0,20,0,0,2},
{0,0,20,0,0,0,2,0,2,0,0,0,20,0,0},
{0,20,0,0,0,3,0,0,0,3,0,0,0,20,0},
{30,0,0,2,0,0,0,30,0,0,0,2,0,0,30},
};
typedef struct
{
	char letra;
	int cantidad;
	int puntos;
}LetraT;
void menu(void);
char generarLetra(LetraT arreglo[]);
char** loadWords(char nomDic[], int num_pal);
int buscarPalabra(char **miDic,  int numPal,char pal[]);
void llenarBarril(LetraT barril[]);
void textcolor(int color); 
void tablero();

void main()
{
	LetraT barril[25];
	int op,i;
	//int tablero[FIL][COL]={0};
	char letra;
	srand(time(NULL));
	llenarBarril(barril);
	do{
		do{
			menu();
			printf("\tIngrese una opcion: ");
			scanf("%d", &op);
		}while(op<=0 || op>SALIR);

		switch(op)
		{
			case 1:
				{
					tablero();
					textcolor(15);
					for(i=0;i<7;i++)
					{
						letra=generarLetra(barril);
						printf("%c ",letra);
					}


				}
				getch();


				
				
				break;
			case 2:

				printf("hola");
				break;
				
			case SALIR:
				system("cls");
				printf("\t\t\tFin del programa\n\t\t\t\n");
				getch();
				break;
			default:
				printf("\tOpcion no valida\n");
				getch();
		}

	}while (op!=SALIR);
}

void menu(void)
{
	system("cls");
	printf("\t\t\tSCRABBLE\n");
	printf("\t\t1. Jugar\n\t\t2. Ver ganadores\n\t\t3. Salir\n\n");
}
char generarLetra(LetraT arreglo[])
{
	int	r;
	do
	{
		r=rand()%25;
	}while(arreglo[r].cantidad<1);
	(arreglo[r].cantidad)--;		
	return arreglo[r].letra;
}
char** loadWords(char nomDic[], int num_pal)
{
    int i=0;
    char pal[100];
    char **miDiccionario;
    FILE *fp=fopen(nomDic,"r");
    miDiccionario = (char **)malloc(sizeof(char*)*num_pal);
    while(!feof(fp))
    {
        fscanf(fp,"%s",pal);
        miDiccionario[i] = (char*)malloc(sizeof(char)*strlen(pal)+1);
        strcpy(miDiccionario[i],pal);
        i++;
    }
    return miDiccionario;
}


int buscarPalabra(char **miDic,  int numPal,char pal[])
{
    int i;
    for(i=0; i<numPal; i++)
    {
        if(strcmp(miDic[i],pal)==0)
            return i;
    }
    return -1;
}
void llenarBarril(LetraT barril[])
{
	barril[0].letra='a';barril[0].cantidad=12;barril[0].puntos=1;
	barril[1].letra='b';barril[1].cantidad=2;barril[1].puntos=3;
	barril[2].letra='c';barril[2].cantidad=4;barril[2].puntos=3;
	barril[3].letra='d';barril[3].cantidad=5;barril[3].puntos=2;
	barril[4].letra='e';barril[4].cantidad=12;barril[4].puntos=1;
	barril[5].letra='f';barril[5].cantidad=1;barril[5].puntos=4;
	barril[6].letra='g';barril[6].cantidad=2;barril[6].puntos=2;
	barril[7].letra='h';barril[7].cantidad=2;barril[7].puntos=4;
	barril[8].letra='i';barril[8].cantidad=6;barril[8].puntos=1;
	barril[9].letra='j';barril[9].cantidad=1;barril[9].puntos=8;
	barril[10].letra='l';barril[10].cantidad=4;barril[10].puntos=1;
	barril[11].letra='m';barril[11].cantidad=2;barril[11].puntos=3;
	barril[12].letra='n';barril[12].cantidad=5;barril[12].puntos=1;
	barril[13].letra='o';barril[13].cantidad=9;barril[13].puntos=1;
	barril[14].letra='p';barril[14].cantidad=2;barril[14].puntos=3;
	barril[15].letra='q';barril[15].cantidad=1;barril[15].puntos=10;
	barril[16].letra='r';barril[16].cantidad=5;barril[16].puntos=1;
	barril[17].letra='s';barril[17].cantidad=6;barril[17].puntos=1;
	barril[18].letra='t';barril[18].cantidad=4;barril[18].puntos=1;
	barril[19].letra='u';barril[19].cantidad=5;barril[19].puntos=1;
	barril[20].letra='v';barril[20].cantidad=1;barril[20].puntos=4;
	barril[21].letra='x';barril[21].cantidad=1;barril[21].puntos=8;
	barril[22].letra='y';barril[22].cantidad=1;barril[22].puntos=4;
	barril[23].letra='z';barril[23].cantidad=1;barril[23].puntos=10;
}
void textcolor(int color)
{
   HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute( handle, 1);
   SetConsoleTextAttribute( handle, color);
}
void tablero()
{
int i,j,m;
	
	char pal[16]="casa";
	for(i=4;i<16;i++)
		pal[i]=' ';	
	printf("\n\n");
	printf("              ");
	for(i=1;i<=15;i++){
		textcolor(0);
		printf("%3d",i);
		if(i==15)
			printf("\n");
	}
	printf("\n");
	for(i=1;i<=15;i++){
		textcolor(15);
		printf("           ");
		for(j=1;j<=15;j++){
			if(j==1){
				textcolor(15);
				printf("%2d  ",i);
			}
			if(premios[i-1][j-1]==30)
				textcolor(100);
			else if(premios[i-1][j-1]==0)
				textcolor(101);
			else if(premios[i-1][j-1]==20)
				textcolor(120);
			else if(premios[i-1][j-1]==2)
				textcolor(110);
			else if(premios[i-1][j-1]==3)
				textcolor(190);
			if (i==7 && j>7)
				printf(" %c ",pal[j-9]);
			else 
				printf("   ");
		}
		printf("\n");
	}
}
