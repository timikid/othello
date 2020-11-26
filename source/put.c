#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6



extern void init_flip();  
int e,w,s,n,ne,nw,se,sw;


void put_w(int a[][N])
{
    int i,j;  
	init_flip();      //�������� ���� ���� �� �ϸ��� �ʱ�ȭ  
	    
    int k,t;
    int result = 0;      // result>=1�� ��� ��ġ����  result=0�� ��� ��ġ �Ұ� 

do{
   
    printf("put a new white othello : " );     //�� ���� ��ǥ �Է¹ޱ�  
	scanf("%i %i", &i, &j);	
	printf("\n");
	
	
    if( i<0 || i>=N || j<0 || j>=N )       // ���� ���� �� �ִ� ��,�� ������ 0<=i,j<N �̹Ƿ� �� �� ���� ���� result �� 0 , �ݺ����ǰ˻�(while)�ΰ�  
     {                                      
	    printf("invaild input! (should be less than 6)\n\n");
	    result = 0;
     }
	
	else if(a[i][j] != blank)              //��ĭ�� �ƴ� ��ǥ �Է½� result �� 0,  �ݺ����ǰ˻�(while)�ΰ�
     {
     	printf("invaild input! (already occupied)\n\n");
		result = 0;
     }

	
	else{
		    if(a[i][j-1] == black)                   //��    �Է��� ��ǥ �̿��� ���ʿ� ������(��뵹) �ִ� ���  
			  {
			  	 for(k=2;k<=j;k++)                   // 0<=j-k<N
			  	 {
				   if(a[i][j-k] == black)            // �������� kĭ���� �������̸� ���� k������  
				    continue;
				   
			  	   else if(a[i][j-k] == white)       // �������� kĭ ���� �Ͼᵹ�� ��� (���� k-1ĭ ������ ������)  
			  	    { 
					    result++;                    // �� ������ ���� ���� result �� ���� 
        				
						for(t=1;t<k;t++){ 
						a[i][j-t] =white;            //k�� ������ ������ ��ǥ�� �Ͼᵹ �Է� (�� ������) 
						w = t;                       //�������� �� ���� w �� ����  
						}
			  	        break;                       //�������� ���� �Ͼᵹ�� ������ �� ���� ���ʹ��� Ž����  ��   
			  	    }
			  	    
				   else if(a[i][j-k] == blank)       //�������� kĭ ���� ��ĭ�� ���( ���� k-1ĭ ������ ������) 
					    break;                       //������ �� �����Ƿ� ���ʹ��� Ž�� ����  
			  	 }
			  }
	  	 
			if(a[i][j+1] == black)    //��   ���� ����     
			  {
			  	for(k=2; k<N-j ;k++)     //0<=j+k<N
			  	 {
				   if(a[i][j+k] == black)
				    continue;
				    
			  	   else if(a[i][j+k] == white)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i][j+t] =white;
						 	e=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i][j+k] == blank)
			  	    break;
			  	 }
			  }
			  
			if(a[i+1][j] == black)   //��  
			  {
			  	for(k=2;(k<N-i);k++)  // 0<=i+k<N
			  	 {
				   if(a[i+k][j] == black)
				    continue;
				    
			  	   else if(a[i+k][j] == white)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i+t][j] =white;
						 	s=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j] == blank)
			  	    break;
			  	 }
			  }
			  
			if(a[i-1][j] == black)   //��  
			  {
			  	for(k=2;k<=i;k++)    // 0<=i-k<N 
			  	 {
				   if(a[i-k][j] == black)
				      continue;
				    
			  	   else if(a[i-k][j] == white)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i-t][j] =white;
						 	n=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j] == blank)
			  	      break;
			  	 }
			  }  
			  
			if(a[i+1][j-1] == black)   //����   
			  {
			  	for(k=2;(k<N-i && k<=j);k++)      // 0<=i+k<N, 0<=i-k<N
			  	 {
				   if(a[i+k][j-k] == black)
				    continue;
				    
			  	   else if(a[i+k][j-k] == white)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i+t][j-t] =white;
						 	sw=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j-k] == blank)
			  	    break;
			  	 }
			  }
			  
		  	if(a[i+1][j+1] == black)   //����   
			  {
			  	for(k=2;(k<N-i && k<N-j);k++)      // 0<=i+k<N , 0<=i+k<N
			  	 {
				   if(a[i+k][j+k] == black)
				    continue;
				    
			  	   else if(a[i+k][j+k] == white)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i+t][j+t] =white;
						 	se=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j+k] == blank)
			  	    break;
			  	 }
			  }

		  	if(a[i-1][j+1] == black)   //�ϵ�   
			  {
			  	for(k=2;( k<=i && k<N-j);k++)      // 0<=i-k<N , 0<=j+k<N
			  	 {
				   if(a[i-k][j+k] == black)
				    continue;
				    
			  	   else if(a[i-k][j+k] == white)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i-t][j+t] =white;
						 	ne=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j+k] == blank)
			  	    break;
			  	 }
			  }		
			  
		  	if(a[i-1][j-1] == black)   //�ϼ�  
			  {
			  	for(k=2;( k<=i && k<=j );k++)      // 0<=i-k<N  , 0<=j-k<N
			  	 {
				   if(a[i-k][j-k] == black)
				    continue;
				    
			  	   else if(a[i-k][j-k] == white)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i-t][j-t] =white;
						 	nw=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j-k] == blank)
			  	    break;
			  	 }
			  }				  	  
			  if(result == 0)
			  printf("invaild input! (no flips)\n\n");
        }
    
	
}while(result == 0);      /* ��ǥ����, ��ĭ���� ���� Result���� 0�� ������� �ʰ�(�������������)
                             �� ���⿡�� ������ ������ �� ���� ��ŭ Result�� �����ϹǷ� Result>=1�� ��ǥ ���� ������ �ݺ�*/     
   
    a[i][j] = white;       //�ݺ� �� ����� �ش� ��ǥ�� white�� ����  
}




void put_b(int a[][N])       //put_w����  black, white �� �ٲ� 
{
	int i,j;
	init_flip();
	
	int k,t; 
    int result = 0;  // result>=1�� ��� ��ġ����  0�� ��� ��ġ �Ұ�  
    
do{	
	printf("put a new black othello : " );
	scanf("%i %i", &i, &j);
	printf("\n");
	
    if( i<0 || i>5 || j<0 || j>5 )
	 {
	 printf("invaild input! (should be less than 6)\n\n");	
	 result = 0;
     }
	
	else if(a[i][j] != blank)
     {
	 printf("invaild input! (already occupied)\n\n");
	 result = 0;
     }
	
	else{
		  	if(a[i][j-1] == white)   //��  
			  {
			  	 for(k=2;k<=j;k++)
			  	 {
				   if(a[i][j-k] == white)
				    continue;
				   
			  	   else if(a[i][j-k] == black)   
					 //���� �� ���� �̿��� ���������� ���� �� ���� �ִ� ��� �ѷ����� �������� ����t ��ŭ ��������  
			  	    {
					  result++;
					  for(t=1;t<k;t++)
					    {
						   a[i][j-t] = black;
						   w=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i][j-k] == blank)
			  	    break;
			  	 }
			  }
	  	 
	  	 
			if(a[i][j+1] == white)    //��    
			  {
			  	for(k=2;k<(N-j);k++)
			  	 {
				   if(a[i][j+k] == white)
				    continue;
				    
			  	   else if(a[i][j+k] == black)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i][j+t] = black;
						 	e=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i][j+k] == blank)
			  	    break;
			     }
			  }
			  
			if(a[i+1][j] == white)   //��  
			  {
			  	for(k=1;k<(N-i);k++)
			  	 {
				   if(a[i+k][j] == white)
				    continue;
				    
			  	   else if(a[i+k][j] == black)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i+t][j] = black;
						 	s=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j] == blank)
			  	    break;
			  	 }
			  }
			  
			if(a[i-1][j] == white)   //��  
			  {
			  	for(k=1;k<=i;k++)
			  	 {
				   if(a[i-k][j] == white)
				      continue;
				    
			  	   else if(a[i-k][j] == black)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i-t][j] = black;
						 	n=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j] == blank)
			  	      break;
			  	 }
			  }  
			  
				if(a[i+1][j-1] == white)   //����   
			  {
			  	for(k=2;(k<=j && k<N-i);k++)      
			  	 {
				   if(a[i+k][j-k] == white)
				    continue;
				    
			  	   else if(a[i+k][j-k] == black)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i+t][j-t] = black;
						 	sw=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j-k] == blank)
			  	    break;
			  	 }
			  }
			  
			  
			  	if(a[i+1][j+1] == white)   //����   
			  {
			  	for(k=2;(k<N-j && k<N-i);k++)     
			  	 {
				   if(a[i+k][j+k] == white)
				    continue;
				    
			  	   else if(a[i+k][j+k] == black)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i+t][j+t] = black;
						 	se=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j+k] == blank)
			  	    break;
			  	 }
			  }

			  	if(a[i-1][j+1] == white)   //�ϵ�   
			  {
			  	for(k=2;( k<=i && k<N-j);k++)      
			  	 {
				   if(a[i-k][j+k] == white)
				    continue;
				    
			  	   else if(a[i-k][j+k] == black)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i-t][j+t] = black;
						 	ne=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j+k] == blank)
			  	    break;
			  	 }
			  }		
			  
			  	if(a[i-1][j-1] == white)   //�ϼ�  
			  {
			  	for(k=2;( k<=i && k<=j );k++)         
			  	 {
				   if(a[i-k][j-k] == white)
				    continue;
				    
			  	   else if(a[i-k][j-k] == black)
			  	    {
					  result++;
					  for(t=1;t<k;t++){
						 	a[i-t][j-t] = black;
						 	nw=t;
						}
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j-k] == blank)
			  	    break;
			  	 }
			  }	
			  
			  if(result == 0)
			  printf("invaild input! (no flips)\n\n");				  	  
        
		}		

}while(result == 0);

	a[i][j] = black;
}

