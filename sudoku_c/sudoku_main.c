#include "functions_variables.c"
#include "easy.c"
#include "average.c"
#include "difficult.c"

void menu()
{
    system("cls");
    printf("Sudoku!\n\n");
    printf("Input a number corresponding to Sudoku Problem:\n");
    printf("1. Easy      (3 values missing)\n");
    printf("2. Average   (4 values missing)\n");
    printf("3. Difficult (5 values missing)\n");
    printf("4. Exit\n\n");

    printf(">> ");
    scanf("%d", &input);
    if (input == 1)
        easy();
    else if (input == 2)
        average();
    else if (input == 3)
        difficult();
    else if (input == 4)
        confirm_exit();
    menu();
}

void main()
{
    menu();
}
