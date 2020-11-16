#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define blank -1
#define white 0
#define black 1

#define N 6

extern void init(int a[][N]);
extern void print_othello(int a[][N]);
extern void status(int a[][N]);
extern void put_w(int a[][N]);
extern void put_b(int a[][N]);


int main(int argc, char *argv[]) {
	
   int coordinate[N][N];
	
   init(coordinate);
   print_othello(coordinate);
   status(coordinate); 
   
   put_w(coordinate);
  
   
	
 	
			
	return 0;
}




	  
