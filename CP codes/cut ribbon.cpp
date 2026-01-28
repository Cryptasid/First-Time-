#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[3];
    for(int i=0;i<3;i++)
    {
        cin>>arr[i];
    }
    int max=0;
    int i=0;
    while(i<=n/arr[0])
    {
       int j = 0;
        while(i*arr[0]+j*arr[1]<=n)
        {
            int rest=n-(i*arr[0]+j*arr[1]);
            if(rest%arr[2]==0)
            {
                int k=rest/arr[2];
                int total = i + j + k;
                if(total>max)
                    max=total;
            }
        j++;
        }
        i++;
    }

    cout<<max<<endl;
    return 0;
}

