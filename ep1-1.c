/*Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated*/
#include<stdio.h>
int main()
{
    int a,n,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n],new_arr[n+1];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("ENTER THE ELEMENT TO BE ENTERED:");
    scanf("%d",&a);
    printf("ENTER THE POSITION ON WHICH THE ELEMENT IS TO BE ENTERED:");
    scanf("%d",&pos);
    for(int i=0;i<pos-1;i++)
    {
        new_arr[i]=arr[i];
    }
    new_arr[pos-1]=a;
    for(int i=pos-1;i<n;i++)
    {
        new_arr[i+1]=arr[i];
    }
    printf("The new array is: ");
    for(int i=0;i<n+1;i++)
    {
        printf("%d ",new_arr[i]);
    }
}