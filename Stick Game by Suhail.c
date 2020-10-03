#include<stdio.h>
#include<conio.h>
void rules();
void game ();
int main()
{
  int c=0;
  char name[20];
  clrscr();
  printf("\t\4\t\t\t\t\t\t\t\t\t\t*WELCOME TO THIS GAME*\n\n\t\t\t\t\t\tTHIS GAME IS IMPOSSIBLE TO WIN\n\n\t\t\t\t\t\t\t\t\t\t\tSTILL GIVE IT A TRY\n\n");
  start :
    printf("\n\t\t\t\t\t*HOMEPAGE*\n\n\t\t1. Start the game.\n\t\t2. See game rules.\n\t\t3. Information about the game.\n\t\t4. Exit.\n\n");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
      printf("Enter your first name: ");
      scanf("%s",name);
      printf("\nHey '%s', Let's Begin the Game.\n",name);
      game();
      break;
    case 2:
      rules();
      goto start;
      break;
      case 3:
        printf("This Project is made by :");
        printf("'Sheikh Suhail Khursheed'.");
        printf("\n\nCollege Name : ");
        printf("'Noida Institute of Engineering and Technology, Greater Noida'.");
       printf("\n\nTime taken to complete the project : 3 hours.");
       break;
    case 4:
      exit(0);
      break;
      default:
      printf("Invalid Choice Entered");
      printf("\nChoose Again\n");
      goto start;
      }
 return 0; 
  }
  void rules()
  {
    char ch=0;
    printf("\n\t\t\t\t\t\t\t\tTHE GAME RULES ARE PRETTY SIMPLE:\n\n");
    printf("1. There are total 21 sticks.\n");
    printf("2. You are given the first try to pick from\n\t\t\t\tthe pile of 21 sticks.\n");
    printf("3. You can pick a minimum of 1 stick & a\n\t\t\t\tmaximum of 4 sticks in a single attempt.\n");
    printf("4. After you 'SUHAIL' will be given a\n\t\t\t\ttry to do the same.\n");
    printf("5. Then again it'll be your turn to pick.\n");
    printf("6. The one who picks up the last stick\n\t\t\t\twill LOSE the game.\n");
    printf("7. And eventually the other player will be\n\t\t\t\tdeclared as the WINNER\n");
  /*  printf("\n ENTER H (or h) TO GO BACK TO THE HOMEPAGE");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tOR\n\n ENTER ANY KEY TO EXIT\n");
    scanf("%c",&ch);
    printf("%c",ch);
    if(ch != 'H' && ch != 'h')
    exit(0);
    else
    exit(1);  */
    }
    void game()
    {
      int p=0,c=0,S=21,r;
      again:
      do
      {
      printf("\nSTICKS AVAILABLE : %d",S);
       printf("\n\n\t\t\t\t\t\t\t\t*YOUR TURN*:");
      printf("\nPick any number of sticks from 1 to 4\n");
      scanf("%d",&p);
      if(p<4)
      c=(5-p);
      else if(p>4)
     {
       printf("\nINVALID CHOICE ENTERED\n\nCHOOSE AGAIN!\n\n");
       goto again;
      }
      else c=1;     
      printf("\n'SUHAIL' picked %d sticks.\n",c);
      S=(S-(c+p));
      }
      while(S!=1);
      printf("\nSTICKS AVAILABLE : %d",S);
      printf("\n\n\t\t\t\t\t\tYOU LOST!\n\n");
      printf("1.Play Again\n2.I admit that I can't beat him.\n");
      scanf("%d",&r);
      S=21;
      if(r==1)
      goto again;
      else
     {printf("\nTHANK YOU FOR PLAYING THIS GAME!");
      printf("\n\nHAVE A NICE TIME!");
      }
      return 0;
      }