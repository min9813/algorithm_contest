#include<iostream>
#include<algorithm>
using namespace std;
int N;
long x[18],c[18],v[18];
long xs[19],cs[1<<18],vs[1<<18];
long f[1<<18][19],dp[1<<18];

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>x[i];
		xs[i+1]=xs[i]+x[i];
	}
	for(int i=0;i<N;i++)cin>>c[i];
	for(int i=0;i<N;i++)cin>>v[i];
	for(int i=0;i<1<<N;i++)
		for(int j=0;j<N;j++)if(i>>j&1)cs[i]+=c[j],vs[i]+=v[j];
	for(int i=1<<N;i--;)for(int j=0;j<=N;j++)
	{
		if(cs[~i&(1<<N)-1]<=xs[j])f[i][j]=vs[~i&(1<<N)-1];
		else for(int k=0;k<N;k++)f[i][j]=max(f[i][j],f[i|1<<k][j]);
	}
	for(int i=(1<<N)-1;i--;)
	{
		long t=9e18;
		for(int j=0;j<N;j++)if(!(i>>j&1))t=min(t,dp[i|1<<j]);
        cout << "i=" << i <<" t=" << t << endl;
		dp[i]=max(f[i][__builtin_popcount(i)],t);
	}
	cout<<dp[0]<<endl;
}