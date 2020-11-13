#include <stdio.h>
#include <stdlib.h>


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



