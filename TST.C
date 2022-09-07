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
void main()
{
    void create1(), traverse1(), create2(), traverse2(), polyadd(), traverse();
    clrscr();
    create1();
    traverse1();
    create2();
    traverse2();
    polyadd();
    traverse();
    getch();
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

void polyadd()
{
    struct node *ptr, *ptr1, *ptr2, *cptr;
    ptr1 = head1;
    ptr2 = head2;
    if (ptr1->expo > ptr2->expo)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->coeff = ptr1->coeff;
        ptr->expo = ptr1->expo;
        ptr1 = ptr1->link;
    }
    else if (ptr1->expo < ptr2->expo)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->coeff = ptr2->coeff;
        ptr->expo = ptr2->expo;
        ptr2 = ptr2->link;
    }
    else
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->coeff = ptr1->coeff * ptr2->coeff;
        ptr->expo = ptr2->expo * 2;
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }
    head = ptr;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        cptr = (struct node *)malloc(sizeof(struct node));
        if (ptr1->expo > ptr2->expo)
        {
            cptr->coeff = ptr1->coeff;
            cptr->expo = ptr1->expo;
            ptr1 = ptr1->link;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            cptr->coeff = ptr2->coeff;
            cptr->expo = ptr2->expo;
            ptr2 = ptr2->link;
        }
        else
        {
            cptr->coeff = ptr1->coeff * ptr2->coeff;
            cptr->expo = ptr2->expo * 2;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        ptr->link = cptr;
        ptr = cptr;
    }

    while (ptr1 != NULL)
    {
        cptr = (struct node *)malloc(sizeof(struct node));
        cptr->coeff = ptr1->coeff;
        cptr->expo = ptr1->expo;
        ptr1 = ptr1->link;
        ptr->link = cptr;
        ptr = cptr;
    }
    while (ptr2 != NULL)
    {
        cptr = (struct node *)malloc(sizeof(struct node));
        cptr->coeff = ptr2->coeff;
        cptr->expo = ptr2->expo;
        ptr2 = ptr2->link;
        ptr->link = cptr;
        ptr = cptr;
    }
    ptr->link = NULL;
}

void traverse()
{
    struct node *ptr;
    printf("\nAddition result is : ");
    ptr = head;
    while (ptr->link != NULL)
    {
        printf(" %dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->link;
    }
    printf(" %dx^%d", ptr->coeff, ptr->expo);
}