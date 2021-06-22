#include<iostream>
#include<cstdlib>
using namespace std;

struct data{
	int key;
	int value;
};
struct data *arr;
int capacity=10;
int size=0;
int hashcode(int key)
{
	return(key%capacity);
}
int ifprime(int n)
{
	int i;
	if(n==1||n==0)
	{
		return 0;
	}
	for(i=2;i<n;++i)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}
int getprime(int n)
{
	if(n%2==0){
		n++;
	}
	for(;ifprime(n);n+=2)
	return n;
}

void initarr()
{
	int i;
	capacity=getprime(capacity);
	arr=new data[capacity];
	for(i=0;i<capacity;++i)
	{
		arr[i].key=0;
		arr[i].value=0;
	}
	
}
void insert(int key)
{
	int index=hashcode(key);
	if(arr[index].value==0)
	{
		arr[index].key=key;
		arr[index].value=1;
		size++;
		cout<<"key "<<key<<" has been inserted \n";
		
	}
	else if(arr[index].key==key)
	{
		cout<<"key "<<key<<" already presented, hence updating its value \n";
		arr[index].value+=1;
	}
	else
	{
		cout<<"\nELEMENT CANNOT BE INSERTED\n";
	}
}
void remove(int key)
{
	int index=hashcode(key);
	if(arr[index].value==0)
	{
		cout<<"Key doesn't exist\n";
	}
	else
	{
		arr[index].key=0;
		arr[index].value=0;
		size--;
		cout<<"key has been removed ";
	}
}
void display()
{
	int i;
	for(i=0;i<capacity;++i)
	{
		if(arr[i].value==0)
		cout<<"\narray[<<"<<i<<"] has no elements\n";
		else
		cout<<"\narray["<<i<<"] has elements-: key( "<<arr[i].key<<") and value value( "<<arr[i].value<<")";
	}
}
int sizeofhashtable()
{
	return size;
}
int main()
{
	int choice, key, value, n, c;
	
 
	initarr();
 
	do {
		cout<<"\n Implementation of Hash Table in C++\n\n";
		cout<<"MENU-:  \n1.Inserting item in the Hash Table" 
                        "\n2.Removing item from the Hash Table"
		               "\n3.Check the size of Hash Table" 
                        "\n4.Display a Hash Table"
		       "\n\n Please enter your choice -:";
 
		cin>>choice;
 
		switch(choice) 
                {
 
		case 1:
 
		      cout<<"Inserting element in Hash Table\n";
		      cout<<"Enter key -:\t";
		      cin>>key;
		      insert(key);
 
		      break;
 
		case 2:
 
		      cout<<"Deleting in Hash Table \n Enter the key to delete-:";
		      cin>>key;
		      remove(key);
 
		      break;
 
		case 3:
 
		      n = sizeofhashtable();
		      cout<<"Size of Hash Table is-:\n"<<n;
		      break;
 
		case 4:
 
		      display();
 
		      break;
 
		default:
 
		       cout<<"Wrong Input\n";
 
		}
 
		cout<<"\n Do you want to continue-:(press 1 for yes)\t";
		cin>>c;
 
	}while(c == 1);
 

 
}

