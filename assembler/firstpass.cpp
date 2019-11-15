#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map> 
#include<bits/stdc++.h>
#include<cmath>
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

int hex_to_int(int n)
		{ 	int i=0,temp,hex=0;
			while(n!=0)
			{ temp = n%10;
			  hex += temp*pow(16,i++);
			  n = n/10;
			}
		    return hex;
		  }

int verify_opcode(string opcode,int &LOCCTR,string operand)
    {  
       fstream file;
       string word;
       file.open("opcode.txt");
       while(file>>word)
        	{
        	if(word.compare(opcode)==0)
            	  {if(opcode[0]=='+') 
            	  		LOCCTR +=4;
            	   else if(opcode[opcode.size()-1] =='R')
            	   		LOCCTR +=2;
            	   else
            	   		LOCCTR += 3;return 1;}
            	  }               
       if((opcode.compare("START")==0) || (opcode.compare("END")==0))
       					{LOCCTR +=0;return 1;}
       		else if(opcode.compare("WORD")==0)
						{LOCCTR += 3;return 1;}
        	else if(opcode.compare("RESW")==0)
						{LOCCTR += 3*stoi(operand);return 1;}
	   		else if(opcode.compare("RESB")==0)
						{LOCCTR += stoi(operand);return 1;}
	   		else if(opcode.compare("BYTE")==0)
						{{ if (operand[0] == 'X') 
								LOCCTR++;
							else
						  		LOCCTR += operand.size()-3;
							}
						return 1;}
       else
       		return -1;
    }
    

int main()
	{   map<string,string > SYMTAB; 
    	int LOCCTR=0000;
		FILE *fptr;
		ifstream fin;
		ofstream fout,fim;
		fim.open("intermediate.txt");
		int mneumonic;
    	string opcode,LABEL,operand;
		fin.open("sic.txt");
	
		fin>>LABEL>>opcode>>operand;
		LOCCTR=hex_to_int(stoi(operand));
		
		while(opcode.compare("END")!=0)
		{
			     mneumonic = verify_opcode(opcode,LOCCTR,operand);
    	         string hexLOCCTR = int_to_hex(LOCCTR);
    			 if((LABEL.size() != 0)&& (LABEL.compare("-")!=0))
    	   	     	  SYMTAB.insert({LABEL,hexLOCCTR});
				 if(LABEL.size()==0)
   		   		 	  fim<<hexLOCCTR<<" "<<"-"<<" "<<opcode<<" "<<operand;
   		     	 else
   		   			  fim<<hexLOCCTR<<" "<<LABEL<<" "<<opcode<<" "<<operand;
   		     	 fim<<endl;
    	         fin>>LABEL>>opcode>>operand;
	   	}
	
        fout.open("symtab.txt"); 
	 
        for(map<string, string >::iterator i=SYMTAB.begin(); i!=SYMTAB.end(); i++)
         {
           fout<<i->first<<" "<<i->second<<endl;}
           fin.close();
    	fout.close();
        return 0;

	} 
