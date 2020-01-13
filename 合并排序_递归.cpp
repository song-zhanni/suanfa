#include <stdio.h>
#include <stdlib.h>
#define N 7

void merge(int arr[], int low, int mid, int high)
{
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));//������ʱ���������� 
    int left_low = low; //�����е���ָ�� 
    int left_high = mid;//�����е���ָ�� 
    int right_low = mid + 1;//�ҡ�������ָ�� 
    int right_high = high;
    
	//���ָ������������ʱ���� 
    for(k=0; left_low<=left_high && right_low<=right_high; k++)
	{  // �Ƚ�����ָ����ָ���Ԫ�ش�С 
        if(arr[left_low]<=arr[right_low])
		{// �����е���ָ����ָ��ֵ ���� �����е���ָ��� 
            tmp[k] = arr[left_low++];//С���Ǹ�ֵ������ʱ���飬 ָ������ 
        }
		else	// �����е���ָ����ָ��ֵ С�� �����е���ָ��� 
		{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high)
	{  //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
       for(i=left_low;i<=left_high;i++)
       { 
        tmp[k++] = arr[i];
        } 
    }

    if(right_low <= right_high)
	{//���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
        for(i=right_low; i<=right_high; i++)
        { 
            tmp[k++] = arr[i];
        } 
    }

    for(i=0; i<high-low+1; i++)//����ʱ��������ƻ�ԭ������ 
    { 
        arr[low+i] = tmp[i];
    } 
    free(tmp);
    return;
}

void merge_sort(int arr[], unsigned int first, unsigned int last){
    //int mid = 0;
    if(first<last)//����Ԫ�ظ�������2
	{
       int mid = (first+last)/2; /* ע���ֹ��� */
        merge_sort(arr, first, mid);//�ָ� 
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);//�ϲ� 
    }
    return;
}

int main(){
    int i;
    int a[N]={32,12,56,78,76,45,36};

    printf ("����ǰ \n");
    for(i=0;i<N;i++)
        printf("%d\t",a[i]);
    printf("\n"); 

    merge_sort(a,0,N-1);  

    printf ("\n����� \n");
    for(i=0;i<N;i++)
    { 
        printf("%d\t",a[i]);
	} 
	printf("\n");
    return 0;
}

