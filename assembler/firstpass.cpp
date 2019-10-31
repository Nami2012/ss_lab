#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map> 
#include<bits/stdc++.h>
using namespace std;
void int_to_hex(int n)
    {
        
        vector<char> hex_value;
        
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


int verify_opcode(vector<char> opcode)
    {
       fstream file;
       string word;
       string op(opcode.begin(),opcode.end());
       file.open("opcode.txt");
       while(file>>word)
        {  
            if(word.compare(op)==0)
               return 1;

        }
       return -1;
    }
        
int verify_SYMTAB(vector<char> LABEL,map<int, int> SYMTAB)
    {
        if(SYMTAB.find(LABEL)!=SYMTAB.end())
            return 1;
        else
        {
        }
        
    }
int main()
{   map<vector<char>, int> SYMTAB; 
    int LOCCTR=0000;
	FILE *fptr;
    vector<char> opcode,LABEL;
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
	{    int j = 0 , i=0;
        opcode.clear();
        LABEL.clear();
	
        while(line[i]!=' ' && line[i]!='\n')
           { opcode.push_back(line[i++]);
           }
        if(verify_opcode(opcode))
            {while(line[i]!='\n')
                LABEL.push_back(line[++i]);
                //verify_SYMTAB(LABEL,SYMTAB);
                }
        for(int i=0;i<opcode.size();i++)
            cout<<opcode[i];
        
        //cout<<LABEL; 		
        }  
    	fclose(fptr);
        return 0;
} 