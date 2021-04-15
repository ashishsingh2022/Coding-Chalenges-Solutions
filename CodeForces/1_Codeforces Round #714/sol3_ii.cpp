#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;

bool is_prime[2*100000+5];
void prime_upto_n(INT,bool*);



bool once=false;

int ans[3*100000][10];
int p,q;
for(q=0;q<10;q++)ans[0][q]=1;
for(p=1;p<3*100000;p++)
    {
        for(q=0;q<9;q++)ans[p][q]=ans[p-1][q+1];
        ans[p][q]=ans[p-1][0]+ans[p-1][1];
    }

void solve()
{

    string n;
    int m;
    cin>>n>>m;
    int ans1=0;
    for(int i=0;i<n.length();i++)
        {
            int d=n[i]-'0';
            ans1+=ans[m][d]%mod;
        }
    cout<<ans1<<endl;
}








int main()
{
    if(once)
        {
            solve();
        }
    else
        {
            INT t;
            cin>>t;
            while(t--)
                {
                    solve();
                }
        }
    return 0;
}



void prime_upto_n(INT n,bool is_prime[])
{
    INT i;
    for(i=0;i<=n;i++)is_prime[i]=true;
    is_prime[1]=false;
    is_prime[0]=false;
    for(INT p=2;p*p<=n;p++)
        {
            if(is_prime[p])
                {
                    for(INT i=p*p;i<=n;i+=p)
                        {
                            is_prime[i]=false;
                        }
                }
        }
    for(INT i=0;i<=n;i++)
        {
            if(is_prime[i])cout<<i<<" ";
        }
}
