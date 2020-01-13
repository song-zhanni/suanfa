
/*	���裺 
a. �ȴ�������ȡ��һ������Ϊ��׼����

b. �������̣���������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�

c. �ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������
*/

#include<stdio.h>
#include<stdlib.h>
void display(int a[], int len)		//��ӡ���� 
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%-3d",a[i]);
	}
	printf("\n");
	return ;		  	//��ֹ���� 
}

void QiuckSort(int a[],int left,int right)		//һ�˻���  left��ԭ���鿪ʼ�±꣬right�ǽ����±� 
{
	if(left<right)		//����ʼ�±���ڽ����±꣬�ݹ���� 
	{
		int key=a[left];		 //ԭ�����һ��Ԫ�ص���׼ֵ 
		int start=left;			//��������±� 
		int end=right;		//�ұ������±�  
		int tem;		    //��ʱ���� 

	while(start<end)		//���ѭ������low=highʱ��ѭ�����������һ�˵����ֽ���
	{
		
		while( start<end && a[end]>=key )		// ���������ҵ�һ��С��tem����
		{
			end--;		//end��Ҫ�ұȻ�׼ֵС��������a[high]���ڻ�׼ֵ���ǣ������ƶ�������high-- 
		}
		if(a[end]<key)		//����Ǹ�ֵС�ڻ�׼ֵ�������������������е�λ�� 
		{
			tem=a[end];
			a[end]=a[start];
			a[start]=tem;
			///low��Ҫ�ұȻ�׼ֵ���������a[low]С�ڻ�׼ֵʱ�������ƶ�������low++ 
		}
		while(start<end && a[start]<key)		// ���������ҵ�һ�����ڵ���key����
		{
			start++;
		}
		if(start<end)
		{
			tem=a[start];
			a[start]=a[end];
			a[end]=tem;
		}
	}
	
	//����׼ֵ��λ 
	//a[low]=a[d];
	//a[d]=tem;
	
	//�ݹ���� 
	QiuckSort(a,left,start-1);			//��������ǰ�벿�� ,��һ������λ�õ��ؼ�ֵ����-1
	QiuckSort(a,start+1,right);			//�����ź�벿�� ,�ӹؼ�ֵ����+1�����һ��
	
	}
}
int main()
{
	
	int arr[]={6,88,5,8,99,69,36,45,14,25};
	int len = (sizeof(arr)/sizeof(arr[0]));
	int i;
	printf("����ǰ�����飺\n");
	display(arr,len);
	QiuckSort(arr,0,len-1);
	printf("���������飺\n");
	display(arr,len);
	return 0;
 } 
