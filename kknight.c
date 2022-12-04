#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int n, m, k;
int count = 1;
// int board[n][m];
void display(int **board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void attack(int i, int j, int a, int **board)
{
    if ((i + 2) < n && (j - 1) >= 0)
    {
        board[i + 2][j - 1] = a;
    }
    if ((i - 2) >= 0 && (j - 1) >= 0)
    {
        board[i - 2][j - 1] = a;
    }
    if ((i + 2) < n && (j + 1) < m)
    {
        board[i + 2][j + 1] = a;
    }
    if ((i - 2) >= 0 && (j + 1) < m)
    {
        board[i - 2][j + 1] = a;
    }
    if ((i + 1) < n && (j + 2) < m)
    {
        board[i + 1][j + 2] = a;
    }
    if ((i - 1) >= 0 && (j + 2) < m)
    {
        board[i - 1][j + 2] = a;
    }
    if ((i + 1) < n && (j - 2) >= 0)
    {
        board[i + 1][j - 2] = a;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0)
    {
        board[i - 1][j - 2] = a;
    }
}
int can(int i, int j, int **board)
{
    if (board[i][j] == 0)
        return 1;
    else
        return 0;
}
void place(int i, int j, int k, int a, int **board, int **newb)
{
    for (int y = 0; y < n; y++)
    {
        for (int z = 0; z < m; z++)
        {
            newb[y][z] = board[y][z];
        }
    }
    newb[i][j] = k;
    attack(i, j, a, newb);
}
void kkn(int k, int beg, int end, int **board)
{
    if (k == 0)
    {
        printf("solution\n");
        display(board);
        count++;
    }
    else
    {
        for (int i = beg; i < m; i++)
        {
            for (int j = end; j < n; j++)
            {
                if (can(i, j, board))
                {
                    int **newb = malloc(n * sizeof(int));
                    for (int x = 0; x < n; x++)
                    {
                        newb[x] = malloc(m * sizeof(int));
                    }
                        place(i, j, 1, 2, board, newb);
                        kkn(k - 1, i, j, newb);
                }
            }
            end = 0;
        }
    }
}
int main()
{
    struct timeval start, end;
    printf("Enter the dimensions of the board\n");
    scanf("%d%d", &n, &m);
    printf("Enter the number of knights to be placed\n");
    scanf("%d", &k);
    int **board = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        board[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = 0;
        }
    }
    gettimeofday(&start, NULL);
    kkn(k, 0, 0, board);
    gettimeofday(&end, NULL);
    long seconds = (end.tv_sec - start.tv_sec);
    long micro = end.tv_usec - start.tv_usec;
    long total = (seconds * 1000000) + micro;
    printf("Time taken by the program is %ld, seconds and total number f solutions is %d", total,count);
    return 0;
}
