#include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
using namespace std;
struct avl_node
{
	int data;
	struct avl_node *left;
	struct avl_node *right;
}*root=NULL;


int height(avl_node *temp)
{
	int h=0;
	if(temp!=NULL)
	{
		int l_height=height(temp->left);
		int r_height=height(temp->right);
		int m_height=max(l_height,r_height);
		h=m_height+1;
	}
	return h;
}
int diff(avl_node*temp)
{
	int l_height=height(temp->left);
	int r_height=height(temp->right);
	int b_factor=l_height-r_height;
	return b_factor;
}
struct avl_node*  rr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp=parent->right;
	parent->right=temp->left;
	temp->left=parent;
	cout<<"RR Rotation";
	return temp;
}
struct avl_node* ll_rotation(avl_node *parent)
{
	avl_node *temp;
	temp=parent->left;
	parent->left=temp->right;
	temp->right=parent;
	cout<<"LL Rotation ";
	return temp;
}
struct avl_node* lr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp=parent->left;
	parent->left=rr_rotation(temp);
	
	cout<<"LR Rotation";
	return ll_rotation(parent);
}
struct avl_node* rl_rotation(avl_node *parent)
{
	avl_node *temp;
	temp=parent->right;
	parent->right=ll_rotation(temp);
	cout<<"RL Rotation ";
	return rr_rotation(parent);
}
struct avl_node* balance(avl_node *temp)
{
	int bal_factor=diff(temp);
	if(bal_factor>1)
{
	if(diff(temp->left)>0)
	{
		temp=ll_rotation(temp);
	}
	else
	{
		temp=lr_rotation(temp);
	}
}
else if(bal_factor<-1)
{
	if(diff(temp->right)>0)
	{
		temp=rl_rotation(temp);
	}
	else
	{
		temp=rr_rotation(temp);
	}
}
return temp;
}
struct avl_node* insert(avl_node *root,int value)
{
	if(root==NULL)
	{
		root =new avl_node;
		root->data=value;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(value<root->data)
	{
		root->left=insert(root->left, value);
		root=balance(root);
	}
	else if(value>=root->data)
	{
		root->right=insert(root->right,value);
		root=balance(root);
	}
	return root;
}
void display(avl_node *ptr,int level)
{
	int i;
	if(ptr!=NULL)
	{
		display(ptr->right,level+1);
		cout<<"\n";
		if(ptr==root)
			cout<<"Root->";
		
		for(i=0;i<level&& ptr!=root; i++)
			cout<<"      ";
		cout<<ptr->data;
		display(ptr->left,level + 1);
	}
}
void preOrder(avl_node*tree)
{
	if(tree==NULL)
	{
		return;
	}

	cout<<tree->data<<" ";
	preOrder(tree->left);
	preOrder(tree->right);

}
void postOrder(avl_node* tree)
{
	if(tree==NULL)
	{	return;}
	
	postOrder(tree->left);
	postOrder(tree->right);
	cout<<tree->data<<" ";
	
}
void inOrder(avl_node* tree)
{
	if(tree==NULL)
		return;

inOrder(tree->left);
cout<<tree->data<<"  ";
inOrder(tree->right);
}

int menu()
{
	int ch;
	cout<<"\n\t AVL TREE\n";
	cout<<"\n1.Insertion \n";
	cout<<"\n2.Display \n";
	cout<<"\n3.PreOrder Traversal\n";
	cout<<"\n4.PostOrder Traversal\n";
	cout<<"\n5.InOrder Traversal \n";
	cout<<"Enter your choice\n";
	cin>>ch;
	return ch;
}
int main()
{int item;
	while(1)
	{
		switch(menu())
		{
			case 1: cout<<"Enter value to be inserted ";
					cin>>item;
					root=insert(root,item);
					break;
			case 2:
					cout<<"Balance AVL Tree"<<endl;
					display(root,1);
					break;
			case 3:	cout<<"PreOrder Traversal "<<endl;
					preOrder(root);
					break;
			case 4:	cout<<"PostOrder Traversal "<<endl;
					postOrder(root);
					break;
			case 5:	cout<<"InOrder Traversal "<<endl;
					inOrder(root);
					break;
			default:
					cout<<"Wrong choice"<<endl; 
					exit(0);
		}
	}
	return 0;
}
