#include<stdio.h>
int main()
{
	int flag,k,i=0;		//flag检查标志 
	int a[6];
	a[0]=1;
	printf("填入顺序可为：");
	while(1)
	{
		flag=1;
 
		for(k=i-1;k>=0;k--)    
		{
			if(a[i]==a[k])            //检查是否有相同值，有则g=0
			{
				flag=0;
				break;
			}
		}
		
		//两两边相等条件
		if(((a[0]+a[1]+a[2])==(a[2]+a[3]+a[4]))&&((a[2]+a[3]+a[4])==(a[0]+a[4]+a[5])) && flag==1 && i==5)       
		{ 
			
			for(i=0;i<6;i++)
			{
				printf("%3d",a[i]);
			}
			printf("\n");
		}
		if(i<5&&flag==1)           //当i没等于5时，说明没有装满a[6]数组
		{
			i++;
			a[i]=1;
            continue;
		}
		while(a[i]==6&&i>0)     //回溯点，往前回溯
		{
			i--;
		}
		if(a[i]==6&&i==0)      //当回溯到最后一个值为6时，全部回溯完成
		{
			break;
		}
		else
		{
			a[i]++;		//元素值加一 
		}
	}
	return 0;
}

