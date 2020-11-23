#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6


int over_w(int a[][N]){
	
    int i,j;
    
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
	
    if(a[i][j]==blank){
	    
		int k;
        int result=0;
        
		if(a[i][j-1] == black)   //¼­  
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
			  	    {
			  	        
					    break;
				    }
			}
		}
	  	 
	  	 
		if(a[i][j+1] == black)    //µ¿    
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
			  
		
		if(a[i+1][j] == black)   //³²  
		{
		  	for(k=1;k<(N-i);k++)
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
			  
		if(a[i-1][j] == black)   //ºÏ  
		{
		  	for(k=1;k<=i;k++)
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
			  
				if(a[i+1][j-1] == black)   //³²¼­   
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
			  
			  
			  	if(a[i+1][j+1] == black)   //³²µ¿   
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

			  	if(a[i-1][j+1] == black)   //ºÏµ¿   
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
			  
			  	if(a[i-1][j-1] == black)   //ºÏ¼­  
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
	
		if(result>=1)	  
		return 1;
		
		else
		return -1;
}
}
}
}
