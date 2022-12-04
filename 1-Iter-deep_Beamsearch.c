#include <stdio.h>
#include <stdlib.h>
int visit[100];
void DFS(int n, int G[n][n], int d, int i, int width)
{
    int j;
    printf("%d->", i);
    visit[i] = 1;

    if (d == 0)
        return;
    int count = 0;
    for (j = 0; j < n; j++)
    {

        if (visit[j] != 1 && G[i][j] == 1 && d > 1)
        {
            DFS(n, G, d - 1, j, width);
            count++;
        }
        if(count==width)
            break;
    }
}
int main()
{
    int i, j, n, m, v1, v2, d, s, w;
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
    for (d = 1; d < 6; d++)
    {
        printf("\n\nThe depth %d: \n",d);
        for (w = 1; w < 4; w++)
        {
            for (i = 0; i < n; i++)
                visit[i] = 0;
            printf("\nWidth: %d\n",w);
            DFS(n, g, d, s, w);
        }
    }
    return 0;
}
