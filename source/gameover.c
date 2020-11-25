#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6



void game_over(int a[][N]){
    
	printf("\n::GAME OVER::\n");
		
		int i,j;
		int w=0;
		int b=0;
		
		for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(a[i][j] == white)  
			 w+=1;
			else if(a[i][j] == black)
			 b+=1;
		}
	}
	
	if(b>w){
		printf("Winner is black! black:%i white:%i\n", b, w);		
	}
	else if(b<w){
		printf("Winner is white! black:%i white:%i\n", b, w);
	}
	else
	printf("Winner is white&black! black:%i white:%i\n", b, w);
	
}
