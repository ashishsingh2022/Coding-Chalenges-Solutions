#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;


// Soln 2
void pre_process()
{

}


// Soln 2
bool once=false;
void solve()
{
    INT n;
    cin>>n;
    INT num;
    INT count=0;
    for(num=1;num<=9;num++)
        {
            INT curr=num;
            while(curr<=n)
                {
                    count++;
                    curr=curr*10+num;
                }
        }
    cout<<count<<endl;
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
