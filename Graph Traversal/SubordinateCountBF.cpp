/* Problem Link: https://cses.fi/problemset/task/1674/ */

// Brute force Approach

#include<bits/stdc++.h>
using namespace std;

//normal bfs function to print the count of subordinates
void subordinatCount(int src, vector<vector<int>>&adjList , int immediateSubordinate[]){
  
  int count =0; 
  
  queue<int>q;
  
  q.push(src);
  
  while(!q.empty()){
   
    int curr = q.front();
    q.pop();
    
    count += immediateSubordinate[curr];
    
    for(auto children:adjList[curr]){
      q.push(children);
    }
  }
  
  cout<<count<<" ";
  
}

int main()
{
  int n,x;
  cin>>n;
  
  int parents[n+1];
  int immediateSubordinate[n+1]={0};
  
  vector<vector<int>>adjList(n+1); // to store the children for each node
  
  for(int i=2;i<=n;i++){
    
    cin>>x;
    
    parents[i] = x;
    
    immediateSubordinate[x]++;
    
    adjList[x].push_back(i);

  }
  
  // we will call Subordinate count for each node to print the count
  
  for(int i=1;i<=n;i++){
    subordinatCount(i,adjList, immediateSubordinate);
  }
  cout<<endl;
  
}
