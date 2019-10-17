#include<stdio.h>
#include<string.h>
void main()
{

	FILE *fptr;
	fptr = fopen("input.txt", "r"); 
	char line[50];
	/*char c = fgetc(fptr); 
    	while (c != EOF) 
    	{ 
        	printf ("%c", c); 
       		c = fgetc(fptr); 
    	}*/
	fgets(line,50,fptr);
	 while(fgets(line,50,fptr)!= NULL) 
	{
	 	printf ("%s", line); 
       		
        }  
    	fclose(fptr);
} 
