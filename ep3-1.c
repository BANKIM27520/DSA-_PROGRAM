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
    int n,key;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d space-separated integers: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d",&key);
    int c=0;
    int f=0;
    for(int i=0;i<n;i++)
    {
        c++;
        if(arr[i]==key)
        {
            f=1;
            break;
        }
        else
        {
            continue;
        }
    }
    if(f==1)
    {
        printf("Found at index=%d\n",c-1);
        printf("Comparisons=%d\n",c);
    }
    else
    {
        printf("Not Found\n");
    }
    return 0;       
}    