#include<iostream>
#include<sys/time.h>
using namespace std;



void ordinary(int*a,int **b,int*sum){

    for(int i=0;i<1000;i++){    //��������ƽ���˷�
       
        for (int j = 0; j < 1000; j++)     
            sum[i]=b[j][i]*a[j];   
    }
}
int main(){
    int a[1000];
    for (int i = 0; i < 1000; i++) //��ʼ������
        a[i]=2*i+1;
    int **b=new int* [1000];
    for (int i = 0; i < 1000; i++) //�������ռ�
        b[i]=new int[1000];

    int sum[1000];                //�������ռ�
    for (int i = 0; i < 1000; i++)
         sum[i]=0;

    for(int i=0;i<1000;i++){       //��ʼ������
        for(int j=0;j<1000;j++)
            b[i][j]=i+j;
    }
   
    struct timeval tv_begin,tv_end; //����ʱ��
    gettimeofday(&tv_begin,NULL);
    ordinary(a,b,sum);
    gettimeofday(&tv_end,NULL);
    unsigned long int diff;
    diff=1000000 * (tv_end.tv_sec-tv_begin.tv_sec)+ tv_end.tv_usec-tv_begin.tv_usec;
    cout<<diff<<"us"<<endl;
   
}