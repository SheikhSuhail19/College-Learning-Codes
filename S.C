#include <stdio.h>

void sparse(int r, int c, int v)
{
    int s[3][20], k = 0;
    s[0][k] = r;
    s[1][k] = c;
    s[2][k] = v;
    k++;
}
void main()
{
    int i, j, row = 0, column = 0, a[5][5] = {{1, 0, 0, 0, 0}, {0, 2, 0, 0, 0}, {0, 0, 3, 0, 0}, {0, 0, 0, 4, 0}, {0, 0, 0, 0, 5}};

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (a[i][j] != 0)
            {
                sparse(i + 1, j + 1, a[i][j]);
                row++, column++;
            }
        }
    for (i = 0; i < 5; i++)
        {
        for (j = 0; j < 5; j++)
        {
        }
            getchar();
        }