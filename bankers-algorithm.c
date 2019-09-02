#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

//Data structures
struct process{
 	int pid;
  	int allocation[4];
  	int need[4];
  	int req[4];
  	int finish;}P[15];

int available[4] , max[4] , work[4],res; 


int Flag(int n){
       for(int j=0;j<n;j++)
		if(P[j].finish==0)
		return 0;
  	return 1;}


int need_lt_work(int i,int n){
	for(int j=0;j<res;j++){
	 if(P[i].need[j]>work[j]){
	 	return 0;}}	
	return 1;}


void work_allocation(int i,int n){
 	printf(" work = ");
 	for(int j=0;j<res;j++)
	  	{work[j] += P[i].allocation[j];
	  	 printf("%d ",work[j]);}}
int req_lt_need(int i, int n){
	printf("\n need = ");
	for(int j=0;j<res;j++)
		printf("%d ",P[i].need[j]);
	
	for(int j=0;j<res;j++){
	 if(P[i].req[j]>P[i].need[j]){
	 	return 0;}}
	return 1;}

int req_lt_available(int i, int n){
	printf("\n available = ");
	for(int j=0;j<res;j++)
		printf("%d ",available[j]);	
	
	for(int j=0;j<res;j++){
	 if(P[i].req[j]>available[j]){
	 	return 0;}}
	 
	return 1;}
		
		
void display(int n){
    printf("\n max ");
    for(int i=0;i<res;i++){
    printf(" %d ",max[i]);}
    
    printf("\n available ");
    for(int i=0;i<res;i++){
    printf(" %d ",available[i]);}

    printf("\nPno process-id  allocation  need ");
    
    for(int i=0;i<n;i++){
    	printf("\n %d   %d",i,P[i].pid);
    	
    	printf("\t \t");
    	for(int j=0;j<res;j++){
    	  printf("%d ",P[i].allocation[j]);}
    	
    	printf("\t ");
    	for(int j=0;j<res;j++){
    	  printf("%d ",P[i].need[j]);}}}

void resource_request(int i,int n){
	if (req_lt_need(i,n)){
		if(req_lt_available(i,n)){./fcfs.c
		for(int j=0;j<res;j++)
			{available[j] -= P[i].req[j];
			 P[i].allocation[j] += P[i].req[j];
			 P[i].need[j] -= P[i].req[j];}
	        printf("\n Allocation succesful");
		printf("\n max ");
    		for(int i=0;i<res;i++){
    		printf(" %d ",max[i]);}
    
   		printf("\n available ");
    		for(int i=0;i<res;i++){
    		printf(" %d ",available[i]);}
    		
    		printf("\n allocation ");
    		for(int j=0;j<res;j++){
    		printf(" %d ",P[i].allocation[j]);}
    		
    		printf("\n need ");
    		for(int j=0;j<res;j++){
    		printf(" %d ",P[i].need[j]);}
    		}
	        else printf("\n Not possible.Req<available");
	        return ;}
        printf("\n Error request > need");}

void main(){
	int n;int safe_seq[15];
	srand(time(0));
	res = rand()%4 + 1;
	n = rand()%10 + 1;
    	for(int i=0;i<res;i++){
    		 max[i] = rand()%10 + 5;
		 available[i] = rand()%10+1;
		 work[i] = available[i];}
	for(int i =0;i<n;i++){
		P[i].pid = rand()%10 + 1;
		for(int j=0;j<res;j++)
		{P[i].allocation[j]= rand()%max[j] + 1;}
		P[i].finish = 0;}
	
	for(int i=0;i<n;i++){
    		for(int  j=0;j<res;j++){
    		P[i].need[j]=abs(max[j] - P[i].allocation[j]);}}
 	display(n);
 	int j=0;
    	while(!Flag(n)){
    	int flag =0;
    	for(int i=0;i<n;i++)
      		{ if((P[i].finish == 0) && (need_lt_work(i,n)))
         	{ 	printf("\n Process %d ;",i);
         		work_allocation(i,n);
           		P[i].finish = 1;
           		safe_seq[j] = i;
           		j++;
           		flag = 1;}}
      	if(flag==0) break;}
      
      
      	
      
        if(Flag(n))
  	    { printf("\n Safe sequence <");
        	for(int i =0;i<n;i++)
        	printf("P%d ",safe_seq[i]);
        	printf("> \n");
       	 	int i = rand()%res;
        	printf("\n resource request pid:%d request value:",i);
        	for(int j=0;j<res;j++){
        	P[i].req[j]=rand()%(P[i].need[j]+1) +1;
        	printf(" %d", P[i].req[j]);}
        
        resource_request(i,n);}
        else
        printf("\n safe sequence doesnt exist");} 

