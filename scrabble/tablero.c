#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
void textcolor(int color);
void main(){
	int i, j;
	textcolor(12);

	for(i=0; i<15; i++){
		for(j=0; j<15;j++){
			printf("%c",220);
		}
		printf("\n");
	}

}

void textcolor(int color)
{
   HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute( handle, 1);
   SetConsoleTextAttribute( handle, color);
}