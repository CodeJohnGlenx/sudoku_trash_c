#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void menu(void);
void confirm_exit(void);
void print_cells(void);
void solve(void);

int sudoku[3][3] = {0}, i, j, data, input, limit, index_, count = 0;
char response;

void confirm_exit(void)
{
    printf("Are you sure you want to exit? (y/n) ");
    scanf(" %c", &response);
    if (tolower(response) != 'y')
        menu();
    exit(1);
}

void print_cells(void)
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", sudoku[i][j]);
        putchar('\n');
    }
}

void solve(void)
{
    for (data = i = 1; i <= 9; i++)
        while (sudoku[(i-1)/3][(i-1)%3] == 0)  // one-way to access element in multi-dimensional array if we're only using index and not rows and columns
        {
            loop:
                for (j = 1; j<=9; j++)
                    if (data == sudoku[(j-1)/3][(j-1)%3])  // checks if data is present in sudoku[][]
                    {
                        data++;
                        goto loop;
                    }
            sudoku[(i-1)/3][(i-1)%3] = data;
        }
    system("cls");
    print_cells();
}
