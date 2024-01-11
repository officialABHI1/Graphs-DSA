#include<bits/stdc++.h>
using namespace std;

void  breadthFirstSearch( vector<vector<int>>&adjList, int src, int nodes){
  
  int visited[nodes+1]={0};
  
  queue<int>q;
  
  cout<<src<<" ";
  q.push(src);
  visited[src]=1;
  
  while(!q.empty()){
   
    int curr_node = q.front(); // extract the current node which we need to explore
    
    q.pop(); // remove that node from the queue
    
    for(auto nieghbour:adjList[curr_node]){
      
      if(visited[nieghbour])
      {
        continue;
      }
      
      cout<<nieghbour<<" ";
      visited[nieghbour]=1;
      q.push(nieghbour);
    }
  }

}

int main(){
  
  int nodes, edges, a, b,src;
  cin>>nodes>>edges;
  
  vector<vector<int>>adjList(nodes+1);
  
  for(int i=0;i<edges;i++){
    cin>>a>>b;
    
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    
  }
  
  cin>>src;
  
  /* Ajacency List Traversal 
  for(auto x: adjList){
    for(auto nieghbour:x){
      cout<<nieghbour<<" ";
    }
    cout<<endl;
  }
  */
  
  breadthFirstSearch(adjList,src,nodes);

}
