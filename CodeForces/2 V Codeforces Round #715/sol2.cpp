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
    string s;
    cin>>s;
    INT left[n];
    INT right[n];
    INT left_m[n];
    INT right_m[n];
    INT i;
    for(i=0;i<n;i++)
        {
            left[i]=0;
            right[i]=0;
        }
    int l=0;
    int lm=0;
    int t=0;
    int m=0;
    for(i=0;i<s.length();i++)
        {
            left[i]=l;
            if(s[i]=='T')
                {
                    l++;
                    t++;
                }
            else
                {
                    lm++;
                    m++;
               }
            left_m[i]=lm;
        }
    int r=0;
    int rm=0;
    for(i=s.length()-1;i>=0;i--)
        {
            right[i]=r;
            if(s[i]=='T')
                {
                    r++;
                }
            else
                {
                    rm++;
                }
            right_m[i]=rm;
        }
    if(2*m!=t)
        {
            cout<<"NO"<<endl;
            return;
        }
    string ans="YES";
    for(i=0;i<s.length();i++)
        {
            if(left_m[i]>left[i])
                {
                    cout<<"NO"<<endl;
                    return ;
                }
            if(right_m[i]>right[i])
                {
                    cout<<"NO"<<endl;
                    return;
                }
        }
    cout<<"YES"<<endl;
    return;

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
