#include <cstdio>
#include <cstring>
#include <cmath>
#define min(a,b) (((a)<(b))?(a):(b))
double a[20][20];
double x[20],y[20];
double F[18][34000];
int N;
double distance(int v,int w)
{
	return sqrt((x[v]-x[w])*(x[v]-x[w])+(y[v]-y[w])*(y[v]-y[w]));
}
int main()
{
	int i,j,k;
	double ans;
	memset(F,127,sizeof(F));
	ans=F[0][0];
	scanf("%d",&N);
	for(i=1; i<=N; i++)
		scanf("%lf%lf",&x[i],&y[i]);
	x[0]=0;
	y[0]=0;
	for(i=0; i<=N; i++)
		for(j=i+1; j<=N; j++)
			a[i][j]=distance(i,j),a[j][i]=a[i][j];
	for(i=1; i<=N; i++) 
		F[i][(1<<(i-1))]=a[0][i];
	for(k=1; k<(1<<N); k++)
	{
		for(i=1; i<=N; i++)
		{
			if((k&(1<<(i-1)))==0)continue;
			for(j=1; j<=N; j++)
			{
				if(i==j)continue;
				if((k&(1<<(j-1)))==0)continue;
				F[i][k]=min(F[i][k],F[j][k-(1<<(i-1))]+a[i][j]);
			}
		}
	}
	for(i=1; i<=N; i++)
		ans=min(ans,F[i][(1<<N)-1]);
	printf("%.2f\n",ans);
	return 0;
}