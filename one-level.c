#include<stdio.h>
#include<string.h>



struct tree { 
  char Filename[20]; 
   struct tree *child[5];   
}; 
int main()
{
	char command[40];
	char cmd[20],param[20];
	scanf("%s",cmd);
	scanf("%s",param);
	if((strcmp(cmd,"gedit")) || (strcmp(cmd,"touch")))
		printf("%s %s",cmd,param);
	else if(strcmp(cmd,"rm"))
	 	printf("%s:command not found",cmd);
	else if(strcmp(cmd,"ls"))
		printf("%s:command not found",cmd);
	else
	printf("%s:command not found",cmd);
	 
	
	
	
} 
