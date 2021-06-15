#include<iostream>
using namespace std;

int row,col;
int img[100][100];
bool Valid(int r,int c){
  return r>=0 &&r<row && c>=0 && c<col;
}


void fill(int r,int c,int origColor,int newColor){
  if(!Valid(r,c))return;

  if(img[r][c]!=origColor)return;

  img[r][c]=newColor;

  if(img[r][c]==-1)return;

  img[r][c]=-1;
  fill(r,c+1,origColor,newColor);
  fill(r,c-1,origColor,newColor);
  fill(r-1,c,origColor,newColor);
  fill(r+1,c,origColor,newColor);
  img[r][c]=newColor;

}

void floodfill(int r,int c,int p){
  int origColor=img[r][c];
  fill(r,c,origColor,p);
}

//tc 
/*
1 0 1 1 0
0 1 0 1 0
1 1 1 1 1
0 0 1 0 1
1 0 0 0 0
*/



int main()
{
row=5, col=5;
for(int i=0;i<row;i++){
	for(int j=0;j<col;j++){
	cin>>img[i][j];
	}
}

int p=5;
floodfill(2,2,p);

for(int i=0;i<row;i++){
	for(int j=0;j<col;j++){
	cout<<img[i][j]<<" ";
	}

	cout<<"\n";
}

return 0;
}
