#include <stdio.h>
int board[3][3];
int d = -9999, comp = 1, me = 2;
void display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == d)
            {
                printf("_ ");
            }
            else if (board[i][j] == 10) // x
            {
                printf("X ");
            }
            else if (board[i][j] == 20) // 0
            {
                printf("O ");
            }
        }
        printf("\n");
    }
}
int poswin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != d)
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != d)
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != d)
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != d)
        return 1;
    return 0;
}
int minimax(int depth, int com)
{
    int score = 0;
    int best = 0;
    if (poswin() == 1)
    {
        if (com == 1)
            return -1;
        if (com != 0)
            return +1;
    }
    else
    {
        if (depth < 9)
        {
            if (com == 1)
            {
                best = -9999;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == d)
                        {
                            board[i][j] = 20;
                            score = minimax(depth + 1, 0);
                            board[i][j] = d;
                            if (score > best)
                            {
                                best = score;
                            }
                        }
                    }
                }
                return best;
            }
            else
            {
                best = -d;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == d)
                        {
                            board[i][j] = 10;
                            score = minimax(depth + 1, 1);
                            board[i][j] = d;
                            if (score < best)
                            {
                                best = score;
                            }
                        }
                    }
                }
                return best;
            }
        }
        else
        {
            return 0;
        }
    }
}
int best(int index)
{
    int x = -1, y = -1;
    int score = 0, best = d;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == d)
            {
                board[i][j] = 20;
                score = minimax(index + 1, 0);
                board[i][j] = d;
                if (score > best)
                {
                    best = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}
void playTicTacToe(int who)
{
    int index = 0, x = 0, y = 0;
    while (!poswin() && index != 9)
    {
        int n;
        if (who == comp)
        {
            n = best(index);
            x = n / 3;
            y = n % 3;
            board[x][y] = 20;
            printf("\nAfter computer move:\n");
            display();
            index++;
            who = 2;
        }
        else if (who == me)
        {
            printf("\nEnter the position:\n");
            scanf("%d", &n);
            n--;
            x = n / 3;
            y = n % 3;
            if (board[x][y] == d && n < 9 && n >= 0)
            {
                board[x][y] = 10;
                display();
                index++;
                who = 1;
            }
            else if (n < 0 || n > 8)
            {
                printf("Position Invalid\n");
            }
            else if (board[x][y] != d && n < 9 && n >= 0)
            {
                printf("\nPosition Unavailable\n");
            }
        }
    }
    if (poswin() != 1 && index == 9)
    {
        printf("Draw\n");
    }
    else
    {
        if (who == comp)
        {
            printf("YOU WON\n");
        }
        else if (who == me)
        {
            printf("COMPUTER WON\n");
        }
    }
}

int main()
{
    int whose;
    printf("Enter 1 to get first turn else enter 2:\n");
    scanf("%d", &whose);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = d;
    }
    if (whose == 2) // comp move
    {
        playTicTacToe(comp);
    }
    else if (whose == 1) // me move
    {
        playTicTacToe(me);
    }
    else
    {
        printf("Invalid choice\n");
    }
    return 0;
}
