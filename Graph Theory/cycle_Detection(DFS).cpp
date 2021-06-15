#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> adj[N];
vector<bool> vis(N,false);
int v=4;


bool is_Cycle(int node,int parent){
  vis[node]=1;
  for(auto nbr: adj[node]){
    if(!vis[nbr]){
      bool got_cycle=is_Cycle(nbr,node);
    if(got_cycle)
      return true;
    }
    else if(nbr!=parent)
    return true;


  }

  return false;
}
bool containsCycle(){
 

  return is_Cycle(1,-1);

}

int main(){
	vis.resize(v);



  for(int i=0;i<v;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  if(containsCycle()){
    cout<<"Cycle";
  }
  else
  cout<<"No Cycle";



return 0;
}