#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6

static int e,w,s,n,ne,nw,se,sw;

void put_w(int a[][N])
{

	int i,j;
	int check;
	    
    int k,t;
    int result = 0;  // result>=1일 경우 배치가능  0일 경우 배치 불가  

do{
	
	printf("put a new white othello : " );
	scanf("%i %i", &i, &j);

    if(a[i][j] != blank)
     result = 0;
     
	else if( i<0 || i>5 || j<0 || j>5 )
	 result = 0;
	
	else{
		    if(a[i][j-1] == black)   //서  
			  {
			  	 for(k=2;k<=j;k++)   // 0<=j-k<N
			  	 {
				   if(a[i][j-k] == black)
				    continue;
				   
			  	   else if(a[i][j-k] == white)
			  	    {
					    result++;
        				for(t=1;t<k;t++){
						a[i][j-t] =white;
						w = t;
						}
			  	        break;
			  	    }
			  	    
				   else if(a[i][j-k] == blank)
			  	    {
			  	        
					    break;
				    }
			  	 }
			  }
	  	 
	  	 
			if(a[i][j+1] == black)    //동    
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
			  	for(k=1;(k<N-i);k++)  // 0<=i+k<N
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
			  	for(k=1;k<=i;k++)    // 0<=i-k<N 
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
        }
 
  if(result>=1)
	 a[i][j] = white;
 
  else
	 printf("invaild input\n!");

}while(result == 0);
	 
}





void put_b(int a[][N])
{
	int i,j;
	int check;
	
	int k,t; 
    int result = 0;  // result>=1일 경우 배치가능  0일 경우 배치 불가  
    
do{	
	printf("put a new black othello : " );
	scanf("%i %i", &i, &j);
	
	if(a[i][j] != blank)
    result = 0;
    
    else if( i<0 || i>5 || j<0 || j>5 )
	 result = 0;
	
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
        
		}		
         
    if(result>=1)
	a[i][j] = black;
  
    else
	printf("invaild input!\n");

}while(result == 0);
	
}

  

	


