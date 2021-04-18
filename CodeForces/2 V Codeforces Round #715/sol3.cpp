#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;
INT p=0;
bool is_prime[2*100000+5];
void prime_upto_n(INT,bool*);

INT ans[3000][3000];
void pre_process()
{
    INT i,j;
    for(i=0;i<3000;i++)
        {
            for(j=0;j<3000;j++)ans[i][j]=-1;
        }
}
bool once=true;

INT minn(INT arr[],int l,int r)
{
    if(ans[l][r]!=-1)return ans[l][r];
    if(l==r)return 0;
    if(l+1==r)return arr[r]-arr[l];
    INT d=arr[r]-arr[l];
    INT min1=minn(arr,l,r-1);
    INT min2=minn(arr,l+1,r);
    ans[l][r]=d+min(min1,min2);
    return ans[l][r];
}
void solve()
{
    INT n;
    cin>>n;
    INT arr[n];
    INT i;
    for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    sort(arr,arr+n);
    cout<<minn(arr,0,n-1)<<endl;
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
