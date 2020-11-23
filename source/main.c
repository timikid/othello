#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define blank -1
#define white 0
#define black 1   // 빈칸, 검은알, 하얀알에 해당하는 정수 지정 

#define N 6

extern void init(int a[][N]);
extern void print_othello(int a[][N]);
extern void status(int a[][N]);

extern int put_w(int a[][N]);
extern int put_b(int a[][N]);

extern int over_w(int a[][N]);
extern int over_b(int a[][N]);

extern void flip_result_w();
extern void flip_result_b();
extern void init_flip();

extern void game_over(int a[][N]);

int othello[N][N];



int main(int argc, char *argv[]) {
	
    
	init(othello);
	

while(over_w(othello) != 0 && over_b(othello) != 0)
{
   
     
    print_othello(othello);
    status(othello);
    put_w(othello);
    printf("\n");   
	
    flip_result_w();
    
     
    if(over_b(othello)==0)
     break;
      
    if(over_b(othello)!=0)	  
	{
	  
	   print_othello(othello);
	   status(othello);
       put_b(othello);
       printf("\n");
	   flip_result_b();
       
    }
}
    
    game_over(othello);
   
 	return 0;
}




	  
