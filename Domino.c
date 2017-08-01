#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void menu(void);
void game(int a, int b, int *p, int *q);
int testOfArr (int a, int b);
/*
1 + задать массив хранящий в себе 28 фишек 
2 + Пользователю(П) выдается 6 фишек и он ходит
3 + Реакция пк || условия игры
4 + Проверка можно ли так ходить
5 //Далее ходит компьютер 
6 Прописать что делать если нужной фишки не оказалось (добавить 1 новую || пропустить ход)
7 Когда массив кончится сообщить об этом П
8 Выигрывает тот у кого кончились фишки
9 Реализовать вывод на экран 
*/

int ZnKnuck[11]={0}, ZnKk[11]={0}, OstKk[35]={0};

int  main()
{ system("chcp 1251 > nul");

int i=0, j=0, e=0, r=0;
int x, y, *p, *q;
//int ZnKnuck[11]={0}, ZnKk[11]={0}, OstKk[35]={0};
int a, b, a1, b1;
 
do{
          srand(time(NULL));
          x=(int)rand()%7; 
          y=(int)rand()%7;
          } while(x==0&&y==0);
    
while(1)
{ 
    //int a, b, a1, b1; 
   do
	{
        system("cls");
        
        if (j==6)  
        for(i=0; i<6; ++i)
        {
             printf("%d. [%d|%d]\n", i+1, ZnKnuck[i], ZnKnuck[i+6]);               
        }
        else 
            for(i=0; i<6; ++i)//через 1 кость может выпасть одинаковая, но вероятность маленькая
		  	{
				S: a = (int)rand() % 7;
                srand(time(NULL));
                b = (int)rand() % 7;
                if(a==a1&&b==b1||a==b1&&b==a1)
                  goto S;
				printf("%d. [%d|%d]\n", i+1, a, b);
				b1=b; a1=a;
				ZnKnuck[i]=a;
				ZnKnuck[i+6]=b;
				
                for (j=0;j<6;j++)
                {
                    if(ZnKk[j]==0)
                    {
	    		 	    S1: a = (int)rand() % 7;
                        srand(time(NULL));
                        b = (int)rand() % 7;
                        if(a==a1&&b==b1||a==b1&&b==a1) 
                           goto S1;
			           	b1=b; a1=a;
			            r = testOfArr (a, b);
				        ZnKk[j]=a;
				        ZnKk[j+6]=b;
                    }
                    // system("pause");
                    for (e=0;e<16;e++)
                    {  
                        //while (r==0)
                        if(OstKk[e]==0)
                        {  S2: a = (int)rand() % 7;
                           srand(time(NULL));
                           b = (int)rand() % 7;
                           if(a==a1&&b==b1||a==b1&&b==a1) goto S2;
                           b1=b; a1=a;
                           r = testOfArr (a, b);
                           OstKk[e]=a;
                           OstKk[e+16]=b;
                        }
                    }//fot OstKk[]*/
                }//for ZnKk[]
             }//for ZnKnuck[]
             
             //system("pause");
 
        //printf("7. Эпичная фразочка\n");	
		printf("%d. %s\n", 0, "Выход");	
		
//for (i=0;i<6;i++) printf("ZnKnuck[%d|%d]\tZnKk[%d|%d]\n", ZnKnuck[i], ZnKnuck[i+6], ZnKk[i], ZnKk[i+6]);
//for (i=0;i<16;i++) printf("OstKk [%d|%d]\n", OstKk[i], OstKk[i+16]); 
  
        p=x; q=y;
	   	
    	printf("\nFalling knuck [%d|%d]\n", p, q);
		printf("\nВаш выбор: ");
		p=&x; q=&y;

			fflush(stdin);
     } while(scanf("%d", &r)!=1 || r<0 || r>6 );

    system("cls");
		
		switch( r )
		{
		case 1: game(ZnKnuck[0],ZnKnuck[6], p, q);break;
		case 2:	game(ZnKnuck[1],ZnKnuck[7], p, q);break;
		case 3:	game(ZnKnuck[2],ZnKnuck[8], p, q);break;
		case 4:	game(ZnKnuck[3],ZnKnuck[9], p, q);break;
		case 5:	game(ZnKnuck[4],ZnKnuck[10], p, q);break;
		case 6: game(ZnKnuck[5],ZnKnuck[11], p, q);break;
			//case 7: printf("И да начнем!\n"); break;
		case 0: return;
		}
		system("pause");	
}//while(1)
  
}//main

void game(int a, int b, int  *p, int *q)
{   int k=0;
    int x=*p, y=*q;
    
       if((a==x&&b==y)||(a==y&&b==x)&&k==0)//надо дать человеку выбор
     { 
       printf("Выбирите сторону кости:\t [%d|%d]\n", a, b);
       scanf("%d", &x);
       printf("Возможые следующие ходы [%d|%d]\n", y, y);  
       k=1;     
     } 
      if((a==y||a==x)&&x==y&&k==0)
     { x=b;
       printf("Возможые следующие ходы [%d|%d]\n", x, y); 
       k=1;       
     } 
      if(x==y&&(b==x||b==y)&&k==0)
     { x=a;
       printf("Возможые следующие ходы [%d|%d]\n", x, y); 
       k=1;       
     }
      if(a==b&&(a==y||b==y)&&k==0)
     { x=a;
       printf("Возможые следующие ходы [%d|%d]\n", x, y); 
       k=1;       
     } 
     if(a==b&&(a==y||a==x)&&k==0)
     { 
       printf("Возможые следующие ходы [%d|%d]\n", x, y); 
       k=1;       
     } 
     
  if(k!=1) { 
     if(a==x&&k==0)
     { x=b;
       printf("Возможые след ходы [%d|%d]\n", x, y); 
       k=2;       
     } 
     if(a==y&&k==0)
     { y=b;
       printf("Возможые след ходы [%d|%d]\n", x, y);
       k=2;      
     } 
     if(b==x&&k==0)
     { x=a; 
       printf("Возможые след ходы [%d|%d]\n", x, y); 
       k=2;       
     } 
     if(b==y&&k==0)
     { y=a; 
       printf("Возможые след ходы [%d|%d]\n", x, y);  
       k=2;     
     } 
   } 
     if(k==0) printf("Так ходить низя\n");
     *p=x; *q=y;
}


int testOfArr (int a, int b)//ловит два элемента, две стороны кости
{ int i, j=0;
  for (i=0;i<6;i++)  
  { if(a==ZnKnuck[i]&&b==ZnKnuck[i+6]||b==ZnKnuck[i]&&a==ZnKnuck[i+6]) j=-1;                                                                            
    if(a==ZnKk[i]&&b==ZnKk[i+6]||b==ZnKk[i]&&a==ZnKk[i+6]) j=-1;
  }
  return j;   
}
