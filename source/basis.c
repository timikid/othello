#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6

void init(int a[][N])
{
//��� �迭���� blank�� ���� �� (2,2)(3,3)���� �ٽ� white��, (2,3) (3,2)���� black�� �־���  
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
   	printf("   0 1 2 3 4 5");  //�� �Է�  
    printf("\n"); 
	printf("   - - - - - -");
    printf("\n");
  
   for(i=0;i<N;i++){           
        printf("%i |", i);    //�� �Է�  
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
			if(a[i][j] == white)  //�迭����  white���̸� countw������ 1����, black���̸� countb������ 1���� 
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
	// �� ���� �� �������� ���� ���� �ʱ�ȭ  
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


