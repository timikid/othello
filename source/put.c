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
	init_flip();      //뒤집어진 돌의 개수 각 턴마다 초기화  
	    
    int k,t;
    int result = 0;      // result>=1일 경우 배치가능  result=0일 경우 배치 불가 

do{
   
    printf("put a new white othello : " );     //돌 놓을 좌표 입력받기  
	scanf("%i %i", &i, &j);	
	printf("\n");
	
	
    if( i<0 || i>=N || j<0 || j>=N )       // 돌을 놓을 수 있는 행,열 범위가 0<=i,j<N 이므로 그 외 범위 수는 result 값 0 , 반복조건검사(while)로감  
     {                                      
	    printf("invaild input! (should be less than 6)\n\n");
	    result = 0;
     }
	
	else if(a[i][j] != blank)              //빈칸이 아닌 좌표 입력시 result 값 0,  반복조건검사(while)로감
     {
     	printf("invaild input! (already occupied)\n\n");
		result = 0;
     }

	
	else{
		    if(a[i][j-1] == black)                   //서    입력한 좌표 이웃한 서쪽에 검은돌(상대돌) 있는 경우  
			  {
			  	 for(k=2;k<=j;k++)                   // 0<=j-k<N
			  	 {
				   if(a[i][j-k] == black)            // 서쪽으로 k칸옆이 검은돌이면 다음 k값으로  
				    continue;
				   
			  	   else if(a[i][j-k] == white)       // 서쪽으로 k칸 옆이 하얀돌인 경우 (현재 k-1칸 까지는 검은돌)  
			  	    { 
					    result++;                    // 돌 뒤집어 질때 마다 result 값 증가 
        				
						for(t=1;t<k;t++){ 
						a[i][j-t] =white;            //k전 까지의 검은돌 좌표에 하얀돌 입력 (돌 뒤집기) 
						w = t;                       //뒤집어진 돌 개수 w 에 저장  
						}
			  	        break;                       //검은돌을 따라가 하얀돌을 만나면 그 턴의 서쪽방향 탐색은  끝   
			  	    }
			  	    
				   else if(a[i][j-k] == blank)       //서쪽으로 k칸 옆이 빈칸인 경우( 현재 k-1칸 가지는 검은돌) 
					    break;                       //뒤집을 수 없으므로 서쪽방향 탐색 중지  
			  	 }
			  }
	  	 
			if(a[i][j+1] == black)    //동   서와 동일     
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
			  
			if(a[i+1][j] == black)   //남  
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
			  
			if(a[i-1][j] == black)   //북  
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
			  
			if(a[i+1][j-1] == black)   //남서   
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
			  
		  	if(a[i+1][j+1] == black)   //남동   
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

		  	if(a[i-1][j+1] == black)   //북동   
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
			  
		  	if(a[i-1][j-1] == black)   //북서  
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
    
	
}while(result == 0);      /* 좌표범위, 빈칸여부 에서 Result값에 0이 저장되지 않고(돌놓기조건통과)
                             각 방향에서 뒤집기 가능한 돌 개수 만큼 Result값 증가하므로 Result>=1인 좌표 받을 때까지 반복*/     
   
    a[i][j] = white;       //반복 문 통과시 해당 좌표에 white값 저장  
}




void put_b(int a[][N])       //put_w에서  black, white 만 바뀜 
{
	int i,j;
	init_flip();
	
	int k,t; 
    int result = 0;  // result>=1일 경우 배치가능  0일 경우 배치 불가  
    
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
		  	if(a[i][j-1] == white)   //서  
			  {
			  	 for(k=2;k<=j;k++)
			  	 {
				   if(a[i][j-k] == white)
				    continue;
				   
			  	   else if(a[i][j-k] == black)   
					 //놓을 흰 돌에 이웃한 검은돌들의 끝에 흰 돌이 있는 경우 둘러싸인 검은돌의 개수t 만큼 뒤집어줌  
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
	  	 
	  	 
			if(a[i][j+1] == white)    //동    
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
			  
			if(a[i+1][j] == white)   //남  
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
			  
			if(a[i-1][j] == white)   //북  
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
			  
				if(a[i+1][j-1] == white)   //남서   
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
			  
			  
			  	if(a[i+1][j+1] == white)   //남동   
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

			  	if(a[i-1][j+1] == white)   //북동   
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
			  
			  	if(a[i-1][j-1] == white)   //북서  
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

