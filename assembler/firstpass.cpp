#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map> 
#include<bits/stdc++.h>
using namespace std;
vector<char> int_to_hex(int n)
    {   vector<char> hex_value;
        if(n==0) {hex_value.push_back('0');return hex_value;}
        while(n!=0)
        {   
            int temp = 0;
            temp = n%16;
            if(temp<10)
            {
                hex_value.push_back((char)(temp+48)); 
            }
            else
            {
                hex_value.push_back((char)(temp+55));
            }
            n=n/16;
        }
        reverse(hex_value.begin(),hex_value.end());
        return hex_value; 
         }


int verify_opcode(string opcode)
    {  
       fstream file;
       string word;
       file.open("opcode.txt");
       while(file>>word)
        {  if(word.compare(opcode)==0)
              {return 1;}}               
       if((opcode.compare("START")==0) || (opcode.compare("END")==0))
       			return 2;
        if(opcode.compare("WORD")==0)
				return 3;
       return -1;
    }
    
int update(int mneumonic,int &LOCCTR)
	{
		if(mneumonic == 1)
			LOCCTR += 3;
		if (mneumonic ==3)
			LOCCTR +=3;}

int main()
{   map<string,vector<char> > SYMTAB; 
    int LOCCTR=0000;
	FILE *fptr;
	ofstream fout,fim;
	fim.open("intermediate.txt");
	int mneumonic;
    string opcode,LABEL,operand;
	fptr = fopen("input.txt", "r"); 
	
	char line[50];
	 while(fgets(line,50,fptr)!= NULL) 
	  {    int j = 0 , i=0;
        opcode.clear();
        LABEL.clear();
        operand.clear();
	    while(line[i]!='-' && line[i]!=' ')
           { LABEL.push_back(line[i++]);
           }
        while(line[++i] == ' ');
		while(line[i]!=' ')
           { opcode.push_back(line[i++]);
           }
        while(line[++i] == ' ');
        while(line[i]!='\n')
           { operand.push_back(line[i++]);
           }
       mneumonic = verify_opcode(opcode);
       vector<char> hexLOCCTR = int_to_hex(LOCCTR);
      
       if(mneumonic!=-1)
       		update(mneumonic,LOCCTR);
       if(LABEL.size() != 0)
       		SYMTAB.insert({LABEL,hexLOCCTR});
   	   if(LABEL.size()==0)
   	   fim<<LOCCTR<<" "<<"-"<<" "<<opcode<<" "<<operand;
   	   else
   	   fim<<LOCCTR<<" "<<LABEL<<" "<<opcode<<" "<<operand;
   	   fim<<endl;
        }
       fout.open("symtab.txt"); 
	 
       for(map<string, vector<char> >::iterator i=SYMTAB.begin(); i!=SYMTAB.end(); i++)
       {
        fout<<i->first<<" ";
        for(int j=0;j<i->second.size();j++)
        { fout<<i->second[j];}
        fout<<endl;
        }  
    	fclose(fptr);
    	fout.close();
        return 0;

} 
