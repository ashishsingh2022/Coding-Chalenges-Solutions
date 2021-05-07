#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
typedef pair<INT,INT> pr;
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
    vector<INT>adj[n+3];
    INT cost[n+3];
    INT i,j;
    for(i=0;i<=n;i++)cost[i]=INT_MAX;
    bool isConnected[n+3][n+3];
    for(i=0;i<n-1;i++){
        INT u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        isConnected[min(u,v)][max(u,v)]=true;
    }

    vector<INT>zero;
    INT ans=0;
    INT count[n+5];//={0};
    for(i=0;i<=n;i++)
        {
            ans+=max((INT)0,(INT)adj[i].size()-2);
            count[i]=adj[i].size();
            if(adj[i].size()==1)zero.push_back(i);
        }
    cout<<2*ans<<endl;
    INT ind=0;
    for(i=1;i<=n;i++)
        {
            int p=0;
            while(count[i]>2)
                {
                    INT u=i;
                    INT v=adj[i][p];
                    if(isConnected[min(u,v)][max(u,v)]==true)
                    {
                        cout<<i<<" "<<adj[i][p]<<" "<<adj[i][p]<<" "<<zero[ind]<<endl;
                        count[u]--;
                        count[v]--;
                        count[ind]++;
                        isConnected[min(u,v)][max(u,v)]=false;
                    }
                    p++;
                }

        }
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
