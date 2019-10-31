#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map> 
using namespace std;
void int_to_hex(int n)
    {
        
        vector<char> hex_value;
        map<int, int> SYMTAB; 
        while(n!=0)
        {   int temp = 0;
            temp = n%16;
            if(temp<10)
            {
                hex_value.push_back((char)temp+48);
                cout<<(char)temp+48<<endl;
            }
            else
            {
                hex_value.push_back((char)temp+55);
                cout<<(char)temp+55<<endl;
            }
            n=n/16;
        }
        for(int j=hex_value.size()-1;j>=0;j--)
            cout<<hex_value[j];
        //return reverse(hex_value.begin(),hex_value.end());
    }
int main()
{ 
    int LOCCTR=0000;
	FILE *fptr;
    ofstream fout;
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
	 	cout<<line; 
       		
        }  
    	fclose(fptr);
        return 0;
} 