# MyGameinC
CENG209HW
A TEXT-BASED ADVENTURE GAME in C.
The player navigates a defined coordinate space within a room that contains various items such as food and arrows. Occasionally, a monster may also be present in the box in the room. If a monster appears, the player must defeat it by shooting arrows. Failing to do so will result in the monster attacking and ultimately killing the player.
How the Game Works
The player starts at the origin (0, 0), can move in different directions [M (Move), L (Turn Left), R (Turn Right), B (Go Back)] or can jump(J), look around(L) ,shoot an arrow (S).
A box in the room can contain either a monster or be clean.
The player should avoid losing all lives (health) equal to 3 and defeat the monster by shooting an arrow when it appears. The player wins if they shoot the monster. They lose if they run out of health.
Items present in the room are pre-defined.
Player (struct player): Tracks player's name, health, and coordinates.
Room (struct room): Represents the space where the player interacts.
Monster (struct monster): Holds the monster's coordinates and health.
Box (struct box): Denotes a special location in the room.
Enum items define various items in the room.
itemNames provides string representations of these items for display.
The monster is placed randomly in the room, ensuring it does not start at (0, 0).
The monster randomly can appear in the box . Randomization is achieved using rand() seeded with time(NULL).
The player moves within a bounded space (coordinates between -9 and 9).
Wall collisions are handled with appropriate feedback.
If the player comes near the monster, they must shoot it with an arrow (S) to survive.
Players can use the LOOK command to see all items in the room.
Commands are entered as single characters (e.g., M, L, R) or as the word LOOK.                                                                         Hayrunnisa Durdu
