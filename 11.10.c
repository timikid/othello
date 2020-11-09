#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 6 

int main(int argc, char *argv[]) {
	
    int i,j;
    
   
    int gameboard[N][N]={
    	{0,0,0},
		{0,0,0},
		{0,0,0}
	};
	 
    
    
    for(j=0;j<6;j++)
    {
	
    for(i=0;i<6;i++)
    {
    	printf(" %d", gameboard[j][i]);
    }
     printf("\n");
    }
		
	return 0;
}
