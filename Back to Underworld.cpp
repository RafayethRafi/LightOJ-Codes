#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 2e4+123;
bool vis[mx];
vector<int>adj[mx];
bool isNode[mx];
int cnt,cnt1;

void dfs(int x,int col)
{
    vis[x] =1;
    if(col ==1) cnt1++;
    cnt++;

    int tmp;
    if(col==1) tmp = 2;
    else tmp=1;

    for(auto u:adj[x])
    if(vis[u]==0)
    dfs(u,tmp);
}
int main()
{
    optimize();
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int m,i;
        for(i=0;i<mx;i++)
        {
            adj[i].clear();
            isNode[i] = 0;
            vis[i] = 0;
        }
        
        cin>>m;
        for(i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
            isNode[u] = 1;
            isNode[v] = 1;
        }

        int ans= 0;
        for(i=1;i<=2e4;i++)
        {
            if(isNode[i]==1 && vis[i]==0)
            {
                cnt=0,cnt1=0;
                dfs(i,1);
                ans+= max(cnt1,(cnt-cnt1));
            }
        }

        cout<<"Case "<<k<<": "<<ans<<endl;

    }
    return 0;
}
