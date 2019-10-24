#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std; 

struct tree { 
   char DirectoryName[20];
   char Filename[20]; 
   tree *parent;
   vector<tree *> child;   
}; 

tree *newFileNode(char const *name)
	{	tree *temp = new tree;
		strcpy(temp->Filename,name);
                return temp; 
	}

tree *newDirectoryNode(char const *name, struct tree *root = NULL)
	{	tree *temp = new tree;
		strcpy(temp->DirectoryName,name);
		temp->parent = root;
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
	{	cout<<root->DirectoryName<<endl;
		cout<<root->child.size();
		//for(int i=0;i<(root->child).size();i++)
			//{  cout<<root->child[i]->DirectoryName<<"\t";
			   //cout<< root->child[i]->Filename <<"\t";}
		cout<<endl;
		return;
	}
int DirectoryExists(struct tree *root,char const *param)
	{    int pos=-1;
             cout<<"Hey";
		for(int i=0;i<(root->child).size();i++)
			{
				if(!strcmp(root->child[i]->DirectoryName,param))
					{ pos=i;
					  break;}
			}
		cout<<pos;
		return pos;
		}

int main()
{	tree *root = newDirectoryNode("ROOT");
	int i;
	tree *cur_root=root;
        cout<<"user@user-260-p022il:$";
	char command[40];
	char cmd[20],param[20];
	cin>>cmd;
	int flag=0;
	char meh[]="user@user-260-p022il:$";
	while(strcmp(cmd,"exit"))
	{
		if(!strcmp(cmd,"ls"))
	    		display(cur_root);
		else
	    		{	cin>>param;	
				
				if(!(strcmp(cmd,"gedit")) ||(!(strcmp(cmd,"touch"))))
					(cur_root->child).push_back(newFileNode(param));
				if(!strcmp(cmd,"mkdir"))
					(cur_root->child).push_back(newDirectoryNode(param,cur_root));
				else if(!strcmp(cmd,"rm"))
					remove(cur_root,param);
				else if(!strcmp(cmd,"cd"))
					{
					if(i=DirectoryExists(cur_root,param) >=0)
						{ 
						  strcat(meh,param);
						 
						  flag=1;
						  cur_root = cur_root->child[i];
						}
					else if (!strcmp(param,"../"))
						{ //remove meh
						  flag=0;
						  cur_root=cur_root->parent;
						}	
					
					 }   

				else
					cout<<"Command Not found";
	    		}
	cout<<meh;	
	cin>>cmd;
	}
	exit(0);

	
} 
