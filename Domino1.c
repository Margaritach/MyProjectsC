#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void menu(void);
void game(int a, int b, int *p, int *q);

/*
1 + ������ ������ �������� � ���� 28 �����
2 + ������������(�) �������� 6 ����� � �� �����
3 + ������� ����
3.1 ������ �������������� �����
4 + �������� ����� �� ��� ������
5 //����� ����� ���������
6 ��������� ��� ������ ���� ������ ����� �� ��������� (�������� 1 ����� || ���������� ���)
7 ����� ������ �������� �������� �� ���� �
8 ���������� ��� � ���� ��������� �����
9 ����������� ����� �� �����
*/

 struct {
       int a;
       int b;
       //int c;
       } Knuck[28];

int  main()
{ system("chcp 1251 > nul");
int  i=0, j=0, n=0;
int x, y, *p, *q;
int NumKk[6];

for (i=0;i<28;i++, j++) //������ "�������"
{
    if (j==7||(n+j>6))
       { j=0; n++;}
     Knuck[i].a=j;
     Knuck[i].b=j+n;
     printf("Knuck[%d].a = %d\tKnuck[%d].b = %d\t\n", i, Knuck[i].a, i, Knuck[i].b);
}

do{ //������ ��������� �����
    srand(time(NULL));
    x=(int)rand()%7;
    y=(int)rand()%7;
   } while(x==0&&y==0);

   //system("pause");

while(1)
{
	do
	{
        system("cls");

         for(i=0; i<6; ++i)
        {
            NumKk[i] = (int)rand() % 27;
            printf("'njuobojl %d\t", NumKk[i]);
            printf("%d. [%d|%d]\n", i+1, Knuck[NumKk[i]].a, Knuck[NumKk[i]].b);

        }
        	printf("%d. %s\n", 0, "�����");

        p=x; q=y;
    	printf("\nFalling knuck [%d|%d]\n", p, q);
		printf("\n��� �����: ");
  	    p=&x; q=&y;

			fflush(stdin);
     } while(scanf("%d", &n)!=1 || n<0 || n>6 );

    	system("cls");



		switch( n )
		{
		case 1: game(Knuck[NumKk[0]].a, Knuck[NumKk[0]].b, p, q);break;
		case 2:	game(Knuck[NumKk[1]].a, Knuck[NumKk[1]].b, p, q);break;
		case 3:	game(Knuck[NumKk[2]].a, Knuck[NumKk[2]].b, p, q);break;
		case 4:	game(Knuck[NumKk[3]].a, Knuck[NumKk[3]].b, p, q);break;
		case 5:	game(Knuck[NumKk[4]].a, Knuck[NumKk[4]].b, p, q);break;
		case 6: game(Knuck[NumKk[5]].a, Knuck[NumKk[5]].b, p, q);break;
		case 0: return;
		}
		//system("pause");
  }//while(1)
system("pause");
}//main

void game(int a, int b, int  *p, int *q)
{   int k=0;
    int x=*p, y=*q;

      if ((a==x&&b==y)||(a==y&&b==x)&&k==0)//���� ���� �������� �����
     {
       printf("�������� ������� �����:\t [%d|%d]\n", a, b);
       scanf("%d", &a);
       if (a==y)
         printf("�������� ��������� ���� [%d|%d]\n", x, x);
       else
         printf("�������� ��������� ���� [%d|%d]\n", y, y);
       k=1;
     }
      if((a==y&&a==x)&&a!=b&&k==0)
     { x=b;
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=1;
     }
      if(a!=b&&(b==x&&b==y)&&k==0)
     { x=a;
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=1;
     }
     if(a==b&&(a==y||a==x)&&k==0)
     {
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=1;
     }
     if(a==x&&a!=b&&k==0)
     { x=b;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
     if(a==y&&a!=b&&k==0)
     { y=b;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
     if(b==x&&a!=b&&k==0)
     { x=a;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
     if(b==y&&a!=b&&k==0)
     { y=a;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
     if(k==0) printf("��� ������ ����\n");
     *p=x; *q=y;
     system("pause");
}

/*int randKk(int *a, int *Kkk)
{
    srand(time(NULL));
    i = rand() % 28;
    Kk=i;

}

/*int testOfArr (int a, int b)//����� ��� ��������, ��� ������� �����
{ int i, j=0;
  for (i=0;i<6;i++)
  { if(a==ZnKnuck[i]&&b==ZnKnuck[i+6]||b==ZnKnuck[i]&&a==ZnKnuck[i+6]) j=-1;
    if(a==ZnKk[i]&&b==ZnKk[i+6]||b==ZnKk[i]&&a==ZnKk[i+6]) j=-1;
  }
  return j;
}*/
