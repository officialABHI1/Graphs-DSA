#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main(){
  
    ll n,a,b,maxm = INT_MIN;
    cin>>n;
    
   vector<vector<ll>> adjM(n+1, vector<ll>(n+1, 0));
    
    for(int i=0;i<n;i++){
      cin>>a>>b;
      
      maxm = max(maxm,max(a,b));
      
      adjM[a][b]=1;
      
      adjM[b][a]=1;
      
    }
    
    cout<<maxm<<endl;
    
    for(int i=0;i<adjM.size();i++){
      
      for(int j=0;j<adjM[i].size();j++){
        cout<<adjM[i][j]<<" ";
      }
      cout<<endl;
    }
    
}
