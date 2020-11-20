#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6


extern int e,w,s,n,ne,nw,se,sw;

void flip_result_w(){
	
    
	int all; // 뒤집힌 모든 알 개수
	all = e + w + s + n + ne + nw + se + sw;
	
	printf(":: flip result ::\n");
	printf("W:%i E:%i N:%i S:%i NW:%i NE:%i SW:%i SE:%i\n", w,e,n,s,nw,ne,sw,se);
	printf("White has flipped %i otheillos!\n", all); 
}


void flip_result_b(){

	
	int all; // 뒤집힌 모든 알 개수
	all = e+w+s+n+ne+nw+se+sw;
	
	printf(":: flip result ::\n");
	printf("W:%i E:%i N:%i S:%i NW:%i NE:%i SW:%i SE:%i\n",w,e,n,s,nw,ne,sw,se);
	printf("Black has flipped %i otheillos!\n", all); 
}
