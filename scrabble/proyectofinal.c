#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "dicc.h"
#define  A 100
#define totpal 94699
#define DIM	15
char** loadWords(char nomDic[], int num_pal);
int buscarPalabra(char **miDic,  int numPal,char pal[]);
void textcolor(int color); 
void convertir(char usuario[]);
void tablero();
int premios[DIM][DIM]=
{ 
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

typedef struct{
	char pal[27];
	int punt[27];
	int cant[27];
}FichasT;


void main(){
	char ** diccionario;
	char palabra[A];
	char fichas[7]={0};
	int pal,i=0,j=0,ale,m=0,r,fil,col;
	FichasT arr[50];
	FILE* lis= fopen("stokens.txt","r");

		diccionario=loadWords("diccionario.txt",totpal);
		while(!feof(lis)){
			fscanf(lis,"%d,%d,%s",&arr[i].punt,&arr[i].cant,arr[i].pal);
			i++;
		}
		srand(time(NULL));

		printf("%s\n",diccionario[rand()%totpal]);
		tablero();
		textcolor(15);
		
		do{

		do{
			ale=rand()%27;
			arr[ale].cant-1;
			printf("%s\n",arr[ale].pal);
			strcpy(fichas,arr[ale].pal);
			j++;
		}while(j<7 && arr[ale].cant>0);

		

			do{
				printf("ingrese una palabra\n");
				textcolor(3);
				scanf("%s",palabra);
				convertir(palabra);
				r=strstr(fichas,"palabra[m]");
				m++;
			}while(r!=NULL  && m<strlen(palabra));
			
			
		pal=buscarPalabra(diccionario,totpal,palabra);
		if(pal==-1){
			printf("No existe\n");
		} else{
			printf("existe\n");
		}

		for(m=0; m<26; m++)
			r=r+arr[m].cant;
		}while(r!=0);

		fclose(lis);
		

		
		
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
void textcolor(int color)
{
   HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute( handle, 1);
   SetConsoleTextAttribute( handle, color);
}
void convertir(char usuario[]){
	int i;
	for(i=0; usuario[i]!='\0'; i++)
		usuario[i]=tolower(usuario[i]);
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
		textcolor(15);
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
				textcolor(60);
			else if(premios[i-1][j-1]==0)
				textcolor(18);
			else if(premios[i-1][j-1]==20)
				textcolor(133);
			else if(premios[i-1][j-1]==2)
				textcolor(12);
			else if(premios[i-1][j-1]==3)
				textcolor(110);
			if (i==7 && j>7)
				printf(" %c ",pal[j-9]);
			else 
				printf("   ");
		}
		printf("\n");
	}
}