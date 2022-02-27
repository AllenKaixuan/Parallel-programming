#include<iostream>
#include<sys/time.h>
using namespace std;



void optimize(int*a,int **b,int*sum){
      
    for(int i=0;i<1000;i++){    //矩阵向量优化乘法，每次向每个内积积累一个值
        for (int j = 0; j < 1000; j++)        
             sum[i]=b[i][j]*a[i];      
    }
}
int main(){
    int a[1000];
    for (int i = 0; i < 1000; i++) //初始化向量
        a[i]=2*i+1;
    int **b=new int* [1000];
    for (int i = 0; i < 1000; i++) //分配矩阵空间
        b[i]=new int[1000];
    
    int sum[1000];
    for (int i = 0; i < 1000; i++)  //分配结果空间
        sum[i]=0;

    for(int i=0;i<1000;i++){       //初始化矩阵
        for(int j=0;j<1000;j++)
            b[i][j]=i+j;
    }
   
    struct timeval tv_begin,tv_end; //测量时间
    gettimeofday(&tv_begin,NULL);
    optimize(a,b,sum);
    gettimeofday(&tv_end,NULL);
    unsigned long int diff;
    diff=1000000 * (tv_end.tv_sec-tv_begin.tv_sec)+ tv_end.tv_usec-tv_begin.tv_usec;
    cout<<diff<<"us"<<endl;
   
}