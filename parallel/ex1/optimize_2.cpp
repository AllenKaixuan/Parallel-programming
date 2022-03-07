#include <iostream>
#include <sys/time.h>
#include <math.h>
using namespace std;
void optimize(long int a, long int b,  int *l, long long int n)
{
    for (int i = 0; i < n; i += 4)
    {
        a += l[i] + l[i + 1];
        b += l[i + 2] + l[i + 3];
        // c += l[i + 4] + l[i + 5];
        // d += l[i + 6] + l[i + 7];
    }
      
}


int main()
{
    for (int m = 15; m < 20; m++)
    {
        double diff = 0;
        int counter = 0;
        while (diff < 300)
        {
            counter++;
            long long int n = round(pow(2, m)), sum = 0;
            long int sum_0 = 0, sum_1 = 0, sum_2 = 0, sum_3 = 0;

            int a[n];
           
            for (int i = 0; i < n; i++) //初始化
                a[i] = i * i + 1;
            struct timeval tv_begin, tv_end; //测量时间
            gettimeofday(&tv_begin, NULL);
            optimize(sum_0, sum_1, a, n);
            sum = sum_0 + sum_1 ;
            gettimeofday(&tv_end, NULL);

            diff += 1000000 * (tv_end.tv_sec - tv_begin.tv_sec) + (tv_end.tv_usec - tv_begin.tv_usec);
        }
        cout << round(pow(2, m)) << "  " << counter << "  " << diff / counter << "us" << endl;
    }
}