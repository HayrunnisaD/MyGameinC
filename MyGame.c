#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void clean_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

struct food
{
};

enum items
{
    windows,
    door,
    arrow,
    food,
    sword,
    monster
};
     const char *itemNames[] = {
        "windows",
        "door",
        "arrow",
        "food",
        "sword",
        "monster"
    };
struct room
{
    enum items item;
    int xCoordinates;
    int yCoordinates;
};

struct box
{
    enum items item;
    int xCoordinates;
    int yCoordinates;
};

struct shop
{
    enum items arrow;
    struct food food;
    enum items sword;
};

struct player
{
    int health;
    char name[10];
    int xCoordinates;
    int yCoordinates;
};

struct monster
{
    int health;
    int xCoordinates;
    int yCoordinates;
};

int showCoordinates(struct player player1)
{
    printf("Player's coordinates = (%d,%d)\n", player1.xCoordinates, player1.yCoordinates);
}

int look(struct room room)
{

    printf("In the room,there are those items: \n");
     for(int i =0;i<6;i++)
              printf("%s\n",itemNames[i]);
}
int game()
{
    srand(time(NULL));
    char myChar[20];
    struct player player1;
    player1.health = 3;
    struct room room;
    struct monster monster1;
    struct box box1;
    enum items;
    room.xCoordinates = 10;
    room.yCoordinates = 10;
    player1.xCoordinates = 0;
    player1.yCoordinates = 0;
    box1.xCoordinates = 0;
    box1.yCoordinates = 0;
    int maxX = 9, maxY = 9;
    int minX = -9, minY = -9;

    do
    {
        box1.xCoordinates = minX + rand() % (maxX - minX + 1);
        box1.yCoordinates = minY + rand() % (maxY - minY + 1);
    } while (box1.xCoordinates == 0 || box1.yCoordinates == 0);

    printf("Player name: ");
    scanf("%15s", player1.name);

    printf("Press M to move\nPress L to move left\nPress R to move right\nPress B to go back\nPress J to jump\nPress S to throw the arrow\n");
    int choice = rand() % 2;

    if (choice == 0)
    {
        monster1.xCoordinates = box1.xCoordinates;
        monster1.yCoordinates = box1.yCoordinates;
        monster1.health = 1;
        printf("Monster's coordinates: (%d,%d)\n", monster1.xCoordinates, monster1.yCoordinates);
    }
    else
    {
        printf("The room is clean. Doesn't seem monster\n");
        monster1.xCoordinates = -20;
        monster1.yCoordinates = -20;
        monster1.health = 0;
    }
  
    while (1)
    {
        showCoordinates(player1);
        if (player1.health == 0)
        {
            printf("You died");
            exit(0);
            break;
        }
        if (monster1.xCoordinates != -20 && (abs(player1.xCoordinates - box1.xCoordinates) <= 1 &&
                                             abs(player1.yCoordinates - box1.yCoordinates) <= 1))
        {
            printf("Monster is appear. You have to shoot arrows.\n");
            scanf("%19s", myChar);
            if (myChar[0] != 'S' && myChar[0] != 's')
            {
                player1.health--;
                printf("ONE OF YOUR LIVES IS GONE\n");
                continue;
            }
            else
            {

                printf("Monster dead. You won.");
                exit(0);
                break;
            }
        }

        scanf("%9s", myChar);

        for (int i = 0; i < strlen(myChar); i++)
        {
            myChar[i] = toupper(myChar[i]);
        }

        if (strlen(myChar) == 1)
        {
            switch (myChar[0])
            {

            case 'M':
                if (player1.yCoordinates >= -9 && player1.yCoordinates < 9)
                {
                    printf("You moved forward\n");
                    player1.yCoordinates++;
                }
                else
                    printf("You crossed the wall\n");
                break;
            case 'L':
                if (player1.xCoordinates > -9 && player1.xCoordinates <= 9)
                {
                    printf("You moved left\n");
                    player1.xCoordinates--;
                }
                else
                    printf("You crossed the wall\n");
                break;
            case 'R':
                if (player1.xCoordinates >= -9 && player1.xCoordinates < 9)
                {
                    printf("You moved right\n");
                    player1.xCoordinates++;
                }
                else
                    printf("You crossed the wall\n");

                break;
            case 'B':
                if (player1.yCoordinates > -9 && player1.yCoordinates <= 9)
                {
                    printf("You moved back\n");
                    player1.yCoordinates--;
                }
                else
                    printf("You crossed the wall\n");
                break;

                break;
            case 'S':
                printf("Shot the arrow\n");
                break;
            case 'J':
                printf("You jumped\n");
                break;
            case 'Q':
                    printf("Exiting the game...\n");
                exit(0);
                break;
            default:
                printf("Enter a valid character\n");
                break;
            }
            clean_input_buffer();
        }
        else if (strcmp(myChar, "LOOK") == 0)
        {
            look(room);
        }
        else
        {
            printf("Enter a valid character\n");
            break;
        }
    }
    return 0;
}
int main()
{
    game();

    return 0;
}
