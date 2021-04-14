#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
int main()
{
    int t;
    cin>>t;
    long long int dp[2*100000+4];
    dp[0]=1;
    for(int j=1;j<2*100000+4;j++)
        {
            dp[j]=(dp[j-1]*j)%mod;
        }
    while(t--)
        {
            int n;
            cin>>n;
            long long int minn=INT_MAX;
            long long int freq=0;
            long long int arr[n];
            int i;
            for(i=0;i<n;i++)
                {
                    long long int temp;
                    cin>>temp;
                    arr[i]=temp;
                    if(temp<minn)
                    {
                        minn=temp;
                        freq=1;
                    }
                    else if(temp==minn)freq++;
                }
            long long int ans=(freq*(freq-1))%mod;
            ans=(ans*dp[n-2])%mod;
            for(i=0;i<n;i++)
                {
                    if((minn&arr[i])!=minn)ans=0;
                }
            cout<<ans<<endl;
        }
}
