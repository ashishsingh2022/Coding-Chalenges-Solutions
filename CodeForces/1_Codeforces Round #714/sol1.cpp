#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t--)
        {
            int n,k;
            cin>>n>>k;
            int minn=1;
            int maxx=n;
            if(n%2==0 && k>=n/2)
                {
                    cout<<-1;
                }
            else if(n%2!=0 && k>n/2)
                {
                    cout<<-1;
                }
            else
                {
                    int c=0;
                    int peak=0;
                    while(c<n && peak<k)
                        {
                            if(c%2==0)cout<<(minn++)<<" ";
                            else
                                {
                                    cout<<(maxx--)<<" ";
                                    peak++;
                                }
                            c++;
                        }
                    for(int l=minn;l<=maxx;l++)cout<<l<<" ";

                }
            cout<<endl;
        }
}
