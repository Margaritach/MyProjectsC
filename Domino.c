#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void menu(void);
int game(int a, int b, int *p, int *q);

/*
1 + ������ ������ �������� � ���� 28 �����
2 + ������������ �������� 6 ����� � �� �����
3 + ������� ����
3.1 + ������ �������������� �����
4 + �������� ����� �� ��� ������
5 //����� ����� ���������
6 ��������� ��� ������ ���� ������ ����� �� ��������� (�������� 1 ����� || ���������� ���)
7 + ����� ������ �������� �������� �� ���� �
8 ���������� ��� � ���� ��������� �����
9 ����������� ����� �� �����
10 ����� ����, ����� ����� � ������ �����������
*/

 struct {
       int a; //������ ������� �����
       int b; //������ ������� �����
       int c; //����� �����
       } Knuck[28];

int  main()
{ system("chcp 1251 > nul");
int  i=0, j=0, n=0, t=0, k=0;
int x, y, *p, *q;
int NumKk[7], fallKk[29]={-1};

for (i=0;i<28;i++, j++) //������ "�������"
{
    if (j==7||(n+j>6))
       { j=0; n++;}
     Knuck[i].a=j;
     Knuck[i].b=j+n;
     printf("Knuck[%d].a = %d\tKnuck[%d].b = %d\t\n", i, Knuck[i].a, i, Knuck[i].b);
     Knuck[i].c=i;
     fallKk[i]=-1;
}



do{ //������ ��������� �����
    srand(time(NULL));
    x=y=(int)rand()%7;
    //y=(int)rand()%7;
   } while(x==0&&y==0);

   //system("pause");

while(1)
{
	do
	{
        system("cls");

         for(i=0; i<7; ++i)
        {
            if (fallKk[6]==-1)
            {
               S: NumKk[i] = (int)rand() % 27;
                    for (j=0;j<6;j++)
                        if (fallKk[j]==NumKk[i]) goto S;
               printf("%d. [%d|%d]\n", i+1, Knuck[NumKk[i]].a, Knuck[NumKk[i]].b);
               fallKk[t]=NumKk[i];
               t++;
            } else if (i==k&&k<9)
                {
                    S1: NumKk[k] = (int)rand() % 27;
                    for (j=0;j<28;j++)
                        if (fallKk[j]==NumKk[k]) goto S1;
                    //printf("����� �������� �����: %d  ", NumKk[k]);
                    fallKk[t]=NumKk[k];
                    if (t==27)
                    {
                        system("cls");
                        printf("���� ��������\n");
                        return 0;
                    } else t++;
                    printf("%d. [%d|%d]\n", k+1, Knuck[NumKk[k]].a, Knuck[NumKk[k]].b);
                    k=10;
                } else
                    printf("%d. [%d|%d]\n", i+1, Knuck[NumKk[i]].a, Knuck[NumKk[i]].b);
        }

        	printf("%d. %s\n", 0, "�����");

        p=x; q=y;
    	printf("\nFalling knuck [%d|%d]\n", p, q);
		printf("\n��� �����: ");
  	    p=&x; q=&y;

			fflush(stdin);
     } while(scanf("%d", &n)!=1 || n<0 || n>7 );

    	system("cls");

		switch( n )
		{
		case 1: k=game(Knuck[NumKk[0]].a, Knuck[NumKk[0]].b, p, q);break;
		case 2:	k=1+game(Knuck[NumKk[1]].a, Knuck[NumKk[1]].b, p, q);break;
		case 3:	k=2+game(Knuck[NumKk[2]].a, Knuck[NumKk[2]].b, p, q);break;
		case 4:	k=3+game(Knuck[NumKk[3]].a, Knuck[NumKk[3]].b, p, q);break;
		case 5:	k=4+game(Knuck[NumKk[4]].a, Knuck[NumKk[4]].b, p, q);break;
		case 6: k=5+game(Knuck[NumKk[5]].a, Knuck[NumKk[5]].b, p, q);break;
		case 7: k=6+game(Knuck[NumKk[6]].a, Knuck[NumKk[6]].b, p, q);break;
		case 0: return;
		}
		printf("\n�������� %d�� �����\n", k+1);

		system("pause");
  }//while(1)
system("pause");
}//main

int game(int a, int b, int  *p, int *q)
{   int k=10;
    int x=*p, y=*q;

      if ((a==x&&b==y)||(a==y&&b==x)&&k==10)//���� ���� �������� �����
     {
       printf("�������� ������� �����:\t [%d|%d]\n", a, b);
       scanf("%d", &a);
       if (a==y)
         printf("�������� ��������� ���� [%d|%d]\n", x, x);
       else
         printf("�������� ��������� ���� [%d|%d]\n", y, y);
       k=0;
     }
      if((a==y&&a==x)&&a!=b&&k==10)
     { x=b;
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=0;
     }
      if(a!=b&&(b==x&&b==y)&&k==10)
     { x=a;
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=0;
     }
     if(a==b&&(a==y||a==x)&&k==10)
     {
       printf("�������� ��������� ���� [%d|%d]\n", x, y);
       k=0;
     }
     if(a==x&&a!=b&&k==10)
     { x=b;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=0;
     }
     if(a==y&&a!=b&&k==10)
     { y=b;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=0;
     }
     if(b==x&&a!=b&&k==10)
     { x=a;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=0;
     }
     if(b==y&&a!=b&&k==10)
     { y=a;
       printf("�������� ���� ���� [%d|%d]\n", x, y);
       k=0;
     }
     if(k==10) printf("��� ������ ����\n");
     *p=x; *q=y;
     system("pause");
     return k;
}
