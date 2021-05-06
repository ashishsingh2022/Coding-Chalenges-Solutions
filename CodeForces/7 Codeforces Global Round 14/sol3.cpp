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
bool desc(pair<INT,INT>a,pair<INT,INT>b)
{
    return a.first>b.first;
}
bool once=false;
void solve()
{
    INT n,m,x,i,j;
    cin>>n>>m>>x;
    INT place[n];
    pair<INT,INT>towers[n];
    for(i=0;i<n;i++)
        {
            INT temp;
            cin>>temp;
            towers[i].first=temp;
            towers[i].second=i;
        }
    priority_queue<pair<INT,INT>,vector<pair<INT,INT>>,greater<pair<INT,INT>>>minq;
    sort(towers,towers+n,desc);
    for(i=0;i<m;i++)
        {
            minq.push({towers[i].first,i+1});
            place[towers[i].second]=i+1;
        }
    for(;i<n;i++)
        {
            pair<INT,INT>pr=minq.top();
            minq.pop();
            INT h=pr.first+towers[i].first;
            pr.first=h;
            place[towers[i].second]=pr.second;
            minq.push(pr);
        }
    INT min_height=minq.top().first;
    INT max_height;
    for(i=0;i<m;i++)
        {
            max_height=minq.top().first;
            minq.pop();
        }

    if(max_height-min_height>x)
        {
            cout<<"NO"<<endl;
        }
    else
        {
            cout<<"YES"<<endl;
            for(i=0;i<n;i++)cout<<place[i]<<" ";
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
