#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void plot(int *s, int head, int n, char str[])
	{
    	char * commandsForGnuplot[] = {"set style data line", "plot [0:250][0:10] 'data.temp'"};
    	FILE * temp = fopen("data.temp", "w");
    	FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    	fprintf(temp, "%d 0 \n", head);
    	for (int i=0; i < n; i++)
        	fprintf(temp, "%d %d \n", s[i], i+1);
    
    	fprintf(gnuplotPipe, "set title \"%s\" \n", str);

    	for (int i=0; i < 2; i++)
        	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
	}


//calculate total head movements 
int total (int head, int n, int *seek_pos , char ch)
	{	int *s = (int *)malloc(sizeof(int *)*n);
		int j=0,real_head=head;
	 	int total = 0; int pos ,flag = 0;
	    for(int i=0;i<n;i++)
	    {if(head<seek_pos[i])
	    	{ pos = i; flag = 1;break;}
	    }
	    if(flag ==0)
	    pos = n - 1;
	    
	    printf(" ch = %c",ch);
	    printf(" \n Scheduled queue is \n");
	    if(ch == 'l')
	    	{ for(int i=pos-1;i>=0;i--)
	    		{ printf(" %d",seek_pos[i]); 
	    		  s[j++] = seek_pos[i];
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i]; }
	    		  s[j++] = 0;
	    		  s[j++] = 250;
	     	  for(int i=n;i>pos;i--)
	    		{ s[j++] = seek_pos[i];
	    		  printf(" %d",seek_pos[i]); 
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i];
	    		   }
	        }
	    
	    if(ch == 'r')
	    	{ for(int i=pos;i<n;i++)
	    		{ s[j++] = seek_pos[i];
	    		  printf(" %d",seek_pos[i]); 
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i]; }
	    		  s[j++] = 250;
	    		  s[j++] = 0;
	    	  for(int i=0;i>=pos-1;i++)
	    		{ s[j++] = seek_pos[i];
	    		  printf(" %d",seek_pos[i]); 
	    		  total += abs(head - seek_pos[i]);
	    		  head = seek_pos[i]; }
	     	 }
	     	 
	     	 
			//gnuplot
			char str[] = "SCAN";
    		plot(s,real_head,n,str);
	     return total;
	     }
	
void sort(int *seek_pos, int n)
	{   int temp;
    	for(int i=0;i<n-1;i++)
        	for(int j=0;j<n-i-1;j++)
            	if(seek_pos[j]>seek_pos[j+1])
            	{
            		 temp = seek_pos[j];
            		 seek_pos[j]=seek_pos[j+1];
            		 seek_pos[j+1]=temp;
            	}
           
	}


// configure gnuplot

	 
void main()
{
	srand(time(0));
	
	//generate number of requests, seek position, current head position
	
	int n = rand()%10;
	int *seek_pos = (int *)malloc(sizeof(int *)*n);
	int head = rand()%250;
	for(int i=0; i<n; i++)
		 seek_pos[i] = rand()%250;  
	//print schedule
	
	printf("head position = %d \n",head);
	printf("Disk Request queue  \n");
	for(int i=0; i<n; i++)
		printf(" %d ",seek_pos[i]); 
	sort(seek_pos,n);
	char option[2] = {'l','r'};
	printf("\n Total head movements = %d \n", total(head,n,seek_pos,'l'));
	                                                      
	 
 }
	
	
	
	
