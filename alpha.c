#include <stdio.h>
int d = 99999, comp = 1, me = 2,count=0;
char board[3][3];
void showBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void initialise()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    }
}
int won()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}
int minimax(int depth, int isAI, int alpha, int beta)
{
    int score = 0;
    int bestScore = 0;
    if (won(board) == 1)
    {
        if (isAI == 1)
            return -1;
        if (isAI == 0)
            return +1;
    }
    else
    {
        if (depth < 9)
        {
            if (isAI == 1)
            {
                bestScore = -d;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = 'O';
                            score = minimax(depth + 1, 0, alpha, beta);
                            count++;
                            board[i][j] = ' ';
                            bestScore = (score > bestScore) ? score : bestScore;
                            alpha = (alpha > bestScore) ? alpha : bestScore;
                            if (beta <= alpha)
                                break;
                            // bestScore = (score > bestScore) ? score : bestScore;
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 9999;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (board[i][j] == ' ')
                        {
                            board[i][j] = 'X';
                            score = minimax(depth + 1, 1, -beta, -alpha);
                            count++;
                            board[i][j] = ' ';
                            bestScore = (score < bestScore) ? score : bestScore;
                            beta = (beta < bestScore) ? beta : bestScore;
                            if (beta <= alpha)
                                break;
                            // bestScore = (score < bestScore) ? score : bestScore;
                        }
                    }
                }
                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
}
int bestMove(int moveIndex)
{
    int x = -1, y = -1;
    int score = 0, bestScore = -d;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                score = minimax(moveIndex + 1, 0, -d, d);
                count++;
                board[i][j] = ' ';
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}
void playTicTacToe(int whoseTurn)
{
    int moveIndex = 0, x = 0, y = 0;
    while (!won(board) && moveIndex != 9)
    {
        int n;
        if (whoseTurn == comp)
        {
            n = bestMove(moveIndex);
            x = n / 3;
            y = n % 3;
            board[x][y] = 'O';
            printf("after computer move:\n");
            showBoard();
            moveIndex++;
            whoseTurn = me;
        }
        else if (whoseTurn == me)
        {
            printf("Enter the position where you want to put your move: ");
            scanf("%d", &n);
            n--;
            x = n / 3;
            y = n % 3;
            if (board[x][y] == ' ' && n < 9 && n >= 0)
            {
                board[x][y] = 'X';
                showBoard();
                moveIndex++;
                whoseTurn = comp;
            }
            else if (board[x][y] != ' ' && n < 9 && n >= 0)
            {
                printf("Postion not available\n");
            }
            else if (n < 0 || n > 8)
            {
                printf("Position invalid\n");
            }
        }
    }
    if (won(board) == 0 && moveIndex == 9)
    {
        printf("DRAW!\n");
    }
    else
    {
        if (whoseTurn == comp)
        {
            printf("You Won!\n");
        }
        else if (whoseTurn == me)
        {
            printf("Computer won\n");
        }
    }
}
int main()
{
    int whose;
    printf("Enter 1 to get first turn else enter 2:\n");
    scanf("%d", &whose);
    initialise(board);
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
    printf("The count is %d", count);
    return 0;
}
