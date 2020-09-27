#define MAXTEAMS 5
#define MAXGAMES 8
#include <stdio.h>
struct team
{
    char name [1000];
    int pld;
    int w;
    int d;
    int l;
    int pts;
    int GS;
    int games[MAXGAMES];

};
struct team leagueteams[MAXTEAMS];  //Globally declared, because it's access is needed to all other functions.

void createOrder(struct team leagueteams[]); // Prototype

int main (void)
{

    printf("**********************************\n");
    printf("Welcome To The Premier League\n\n");
    printf("Type 5 Teams To Create The League");
    printf("\n**********************************\n");
    createleague(leagueteams);
    createOrder(leagueteams); // Bubble sorting.
    displayleague(leagueteams);

    return 0;
}
void createOrder(struct team leagueteams[])
{
   int i, j;
   struct team temp;
   for (i = 0; i < MAXTEAMS-1; i++)
   {
       for (j = 0; j < MAXTEAMS-1-i; j++)
       {

           if (leagueteams[j].pts < leagueteams[j+1].pts)
              {
                  temp = leagueteams[j];
                  leagueteams[j] = leagueteams[j+1];
                  leagueteams[j+1] = temp;
              }
       }

   }
            for (i = 0; i < MAXTEAMS-1; i++)
     {
            for (j = 0; j < MAXTEAMS-1-i; j++)
            {
                 if (leagueteams[j].GS < leagueteams[j+1].GS && leagueteams[j].pts==leagueteams[j+1].pts)
                {
                  temp = leagueteams[j];
                  leagueteams[j] = leagueteams[j+1];
                  leagueteams[j+1] = temp;
                }
            }
    }
}

void createleague(struct team leagueteams[])
{
    int t;
    int g;
    for (t=0; t<MAXTEAMS; t++)
    {
        printf("\nEnter Team:");
        gets(leagueteams[t].name);
        fflush(stdin);
        printf("Played:");
        scanf("%d", &leagueteams[t].pld);
        fflush(stdin);
        printf("Win:");
        scanf("%d",&leagueteams[t].w);
        fflush(stdin);
        printf("Lost:");
        scanf("%d",&leagueteams[t].l);
        fflush(stdin);
        printf("Drawn:");
        scanf("%d",&leagueteams[t].d);
        fflush(stdin);
        printf("Goal Scored:");
        scanf("%d",&leagueteams[t].GS);
        fflush(stdin);

        leagueteams[t].pts= (leagueteams[t].w*3);
        leagueteams[t].pts= (leagueteams[t].d*1);

        leagueteams[t].pts= (leagueteams[t].w*3)+(leagueteams[t].d*1);
    }
    for (g=0; g<MAXGAMES; g++)
    {
        leagueteams[t].games[MAXTEAMS] = 0;
    }
}
void displayleague(struct team leagueteams[])
{
    printf("\n\n\t\tPremier League Table\n");
    printf("\n-----------------------------------------------------\n");
    printf("\tName  \t          P   W   D   L  GS Pts\n");
    printf("------------------------------------------------------\n");
    int d;
    for (d=0; d<MAXTEAMS; d++)
    {
        printf("%15s \t%3d %3d %3d %3d %3d %3d\n", leagueteams[d].name,
               leagueteams[d].pld, leagueteams[d].w, leagueteams[d].d,
               leagueteams[d].l,leagueteams[d].GS, leagueteams[d].pts);
    }

}
