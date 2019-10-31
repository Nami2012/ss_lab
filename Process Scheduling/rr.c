#include<stdio.h>
void main()
{  int p,bt[10],wt[10],tt[10], at[10];
   float avgwt=0,avgtt=0;
   int time_slice;
  //enter the number of processes
 printf("enter the number of processes");
 scanf("%d",&p);
 printf("enter time slice");
 scanf("%d",&time_slice);
 int pno[p];
  //enter the burst time 
  printf("enter the arrival time,burst time   of each process");
  for(int i=0;i<p;i++)
  	{pno[i] = i+1;
  	 scanf("%d %d",&at[i],&bt[i]);}          
 
  //arrival time sort
 for(int i=0;i<p-1;i++)
    for(int j=i+1;j<p;j++)
    { if (at[i]>at[j])
         {  {int temp = bt[i];bt[i] = bt[j];bt[j] = temp;}
            {int temp = at[i];at[i] = at[j];at[j] = temp;}
            {int temp = pno[i];pno[i] = pno[j];pno[j] = temp;}}}

 
 //calculate waiting time
 wt[0]=0;
 for(int i=1;i<p;i++)
 { wt[i]=0;
   for(int j=0;j<i;j++)
 	wt[i] += bt[j];
   avgwt += wt[i];}
   
  //calculate turnaround time
  
 for(int i=0;i<p;i++)
 { tt[i] = wt[i] + bt[i];
   avgtt += tt[i];}
 
 avgwt /= p;
 avgtt /= p;
 
 printf("process \t arrival time \t burst time \t waiting time \t turnaround time \n");
 for(int i=0;i<p;i++)
 {
    printf("%d \t\t %d \t\t %d \t\t %d \t\t %d", pno[i],at[i],bt[i],wt[i],tt[i]);
    printf("\n"); }

    
 printf("average waiting time %0.2f" ,avgwt);
 printf("average turnaround time %0.2f", avgtt);}
 
