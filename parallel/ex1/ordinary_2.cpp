#include<iostream>
#include<sys/time.h>
#include<math.h>
using namespace std;
void ordinary(long long int sum,int a[],long long int n){
    for (int i = 0; i < n; i++)    
        sum+=a[i];
      
}
int main(){
    
    
    long long int n= round(pow(2,20));
    long long int sum=0;
    int a[n];                
    for (int i = 0; i < n; i++) //初始化
         a[i]=i*i+1;
   
    struct timeval tv_begin,tv_end; //测量时间
    gettimeofday(&tv_begin,NULL);
    ordinary(sum,a,n);
    gettimeofday(&tv_end,NULL);
    unsigned long int diff;
    diff=1000000 * (tv_end.tv_sec-tv_begin.tv_sec)+ tv_end.tv_usec-tv_begin.tv_usec;
    cout<<diff<<"us"<<endl;
   
}