#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct process_node
{ int pid;
  int burst;
  int waiting;
  int turnaround;}P[15];
  
void waiting_time( int n)
{	P[0].waiting = 0;
    P[0].turnaround = P[0].burst;
    int tburst = P[0].burst;
    int total_wait = 0;
    int total_turnaround = 0;
    float avg_wait,avg_turnaround;
    for(int i=1;i<n;i++)
    {
    		P[i].waiting = tburst;
    		P[i].turnaround = P[i].waiting + P[i].burst;
    		tburst += P[i].burst;
    		total_wait += P[i].waiting;
    		total_turnaround += P[i].turnaround;}
    		avg_wait = total_wait/n;
    		avg_turnaround = total_turnaround/n;
    printf("Process-id \t Burst-time \t waiting-time \t Turnaround time \n");
	for(int i =0;i<n;i++)
	{ 
		printf(" %d \t \t", P[i].pid);
		printf(" %d \t \t",P[i].burst);
		printf(" %d \t \t",P[i].waiting);
		printf(" %d \t \t",P[i].turnaround);		
		printf("\n");}
    printf("\n Average waiting time= %.3f",avg_wait);
    printf("\n Average turnaround = %.3f", avg_turnaround); 

}
    		
	
  
void main()
{	int n;
	srand(time(0));
	n = rand()%10 + 1;
	for(int i =0;i<n;i++)
	{
		P[i].pid = rand()%10 + 1;
		P[i].burst = rand()%10 + 1;}
	
	waiting_time(n);
	
}

	
