#include <iostream>
#include <sys/time.h>
using namespace std;

void ordinary(int *a, int **b, int *sum, int n)
{

    for (int i = 0; i < n; i++)
    { //矩阵向量平凡乘法

        for (int j = 0; j < n; j++)
            sum[i] = b[j][i] * a[j];
    }
}
int main()
{
    for (int n = 1000; n <= 5000; n += 1000)
    {
        int counter = 0;
        double diff = 0;
        while (diff < 300)
        {
            counter++;
            int a[n];
            for (int i = 0; i < n; i++) //初始化向量
                a[i] = 2 * i + 1;
            int **b = new int *[n];
            for (int i = 0; i < n; i++) //分配矩阵空间
                b[i] = new int[n];

            int sum[n]; //分配结果空间
            for (int i = 0; i < n; i++)
                sum[i] = 0;

            for (int i = 0; i < n; i++)
            { //初始化矩阵
                for (int j = 0; j < n; j++)
                    b[i][j] += i + j;
            }

            struct timeval tv_begin, tv_end; //测量时间

            gettimeofday(&tv_begin, NULL);
            ordinary(a, b, sum, n);
            gettimeofday(&tv_end, NULL);
           
            diff += 1000 * (tv_end.tv_sec - tv_begin.tv_sec) + (tv_end.tv_usec - tv_begin.tv_usec) / 1000;
        }
        cout << n << "  " <<counter<<"  "<< diff/counter << "ms" << endl;
    }
}