#include <stdio.h>
#include <stdlib.h>

int adj[10][10];

int main()
{
    int v, e, sc, dest;

    printf("Enter total number of vertices:"); // 4
    scanf("%d", &v);
    printf("\nEnter total number of Edges:"); // 5
    scanf("%d", &e);

    for (int i = 1; i <= e; i++)
    {
        printf("\nEnter %d edge:", i);
        printf("\nEnter source vertex:");
        scanf("%d", &sc);
        printf("\nEnter destination vertex:");
        scanf("%d", &dest);

        if (sc > v || dest > v || sc <= 0 || dest <= 0)
        {
            printf("\nInvalid Edge");
            i--;
        }
        else
        {
            adj[sc][dest] = 1;
            adj[dest][sc] = 1;
        }
    }
    printf("\nAdjacency Matrix for Undirected Graph:");
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            printf("\t%d", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
