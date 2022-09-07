#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct stack
{
    int info;
    struct stack *link;
};
struct stack *top;

void create()
{
    char ch;
    struct stack *ptr, *cpt;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter info\n");
    scanf("%d", &ptr->info);
    ptr->link = NULL;
    top = ptr;
    do
    {
        cpt = (struct stack *)malloc(sizeof(struct stack));
        printf("Enter info\n");
        scanf("%d", &cpt->info);
        cpt->link = top;
        top = cpt;
        printf("Press <Y> for more node\n");
        ch = getch();
    } while (ch == 'y');
}

void push()
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    if (ptr == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter info\n");
    scanf("%d", &ptr->info);
    ptr->link = top;
    top = ptr;
    printf("Pushed element successfully\n");
    sleep(3);
}

void pop()
{
    struct stack *ptr;
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popping top element\n");
    sleep(3);
    ptr = top;
    top = top->link;
    free(ptr);
}

void traverse()
{
    struct stack *ptr;
    printf("Traversing stack from top to bottom\n");
    sleep(3);
    ptr = top;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->info);
        ptr = ptr->link;
    }
}

void main()
{
    clrscr();
    create();
    traverse();
    push();
    traverse();
    pop();
    traverse();
    getch();
}