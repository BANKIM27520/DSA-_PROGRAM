/*Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array IN SORTED MANNER:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unique elements in the array are:\n");
    for(int i=0;i<n;i++)
    {
        if(i==0 || arr[i]!=arr[i-1])
        {
            printf("%d ",arr[i]);
        }
        else
        {
            continue;
        }
    }
}