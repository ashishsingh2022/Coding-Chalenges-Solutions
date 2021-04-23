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
unordered_map<INT,INT>mp;
INT minn(INT n)
{
    if(mp.find(n)!=mp.end())
        {
            return mp[n];
        }
    INT ans=0;
    INT res=n/2050;
    while(res!=0)
        {
            INT logg=log10(res);
            INT poww=pow(10,logg);
            INT num=res/poww;
            res-=poww*num;
            ans+=num;
        }
    mp[n]=ans;
    return mp[n];
}
bool once=false;
void solve()
{
    INT n;
    cin>>n;
    if(n%2050!=0)
        {
            cout<<-1<<endl;
            return;
        }
    cout<<minn(n)<<endl;
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
