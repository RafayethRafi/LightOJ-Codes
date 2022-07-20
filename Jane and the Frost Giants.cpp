#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
const int inf = 2000000000;
const int mx = 212;
char c[mx][mx];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int lvlFire[mx][mx]  ,  lvlJane[mx][mx],n,m;
vector<pair<int,int>> s;


void bfsFire()
{
    memset(lvlFire,-1,sizeof(lvlFire));
    queue<pair<int,int>>q;
    for(auto u:s)
    {
        q.push(u);
        lvlFire[u.first][u.second] = 0;
    }

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x1 = x+ dx[i];
            int y1 = y+ dy[i];

            if(x1>=1 && x1<=n && y1>=1 && y1<=m && c[x1][y1]!= '#' && lvlFire[x1][y1] == -1)
            {
                lvlFire[x1][y1] = lvlFire[x][y]+1;
                q.push({x1,y1});
            }
        }
    }

}

void bfsJane(int xs,int ys)
{
    memset(lvlJane,-1,sizeof(lvlJane));
    queue<pair<int,int>>q;
    q.push({xs,ys});
    lvlJane[xs][ys] = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x1 = x+ dx[i];
            int y1 = y+ dy[i];

            if(x1>=1 && x1<=n && y1>=1 && y1<=m && c[x1][y1]!= '#' && lvlJane[x1][y1] == -1 && (lvlJane[x][y]+1)<lvlFire[x1][y1]) 
            {
                lvlJane[x1][y1] = lvlJane[x][y]+1;
                q.push({x1,y1});
            }
        }
    }

}

int main()
{
    optimize();
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n>>m;

        int x,y;
        s.clear();

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {cin>>c[i][j];

            if(c[i][j]=='J')
            {
                x = i;
                y = j;
            }
            else if(c[i][j]=='F')
            {
                s.push_back({i,j});
            }
            }
        }

        bfsFire();
        bfsJane(x,y);

        int ans = inf;

        for(int i=1;i<=n;i++)
        if(lvlJane[i][1]!=-1) ans = min(ans,lvlJane[i][1]);
        
        for(int i=1;i<=n;i++)
        if(lvlJane[i][m]!=-1) ans = min(ans,lvlJane[i][m]);

        for(int i=1;i<=m;i++)
        if(lvlJane[1][i]!=-1) ans = min(ans,lvlJane[1][i]);

        for(int i=1;i<=m;i++)
        if(lvlJane[n][i]!=-1) ans = min(ans,lvlJane[n][i]);

        if(ans == inf) cout<<"Case "<<tc<<": IMPOSSIBLE"<<endl;
        else cout<<"Case "<<tc<<": "<<ans+1<<endl;
    }
    
    return 0;
}
