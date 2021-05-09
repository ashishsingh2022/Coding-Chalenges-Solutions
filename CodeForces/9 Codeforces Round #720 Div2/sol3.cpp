#include <iostream>
using namespace std;

int query(int t,int i,int j,int x)
{
    int arr[]={2,5,3,4,1};
    int pi=arr[i-1];
    int pj=arr[j-1];
    if(t==1)
        {
         return max(min(x,pi),min(x+1,pj));
        }
        return min(max(x,pi),max(x+1,pj));
}

int index_of_n(int i,int j,int x,int n)
{
     cout<<"?"<<" "<<1<<" "<<i<<" "<<j<<" "<<x<<"\n";
     cout.flush();
    int ans;// =query(1,i,j,x);
    //cout<<"ANS "<<ans<<endl;
    cin>>ans;
    if(ans==-1)exit(0);
    if(ans==n)return j;
    if(ans==n-1)
    {
        cout<<"?"<<" "<<1<<" "<<j<<" "<<i<<" "<<x<<"\n";
        cout.flush();
        cin>>ans;
        //ans=query(1,j,i,x);
        //cout<<"ANS "<<ans<<endl;
        if(ans==n)return i;
    }
    return -1;
}
int curr(int i,int p)
{
    cout<<"?"<<" "<<2<<" "<<i<<" "<<p<<" "<<1<<"\n";
   // cout.flush();
    int ans;// =query(2,i,p,1);
    //cout<<"ANS "<<ans<<endl;
    cin>>ans;
    if(ans==-1)exit(0);
    return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n==1)
	    {
	        cout<<1<<endl;
	        break;
	    }
	    int i,j,k;
	    int arr[n];
	    int p=-1;
	    i=1;
	    while(i<=n && p==-1)
	    {
	        if(i+1<=n)p=index_of_n(i,i+1,n-1,n);
	        else
	        {
	            p=index_of_n(i-1,i,n-1,n);
	        }
	        i=i+2;
	    }
	    arr[p-1]=n;
	    //cout<<"Before ";
	    //for(i=0;i<n;i++)cout<<arr[i]<<" ";
	    //cout<<endl;
	    for(i=0;i<n;i++)
	    {
	        if(i==p-1)continue;
	        arr[i]=curr(i+1,p);
	    }
	    cout<<"! ";
	    for(i=0;i<n;i++)cout<<arr[i]<<" ";
	    cout<<"\n";
	    cout.flush();
	}
	return 0;
}
