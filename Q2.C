#include <stdio.h>

#define MAX 20
#define INF 999999

int cost[MAX][MAX];
int weight[MAX][MAX];
int root[MAX][MAX];
int p[MAX], q[MAX];

int main()
{
    int n, i, j, l, r;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter successful search probabilities:\n");
    for(i = 1; i <= n; i++)
    {
        printf("p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    printf("Enter unsuccessful search probabilities:\n");
    for(i = 0; i <= n; i++)
    {
        printf("q[%d]: ", i);
        scanf("%d", &q[i]);
    }

    for(i = 0; i <= n; i++)
    {
        cost[i][i] = 0;
        weight[i][i] = q[i];
    }

    for(l = 1; l <= n; l++)
    {
        for(i = 0; i <= n - l; i++)
        {
            j = i + l;
            cost[i][j] = INF;
            weight[i][j] = weight[i][j - 1] + p[j] + q[j];

            for(r = i + 1; r <= j; r++)
            {
                int c = cost[i][r - 1] + cost[r][j] + weight[i][j];

                if(c < cost[i][j])
                {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("\nOptimal Cost = %d\n", cost[0][n]);

    printf("Root Matrix:\n");

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            printf("%3d ", root[i][j]);
        }
        printf("\n");
    }

    return 0;
}
