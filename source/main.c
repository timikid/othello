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
extern void sad(int a[][N]);
extern void over_w(int a[][N], int i, int j);
extern void over_b(int a[][N], int i, int j);


int main(int argc, char *argv[]) {
	
   int coordinate[N][N];
	

 
   init(coordinate);
   
    print_othello(coordinate);
    status(coordinate); 


while(over_b != -1 && over_w != -1){

   put_w(coordinate);
   print_othello(coordinate);
   status(coordinate);
   
  
   if(over_b == -1);
    break;
	   
   put_b(coordinate);
   print_othello(coordinate);
 
}
    
    
   
 	return 0;
}




	  
