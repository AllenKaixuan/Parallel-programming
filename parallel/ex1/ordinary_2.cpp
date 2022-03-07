#include <iostream>
#include <sys/time.h>
#include <math.h>
using namespace std;
void ordinary(long long int sum, int a[], long long int n)
{
    for (int i = 0; i < n; i += 2)
        sum += a[i] + a[i + 1];
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
            long long int n = round(pow(2, m));
            long long int sum = 0;
            int a[n];
            for (int i = 0; i < n; i++) //初始化
                a[i] = i * i + 1;

            struct timeval tv_begin, tv_end; //测量时间
            gettimeofday(&tv_begin, NULL);
            ordinary(sum, a, n);
            gettimeofday(&tv_end, NULL);

            diff = 1000000 * (tv_end.tv_sec - tv_begin.tv_sec) + (tv_end.tv_usec - tv_begin.tv_usec);
        }
        cout << round(pow(2, m)) << "  " << counter << "  " << diff / counter << "us" << endl;
    }
}