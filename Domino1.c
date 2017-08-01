#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void menu(void);
void game(int a, int b, int *p, int *q);

/*
1 + ������ ������ �������� � ���� 28 �����
2 ������������(�) �������� 6 ����� � �� �����
3 ������� �� || ������� ����
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
       } Knuck[28];

int  main()
{ system("chcp 1251 > nul");
int  i=0, j=0, r=0, n=0;
int x, y, *p, *q;

for (i=0;i<28;i++, j++)
{
    if (j==7||(n+j>6))
       { j=0; n++;}
     Knuck[i].a=j;
     Knuck[i].b=j+n;
     printf("Knuck[%d].a = %d\tKnuck[%d].b = %d\t\n", i, Knuck[i].a, i, Knuck[i].b);
}

do{
    srand(time(NULL));
    x=(int)rand()%7;
    y=(int)rand()%7;
   } while(x==0&&y==0);

   system("pause");

while(1)
{
	do
	{
        system("cls");

        for(i=0; i<6; ++i)
        {
            printf("%d. [%d|%d]\n", i+1, Knuck[i].a, Knuck[i].b);
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
		case 1: game(Knuck[0].a, Knuck[0].b, p, q);break;
		case 2:	game(Knuck[1].a, Knuck[1].b, p, q);break;
		case 3:	game(Knuck[2].a, Knuck[2].b, p, q);break;
		case 4:	game(Knuck[3].a, Knuck[3].b, p, q);break;
		case 5:	game(Knuck[4].a, Knuck[4].b, p, q);break;
		case 6: game(Knuck[5].a, Knuck[5].b, p, q);break;
		case 0: return;
		}
		system("pause");
  }//while(1)
system("pause");
}//main

void game(int a, int b, int  *p, int *q)
{   int k=0;
    int x=*p, y=*q;

       if((a==x&&b==y)||(a==y&&b==x)&&k==0)//���� ���� �������� �����
     {
       printf("�������� ������� �����:\t [%d|%d]\n", a, b);
       scanf("%d", &x);
       printf("�������� ��������� ���� [%d|%d]\n", y, y);
       k=1;
     }
      if((a==y||a==x)&&x==y&&k==0)
     { x=b;
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=1;
     }
      if(x==y&&(b==x||b==y)&&k==0)
     { x=a;
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=1;
     }
     if(a==b&&(a==y||a==x)&&k==0)
     {
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=1;
     }

  if(k!=1) {
     if(a==x&&k==0)
     { x=b;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
     if(a==y&&k==0)
     { y=b;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
     if(b==x&&k==0)
     { x=a;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
     if(b==y&&k==0)
     { y=a;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=2;
     }
   }
     if(k==0) printf("��� ������ ����\n");
     *p=x; *q=y;
}

