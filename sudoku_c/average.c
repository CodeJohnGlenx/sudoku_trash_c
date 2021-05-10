#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void average(void)
{
    system("cls");
    limit = 5;
    print_cells();
    while (count < limit)
    {
        printf("%d - Input index:  ", count + 1);  // get index
        scanf("%d", &index_);
        // checks if input index is less than 1 or greater than 9 or if the index in sudoku[][] contains value other than 0
        if (index_ < 1 || index_ > 9 || sudoku[(index_-1)/3][(index_-1)%3] != 0)
            average();

        input_data:
            printf("%d - Input data:  ", count + 1);
            scanf("%d", &data);
            for (i = 1; i <= 9; i++)
                if (data == sudoku[(i-1)/3][(i-1)%3] || data < 1 || data > 9)  // checks if input data is already present in sudoku[][]
                    goto input_data;

        sudoku[(index_-1)/3][(index_-1)%3] = data;
        count++;
        average();
    }
    solve();

    for (count = 0, i = 1; i <= 9; i++)  // set every value in sudoku[][] to 0
        sudoku[(i-1)/3][(i-1)%3] = 0;
    printf("\nWould you like to try again? (y/n) ");
    scanf(" %c", &response);
    if (tolower(response) != 'y')
        menu();
    average();
}
