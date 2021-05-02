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
    INT l,r;
    INT ans1=0;
    INT ans2=0;
    cin>>n>>l>>r;
    unordered_map<INT,INT>mp;
    INT i,j;
    for(i=0;i<l;i++)
        {
            INT temp;
            cin>>temp;
            mp[temp]++;
        }
    for(i=0;i<r;i++)
        {
            INT temp;
            cin>>temp;
            mp[temp]--;
        }
    unordered_map<INT,INT>::iterator itr;
    INT left=0;
    INT right=0;
    INT rem_left=0;
    INT rem_right=0;
    for(itr=mp.begin();itr!=mp.end();itr++)
        {
            INT cnt=itr->second;
            INT make=abs(cnt)/2;
            if(cnt>0)
                {
                    left+=abs(cnt);
                    rem_left+=abs(cnt)-make*2;
                }
            if(cnt<0)
                {
                    right+=abs(cnt);
                    rem_right+=abs(cnt)-make*2;
                }
            ans2+=make;
            //cout<<rem_left<<"     "<<rem_right<<endl;
        }
    ans1+=min(left,right)+(max(left,right)-min(left,right));
    left=rem_left;
    right=rem_right;
    ans2+=min(rem_left,rem_right)+(max(left,right)-min(left,right));
    cout<<min(ans1,ans2)<<endl;
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
