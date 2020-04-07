#include<iostream>
#include<cstdio>
#include<vector>
#include<iterator>
using namespace std;
class Heap{
	private:
		vector<int> heap;
		int left(int parent);
		int right(int parent);
		int parent(int child);
		void heapifyup(int index);
		void heapifydown(int index);
	public:
		Heap()
		{}
		void insert(int ele);
		void DeleteMin();
		int ExtractMin();
		void DisplayHeap();
		int size();
};
int Heap::size()
{
	return heap.size();
}
void Heap::insert(int ele)
{
	heap.push_back(ele);
	heapifyup(heap.size()-1);
}
void Heap::DeleteMin()
{
	if(heap.size()==0)
	{
		cout<<"Heap is empty"<<endl;
		return;
	}
	heap[0]=heap.at(heap.size()-1);
	heap.pop_back();
	heapifydown(0);
	cout<<"Element Deleted"<<endl;
}
int Heap::ExtractMin()
{
	if(heap.size()==0)
		return -1;
	else
		return heap.front();
}
void Heap::DisplayHeap()
{
	vector<int>::iterator pos=heap.begin();
	cout<<"Heap--> ";
	while(pos!=heap.end())
	{
		cout<<*pos<<" ";
		pos++;
	}
	cout<<endl;
}
int Heap::left(int parent)
{
	int l=2*parent+1;
	if(l<heap.size())
	return 1;
	else
	return -1;
	
}
int Heap::right(int parent)
{
	int r=2*parent+2;
	if(r<heap.size())
	return r;
	else
	return -1;
}
int Heap::parent(int child)
{
	int p =(child-1)/2;
	if(child==0)
	return -1;
	else
	return p;
}
void Heap:: heapifyup(int in)
{
	if(in>=0&& parent(in)>=0&&heap[parent(in)]>heap[in])
	{
		int temp=heap[in];
		heap[in]=heap[parent(in)];
		heap[parent(in)]=temp;
		heapifyup(parent(in));
	}
}
void Heap::heapifydown(int in)
{
	int child=left(in);
	int child1=right(in);
	if(child>=0&&child1>=0&&heap[child]>heap[child1])
	{
		child=child1;
	}
	if(child>0)
	{
		int temp=heap[in];
		heap[in]=heap[child];
		heap[child]=temp;
		heapifydown(child);
	}
	
}
int  main()
{
	Heap h;
	while(1)
	{
		cout<<"Operations on Heap "<<endl;
		cout<<"1.Insert Element "<<endl;
		cout<<"2.Delete Minimum Element "<<endl;
		cout<<"3.Extract Minimum Element "<<endl;
		cout<<"4.Print Heap "<<endl;
		cout<<"5.Exit "<<endl;
		int ch,elem;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the element to be inserted: ";
				cin>>elem;
				h.insert(elem);
				break;
			case 2:
				h.DeleteMin();
				break;
			case 3:
				cout<<"Minimum Element: ";
				if(h.ExtractMin()==-1)
				{
					cout<<"Heap is empty "<<endl;
				}
				else
				cout<<"Minimum Element: "<<h.ExtractMin()<<endl;
				break;
			case 4:
				cout<<"Displaying Elements of Heap: ";
				h.DisplayHeap();
				break;
			case 5:
				exit(1);
			default:
			cout<<"Enter correct Choice "<<endl;
		}
	}
	return 0;
}
