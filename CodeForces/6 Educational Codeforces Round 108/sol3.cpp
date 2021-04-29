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
    cin>>n;
    INT k=n;
    short int u[n];
    bool isPresent[n];
    vector<int>uni;
    vector<INT>skill[n+1];
    int i;

    for(i=0;i<n;i++)isPresent[i]=false;
    for(i=0;i<n;i++)
        {
            cin>>u[i];
            if(!isPresent[u[i]])
                {
                    uni.push_back(u[i]);
                }
            isPresent[u[i]]=true;
        }

    for(i=0;i<n;i++)
        {
            int index=u[i];
            INT temp;
            cin>>temp;
            skill[index].push_back(temp);
        }
    INT maxx=0;
    for(int q:uni)
        {
            i=q;
            sort(skill[i].begin(),skill[i].end(),greater<INT>());
            maxx=max(maxx,(INT)skill[i].size());
            for(INT p=1;p<skill[i].size();p++)
                {
                    skill[i][p]+=skill[i][p-1];
                }
        }
    INT limit=k;
    for(k=1;k<=limit;k++)
        {
            INT sum=0;
            for(int p:uni)
                {
                    INT grp=(skill[p].size())/k;
                    INT part=grp*k;
                    if(part==0)continue;
                    sum+=skill[p][part-1];
                }
             cout<<sum<<" ";
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
