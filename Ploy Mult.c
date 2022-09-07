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
    void create1(), traverse1(), create2(), traverse2(), polymult(), traverse();
    clrscr();
    create1();
    traverse1();
    create2();
    traverse2();
    polymult();
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
        printf("\nEnter link Coefficient & Exponent");
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
        printf("\nEnter link Coefficient & Exponent");
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

void polymult()
{
    struct node *ptr1, *ptr2;
    int coeff, expo;
    ptr1 = head1;
    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2->link != NULL)
        {
            coeff = ptr1->coeff * ptr2->coeff;
            expo = ptr1->coeff + ptr2->expo;
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
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



// Function add a new node at the end of list

struct node *addnode(struct node *head, int coeff, int power)

{

    // Create a new node

    struct node *newnode = new Node;

    newnode->coeff = coeff;

    newnode->power = power;

    newnode->link = NULL;

    // If linked list is empty

    if (head == NULL)

        return newnode;

    // If linked list has nodes

    struct node *ptr = head;

    while (ptr->link != NULL)

        ptr = ptr->link;

    ptr->link = newnode;

    return head;
}