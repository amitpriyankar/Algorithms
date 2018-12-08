#include <bits/stdc++.h>
using namespace std;
int const N=2*1e5+9;
vector<int> adj[N];
vector<vector<int>> cycles;
vector<int > visited(N,0);
vector<int> path;
void dfs(int v)
{
    path.push_back(v);
    visited[v]=1;
    int to=adj[v][0];
    if(visited[to]!=2)
    {
        if(visited[to]==1)
        {
            cycles.emplace_back();
            int id=path.size()-1;
            while(path[id]!=to)
                cycles.back().push_back(path[id--]);
        cycles.back().push_back(to);
        }
        else 
            dfs(to);
    
        
    }
    path.pop_back();
    visited[v]=2;
}
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0; i<n ;i++)cin>>arr[i+1];
    int aa;
    visited.resize(n+1);
    for(int i=0; i<n ;i++)
    {
        cin>>aa;
        adj[i+1].push_back(aa);
    }
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])dfs(i);
    }
    int ans=0;
    for(auto &it: cycles)
    {
        int x=arr[it[0]];
        for(int u: it)
        {
          
            x=min(x,arr[u]);
        }
        ans+=x;
       
    }
    cout<<ans<<endl;
    
 
   /* vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    for (row = cycles.begin(); row != cycles.end(); row++) {
       int   x=arr[*row->begin()];
    for (col = row->begin(); col != row->end(); col++) {
        // do stuff ...
      
        x=min(x,arr[*col]);
    }
    ans+=x;
   
}

cout<<ans<<endl;
*/
    
}