/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces
*/
#include<stdio.h>
int main() {
    int r, c;
    int mat[100][100];
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int j = left; j <= right; j++) {
            printf("%d ", mat[top][j]);
        }
        top++;
        
        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++) {
            printf("%d ", mat[i][right]);
        }
        right--;
        
        if (top <= bottom) {
            // Traverse from right to left
            for (int j = right; j >= left; j--) {
                printf("%d ", mat[bottom][j]);
            }
            bottom--;
        }
        
        if (left <= right) {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; i--) {
                printf("%d ", mat[i][left]);
            }
            left++;
        }
    }
    
    printf("\n");
    return 0;
}