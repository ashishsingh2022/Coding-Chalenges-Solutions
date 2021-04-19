#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;
INT p=0;
bool is_prime[2*100000+5];
void prime_upto_n(INT,bool*);


void pre_process()
{
	
}
bool once=false;
void solve()
{
    INT n;
    int a,b,c,t,a2,b2,c2;
    cin>>a>>b>>c>>t>>a2>>b2>>c2;
    if(a>a2 ||b>b2||c>c2||a2+b2+c2<t)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    return;
}








int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pre_process();
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
