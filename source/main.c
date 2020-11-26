#include <stdio.h>
#include <stdlib.h>
#include "Othello.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define blank -1
#define white 0
#define black 1   // ��ĭ, ������, �Ͼ�˿� ���� ���� 

#define N 6



int othello[N][N];



int main(int argc, char *argv[]) {
	

	init(othello);  //���ʱ�ȭ  
 
do{
    
	if(over_w(othello)==0)   //�Ͼᵹ ���� �� ������ �� �н�   
    printf("turn pass\n");
    
    else if(over_w(othello)!=0) 
    {
        print_othello(othello);  
	    status(othello);              //��,���� ������ �Ͼᵹ ���� ���  
	    put_w(othello);               //�Ͼᵹ ���� ��ǥ �Է¹���- ������ ��ǥ �Է� ���� ������ �ݺ�-���� �����ϸ� �ݺ��� ��� �� ��ǥ�� �Ͼᵹ �Է�  
        flip_result_w();              //�������� ���� ���� �� ����, �� ���� ���  
    }
   
   
   
   
    if(over_w(othello)==0 && over_b(othello)==0)   //�� ���� ��, �� �� �� ���� �� ������ do-while�� �������� gameover��  
    break;
    
    else if(over_b(othello)==0)   //���� ���� ����, �������� �Ұ����̶�� �� �н�  
    printf("turn pass\n");
    
	else if(over_b(othello)!=0)   //���� �� ���� ����  
    {
    	
        print_othello(othello);   //�� ���� ����  
        status(othello);
        put_b(othello);
        flip_result_b();
    }
    
    
}while(over_w(othello) !=0 || over_b(othello) !=0);    // �� �� �� �� ���̶� �� ���� ���� �ϸ� do-while��(�� ����) �ݺ�  
    
    print_othello(othello);
    game_over(othello);              //���� ����, ���ھ� ���  
	
	   
 	return 0;
}




	  
