#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int cnt = 0,m,n,j,k;
const int mx = 30;
char c[mx][mx];

int dx[] = {-1,+1,0,0};
int dy[] = {0,0,-1,+1};

bool vis[mx][mx];

void dfs(int x,int y)
{
    vis[x][y] = 1;
    cnt++;

    for(int i=0;i<4;i++)
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if(x1>=0 && x1<n && y1>=0 && y1<m && !vis[x1][y1] && c[x1][y1]!= '#')
        {
            dfs(x1,y1);
        } 
    }
}
int main()
{
    optimize();
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        memset(vis,0,sizeof(vis));
        cnt = 0;

        int x,y;

        cin>>m>>n;
        for(j=0;j<n;j++)
            for(k=0;k<m;k++)
            {
                cin>>c[j][k];
                if(c[j][k]=='@')
                x = j, y = k;
            }
        
        dfs(x,y);

        cout<<"Case "<<i<<": "<<cnt<<endl;
    }
    return 0;
}
