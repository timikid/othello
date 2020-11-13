#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define blank -1
#define white 0
#define black 1

#define N 6

void init(int a[][6]){      //판 초기화하기  
	
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			a[i][j]= -1;      
		}
	}
	
    a[2][2] = 0;
    a[2][3] = 1;
    a[3][2] = 1;
    a[3][3] = 0;
}


void print_othello(int a[][N]){
   int i,j;
   
   	printf("   0 1 2 3 4 5");
    printf("\n"); 
	printf("   - - - - - -");
    printf("\n");
  
   for(i=0;i<N;i++){           
        printf("%i |", i);
   	for(j=0;j<N;j++){
   	
   	    if(a[i][j] == blank)
 		 printf(" |");
   		
		else if(a[i][j] == black)
   		 printf("X|");
   		
		else if(a[i][j] == white)
   		 printf("O|");
	   }
	   printf("\n");
	   printf("   - - - - - -");
	   printf("\n");
   }
}

void status(int a[][N])
{
	int i,j;
	int countw=0;
	int countb=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(a[i][j] == white)
			 countw+=1;
			else if(a[i][j] == black)
			 countb+=1;
		}
	}
	printf("\n");
	printf("STATUS - WHITE : %i  BLACK :%i", countw, countb);
	printf("\n\n");
}

void put_w(int a[][N])
{
	int i,j;
	printf("put a new white othello : " );
	scanf("%i %i", &i, &j);
	a[i][j] = white;
}

void put_b(int a[][N])
{
	int i,j;
	printf("put a new black othello : " );
	scanf("%i %i", &i, &j);
	a[i][j] = black;
}


int main(int argc, char *argv[]) {
	
   int coordinate[N][N];
	
   init(coordinate);
   
   print_othello(coordinate);
   
   status(coordinate); 
   
   put_w(coordinate);
   print_othello(coordinate);
   
   put_b(coordinate);
	
			
	return 0;
}
