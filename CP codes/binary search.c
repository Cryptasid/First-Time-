#include <stdio.h>
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int target;
    int size =20;

    printf("Enter a number from 1-20 you would like to find\n");
    scanf("%d",&target);
    int low=0;
    int high= size-1;

    while(low<=high)
    {
        int i=(low+high)/2;
        if(arr[i]==target)
        {
            printf("Element found at index %d",i);
            return 0;
        }
        else if(arr[i]<target)
        {
            low= i+1;
        }
        else if(arr[i]>target)
        {
            high= i-1;
        }

    }
    printf("The searched index was not found\n");
    return 0;
}


