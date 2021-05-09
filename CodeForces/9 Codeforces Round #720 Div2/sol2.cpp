#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;
typedef pair<INT,INT> pr;
INT mod=1000000007;
//INT maxx=LLONG_MAX;
//INT minn=LLONG_MAX;

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
    INT arr[n];
    INT i,j;
    INT minn=LLONG_MAX;
    INT minn_index=-1;
    for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]<minn)
                {
                    minn=arr[i];
                    minn_index=i;
                }
        }
    vector<vector<INT>>ans;
    for(i=minn_index+1;i<n;i++)
        {
            vector<INT>temp;
            temp.push_back(minn_index);
            temp.push_back(i);
            temp.push_back(minn);
            if(arr[i-1]==minn)
                {
                    arr[i]=minn+1;
                    temp.push_back(minn+1);
                }
            else
                {
                    arr[i]=minn;
                    temp.push_back(minn);
                }
            ans.push_back(temp);
        }
    for(i=minn_index-1;i>=0;i--)
        {
            vector<INT>temp;
            temp.push_back(minn_index);
            temp.push_back(i);
            temp.push_back(minn);
            if(arr[i+1]==minn)
                {
                    arr[i]=minn+1;
                    temp.push_back(minn+1);
                }
            else
                {
                    arr[i]=minn;
                    temp.push_back(minn);
                }
            ans.push_back(temp);
        }
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++)
        {
            for(j=0;j<2;j++)cout<<ans[i][j]+1<<" ";
            for(;j<4;j++)cout<<ans[i][j]<<" ";
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
