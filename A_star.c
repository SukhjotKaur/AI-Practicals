#include <stdio.h>
#include <stdlib.h>
struct list
{
    int key;    // node
    int value;  // fval
    int parent; // node's parent
};
int empty(struct list *open)
{
    int i, count = 0;
    for (i = 0; i < 10; i++)
    {
        if (open[i].key != -1)
        {
            count++;
        }
    }
    if (count == 10)
        return 0;
    else
        return 1;
}
int min(struct list *open)
{
    int i, min = open[0].value;
    ;
    for (i = 0; i < 10; i++)
    {
        if (i >= 0)
        {
            if (open[i].value < min)
            {
                min = open[i].value;
            }
        }
    }
    return min;
}
int sort(struct list *top)
{
    int i, j, a;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (top[i].value > top[j].value)
            {
                a = top[i].value;
                top[i].value = top[j].value;
                top[j].value = a;
            }
        }
    }
}
int currentind(struct list *open, int current)
{
    for (int i = 0; i < 10; i++)
    {
        if (open[i].value == current)
            return i;
    }
}
int inlist(int i, struct list *closed)
{
    for (int j = 0; j < 10; j++)
    {
        if (i != closed[j].key)
            return 0;
        else
            return 1;
    }
}
void printpath(int parent[10])
{
    int j = 9;
    do
    {
        j = parent[j];
        printf("-%d", j);
    } while (j != 0);
}
int astar(int h[10], int g[][10])
{
    struct list open[10], closed[10], top[10];
    int parent[10], i, child, j = 0;
    open[j].key = 0, open[j].value = h[j];
    while (!empty(open))
    {
        j++;
        sort(open);
        // int current = open[0].value;//least element in open
        // int ind = open[0].key;//index of elemnt in open with least value
        closed[i].key = open[0].key; // put this elemnt in closed, it is now current
        closed[i].value = open[0].value;
        closed[i].parent = open[0].parent;
        i++;
        open[0].value = -1;  // removing least f value from open;
        open[0].key = -1;    // removing least f value from open;
        open[0].parent = -1; // removing least f value from open;
        if (closed[i].key == 10)
        {
            printpath(parent);
        }
        for (child = 0; child < 10; child++)
        {
            if (g[closed[i].key][child] != 0) // check for adjacent elements
            {
                if (inlist(child, closed)) // if child is in closed list
                    continue;
                // parent[child] = closed[i].key;
                // int gh = g[0][closed[i].key] + g[closed[i].key][child]; // source to successor to child
                // closed[child].parent = closed[i].key;               // child is the index
                // closed[child].value = h[child] + gh;
                // if (inlist(child, open) && g[0][child] > g[0][open[closed[i].key].key])

                else if (inlist(child, open)) // child in open
                {
                    if (open[child].value > closed[i].value) // discard successor
                        continue;                            // we are not taking this child as a successor as its fvalue is not optimal for our needs
                    else                                     // update child node's f and g value
                    {
                        parent[child] = closed[i].key;
                        g[0][child] = g[0][closed[i].key] + g[closed[i].key][child];
                        open[child].value = g[0][child] + h[child];
                    }
                }
                // put child in open if it is not in closed or open
                else
                    open[j].key = child, open[j].value = g[0][child], open[j].parent = closed[i].key;
            }
        }
    }
}
int main()
{
    struct list open[10], closed[10];
    int g[10][10] = {{0, 6, 3, 1, 0, 0, 0, 0, 0, 0},
                     {6, 0, 2, 6, 3, 4, 0, 0, 0, 0},
                     {3, 2, 0, 0, 4, 5, 0, 0, 0, 0},
                     {1, 6, 0, 0, 7, 8, 9, 0, 0, 0},
                     {0, 3, 4, 7, 0, 6, 9, 9, 0, 0},
                     {0, 4, 5, 8, 6, 0, 8, 9, 0, 0},
                     {0, 0, 0, 9, 9, 8, 0, 11, 12, 14},
                     {0, 0, 0, 0, 9, 9, 11, 0, 14, 15},
                     {0, 0, 0, 0, 0, 0, 12, 14, 0, 0},
                     {0, 0, 0, 0, 0, 0, 14, 15, 0, 0}};
    int h[10] = {15, 13, 13, 12, 10, 9, 7, 6, 5, 0};
    astar(h, g);
    return 0;
}
