#include <bits/stdc++.h>
using namespace std;

bool cycleCheck(int src, vector<vector<int>>& adjL, vector<int> &vis, vector<int> &pathVis){
   
   // mark the src in both vis & pathVis vector
   
    vis[src] = 1;
    pathVis[src]=1;
    
    for(auto it : adjL[src]){
       
       if(!vis[it]){  //
           
           if(cycleCheck(it, adjL, vis, pathVis)){
             return true;
           }
       }
       else if(pathVis[it]){ 
            return true;
       }
    }
    
    pathVis[src] =0;
    return false;
    
}

bool hasCycle(vector<vector<int>> &adjL, int v){
  
  vector<int>vis(v+1,0);
  vector<int>pathVis(v+1,0);
  
  for(int i =1;i<=v;i++){
      
      if(!vis[i]){
          if(cycleCheck(i,adjL,vis, pathVis)){
               return true;
          }
      }
  }
  return false;
}

int main(){
  
   int v,e,a,b;
   cin>>v>>e;
   
   // adjacency list declaration
   
   vector<vector<int>>adjL(v+1);
   
   for(int i=0;i<e;i++){
     cin>>a>>b;
     
     adjL[a].push_back(b);
   }
   
    //debugging the adjacency list
   
  // for(int i=1;i<adjL.size();i++){
       
  //     cout<<i<<" ";
       
  //     for(auto nodes:adjL[i]){
  //       cout<<nodes<<" ";
  //     }
  //     cout<<endl;
  // }
  
  if(hasCycle(adjL,v)){
    cout<<" It has a Cycle"<<endl;
  }
  else{
    cout<<" Not has a cycle"<<endl;
  }
  
}
