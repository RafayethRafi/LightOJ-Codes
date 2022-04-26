#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define MOD 1000003
#define endl '\n'
long long modPow(long long b,long long p)
{
    long long ret =1;

    while(p>0)
    {
        if(p%2)
        {
            ret*= b;
            ret%= MOD;
        }
        p/=2;
        b*= b;
        b%= MOD;
    }
    return ret;
}

const int mx = 1e6+123;
long long fact[mx];
long long invFact[mx];
int main()
{
    optimize();
    int lim= 1e6;
    fact[0] =1;
    invFact[0] =1;

    for(int i=1;i<=lim;i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
        invFact[i] = modPow(fact[i],MOD-2) % MOD;
    }
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,k;
        cin>>n>>k;
        long long ans = (fact[n]*invFact[k]*invFact[n-k])%MOD;
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
    return 0;
}
