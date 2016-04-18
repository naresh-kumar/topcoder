// https://www.codechef.com/INSOM2/status/INSOMB2,nemausus
// https://www.codechef.com/viewplaintext/12837
#include<iostream>
#include<fstream>

using namespace std;
int main()
{
    int flag[4]={1,1,1,1};
    char a[4][13];

    for(int i=0;i<4;i++)
    for(int j=0;j<13;j++)
    {
            cin>>a[i][j];
            cin>>a[i][j];
    }

    char top='t';
    int p=0,q=0,r=0,s=0,breaker=0,tcard=52,remain;
    while(breaker<3)
    {
           if(p<13 && flag[0]==1)
           {

                   p++;tcard--;
                   if (top==a[0][p-1])
                   flag[0]=0;
                   top=a[0][p-1];
                   if(p==13)
                   {
                   cout<<'P';
                   breaker++;}
           }
           else
           flag[0]=1;
           if(breaker==3)
           break;

           if(q<13 && flag[1]==1)
           {

                   q++;tcard--;
                   if (top==a[1][q-1])
                   flag[1]=0;
                   top=a[1][q-1];
                   if(q==13)
                   {cout<<'U';
                   breaker++;}

           }
           else
           flag[1]=1;
           if(breaker==3)
           break;

           if(r<13 && flag[2]==1)
           {

                   r++;tcard--;
                   if (top==a[2][r-1])
                   flag[2]=0;
                   top=a[2][r-1];
                   if(r==13)
                   {cout<<'V';
                   breaker++;}
           }
           else
           flag[2]=1;
           if(breaker==3)
           break;

           if (s<13 && flag[3]==1)
           {

                   s++;tcard--;
                   if (top==a[3][s-1])
                   flag[3]=0;
                   top=a[3][s-1];
                   if(s==13)
                   {cout<<'J';
                   breaker++;}
                   }
           else
           flag[3]=1;
           if(breaker==3)
           break;

    }

    if(p<13)
    cout<<'P';
    else if(q<13)
    cout<<'U';
    else if(r<13)
    cout<<'V';
    else
    cout<<'J';

    cout<<' ' <<tcard;

    return 0;
}
