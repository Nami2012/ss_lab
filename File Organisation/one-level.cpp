#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std; 

struct tree { 
  char Filename[20]; 
   vector<tree *> child;   
}; 

tree *newNode(char const *name)
	{	tree *temp = new tree;
		strcpy(temp->Filename,name);
		return temp; 
	}
void remove(struct tree *root,char const *param)
	{	int pos=-1;
		for(int i=0;i<(root->child).size();i++)
			{
				if(!strcmp(root->child[i]->Filename,param))
					{ pos=i;
					  root->child.erase(root->child.begin()+i);
					  break;}
			}
		if(pos==-1)
			cout<<"File Does Not Exist";	
		
	}
void display(struct tree *root)
	{	cout<<root->Filename<<endl;
		for(int i=0;i<(root->child).size();i++)
			{
			   cout<< root->child[i]->Filename <<"\t";}
		cout<<endl;
	}
int main()
{	tree *root = newNode("ROOT");
//(root->child).push_back(newNode("File 1"));
	//(root->child).push_back(newNode("File 2"));
	cout<<"user@user-260-p022il:$";
	char command[40];
	char cmd[20],param[20];
	cin>>cmd;
	int flag=0;
	char meh="user@user-260-p022il:$"
	while(strcmp(cmd,"exit"))
	{
		if(!strcmp(cmd,"ls"))
	    		display(root);
		else
	    		{	cin>>param;	
				
				if(!(strcmp(cmd,"gedit")) ||(!(strcmp(cmd,"touch"))))
					(root->child).push_back(newNode(param));
				else if(!strcmp(cmd,"rm"))
					remove(root,param);
				/*else if(!strcmp(cmd,"cd"))
					if(!strcmp(param,root->Filename)
						{ strcat(meh,root->Filename);
						  flag=1;
				*/		}
					
					    

				else
					cout<<"Command Not found";
	    		}
	cout<<"user@user-260-p022il:$";	
	cin>>cmd;
	}
	exit(0);

	
} 
