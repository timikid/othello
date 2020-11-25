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
	

	init(othello);  //판초기화  
 
do{
    
	if(over_w(othello)==0)   //하얀돌 놓을 곳 없으면 턴 패스   
    printf("turn pass\n");
    
    else if(over_w(othello)!=0) 
    {
        print_othello(othello);  
	    status(othello);              //판,현재 검은돌 하얀돌 개수 출력  
	    put_w(othello);               //하얀돌 놓을 좌표 입력받음-놓기 가능한 좌표 입력 받을 때까지 반복-놓기 가능하면 반복문 통과 후 좌표에 하얀돌 입력  
        flip_result_w();              //뒤집어진 돌의 방향 별 개수, 총 개수 출력  
    }
   
   
   
   
    if(over_w(othello)==0 && over_b(othello)==0)   //흰돌 차례 후, 두 돌 다 놓을 수 없으면 do-while문 빠져나가 gameover로  
    break;
    
    else if(over_b(othello)==0)   //흰돌은 놓기 가능, 검은돌은 불가능이라면 턴 패스  
    printf("turn pass\n");
    
	else if(over_b(othello)!=0)   //검은 돌 놓기 가능  
    {
    	
        print_othello(othello);   //흰 돌과 동일  
        status(othello);
        put_b(othello);
        flip_result_b();
    }
    
    
}while(over_w(othello) !=0 || over_b(othello) !=0);    // 두 돌 중 한 색이라도 돌 놓기 가능 하면 do-while문(돌 놓기) 반복  
    
    print_othello(othello);
    game_over(othello);              //게임 종료, 스코어 출력  
	
	   
 	return 0;
}




	  
