#include<stdio.h>
int main()
{
	int flag,k,i=0;		//flag����־ 
	int a[6];
	a[0]=1;
	printf("����˳���Ϊ��");
	while(1)
	{
		flag=1;
 
		for(k=i-1;k>=0;k--)    
		{
			if(a[i]==a[k])            //����Ƿ�����ֵͬ������g=0
			{
				flag=0;
				break;
			}
		}
		
		//�������������
		if(((a[0]+a[1]+a[2])==(a[2]+a[3]+a[4]))&&((a[2]+a[3]+a[4])==(a[0]+a[4]+a[5])) && flag==1 && i==5)       
		{ 
			
			for(i=0;i<6;i++)
			{
				printf("%3d",a[i]);
			}
			printf("\n");
		}
		if(i<5&&flag==1)           //��iû����5ʱ��˵��û��װ��a[6]����
		{
			i++;
			a[i]=1;
            continue;
		}
		while(a[i]==6&&i>0)     //���ݵ㣬��ǰ����
		{
			i--;
		}
		if(a[i]==6&&i==0)      //�����ݵ����һ��ֵΪ6ʱ��ȫ���������
		{
			break;
		}
		else
		{
			a[i]++;		//Ԫ��ֵ��һ 
		}
	}
	return 0;
}

