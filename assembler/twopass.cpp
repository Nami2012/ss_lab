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
   string hexLOCCTR,LABEL,opcode,operand;
   fin.open("intermediate.txt");
   fin>>hexLOCCTR>>LABEL>>opcode>>operand;
   cout<<hexLOCCTR<<LABEL<<opcode<<operand;
   
 }

