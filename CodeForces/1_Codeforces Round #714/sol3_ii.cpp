#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;

bool is_prime[2*100000+5];
void prime_upto_n(INT,bool*);



bool once=false;

int ans[3*100000][10];


void solve()
{
    int n;
    int m;
    cin>>n>>m;
    long long ans1=0;
    while(n!=0)
        {
            int d=n%10;
            n=n/10;
            ans1=(ans1+ans[m][d])%mod;
        }
    cout<<ans1<<endl;
}








int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int p,q;
    for(q=0;q<10;q++)ans[0][q]=1;
    for(p=1;p<200000+5;p++)
    {
        for(q=0;q<9;q++)ans[p][q]=ans[p-1][q+1];
        ans[p][q]=(ans[p-1][0]+ans[p-1][1])%mod;
    }
    
    
    
     int t;
     cin>>t;
     while(t--)
    {
      solve();
    }
    return 0;
}



