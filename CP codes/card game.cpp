#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }
    int sereja=0, dima=0;
    int front=0;
    int back=n-1;
    for(int j=0; front<=back; j++)
    {

        if(j==0 || j%2==0)
        {
            if(arr[front]>=arr[back])
            {
                sereja+=arr[front];
                        front++;
            }
            else if(arr[back]>=arr[front])
        {
            sereja+=arr[back];
                back--;
            }
        }
        else
        {
            if(arr[front]>=arr[back])
            {
                dima+=arr[front];
                      front++;
            }
            else if(arr[back]>=arr[front])
        {
            dima+=arr[back];
                back--;
            }
        }

    }
    cout<<sereja<<" "<<dima<<endl;
    return 0;
}
