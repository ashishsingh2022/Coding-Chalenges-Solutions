#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;


// Soln 4
void pre_process()
{

}


// Soln 4
bool once=false;
void solve()
{
    INT n;
    cin>>n;
    INT arr[n];
    INT i,j;
    unordered_map<INT,INT>mp;
    for(i=0;i<n;i++)
        {
            INT temp;
            cin>>temp;
            INT diff=temp-i;
            mp[diff]++;
        }
    unordered_map<INT,INT>::iterator itr;
    INT ans=0;
    for(itr=mp.begin();itr!=mp.end();itr++)
        {
            INT num1=itr->first;
            INT num2=itr->second;
            //cout<<num1<<"  "<<num2<<endl;
            if(num2<=1)continue;
            INT num=num2;
            ans+=((num-1)*num)/2;
        }
    cout<<ans<<endl;
    //cout<<endl<<endl<<endl;

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
