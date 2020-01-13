#include<stdio.h>
#include<stdlib.h>
/*循环实现 二分查找 
int BinSearch(int a[],int key,int n)
{
	int low=0;
	int high=n-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==a[mid])
		{
			return mid+1;
		}
		
		if(key<a[mid])
		{
			high=mid-1;
		}
		if(key>a[mid])
		{
			low=mid+1;
		}
	}
	return -1;
 } 
 
 *///递归实现二分查找 
 int BinSearch(int a[], int key, int low, int high) {
	int i = low;	//索引的第一个下标 
	int j = high;	//索引的最后一个下标 
	int mid = (low + high)/2;
	if (i > j) {
		return -1;
	}
	if (key == a[mid]) {
		return mid+1;
	}
	else if (key > a[mid]) {
		return BinSearch(a, key, mid + 1 , j);
	}
	else {
		return BinSearch(a, key, i, mid - 1);
	}
	return -1;
}


 int main()
 {
 	int key;
 	int arr[]={1,2,4,5,6,7,8,9,10,11};
 	int n=sizeof(arr)/sizeof(arr[0])-1;
 	printf("请输入一个要查找的整数：");
	scanf ("%d",&key);
 	int tem=BinSearch(arr,key,0,n-1);
 	if(tem==-1)
 	{
 		printf("找不到%d！",key); 
	 }
	 else
	 {
	 	printf("找到了，%d在数组第%d个位置！",key,tem) ;
	 }
	 return 0;
	  
 }
