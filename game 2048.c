#include<stdio.h>
#include<math.h>
#include<stdlib.h>
char key;
int a[5][5]={0},i=0,j=0,ir,jr,temp,bu[5]={0};

void display()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]!=0)
            printf("%d ",a[i][j]);
            else
                printf("0 ");
    }
    printf("\n");
    }
    printf("enter W,S,A or D");
}

 void ran1()
 {
     int ir,jr;
     while(a[ir=rand()%(5)][jr=rand()%(5)]!=0);
    a[ir][jr]=pow(2,rand()%(2)+1);
     }


int arrf()
     {
       int f=0;
       for(int i=0;i<5;i++)
       {
    if(bu[i]==bu[i+1]&&bu[i]!=0)
            f=1;
       }
       return f;

     }
void up()
{
  int temp;
  for(i=0;i<4;i++)
  {

      for(j=0;j<4-i;j++)
      {

         if(bu[j]==0&&bu[j+1]!=0)
         {
             temp=bu[j];
             bu[j]=bu[j+1];
             bu[j+1]=temp;
         }
      }
  }
  if(arrf())
        {
            for(i=0;i<5;i++)
                {
                 if(bu[i]==bu[i+1]&&bu[i]!=0)
                 {
                     bu[i]=2*bu[i];
                     for(j=i+1;j<5;j++)
                     {
                      bu[j]=bu[j+1];

                     }
                    bu[4]=0;
                }

                }

        }
}
void main()
{
int x,y;

    ran1();
    ran1();
    display();

    while(1)
    {
      key = getchar();

      if(key == 'w'|| key == 'W')
      {
        for(x=0;x<5;x++)
        {
          for(y=0;y<5;y++)
          {
              bu[y]=a[y][x];

          }
          up();
           for(y=0;y<5;y++)
          {
              a[y][x]=bu[y];
          }
        }
        ran1();
      display();
      }

      else if(key =='s'|| key =='S')
      {
        for(x=0;x<5;x++)
        {
          for(y=0;y<5;y++)
          {
              bu[4-y]=a[y][x];
          }
          up();
          for(y=0;y<5;y++)
          {
              a[y][x]=bu[4-y];
          }

        }
        ran1();
      display();
      }

      else if(key =='a'|| key =='A')
      {
        for(x=0;x<5;x++)
        {
          for(y=0;y<5;y++)
          {
              bu[y]=a[x][y];
          }
          up();
           for(y=0;y<5;y++)
          {
              a[x][y]=bu[y];
          }

        }
        ran1();
      display();
      }
      else if(key == 'd'|| key == 'D')
      {
        for(x=0;x<5;x++)
        {
          for(y=0;y<5;y++)
          {
              bu[4-y]=a[x][y];
          }
          up();
          for(y=0;y<5;y++)
          {
              a[x][y]=bu[4-y];
          }

        }
        ran1();
      display();
      }


    }

}


