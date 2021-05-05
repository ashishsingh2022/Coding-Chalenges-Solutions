#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;


// Soln 1
void pre_process()
{

}


// Soln 1
bool once=false;
void solve()
{
    INT n,i;
    cin>>n;
    string s;
    cin>>s;
    bool yes=true;
    bool used[300]={false};
    used[s[0]]=true;
    for(i=1;i<s.length();i++)
        {
            if(used[s[i]] && s[i]!=s[i-1])
                {
                    yes=false;
                    break;
                }
            used[s[i]]=true;
        }
    if(yes)
        {
            cout<<"YES"<<endl;
        }
    else
        {
            cout<<"NO"<<endl;
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
