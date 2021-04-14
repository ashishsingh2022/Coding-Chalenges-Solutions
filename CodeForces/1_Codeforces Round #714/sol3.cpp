#include<bits/stdc++.h>
using namespace std;

long long int rec(int,int);
long long int ans(int,int);

long long int mod=1000000007;

long long int quick[200000];

long long int rec(int d,int m)
{
    if(m==0)return 1;
    int div=m/(10-d);
    long long int res=0;
    if(div>=1 && quick[m-(10-d)]==-1)
        {
            res=ans(10,m-(10-d))%mod;
            quick[m-(10-d)]=res;
        }
    else if(div>=1 && quick[m-(10-d)]!=-1)return quick[m-(10-d)];
    else
        {
            res=1;
        }

    return res;
}
long long int ans(int num,int m)
{
    int p=10;
    long long int res=0;
    while(num!=0)
        {
            res+=rec(num%p,m)%mod;
            num=num/p;
        }
    return res;
}


int main()
{
    int t;
    cin>>t;
    for(int i=0;i<200000;i++)quick[i]=-1;
    while(t--)
    {
      long long int n,m;
      cin>>n>>m;
      cout<<ans(n,m)%mod<<endl;


    }
}
