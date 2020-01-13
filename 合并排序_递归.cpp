#include <stdio.h>
#include <stdlib.h>
#define N 7

void merge(int arr[], int low, int mid, int high)
{
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));//建立临时数组存放数据 
    int left_low = low; //左序列的左指针 
    int left_high = mid;//左序列的右指针 
    int right_low = mid + 1;//右。。。左指针 
    int right_high = high;
    
	//将分割的序列移入临时数组 
    for(k=0; left_low<=left_high && right_low<=right_high; k++)
	{  // 比较两个指针所指向的元素大小 
        if(arr[left_low]<=arr[right_low])
		{// 右序列的左指针所指的值 大于 左序列的左指针的 
            tmp[k] = arr[left_low++];//小的那个值移入临时数组， 指针右移 
        }
		else	// 右序列的左指针所指的值 小于 左序列的左指针的 
		{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high)
	{  //若第一个序列有剩余，直接复制出来粘到合并序列尾
       for(i=left_low;i<=left_high;i++)
       { 
        tmp[k++] = arr[i];
        } 
    }

    if(right_low <= right_high)
	{//若第二个序列有剩余，直接复制出来粘到合并序列尾
        for(i=right_low; i<=right_high; i++)
        { 
            tmp[k++] = arr[i];
        } 
    }

    for(i=0; i<high-low+1; i++)//将临时数组的数移回原来数组 
    { 
        arr[low+i] = tmp[i];
    } 
    free(tmp);
    return;
}

void merge_sort(int arr[], unsigned int first, unsigned int last){
    //int mid = 0;
    if(first<last)//数组元素个数大于2
	{
       int mid = (first+last)/2; /* 注意防止溢出 */
        merge_sort(arr, first, mid);//分割 
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);//合并 
    }
    return;
}

int main(){
    int i;
    int a[N]={32,12,56,78,76,45,36};

    printf ("排序前 \n");
    for(i=0;i<N;i++)
        printf("%d\t",a[i]);
    printf("\n"); 

    merge_sort(a,0,N-1);  

    printf ("\n排序后 \n");
    for(i=0;i<N;i++)
    { 
        printf("%d\t",a[i]);
	} 
	printf("\n");
    return 0;
}

