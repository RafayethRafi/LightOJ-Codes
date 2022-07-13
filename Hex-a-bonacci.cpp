#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int a, b, c, d, e, f;
const long long int mx = 1000100;
long long dp[mx];

int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    if(dp[n]!=-1) return dp[n];
    
    return dp[n] = ((fn(n-1)% 10000007) + (fn(n-2)% 10000007 )+ (fn(n-3)% 10000007) + (fn(n-4)% 10000007) + (fn(n-5)% 10000007) + (fn(n-6)% 10000007)) % 10000007;
}
int main()
{
    optimize();
    int n, cases;
    cin>>cases;
    for (int i = 1; i <= cases; i++) {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c>>d>>e>>f>>n;
        cout<<"Case "<<i<<": "<<(fn(n) % 10000007)<<endl;
    }
    return 0;
}
