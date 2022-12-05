#include <stdio.h>
#include <stdlib.h>
int *N;
int Fibonacci (int n)
{
    if (N[n] != -1)
        return N[n];
    N[n] = Fibonacci (n - 1) + Fibonacci (n - 2);
    return N[n];
}
int main()
{
    int n;
    printf("Give me a n:");
    scanf("%d", &n);
    // 初始化
    N = (int *)malloc(n * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        N[i] = -1;
    }
    N[0] = 0;
    N[1] = 1;
    putchar('\n');
    int result = Fibonacci (n);
    printf("%d", result);
    // free(N);
    return 0;
}
