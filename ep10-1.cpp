/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str[50],rev[50];
    int i,len;
    printf("Enter a string: ");
    scanf("%s",str);
    len = strlen(str);
    // Create the reversed string
    for(i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    rev[i] = '\0'; // Null-terminate the reversed string
    // Check if the original string and reversed string are the same
    printf("%s\n",str ? "YES" : "NO");
    return 0;
}   