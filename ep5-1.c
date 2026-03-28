/*A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70
*/
#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter the number of elements in the 1 array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array IN SORTED MANNER:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the number of elements in the 2 array: ");
    scanf("%d",&m);
    int arr2[m];
    printf("Enter the elements of the 2nd array IN SORTED MANNER:");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }
    int new_arr[n+m];
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(arr[i]<arr2[j])
        {
            new_arr[k++]=arr[i++];
        }
        else
        {
            new_arr[k++]=arr2[j++];
        }
    }
    while(i<n)
    {
        new_arr[k++]=arr[i++];
    }
    while(j<m)
    {
        new_arr[k++]=arr2[j++];
    }
    printf("Merged array is:\n");
    for(int i=0;i<n+m;i++)
    {
        printf("%d ",new_arr[i]);
    }
}