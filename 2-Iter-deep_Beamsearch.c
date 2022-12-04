#include <stdio.h>
#include <stdlib.h>
int visit[100];
void DFS(int n, int G[n][n], int d, int i, int width)
{
    int j;
    printf("%d->", i);
    visit[i] = 1;
    // printf("\nThe width is %d\n",width);13
    
    if (d == 0)
        return;
    int count = 0;
    for (j = 0; j < n; j++)
    {
        if(count==width)
            break;
        if (visit[j] != 1 && G[i][j] == 1 && d > 1)
        {
            DFS(n, G, d - 1, j, width+1);
            count++;
        }
    }
}
int main()
{
    int i, j, n, m, v1, v2, d, s, width=1;
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
        
            for (i = 0; i < n; i++)
                visit[i] = 0;
            // printf("\nWidth: %d\n",width);
            DFS(n, g, d, s, width);
    }
    return 0;
}
