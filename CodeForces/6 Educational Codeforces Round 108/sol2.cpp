#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
INT mod=1000000007;
INT p=0;
bool is_prime[1];
void prime_upto_n(INT,bool*);

short int isPossible[100+1][100+1][10000+1];

void pre_process()
{
	INT p,q,r;
	for(p=0;p<101;p++)
        {
            for(q=0;q<101;q++)
                {
                    for(r=0;r<10001;r++)
                        {
                            isPossible[p][q][r]=0;
                        }
                }
        }
}
bool once=false;


INT rec(INT n,INT m,INT k)
{
    if(isPossible[n][m][k]!=0)return isPossible[n][m][k];
    if(n==1 && m==1 && k==0)
        {
            isPossible[n][m][k]=1;
            return isPossible[n][m][k];;
        }
    if(n<1 ||m<1)return -1;


    if(rec(n,m-1,k-n)==1||rec(n-1,m,k-m)==1)
        {
            isPossible[n][m][k]=1;
        }
    else
        {
            isPossible[n][m][k]=-1;
        }
    return isPossible[n][m][k];
}

void solve()
{
    INT n,m,k;
    cin>>n>>m>>k;
    if(rec(n,m,k)==1)
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
