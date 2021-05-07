#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
typedef pair<INT,INT> pr;
INT mod=1000000007;


// Soln 1
void pre_process()
{

}


// Soln 1
bool once=false;
void solve()
{
    INT a,b;
    cin>>a>>b;
    /*if(a%b==0)
        {
            cout<<"NO"<<endl;
            return;
        }*/
    cout<<"YES"<<endl;
    if(b==2)
        {
            cout<<a<<" "<<3*a<<" "<<4*a<<endl;
            return;
        }
    cout<<a<<" "<<(a*b-a)<<" "<<a*b<<endl;

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
