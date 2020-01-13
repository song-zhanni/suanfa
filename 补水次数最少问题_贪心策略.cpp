/*思想就是选择走最长的距离再补水，也就是说剩余的水不足以到达下一个补给点时就补水，否则就不补水。*/

#include<iostream>
using namespace std;

int tx(int a[],int n,int k)	//数组a中存放n个补充水地点的距离
{	int i,j,s=0;  //s为补充一次水滑行的最远距离
	int sum=0;	//补充水次数
	for (j=0;j<n;j++)
		if (a[j]>k)		//相邻补给点的距离超过在喝光水前能滑行的距离，就退出
			return -1;

	printf(" 在第");
	for (i=0;i<n;i++)
	{	s=s+a[i];
		if (s>k)
		{	sum++;		//补充水次数加1
		    printf("%d  ",i);
			s=a[i];
		}
	}
	printf("补充水地点补充水了!\n");
	return sum;
}

int main() {
	int i,n,k,a[10];
	cout<<"请输入在喝光水前能滑行的距离（KM）： "; 
	cin>>n;
	cout<<"请输入途中所经的补充水的地点个数： ";
	cin>>k;
	cout<<"请输入每相邻两个补充水地之间的距离： "<<endl;
	for(i=0;i<k;i++)   cin>>a[i];
	printf("共补充%d次水\n",tx(a,n,k));
	return 0;

}


