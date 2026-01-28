#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p1,p2,p3,t1,t2;
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    int t=n;
    int temp=0;
    int p1pow=0,p2pow=0,p3pow=0;

    int restTime;
    int total;
    while(t--)
    {
       int a,b;
       cin>>a>>b;

       p1pow+=(b-a);
       if(t<n-1)
       {
           restTime=(a-temp);

        if(restTime<=t1)
        {
            p1pow+=restTime;
        }
        else if(restTime<t1+t2)
        {

            p1pow+=t1;

            p2pow+=(restTime-t1);

        }
        else
        {

            p1pow+=t1;
            p2pow+=t2;
            p3pow+=(restTime-(t1+t2));

        }
     }


       temp=b;

    }
    total=(p1pow*p1)+(p2pow*p2)+(p3pow*p3);
    cout<<total<<endl;
    return 0;
}
