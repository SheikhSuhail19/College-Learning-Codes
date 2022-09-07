#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
    int coeff;
    int expo;
    struct node *link;
};
struct node *head, *head1, *head2;

//Adding new nodes

void new (struct node **head, int coeff, int expo)
{
    struct node *ptr, *cpt;
    ptr = *head;

    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->coeff = coeff;
        ptr->expo = expo;
        ptr->link = NULL;
        *head = ptr;
    }

    else
    {
        while (ptr->link != NULL)
            ptr = ptr->link;
        cpt = (struct node *)malloc(sizeof(struct node));
        cpt->coeff = coeff;
        cpt->expo = expo;
        cpt->link = NULL;
        ptr->link = cpt;
    }
}

void removedup()
{
    struct node *ptr, *cpt, *dup;
    ptr = head;
    while (ptr != NULL && ptr->link != NULL)
    {
        cpt = ptr;
        while (cpt->link != NULL)
        {
            if (ptr->expo == cpt->link->expo)
            {
                ptr->coeff = ptr->coeff + cpt->link->coeff;
                dup = cpt->link;
                cpt->link = cpt->link->link;
                free(dup);
            }
            else
                cpt = cpt->link;
        }

        ptr = ptr->link;
    }
}

void create1()
{
    struct node *ptr, *cpt;
    char ch;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter 1st Polynomial in decreasing order of x");
    printf("\nEnter Coefficient & Exponent");
    scanf("%d %d", &ptr->coeff, &ptr->expo);
    head1 = ptr;
    do
    {
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter next Coefficient & Exponent");
        scanf("%d %d", &cpt->coeff, &cpt->expo);
        ptr->link = cpt;
        ptr = cpt;
        printf("Enter Y/N for more node");
        ch = getch();
    } while (ch == 'y');
    ptr->link = NULL;
}
void traverse1()
{
    struct node *ptr;
    printf("\nPolynomial 1st is : ");
    ptr = head1;
    while (ptr->link != NULL)
    {
        printf(" %dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->link;
    }
    printf(" %dx^%d", ptr->coeff, ptr->expo);
}
void create2()
{
    struct node *ptr, *cpt;
    char ch;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter 2nd Polynomial in decreasing order of x");
    printf("\nEnter Coefficient & Exponent");
    scanf("%d %d", &ptr->coeff, &ptr->expo);
    head2 = ptr;
    do
    {
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter next Coefficient & Exponent");
        scanf("%d %d", &cpt->coeff, &cpt->expo);
        ptr->link = cpt;
        ptr = cpt;
        printf("Enter Y/N for more node");
        ch = getch();
    } while (ch == 'y');
    ptr->link = NULL;
}

void traverse2()
{
    struct node *ptr;
    printf("\nPolynomial 2nd is : ");
    ptr = head2;
    while (ptr->link != NULL)
    {
        printf(" %dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->link;
    }
    printf(" %dx^%d", ptr->coeff, ptr->expo);
}

void traverse()
{
    struct node *ptr;
    printf("\nMuliplication result is : ");
    ptr = head;
    while (ptr->link != NULL)
    {
        printf(" %dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->link;
    }
    printf(" %dx^%d", ptr->coeff, ptr->expo);
}

void polymult()
{
    struct node *ptr1, *ptr2;
    int coeff, expo;
    head = NULL;
    ptr1 = head1;
    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            coeff = ptr1->coeff * ptr2->coeff;
            expo = ptr1->expo + ptr2->expo;
            new (&head, coeff, expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
    removedup();
}

void main()
{
    clrscr();
    create1();
    traverse1();
    create2();
    traverse2();
    polymult();
    traverse();
    getch();
}
