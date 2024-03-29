#include <stdio.h>
#include <stdlib.h>

// Node to represent sparse matrix

struct Node
{

    int value;

    int row_position;

    int column_postion;

    struct Node *next;
};

// Function to create new node

void create_new_node(struct Node **start, int non_zero_element,

                     int row_index, int column_index)
{

    struct Node *temp, *r;

    temp = *start;

    if (temp == NULL)

    {

        // Create new node dynamically

        temp = (struct Node *)malloc(sizeof(struct Node));

        temp->value = non_zero_element;

        temp->row_position = row_index;

        temp->column_postion = column_index;

        temp->next = NULL;

        *start = temp;
    }

    else

    {

        while (temp->next != NULL)

            temp = temp->next;

        // Create new node dynamically

        r = (struct Node *)malloc(sizeof(struct Node));

        r->value = non_zero_element;

        r->row_position = row_index;

        r->column_postion = column_index;

        r->next = NULL;

        temp->next = r;
    }
}

void PrintList(struct Node *start)
{

    struct Node *temp, *r, *s;

    temp = r = s = start;

    printf("row_position: ");

    while (temp != NULL)

    {

        printf("%d ", temp->row_position);

        temp = temp->next;
    }

    printf("\n");

    printf("column_postion: ");

    while (r != NULL)

    {

        printf("%d ", r->column_postion);

        r = r->next;
    }

    printf("\n");

    printf("Value: ");

    while (s != NULL)

    {

        printf("%d ", s->value);

        s = s->next;
    }

    printf("\n");
}

void Print(struct Node *start)
{

    struct Node *temp, *r, *s;

    temp = r = s = start;

    while (temp != NULL && r != NULL && s != NULL)

    {

        printf("%d  ", temp->row_position);

        temp = temp->next;

        printf("%d  ", r->column_postion);

        r = r->next;

        printf("%d ", s->value);

        s = s->next;

        printf("\n");
    }
}
// Driver of the program

void main()
{

    // Assume 4x5 sparse matrix

    int i, j, sparseMatric[4][5] =

                  {

                      {0, 0, 3, 0, 4},

                      {0, 0, 5, 7, 0},

                      {0, 0, 0, 0, 0},

                      {0, 2, 6, 0, 0}

                  };

    /* Start with the empty list */

    struct Node *start = NULL;

    for (i = 0; i < 4; i++)

        for (j = 0; j < 5; j++)

            // Pass only those values which are non - zero

            if (sparseMatric[i][j] != 0)

                create_new_node(&start, sparseMatric[i][j], i, j);

    PrintList(start);
    Print(start);
    getch();
    return 0;
}
