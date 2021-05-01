#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;
INT p=0;
bool is_prime[5];
void prime_upto_n(INT,bool*);


void pre_process()
{

}
bool once=false;
void solve()
{
    INT n;
    cin>>n;
    INT k=n;
    int u[n];
    bool isPresent[n+5];
    vector<int>uni;
    vector<INT>skill[n+1];
    int i;
    for(i=0;i<n+3;i++)isPresent[i]=false;
    unordered_set<int>set1;
    for(i=0;i<n;i++)
        {
            cin>>u[i];
            if(isPresent[u[i]]==false)
                {
                    uni.push_back(u[i]);
                    isPresent[u[i]]=true;
                }
        }

    for(i=0;i<n;i++)
        {
            int index=u[i];
            INT temp;
            cin>>temp;
            skill[index].push_back(temp);
        }
    INT ans[n+1];
    for(i=0;i<=n;i++)ans[i]=0;
    for(int q:uni)
        {
            i=q;
            sort(skill[i].begin(),skill[i].end(),greater<INT>());
            for(INT p=1;p<skill[i].size();p++)
                {
                    skill[i][p]+=skill[i][p-1];
                }
            for(k=1;k<=skill[i].size();k++)
                {
                    INT grp=(skill[i].size())/k;
                    INT part=grp*k;
                    if(part==0)continue;
                    ans[k]+=skill[i][part-1];

                }
        }
    INT limit=n;
    for(k=1;k<=limit;k++)
        {
            cout<<ans[k]<<" ";
        }
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
