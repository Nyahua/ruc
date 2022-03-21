#include <stdio.h>
int a[20][20];
int b[20][30];
int flag=0;
int n,m;
void zmg(int i,int j)
{
 if(i==n-1&&j==m-1)
 {
  flag=1;
  return;
 }
 if(i>0&&a[i-1][j]==1&&b[i][j]==0)
 {
  b[i-1][j]=-1;
  zmg(i-1,j);
  b[i-1][j]=0;
 }
 if(i<n-1&&a[i+1][j]==1&&b[i+1][j]==0)
 {
  b[i+1][j]=-1;
  zmg(i+1,j);
  b[i+1][j]=0;
 }
 if(j>0&&a[i][j-1]==1&&b[i][j-1]==0)
 {
  b[i][j-1]=-1;
  zmg(i,j-1);
  b[i][j-1]=0;
 }
 if(j<m-1&&a[i][j+1]==1&&b[i][j+1]==0)
 {
  b[i][j+1]=-1;
  zmg(i,j+1);
  b[i][j+1]=0;
 }
 return;
}
int main()
{
 
 int i,j,k;
 scanf("%d %d",&n,&m);
 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
   scanf("%d",&a[i][j]);
   b[i][j]=0;
  }
 }
 zmg(0,0);
 if(flag==1)
 {
  printf("YES\n");
 }
 else 
 {
  printf("NO\n");
  } 
 return 0;
}