/*˼�����ѡ������ľ����ٲ�ˮ��Ҳ����˵ʣ���ˮ�����Ե�����һ��������ʱ�Ͳ�ˮ������Ͳ���ˮ��*/

#include<iostream>
using namespace std;

int tx(int a[],int n,int k)	//����a�д��n������ˮ�ص�ľ���
{	int i,j,s=0;  //sΪ����һ��ˮ���е���Զ����
	int sum=0;	//����ˮ����
	for (j=0;j<n;j++)
		if (a[j]>k)		//���ڲ�����ľ��볬���ںȹ�ˮǰ�ܻ��еľ��룬���˳�
			return -1;

	printf(" �ڵ�");
	for (i=0;i<n;i++)
	{	s=s+a[i];
		if (s>k)
		{	sum++;		//����ˮ������1
		    printf("%d  ",i);
			s=a[i];
		}
	}
	printf("����ˮ�ص㲹��ˮ��!\n");
	return sum;
}

int main() {
	int i,n,k,a[10];
	cout<<"�������ںȹ�ˮǰ�ܻ��еľ��루KM���� "; 
	cin>>n;
	cout<<"������;�������Ĳ���ˮ�ĵص������ ";
	cin>>k;
	cout<<"������ÿ������������ˮ��֮��ľ��룺 "<<endl;
	for(i=0;i<k;i++)   cin>>a[i];
	printf("������%d��ˮ\n",tx(a,n,k));
	return 0;

}


