#include <stdio.h>
#define max 20
int stack[max];
int top = -1;
void push(int data) 
{
    if (top == max - 1) 
    {
        printf("Stack overflow\n");
    } 
    else 
    {
        stack[++top] = data;
    }
}
void pop(int m) 
{
    if(top == -1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            top--;
        }
    }
}
void display() 
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
    } 
    else 
    {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) 
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() 
{
    int n, m, data;
    printf("Enter number of elements to push: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &data);
        push(data);
    }
    printf("Enter number of elements to pop: ");
    scanf("%d", &m);
    pop(m);
    display();
    return 0;
}   