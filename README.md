# A TEXT-BASED ADVENTURE GAME in C

This is a simple text-based adventure game written in C. The player navigates a defined coordinate space within a room containing various items such as food and arrows. Occasionally, a monster may also be present in a box within the room. The goal is to survive by defeating the monster when it appears.

---

## How the Game Works
- The player starts at the origin `(0, 0)` and can move in different directions:
  - **M**: Move forward
  - **L**: Turn left
  - **R**: Turn right
  - **B**: Go back
  - **J**: Jump
  - **S**: Shoot an arrow
  - **LOOK**: Look around the room to see available items
- A box in the room may contain:
  - A monster that must be defeated by shooting an arrow.
  - No monster (clean box).

### Objectives:
1. Avoid losing all health (3 lives in total).
2. Defeat the monster by shooting it when it appears.
3. Win by surviving and defeating the monster.

### Key Features:
- Items present in the room are pre-defined.
- The player interacts with:
  - **Player** (`struct player`): Tracks the player's name, health, and coordinates.
  - **Room** (`struct room`): Represents the space where the player navigates.
  - **Monster** (`struct monster`): Holds the monster's coordinates and health.
  - **Box** (`struct box`): Denotes a special location in the room.
  - **Enum items**: Defines various items in the room.
  - **itemNames**: Provides string representations of these items for display.
- Randomization:
  - The monster is placed randomly in the room, ensuring it does not start at `(0, 0)`.
  - Randomization is achieved using `rand()` seeded with `time(NULL)`.
- Movement:
  - The player moves within a bounded space (coordinates between -9 and 9).
  - Wall collisions are handled with appropriate feedback.
- Combat:
  - If the player comes near the monster, they must shoot it with an arrow (`S`) to survive.
  - Failure to do so results in the monster attacking and reducing the player's health.

---

## Commands
- **Single-character commands**:
  - `M`, `L`, `R`, `B`, `J`, `S`
- **LOOK**: Displays all items in the room.

---

## Gameplay Example
1. Start the game and input the player's name.
2. Navigate the room using the commands.
3. Use the `LOOK` command to identify items in the room.
4. If a monster appears, shoot it with an arrow (`S`) to win.
5. The game ends when:
   - The monster is defeated (you win).
   - The player loses all health (you lose).

---

## Compilation and Execution
1. Clone the repository:
   ```bash
   git clone https://github.com/HayrunnisaD/MyGameinC.git

