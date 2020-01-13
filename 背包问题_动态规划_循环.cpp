#include <iostream>
using namespace std;
#define V 500
#define N 20
	int weight[N + 1];	//记录物品重量 
    int value[N + 1];		//记录物品价值
    int f[N + 1][V + 1];	//记录背包能放的最大价值
    int main()
    {
        int n, m;	// n--物品件数  m--背包容量 
        cout << "请输入物品个数:";
        cin >> n;
        cout << "请分别输入" << n << "个物品的重量和价值:" << endl;
        for (int i = 1; i <= n; i++)
        {
            cin >> weight[i] >> value[i];
        }
        cout << "请输入背包容量:";
        cin >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (weight[i] > j)
                {
                    f[i][j] = f[i - 1][j];  // 初始化，假定背包放不下当前这一件物品
                }
                else
                {
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        cout << "背包能放的最大价值为:" << f[n][m] << endl;
        return 0;

    }
