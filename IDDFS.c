#include <stdio.h>
#include <stdlib.h>
int visit[100];
void DFS(int n, int G[n][n], int d, int i)
{
    int j;
    printf("%d->", i);
    visit[i] = 1;
    for (j = 0; j < n; j++)
    {
        if (d == 0)
            return;
        if (visit[j] != 1 && G[i][j] == 1)
            DFS(n, G, d - 1, j);
    }
}
int main()
{
    int i, j, n, m, v1, v2, d, s;
    printf("Enter the number of nodes 'n' in the graph: ");
    scanf("%d", &n);
    printf("Enter the number of edges 'm' in the graph: ");
    scanf("%d", &m);
    int g[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            g[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++)
    {
        printf("Enter the vertices with edge in them: ");
        scanf("%d%d", &v1, &v2);
        g[v1][v2] = 1;
    }
    printf("\nEnter the starting index: ");
    scanf("%d", &s);
    printf("\nUsing IDDFS: ");
    for (d = 0; d < 4; d++)
    {
        for(i=0;i<n;i++)
        visit[i]=0;
        printf("\nThe depth: %d\t",d+1);
        DFS(n, g, d, s);
    }
    return 0;
}
