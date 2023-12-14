#include<iostream>
using namespace std;

void TOH(int n,char a,char b,char c,int &cnt)
{
    if(n==0)
    return;

    
    TOH(n-1,a,c,b,cnt);
    cnt++;
    cout<<"step:"<<cnt<<" Move Disc from "<<a<<" to "<<b<<endl;
    TOH(n-1,c,b,a,cnt);
}
int main()
{
    int cnt=0;
  TOH(3,'A','B','C',cnt);
    return 0;
}