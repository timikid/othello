#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 1 //over_w에서 white와 black에 저장된 값 바꿈  
#define black 0

#define N 6

                                 
                                 //게임 종료 조건 검토 함수  
int over_b(int a[][N]){          //put_b(입력가능한 좌표인지 여덟방향으로 탐색) 에서 돌뒤집기,뒤집은 돌 개수 세기 기능만 빠짐  

    int i,j;
    
    int k;
    int result=0;
    
 
	for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
            
            
			if(a[i][j]!=blank)
			continue;
			
			else
		    {	
              if(a[i][j-1] == black)   //서  
			  {
			  	 for(k=2;k<=j;k++)
			  	 {
				   if(a[i][j-k] == black)
				    continue;
			     
			       
			  	   else if(a[i][j-k] == white)
			  	    {
					    result++;
			  	        break;
			  	    }
			  	    
				   else if(a[i][j-k] == blank)
			  	    break;
				   
			  	 }
			  }
	  	 
	  	 
			if(a[i][j+1] == black)    //동    
			  {
			  	for(k=2;k<(N-j);k++)
			  	 {
				   if(a[i][j+k] == black)
				    continue;
				    
			  	   else if(a[i][j+k] == white)
			  	    {
					  result++;
			  	      break;
			  	    }
			  	    
				   else if(a[i][j+k] == blank)
			  	    break;
			  	 }
			  }
			  
			if(a[i+1][j] == black)   //남  
			  {
			  	for(k=2;k<(N-i);k++)
			  	 {
				   if(a[i+k][j] == black)
				    continue;
				    
			  	   else if(a[i+k][j] == white)
			  	    {
					  result++;
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j] == blank)
			  	    break;
			  	 }
			  }
			  
			if(a[i-1][j] == black)   //북  
			  {
			  	for(k=2;k<=i;k++)
			  	 {
				   if(a[i-k][j] == black)
				      continue;
				    
			  	   else if(a[i-k][j] == white)
			  	    {
					  result++;
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j] == blank)
			  	      break;
			  	 }
			  }  
			  
				if(a[i+1][j-1] == black)   //남서   
			  {
			  	for(k=2;(k<j && k<N-i);k++)      
			  	 {
				   if(a[i+k][j-k] == black)
				    continue;
				    
			  	   else if(a[i+k][j-k] == white)
			  	    {
					  result++;
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j-k] == blank)
			  	    break;
			  	 }
			  }
			  
			  
			  	if(a[i+1][j+1] == black)   //남동   
			  {
			  	for(k=2;(k<N-j && k<N-i);k++)     
			  	 {
				   if(a[i+k][j+k] == black)
				    continue;
				    
			  	   else if(a[i+k][j+k] == white)
			  	    {
					  result++;
			  	      break;
			  	    }
			  	    
				   else if(a[i+k][j+k] == blank)
			  	    break;
			  	 }
			  }

			  	if(a[i-1][j+1] == black)   //북동   
			  {
			  	for(k=2;( k<i && k<N-j);k++)      
			  	 {
				   if(a[i-k][j+k] == black)
				    continue;
				    
			  	   else if(a[i-k][j+k] == white)
			  	    {
					  result++;
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j+k] == blank)
			  	    break;
			  	 }
			  }		
			  
			  	if(a[i-1][j-1] == black)   //북서  
			  {
			  	for(k=2;( k<i && k>j );k++)      
			  	 {
				   if(a[i-k][j-k] == black)
				    continue;
				    
			  	   else if(a[i-k][j-k] == white)
			  	    {
					  result++;
			  	      break;
			  	    }
			  	    
				   else if(a[i-k][j-k] == blank)
			  	    break;
			  	 }
			  }
		    }
		    
			  
}
}
		if(result>=1)	    // 임의의 방향으로 돌 뒤집기 가능을 나타내는 result값이 1보다 크면 retrun값 1 
		return 1;
		
		else
		return 0;


}
