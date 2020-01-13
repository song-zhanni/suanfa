
/*	步骤： 
a. 先从数列中取出一个数作为基准数。

b. 分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。

c. 再对左右区间重复第二步，直到各区间只有一个数。
*/

#include<stdio.h>
#include<stdlib.h>
void display(int a[], int len)		//打印数组 
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%-3d",a[i]);
	}
	printf("\n");
	return ;		  	//终止函数 
}

void QiuckSort(int a[],int left,int right)		//一趟划分  left是原数组开始下标，right是结束下标 
{
	if(left<right)		//当开始下标等于结束下标，递归结束 
	{
		int key=a[left];		 //原数组第一个元素当基准值 
		int start=left;			//左边索引下标 
		int end=right;		//右边索引下标  
		int tem;		    //临时变量 

	while(start<end)		//外层循环，当low=high时，循环结束，完成一趟的数字交换
	{
		
		while( start<end && a[end]>=key )		// 从右向左找第一个小于tem的数
		{
			end--;		//end是要找比基准值小的数，当a[high]大于基准值的是，向左移动，所以high-- 
		}
		if(a[end]<key)		//如果那个值小于基准值，交换两个数在数组中的位置 
		{
			tem=a[end];
			a[end]=a[start];
			a[start]=tem;
			///low是要找比基准值大的数，当a[low]小于基准值时，向右移动，所以low++ 
		}
		while(start<end && a[start]<key)		// 从左向右找第一个大于等于key的数
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
	
	//将基准值归位 
	//a[low]=a[d];
	//a[d]=tem;
	
	//递归调用 
	QiuckSort(a,left,start-1);			//继续排序前半部分 ,第一个索引位置到关键值索引-1
	QiuckSort(a,start+1,right);			//继续排后半部分 ,从关键值索引+1到最后一个
	
	}
}
int main()
{
	
	int arr[]={6,88,5,8,99,69,36,45,14,25};
	int len = (sizeof(arr)/sizeof(arr[0]));
	int i;
	printf("排序前的数组：\n");
	display(arr,len);
	QiuckSort(arr,0,len-1);
	printf("排序后的数组：\n");
	display(arr,len);
	return 0;
 } 
