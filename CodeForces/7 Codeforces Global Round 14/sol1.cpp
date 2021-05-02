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
    INT n,x;
    cin>>n>>x;
    INT i,j;
    INT arr[n];
    for(i=0;i<n;i++)cin>>arr[i];

    sort(arr,arr+n);
    INT exclude=-1;
    INT sum=0;
    vector<INT>vect;
    for(i=0;i<n;i++)
        {
            if(sum+arr[i]==x)
                {
                    exclude=arr[i];
                    if(i==n-1)
                        {
                            cout<<"NO"<<endl;
                            return;
                        }
                    continue;
                }
            vect.push_back(arr[i]);
            sum+=arr[i];
        }
    if(exclude!=-1)vect.push_back(exclude);
    cout<<"YES"<<endl;
    for(i=0;i<n;i++)cout<<vect[i]<<" ";
     cout<<endl;

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
