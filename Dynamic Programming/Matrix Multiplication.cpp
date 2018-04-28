#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int **s, **mat, n,*dim;
int min(int i,int j)
{
	int min=INT_MAX,k,paritionPlace=-1;
	for(k=i;k<j;k++)
	{
		if(min> (mat[i][k]+mat[k+1][j]+(dim[i-1]*dim[k]*dim[j])))
		{
			min=mat[i][k]+mat[k+1][j]+(dim[i-1]*dim[k]*dim[j]);
			paritionPlace=k;
		}
	} 
	mat[i][j]=min;
	return paritionPlace;
}

void matMult()
{
	int i,k,j,len;
	for(i=1;i<=n;i++)
		mat[i][i]=0;
	i=1;
	for(len=2;len<=n;len++)
	{
		for(k=0;k<n-len+1;k++) // no of times it will come down the diagonal
		{
			s[i+k][len+k]=min(i+k,len+k); //this function sets
		//	the minimum value in mat[i,j] and returns the value of k so that we can store it in s array needed
		//bracketing.
		}
	}
}
void printInternalThings()
{
	//printing mat
	int j,i;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<=j)
			printf("%d\t",mat[i][j]);
			else
			printf("\t");
		}	
		printf("\n");
	}
	
	printf("\n");
	
	//printing s
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<j)
			printf("%d\t",s[i][j]);
			else
			printf("\t");
		}	
		printf("\n");
	}
}

void bracketPrint(int i, int j)
{
	if(i==j)
		printf("A%d",i);
	else
	{
		printf("(");
		bracketPrint(i,s[i][j]);
		bracketPrint(s[i][j]+1,j);
		printf(")");
	}
}

int main()
{
	int i;
	scanf("%d",&n);
	dim=(int*)malloc( (n+1) *sizeof(int));
	for(int i=0;i<=n;i++)
		scanf("%d",&dim[i]);
	
	s=(int**)malloc( (n+1) *sizeof(int*));
	mat=(int**)malloc( (n+1) *sizeof(int**));
	for(i=0;i<=n;i++)
	{
		s[i]=(int*)malloc( (n+1) *sizeof(int));
		mat[i]=(int*)malloc( (n+1) *sizeof(int));
	}  
	matMult();
	
	printInternalThings();
	
	bracketPrint(1,n);
	
	return 0;
	
}
