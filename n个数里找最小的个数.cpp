#include<stdio.h>
void f(int a[],int n,int k,int z)
{
	int i,min,s=0,t;
	if(z==k)
	     return;
	else
	{
		min=a[0];	//假定第一个元素值是最小 
		for(i=0;i<n;i++)
		{
			if(a[i]<min)
			{
			   min=a[i];
			   s=i;
	     	}
		}
		t=a[n-1];
	    a[n-1]=a[s];
		a[s]=t;
		
		printf("%d\t",min);
		f(a,n-1,k,z+1);
	}
}

int main()
{
	int k,i,n,a[100],z=0;	 //Z=0  第一个元素下标 
	printf("请输入数组元素的个数:");
	scanf("%d",&n);
	printf("请输入%d个数:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("请输入k:");
	scanf("%d",&k);
	f(a,n,k,z); 
	return 0;
}

