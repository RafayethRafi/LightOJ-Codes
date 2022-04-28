#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 5e6+123;
unsigned long long phi[mx];

int main()
{
    optimize();
    int lim = 5e6;

    int i,j; 
    for(i=1;i<=lim;i++) phi[i]=i;
    for(i=2;i<=lim;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=lim;j+=i)
            {
                phi[j] *= (i-1);
                phi[j] /= i;
            }
        }
    }

    for(i=1;i<=lim;i++) phi[i]*= phi[i];

    for(i=1;i<=lim;i++) phi[i]+= phi[i-1];

    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int a,b;
        cin>>a>>b;

        cout<<"Case "<<tc<<": "<<phi[b]-phi[a-1]<<endl;
    }
    return 0;
}
