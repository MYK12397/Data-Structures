#include<iostream>
#include<iomanip>
using namespace std;
#define INF 99999
#define v 4
void printsol(int dist[][v]);

void floydWarshall(int graph[][v])
{
	int dist[v][v],i,j,k;

		for(i=0;i<v;i++)
			for(j=0;j<v;j++)
				dist[i][j]=graph[i][j];
				
		for(k=0;k<v;k++){
			for(i=0;i<v;i++){
				for(j=0;j<v;j++){
					if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
		
	printsol(dist);
}
void printsol(int dist[][v]){
	cout<<"The following matrix shows the shortest distances between"
			"every pair of vertices\n";
			
			for(int i=0;i<v;i++){
				for(int j=0;j<v;j++){
					if(dist[i][j]==INF)
					cout<<setw(6)<<" INF";
					else 
					cout<<setw(6)<<dist[i][j];
				}
				cout<<"\n";
			}
}
int main()
{
	int graph[v][v] = {  {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF,0}  
                    };  
                    
    floydWarshall(graph);
    return 0;
}
