#include <stdio.h>
#include <conio.h>
#include <alloc.h>

struct node
{
  int row, col, val;
  struct node *link;
};
struct node *head;

void new_node(struct node **, int, int, int), print_sparse(struct node *), print_matrix(struct node *);

void main()
{
  int a[20][20], i, j, m, n;
  clrscr();
  head = NULL;
  printf("Enter size");
  scanf("%d%d", &m, &n);
  printf("Enter matrix");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
      if (a[i][j] != 0)
        new_node(&head, i + 1, j + 1, a[i][j]);
    }
  print_sparse(head);
  print_matrix(head);
  getch();
}

//Adding new nodes

void new_node(struct node **head, int row, int col, int val)
{
  struct node *ptr, *cpt;
  ptr = *head;

  if (ptr == NULL)
  {
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->row = row;
    ptr->col = col;
    ptr->val = val;
    ptr->link = NULL;
    *head = ptr;
  }

  else
  {
    while (ptr->link != NULL)
      ptr = ptr->link;
    cpt = (struct node *)malloc(sizeof(struct node));
    cpt->row = row;
    cpt->col = col;
    cpt->val = val;
    cpt->link = NULL;
    ptr->link = cpt;
  }
}
//3 Column Representation

void print_sparse(struct node *head)
{
  struct node *ptr;
  ptr = head;
  printf("Row\tColumn\tValue\n");
  while (ptr != NULL)
  {
    printf("%d\t%d\t%d\n", ptr->row, ptr->col, ptr->val);
    ptr = ptr->link;
  }
}

//3 Row Representation

void print_matrix(struct node *head)
{
  struct node *ptr, *cpt, *tpt;
  ptr = head;
  cpt = head;
  tpt = head;
  printf("Row   :\t");
  while (ptr != NULL)
  {
    printf("%d\t", ptr->row);
    ptr = ptr->link;
  }
  printf("\n");
  printf("Column:\t");
  while (cpt != NULL)
  {
    printf("%d\t", cpt->col);
    cpt = cpt->link;
  }
  printf("\n");
  printf("Value :\t");
  while (tpt != NULL)
  {
    printf("%d\t", tpt->val);
    tpt = tpt->link;
  }
}
