/** 该解法图的存储为邻接矩阵实现 */

#define INF 1000000000

#include <stdio.h>

int n, m;

int a[101][101];
int dist[101][101];
int path[101][101];

void floyd()
{
    int i, j, k;
    /** init dist */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = a[i][j];
        }
    }
    /** init path */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            path[i][j] = -1;
        }
    }

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
}

int main()
{
    int i, j, k;
    /** input */
    scanf("%d %d", &n, &m);
    /** input edge */
    /** init array */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = INF;
        }
    }

    for (i = 0; i < n; i++)
    {
        j = i;
        a[i][j] = 0;
    }

    for (i = 0; i < m; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);
        a[u][v] = w;
    }
    /** floyd */
    floyd();
    /** output dist */
    printf("dist:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", dist[i][j]);
        }

        printf("\n");
    }
    /** output path */
    printf("path:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", path[i][j]);
        }

        printf("\n");
    }

    return 0;
}
