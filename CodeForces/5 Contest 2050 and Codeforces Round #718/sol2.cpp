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
    INT m;
    cin>>n>>m;
    bool used[n][m];
    INT i,j;
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)used[i][j]=false;
        }
    vector<pair<INT,pair<int,int>>>min_m;
    INT val[n][m];
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                {
                    INT temp;
                    cin>>temp;
                    val[i][j]=temp;
                    pair<int,int>p={i,j};
                    min_m.push_back({temp,p});
                }
        }
    sort(min_m.begin(),min_m.end());
    INT ans[m][n];
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)ans[i][j]=-1;
        }
    for(i=0;i<m;i++)
        {
            pair<INT,pair<int,int>>pr=min_m[i];
            INT val1=pr.first;
            pair<int,int>pos=pr.second;
            int path_no=pos.first;
            int person_no=pos.second;
            //cout<<val1<<"  "<<path_no<<"  "<<person_no<<"  "<<endl;
            ans[i][path_no]=val1;
            used[path_no][person_no]=true;
        }



    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                {
                    if(ans[i][j]!=-1)continue;
                    INT k;
                    for(k=0;k<m;k++)  //decide nth path for mth person
                        {
                            if(!used[j][k])
                                {
                                    used[j][k]=true;
                                    ans[i][j]=val[j][k];
                                    break;
                                }
                        }
                }
        }
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)cout<<ans[j][i]<<" ";
            cout<<endl;
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
