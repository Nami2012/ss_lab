#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map> 
#include<bits/stdc++.h>
using namespace std;
string int_to_hex(int n)
    {   string hex_value;
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
        if(opcode.compare("RESW")==0)
				return 4;
       return -1;
    }
    
int update(int mneumonic,int &LOCCTR,string operand)
	{
		if(mneumonic == 1)
			LOCCTR += 3;
		if (mneumonic ==3)
			LOCCTR +=3;
	    if (mneumonic == 4)
			LOCCTR += 3*stoi(operand);}

int main()
{   map<string,string > SYMTAB; 
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
       string hexLOCCTR = int_to_hex(LOCCTR);
      
       if(mneumonic!=-1)
       		update(mneumonic,LOCCTR,operand);
       if(LABEL.size() != 0)
       		SYMTAB.insert({LABEL,hexLOCCTR});
   	   if(LABEL.size()==0)
   	   fim<<hexLOCCTR<<" "<<"-"<<" "<<opcode<<" "<<operand;
   	   else
   	   fim<<hexLOCCTR<<" "<<LABEL<<" "<<opcode<<" "<<operand;
   	   fim<<endl;
        }
       fout.open("symtab.txt"); 
	 
       for(map<string, string >::iterator i=SYMTAB.begin(); i!=SYMTAB.end(); i++)
       {
        fout<<i->first<<" "<<i->second;}
        fclose(fptr);
    	fout.close();
        return 0;

} 
