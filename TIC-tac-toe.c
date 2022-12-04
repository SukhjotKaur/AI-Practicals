#include <bits/stdc++.h>
using namespace std;
int board[10],turn=1;
void display()
{
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 2)
        {
            cout << "_ ";
        }
        if (board[i] == 3)
        {
            cout << "X ";
        }
        if (board[i] == 5)
        {
            cout << "O ";
        }
        if (i % 3 == 0)
        {
            cout << endl;
        }
    }
}
int poswin2(int num)
{
        if (board[1] * board[2] * board[3] == num * num * num)
        {
            return num * num * num;
        }
        if (board[4] * board[5] * board[6] == num * num * num)
        {
            return num * num * num;
        }
        if (board[7] * board[8] * board[9] == num * num * num)
        {
            return num * num * num;
        }
        
        if (board[1] * board[4] * board[7] == num * num * num)
        {
            return num * num * num;
        }
        
        if (board[5] * board[2] * board[8] == num * num * num)
        {
            return num * num * num;
        }
        
        if (board[6] * board[9] * board[3] == num * num * num)
        {
            return num * num * num;
        }
        
        if (board[1] * board[5] * board[9] == num * num * num)
        {
            return num * num * num;
        }
        
        if (board[5] * board[7] * board[3] == num * num * num)
        {
            return num * num * num;
        }
}
int poswin(int num)
{
    int i;
    if (board[1] * board[2] * board[3] == num * num * 2)
    {
        for (i = 1; i < 4; i++)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
    }
    else if (board[4] * board[5] * board[6] == num * num * 2)
    {
        for (i = 4; i < 7; i++)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
    }
    else if (board[7] * board[8] * board[9] == num * num * 2)
    {
        for (i = 7; i < 10; i++)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
    }
    else if (board[1] * board[4] * board[7] == num * num * 2)
    {
        if (board[1] == 2)
            return 1;
        else if (board[4] == 2)
            return 4;
        else if (board[7] == 2)
            return 7;
    }
    else if (board[2] * board[5] * board[8] == num * num * 2)
    {
        if (board[2] == 2)
            return 2;
        else if (board[5] == 2)
            return 5;
        else if (board[8] == 2)
            return 8;
    }
    else if (board[3] * board[6] * board[9] == num * num * 2)
    {
        if (board[3] == 2)
            return 3;
        else if (board[6] == 2)
            return 6;
        else if (board[9] == 2)
            return 9;
    }
    else if (board[1] * board[5] * board[9] == num * num * 2)
    {
        if (board[1] == 2)
            return 1;
        else if (board[5] == 2)
            return 5;
        else if (board[9] == 2)
            return 9;
    }
    else if (board[3] * board[5] * board[7] == num * num * 2)
    {
        if (board[3] == 2)
            return 3;
        else if (board[5] == 2)
            return 5;
        else if (board[7] == 2)
            return 7;
    }
    return 0;
}

int make2()
{
    if (board[5] == 2)
    {
        return 5;
    }
    else if (board[2] == 2)
    {
        return 2;
    }
    else if (board[4] == 2)
    {
        return 4;
    }
    else if (board[6] == 2)
    {
        return 6;
    }
    else if (board[8] == 2)
    {
        return 8;
    }
    return 0;
}

void go(int box)
{
    if (turn % 2 == 0)
    {
        board[box] = 5;
    }
    else
    {
        board[box] = 3;
    }
    turn += 1;
}
int main()
{
    // printf("Enter 1 to choose X and 2 to choose O\n");
    int whose,user = -1,n=10;
    printf("Enter 1 to choose X and 2 to choose O\n");
    scanf("%d",&whose);
    // int sturn;
    // int user = -1;
    // cin >> sturn;
    // int board[10];
    // int turn = 1;
    for (int i = 1; i <= 9; i++)
    {
        board[i] = 2;
    }
    int flag = 0;
    if (whose == 2)
    {
        go(1);
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (board[9] == 2)
        {
            go(9);
        }
        else
        {
            go(3);
        }
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (poswin(3) != 0)
        {
            go(poswin(3));
            display();
            printf("Computer won !\n");
            return 0;
        }
        else if (poswin(5) != 0)
        {
            go(poswin(5));
        }
        else if (board[7] == 2)
        {
            go(7);
        }
        else
        {
            go(3);
        }
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (poswin(3) != 0)
        {
            go(poswin(3));
            display();
            printf("Computer won !\n");
            return 0;
        }
        else if (poswin(5) != 0)
        {
            go(poswin(5));
        }
        else
        {
            go(make2());
        }
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (poswin(3) != 0)
        {
            go(poswin(3));
            printf("Computer won !\n");
        }
        else if (poswin(5) != 0)
        {
            go(poswin(5));
        }
        else
        {
            go(make2());
        }
        display();

        if (!flag)
        {
            printf("Draw");
        }
    }
    if (whose == 1)
    {
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (board[5] == 2)
        {
            go(5);
        }
        else
        {
            go(1);
        }
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (poswin(3) != 0)
        {
            go(poswin(3));
        }
        else
        {
            go(make2());
        }
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (poswin2(3) == 27 || poswin2(5) == 125)
        {
            printf("User Win");
            return 0;
        }
        if (poswin(5) != 0)
        {
            go(poswin(5));
            display();
            printf("Computer won !\n");
            return 0;
        }
        else if (poswin(3) != 0)
        {
            go(poswin(3));
        }
        else
        {
            go(make2());
        }
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (poswin2(3) == 27 || poswin2(5) == 125)
        {
            printf("User Win");
            return 0;
        }
        if (poswin(5) != 0)
        {
            go(poswin(5));
            printf("User Win\n");
            return 0;
        }
        else if (poswin(3) != 0)
        {
            go(poswin(3));
        }
        else
        {
            go(make2());
        }
        display();
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d",&user);
        go(user);
        if (poswin2(3) == 27 || poswin2(5) == 125)
        {
            go(poswin(5));
            printf("User Win\n");
            return 0;
        }
        display();
        if (!flag)
        {
            printf("DRAW\n");
        }
    }
    return 0;
}
