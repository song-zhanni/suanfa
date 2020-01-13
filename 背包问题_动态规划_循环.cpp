#include <iostream>
using namespace std;
#define V 500
#define N 20
	int weight[N + 1];	//��¼��Ʒ���� 
    int value[N + 1];		//��¼��Ʒ��ֵ
    int f[N + 1][V + 1];	//��¼�����ܷŵ�����ֵ
    int main()
    {
        int n, m;	// n--��Ʒ����  m--�������� 
        cout << "��������Ʒ����:";
        cin >> n;
        cout << "��ֱ�����" << n << "����Ʒ�������ͼ�ֵ:" << endl;
        for (int i = 1; i <= n; i++)
        {
            cin >> weight[i] >> value[i];
        }
        cout << "�����뱳������:";
        cin >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (weight[i] > j)
                {
                    f[i][j] = f[i - 1][j];  // ��ʼ�����ٶ������Ų��µ�ǰ��һ����Ʒ
                }
                else
                {
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        cout << "�����ܷŵ�����ֵΪ:" << f[n][m] << endl;
        return 0;

    }
