#include<stdio.h>
void f(int a[],int n,int k,int z)
{
	int i,min,s=0,t;
	if(z==k)
	     return;
	else
	{
		min=a[0];	//�ٶ���һ��Ԫ��ֵ����С 
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
	int k,i,n,a[100],z=0;	 //Z=0  ��һ��Ԫ���±� 
	printf("����������Ԫ�صĸ���:");
	scanf("%d",&n);
	printf("������%d����:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("������k:");
	scanf("%d",&k);
	f(a,n,k,z); 
	return 0;
}

