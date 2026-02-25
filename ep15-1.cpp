/*Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements
*/
#include <stdio.h>
int main() {
    int m, n;
    int mat[100][100];
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int sum = 0;
    for (int i = 0; i < m && i < n; i++) {
        sum += mat[i][i];
    }
    
    printf("%d\n", sum);
    return 0;
}