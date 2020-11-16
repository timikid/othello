#include <stdio.h>
#include <stdlib.h>

#define blank -1
#define white 0
#define black 1

#define N 6




void put_w(int a[][N])
{
	
		
	int i,j;
	int check;
	
	printf("put a new white othello : " );
	scanf("%i %i", &i, &j);
    
   {
   
    int k;
    int result;
    
	if(0<=i && i<=5 && 0<=j && j<=5)
    
	if(a[i][j-1] == black)   //¼­  
	  {
	  	for(k=1;k<=j;k++)
	  	 {
		   if(a[i][j-k] == black)
		    continue;
		    
	  	   if(a[i][j-k] == white)
	  	    {
			  result++;
	  	      break;
	  	    }
	  	    
		   else if(a[i][j-k] == blank)
	  	    break;
	  	 }
	  }
	  	 
	  	 
	if(a[i][j+1] == black)    //µ¿    
	  {
	  	for(k=1;k<(N-j);k++)
	  	 {
		   if(a[i][j+k] == black)
		    continue;
		    
	  	   if(a[i][j+k] == white)
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
		    
	  	   if(a[i+k][j] == white)
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
		    
	  	   if(a[i-k][j] == white)
	  	    {
			  result++;
	  	      break;
	  	    }
	  	    
		   else if(a[i-k][j] == blank)
	  	      break;
	  	 }
	  }  
	  
	if(result>=1)
	 check=1;
	
	else
	 check=2;
	  
}
    
    if(check=1)
	  a[i][j] = white;
	
	else
	  printf("invaild input!");
}

void put_b(int a[][N])
{
	int i,j;
	printf("put a new black othello : " );
	scanf("%i %i", &i, &j);
	a[i][j] = black;
}

