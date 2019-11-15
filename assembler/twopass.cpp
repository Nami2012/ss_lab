#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map> 
#include<bits/stdc++.h>
using namespace std;


int main()
{  ifstream fin;
   ofstream fout;
   string hexLOCCTR,LABEL,opcode,operand;
   fin.open("intermediate.txt");
   fout.open("objectcode.txt");
   fin>>hexLOCCTR>>LABEL>>opcode>>operand;
   
   fout<<"h^"<<LABEL<<"^"<<hexLOCCTR<<"^";
   
   
   cout<<hexLOCCTR<<LABEL<<opcode<<operand;
   
 }

