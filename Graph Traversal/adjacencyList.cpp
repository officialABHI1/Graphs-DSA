#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
  
    ll n,v,a,b,maxm = INT_MIN;  // n = no of edges && v = no of vertex
    
    cin>>n>>v;
    
      vector<ll> adjL[v+1];
      
      for(int i=0;i<n;i++){
        cin>>a>>b;
        
        maxm = max(maxm,max(a,b));
        
        adjL[a].push_back(b);
        
        adjL[b].push_back(a);
        
      }
    
      cout<<maxm<<endl; // to identify the size we would need to declare for the visited array for BFS/DFS.
    
      for(int i=1;i<=v;i++){
        cout<<i<< " --> ";
        
        for(auto niegh: adjL[i]){
          cout<<niegh<<" ";
        }
        cout<<endl;
      }
  
}
