/*Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3*/

#include<stdio.h>
int main()
{
    int n,key,mid,l,h;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array IN ASCENDING ORDER:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("ENTER THE ELEMENT TO BE SEARCHED:");
    scanf("%d",&key);
    mid=n/2;
    l=0;
    h=n-1;
    while(l<=h)
    {
        if(arr[mid]==key)
        {
            printf("Element found at position %d",mid);
            printf("COMPARISON=%d",mid+1);
            return 0;
        }
        else if(arr[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
        mid=(l+h)/2;
    }
    printf("Element not found in the array.");
    return 0;
}