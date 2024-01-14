#include<bits/stdc++.h>
using namespace std;
/*
void  breadthFirstSearch( vector<set<int>>&adjList, int src, int nodes){
  
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
  
  cout<<endl;

} */

void  breadthFirstSearch( vector<set<int>>&adjList, int nodes){
  
  int visited[nodes+1]={0};
  
  queue<int>q;
  
  for(int src=1; src<=nodes; src++){
    if(visited[src]==0){
      cout<<src<<" ";
      q.push(src);
      visited[src]=1;
      
      while(!q.empty()){
       
        int curr_node = q.front(); // extract the current node which we need to explore
        
        q.pop(); // remove that node from the queue
        
        for(auto neighbour:adjList[curr_node]){
          
          if(visited[neighbour])
          {
            continue;
          }
          
          cout<<neighbour<<" ";
          visited[neighbour]=1;
          q.push(neighbour);
        }
      }
    }
  }
  
  cout<<endl;

}


int main(){
  
  int t;
  cin>>t;
  while(t--){
    
    int n;
    cin>>n;
    
    int arr[n+1];
    
    for(int i=1;i<=n;i++){
      cin>>arr[i];
    }
  
    int nodes, edges, a, b,src;
    
    nodes = n+1;
    
    vector<set<int>>adjList(nodes+1);
    
    for(int i=1;i<=n;i++){
     // cin>>a>>b;
      
      adjList[i].insert(i+1);
      //adjList[b].insert(a);
    }
    
    for(int i=1;i<=n;i++){
      
      if(arr[i]==0)
      adjList[i].insert(nodes);
      else
      adjList[nodes].insert(i);
    }
    
   // cin>>src;
    
   /* Ajacency List Traversal 
    for(auto x: adjList){
      for(auto nieghbour:x){
        cout<<nieghbour<<" ";
      }
      cout<<endl;
    } */
   
     breadthFirstSearch(adjList,nodes);
  
  }

}
