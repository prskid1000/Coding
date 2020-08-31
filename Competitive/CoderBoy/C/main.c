#include<stdio.h>

void matprint(int *arr,int m,int n)
{
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d ",*((arr+i*n)+j));
    }
    printf("\n");
  }
}

void Transp(int *arr,int m,int n,int *mt,int *nt)
{
  *mt=n;
  *nt=m;

  int res[*mt][*nt];

  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      res[j][i]=*((arr+i*n)+j);
    }
  }

  matprint((int *)res,*mt,*nt);
}
int main()
{
  int m=2,n=3;
  int A[m][n],mt,nt,i,j;
  printf("Enter row and col of matrix!\n");
  scanf("%d %d",&m,&n);

  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)scanf("%d\n",&A[i][j]);
  }

  matprint((int *)A,m,n);
  Transp((int *)A,m,n,&mt,&nt);;
}
