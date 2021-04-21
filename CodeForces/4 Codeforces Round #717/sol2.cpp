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
bool rec(INT arr[],INT res1,INT s,INT n)
{
    //cout<<"Res1 "<<res1<<endl;
    if(s>=n)return true;
    INT ans=0;
    for(INT i=s;i<n;i++)
        {
            ans=ans^arr[i];
            if(ans==res1)
                {
                    //cout<<"Calling"<<i+1<<" ans="<<ans<<" Res1 "<<res1<<endl;
                    return rec(arr,res1,i+1,n);
                }
        }
    return false;
}
void solve()
{
    INT n;
    cin>>n;
    INT arr[n];
    INT i,j;
    for(i=0;i<n;i++)cin>>arr[i];
    INT res1=0;
    for(i=0;i<n-1;i++)
        {
            res1=res1^arr[i];
            bool res=rec(arr,res1,i+1,n);
            if(res)
                {
                    //cout<<res1<<endl<<endl;
                    cout<<"YES"<<endl;
                    return;
                }
        }
    cout<<"NO"<<endl;
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
