#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>


struct process
{ int pid;
  int allocation[4];
  int need[4];
  int finish;}P[15];
int available[4] , max[4]; 

int Flag(int n)
{for(int j=0;j<n;j++)
			if(P[j].finish==0)
			return 0;
  return 1;		}

int need_lt_available(int i,int n){
		for(int j=0;j<4;j++)
		{ if(P[i].need[j]>available[j])
		  	{
		  	return 0;}
}	return 1;
}

void available_allocation(int i,int n)
{ 
		for(int j=0;j<4;j++)
		  	available[j] += P[i].allocation[j] ;
  }
  
  
 void display(int n)
 {  printf("\n max available");
    for(int i=0;i<4;i++)
    {printf("\n %d \t %d",max[i],available[i]);}
    
 	printf("\n process-id  \t allocation \t need ");
   for(int i=0;i<n;i++)
   { printf("\n %d ",P[i].pid);
     for(int j=0;j<4;j++)
     {printf("\t \t \t %d \t %d",P[i].allocation[j],P[i].need[j]);
      printf("\n");}
      }
      
   }
void main()
{	int n;int safe_seq[15];
	srand(time(0));
	n = rand()%10 + 1;
    for(int i=0;i<4;i++)
    		{ 
			max[i] = rand()%10 + 5;
		    available[i] = rand()%10+1;
		    }
	for(int i =0;i<n;i++)
	{	P[i].pid = rand()%10 + 1;
	    
		for(int j=0;j<4;j++)
			{
			P[i].allocation[j]= rand()%10 + 1;
			
			}
		
		P[i].finish = 0;
		}
	
    for(int i=0;i<n;i++)
    {	for(int  j=0;j<4;j++)
    		{P[i].need[j]=abs(max[j] - P[i].allocation[j]);
    		
  		
  		}
	
  		
  	 }
  		
  		
  		
    int j=0;
     while(!Flag(n))
    { int flag =0;
      for(int i=0;i<n;i++)
      { if((P[i].finish == false) && (need_lt_available(i,n)))
         { available_allocation(i,n);
           P[i].finish = 1;
           safe_seq[j] = P[i].pid;
           j++;
           flag = 1;
           }
      }
      if(flag==0) break;
      }
      
      
      display(n);
      
      
      if(Flag(n))
      { printf("\n Safe sequence <");
      for(int i =0;i<n;i++)
      printf("%d ",safe_seq[i]);
      printf(">");}
      else
      printf("safe sequence doesnt exist");
      
} 

