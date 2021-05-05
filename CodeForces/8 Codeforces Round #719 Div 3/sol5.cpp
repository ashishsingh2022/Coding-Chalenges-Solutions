#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;


// Soln 5
void pre_process()
{

}


// Soln 5
bool once=false;
void solve()
{
    INT n;
    cin>>n;
    INT i,j,k;
    char arr[n];
    for(i=0;i<n;i++)cin>>arr[i];
    INT left[n];
    INT leftc[n];
    INT sum=0;
    INT count=0;
    for(i=0;i<n;i++)
        {
            left[i]=sum;
            leftc[i]=count;
            if(arr[i]=='*')
                {
                    sum+=i;
                    count++;
                }
        }

    INT right[n];
    INT rightc[n];
    sum=0;
    count=0;
    for(i=n-1;i>=0;i--)
        {
            right[i]=sum;
            rightc[i]=count;
            if(arr[i]=='*')
                {
                    sum+=i;
                    count++;
                }
        }
    INT ans=LLONG_MAX;
    for(i=0;i<n;i++)
        {
            if(arr[i]!='*')continue;
            INT left_sum=leftc[i]*i-(leftc[i]*(leftc[i]+1))/2-left[i];
            INT right_sum=right[i]-rightc[i]*i-((rightc[i]+1)*rightc[i])/2;
            INT curr=left_sum+right_sum;
            ans=min(ans,curr);
        }
    if(ans==LLONG_MAX)
        {
            cout<<0<<endl;
            return;
        }
    //cout<<LLONG_MAX<<endl;
    cout<<ans<<endl;
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
