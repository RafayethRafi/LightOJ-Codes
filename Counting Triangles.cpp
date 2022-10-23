

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
int main()
{
    optimize();
    int t;
    cin>>t;
    for(int tc =1;tc<=t;tc++)
    {
        int n,i,j;
        cin>>n;
        vector<int>a(n);
        for(i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        int ans=0;

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int x = a[i]+ a[j];
                int l = upper_bound(a.begin(),a.end(),x-1) - a.begin();
                ans += (l-j-1);
            }
        }

        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
    return 0;
}
