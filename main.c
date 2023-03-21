#include <stdio.h>
#include <stdlib.h>
#define ROWS 30
#define COLUMNS 50
#define true 1
#define false 0

enum Coordinates{up,down,right,left};

struct ob{
    int x,y;
    int turtledirection;
    int penMode;
};

void printTable(int insertedArray[][COLUMNS]);
int moveTurtle(int steps,int insertedArray[][COLUMNS],struct ob *insertedTurtle);
void resetTable(int insertedArray[][COLUMNS],struct ob *insertedTurtle);


main()
{
    enum Coordinates direction;
    struct ob turtle={0,0,0,false};
    int table[ROWS][COLUMNS]={0},steps,result,penMode,reset;

    while(true)
    {
        fflush(stdin);
        printf("Valid direction options: 0(up),1(down),2(right),3(left): ");
        scanf("%d",&direction);
        printf("Steps(positive integer): ");
        scanf("%d",&steps);

        switch(turtle.penMode)
        {
        case true:
            printf("Turtle's pen is down\n");
            break;
        case false:
            printf("Turtle's pen is up\n");
            break;
        }
        printf("Do you want to change pen mode? 1(yes),0(no): ");
        scanf("%d",&penMode);
        switch(penMode)
        {
        case true:
            if(!turtle.penMode) turtle.penMode = true;
            else turtle.penMode = false;
            break;
        case false:
            break;
        }

        if(steps>0)
            switch(direction)
            {
            case up:
                turtle.turtledirection = 90;
                result = moveTurtle(steps,table,&turtle);
                printTable(table);
                if (result)puts("Turtle moved successfully!");
                else puts("Turtle didn't move at all!");
                break;
            case down:
                turtle.turtledirection = 270;
                result = moveTurtle(steps,table,&turtle);
                printTable(table);
                if (result)puts("Turtle moved successfully!");
                else puts("Turtle didn't move at all!");
                break;
            case right:
                turtle.turtledirection = 0;
                result = moveTurtle(steps,table,&turtle);
                printTable(table);
                if (result)puts("Turtle moved successfully!");
                else puts("Turtle didn't move at all!");
                break;
            case left:
                turtle.turtledirection = 180;
                result = moveTurtle(steps,table,&turtle);
                printTable(table);
                if (result)puts("Turtle moved successfully!");
                else puts("Turtle didn't move at all!");
                break;
            default: puts("Invalid direction input!");
            }
        else puts("Steps must be a positive number!");


        printf("\nDo you want to reset? 1(yes),0(no): ");
        scanf("%d",&reset);
        switch(reset)
        {
        case true:
            resetTable(table,&turtle);
            break;
        case false:
            break;
        default:
            printf("Invalid input\n");
        }
    }

}

void resetTable(int insertedArray[][COLUMNS],struct ob *insertedTurtle)
{
    insertedTurtle->x = insertedTurtle->y = 0;
    int i,j;
    for(i=0;i<ROWS;++i)
        for(j=0;j<COLUMNS;++j)
            insertedArray[i][j] = 0;

    printTable(insertedArray);
}

int moveTurtle(int steps,int insertedArray[][COLUMNS],struct ob *insertedTurtle)
{
    if(steps>0)
    {
        if(insertedTurtle->turtledirection == 0)
        {
            if(steps+(insertedTurtle->x)<COLUMNS)
            {
                if(insertedTurtle->penMode == true)
                {
                    for(int i=0;i<steps;++i)
                    {
                        (insertedTurtle->x)++;
                        insertedArray[insertedTurtle->y][insertedTurtle->x]=1;
                    }
                }
                else
                    for(int i=0;i<steps;++i)
                        (insertedTurtle->x)++;
                return true;
            }
        }
        if(insertedTurtle->turtledirection == 90)
        {
            if((-1)*steps+(insertedTurtle->y)>=0)
            {
                if(insertedTurtle->penMode == true)
                {
                    for(int i=0;i<steps;++i)
                    {
                        (insertedTurtle->y)--;
                        insertedArray[insertedTurtle->y][insertedTurtle->x]=1;
                    }
                }
                else
                    for(int i=0;i<steps;++i)
                        (insertedTurtle->y)--;
                return true;
            }
        }
        if(insertedTurtle->turtledirection == 180)
        {
            if((-1)*steps+(insertedTurtle->x)>=0)
            {
                if(insertedTurtle->penMode == true)
                {
                    for(int i=0;i<steps;++i)
                    {
                        (insertedTurtle->x)--;
                        insertedArray[insertedTurtle->y][insertedTurtle->x]=1;
                    }
                }
                else
                    for(int i=0;i<steps;++i)
                        (insertedTurtle->x)--;
                return true;
            }
        }
        if(insertedTurtle->turtledirection == 270)
        {
            if(steps+(insertedTurtle->y)<ROWS)
            {
                if(insertedTurtle->penMode == true)
                {
                    for(int i=0;i<steps;++i)
                    {
                        (insertedTurtle->y)++;
                        insertedArray[insertedTurtle->y][insertedTurtle->x]=1;
                    }
                }
                else
                    for(int i=0;i<steps;++i)
                        (insertedTurtle->y)++;
                return true;
            }
        }
    }
    return false;
}


void printTable(int insertedArray[][COLUMNS])
{
    system("cls");
    int i,j;
    for(i=0;i<ROWS;++i)
    {
        for(j=0;j<COLUMNS;++j)
        {
            if(insertedArray[i][j]==0)
                printf("-");
            else
                printf("*");
        }
        puts("");
    }
}
