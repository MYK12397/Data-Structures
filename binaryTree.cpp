#include<iostream>
#include<cstdlib>
using namespace std;
struct BSTNode
{
	int info;
	struct BSTNode *left, *right;	
}*root;
BSTNode* FindMax(BSTNode* root)
{
	while(root->right!=NULL)
	root=root->right;
	return root;
}
void preOrder(struct BSTNode *root)
{
if(root)
{
	cout<<root->info<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
}

void insert(struct BSTNode *root,struct BSTNode *data)
{
	struct BSTNode *par;
	struct BSTNode *n;
	n= new struct BSTNode;
	n->left=NULL;
	n->info=data->info;
	n->right=NULL;
	if(root=NULL)
	root=n;
	else
	{
		par=root;
		while(par!=NULL)
		{
			if(par->info>data->info)
			{
				if(par->left==NULL)
					par->left=n;
				else
					par=par->left;
			}
			if(par->info<data->info)
			{
				if(par->right==NULL)
				par->right=n;
				par=par->right;
			}
		}
	}
}
BSTNode* Delete(struct BSTNode *root,int data)
{
	struct BSTNode *temp;
	if(root=NULL)
	cout<<"No such Element Exist";
	else if(data<root->info)
	root->left=Delete(root->left,data);
	else if(data>root->info)
	root->right=Delete(root->right,data); 
else
{
	if(root->left &&root->right){
		temp=FindMax(root->left);
		root->info=temp->info;
		root->left=Delete(root->left,data);
	}
	else
	{
		temp=root;
		if(root->left=NULL)
		root=root->left;
		if(root->right=NULL)
		root=root->right;
	delete temp;
	}
}
return(root);
}
void Display(struct BSTNode *ptr,int level)
{
	int i;
	if(ptr!=NULL)
	{
		Display(ptr->right,level+1);
		cout<<endl;
		if(ptr==root)
		cout<<"Root-> ";
		else
		{
			for(i=0;i<level;++i)
			cout<<"    ";
		}
		cout<<(ptr->info);
		Display(ptr->left,level+1);
		
	}
}
int main()
{
	int ch,num;
	BSTNode *temp;
	while(1){
	
	cout<<"\n1.Insert node ";
	cout<<"\n2.Delete node ";
	cout<<"\n3.Display tree";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	
	
		switch(ch)
		{
			case 1: temp=new BSTNode;
				cout<<"Enter node to be inserted: ";
				cin>>temp->info;
				insert(root,temp);
			break;
			case 2:
				if(root=NULL)
			{	cout<<"\nTree is Empty !Nothing can be Deleted";
				continue;
			}
				cout<<"\nEnter the number to be deleted";
				cin>>num;
				Delete(root,num);
				break;
			case 3: cout<<"\nDispay BST: \n";
					Display(root,1);
					break;
			default:
			cout<<"\nInvalid choice";
			exit(0);	
		}
	}
}
