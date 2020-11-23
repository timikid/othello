#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6

void init(int a[][N])
{
//모든 배열값에 blank값 넣은 후 (2,2)(3,3)에는 다시 white값, (2,3) (3,2)에는 black값 넣어줌  
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j]= blank;      
		}
	    a[2][2] = white;
	    a[2][3] = black;
	    a[3][2] = black;
	    a[3][3] = white;
	}
}


void print_othello(int a[][N])
{
    int i,j;
    
    printf("\n");
   	printf("   0 1 2 3 4 5");  //열 입력  
    printf("\n"); 
	printf("   - - - - - -");
    printf("\n");
  
   for(i=0;i<N;i++){           
        printf("%i |", i);    //행 입력  
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
    int countb = 0;
	int countw = 0;  
 
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(a[i][j] == white)  //배열값이  white값이면 countw변수에 1증가, black값이면 countb변수에 1증가 
			 countw+=1;
			else if(a[i][j] == black)
			 countb+=1;
		}
	}
	printf("\n");
	printf("STATUS - WHITE(O) : %i  BLACK(X) :%i", countw, countb);
	printf("\n\n");
}


void init_flip(){
	// 각 방향 별 뒤집어진 돌의 개수 초기화  
	extern int e,w,s,n,ne,nw,se,sw;
	e=0;
	w=0;
	s=0;
	n=0;
	ne=0;
	nw=0;
	se=0;
	sw=0;
}


