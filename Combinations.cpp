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






//Solution with Modular Arithmatic template

#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define endl '\n'
#define MOD 1000003

inline void normal(long long &a) { a %= MOD; (a < 0) && (a += MOD); }
inline long long modMul(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline long long modAdd(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline long long modSub(long long a, long long b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline long long modPow(long long b, long long p) { long long r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline long long modInverse(long long a) { return modPow(a, MOD-2); }
inline long long modDiv(long long a, long long b) { return modMul(a, modInverse(b)); }

const int mx = 1e6+123;
long long fact[mx];
long long invFact[mx];

int main()
{
    optimize();
    int lim = 1e6;
    fact[0] =1;
    invFact[0] =1;

    for(int i=1;i<=lim;i++)
    {
        fact[i] = modMul(i,fact[i-1]);
        invFact[i] = modInverse(fact[i]);
    }

    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,k;
        cin>>n>>k;
        cout<<"Case "<<tc<<": "<<modMul( modMul (fact[n],invFact[n-k]),invFact[k])<<endl;
    }
    return 0;
}
