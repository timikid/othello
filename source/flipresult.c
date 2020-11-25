#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6


extern int e,w,s,n,ne,nw,se,sw;        //put 함수에서 센, 각 방향 별 뒤집어진 돌의 개수 사용  

void flip_result_w(){
	

	int all;      // 뒤집힌 모든 알 개수
	all = e + w + s + n + ne + nw + se + sw;
	
	printf(":: flip result ::\n");
	printf("W:%i E:%i N:%i S:%i NW:%i NE:%i SW:%i SE:%i\n", w,e,n,s,nw,ne,sw,se);
	printf("White has flipped %i othellos!\n\n", all); 
}


void flip_result_b(){

	
	int all; // 뒤집힌 모든 알 개수
	all = e+w+s+n+ne+nw+se+sw;
	
	printf(":: flip result ::\n");
	printf("W:%i E:%i N:%i S:%i NW:%i NE:%i SW:%i SE:%i\n",w,e,n,s,nw,ne,sw,se);
	printf("Black has flipped %i othellos!\n\n", all); 
}
