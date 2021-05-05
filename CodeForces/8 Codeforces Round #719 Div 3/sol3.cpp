#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;


// Soln 3
void pre_process()
{

}


// Soln 3
bool once=false;
void solve()
{
    INT n,i,j;
    cin>>n;
    if(n==2)
        {
            cout<<-1<<endl;
            return;
        }
    INT num=1;
    INT num2=n*n;
    INT mat[n][n];
    for(INT add=0;add<n;add++)
        {
            for(INT f=0;f<n;f++)
                {
                    INT g=f+add;
                    if(f>=n ||g>=n)continue;
                    mat[f][g]=num++;
                    if(f!=g)mat[g][f]=num++;

                }
        }
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)cout<<mat[i][j]<<" ";
            cout<<endl;
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
