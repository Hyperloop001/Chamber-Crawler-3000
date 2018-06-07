# Chamber Crawler 3000
## A game designed for those who don't like beautiful user interfaces :-)
### Introduction: It's a simplified text-based rouge-like game! 
A map of CC3k consists of a board 79 columns wide and 30 rows high. 

The player character moves through a dungeon and slays enemies and collects treasure 
until reaching the end of the dungeon (where the end of the dungeon is the 5th floor). 
A dungeon consists of different floors that consist of chambers connected with passages. 
Each deault floor will always consist of the same 5 chambers connected in exactly the same way.

CC3k differs from other rogue-likes in a significant way: it does not update the terminal/window in
real-time but rather redraws all elements every turn (e.g. after every command). Many early rogue-likes
were programmed in a similar fashion to CC3k.

### Before you start the game:
#### Compile it!
  Everything is in form of source code, so you might want to compile it before playing.
  The good news is a Makefile is provided. Bad news, emmmm, only tested on linux...
  But you can still compile everything within a shell or even using your IDE. XD

  If you compiled the game successfully, congratulations! 
  You can now start the game by entering "./cc3k" to your command line
#### You must check this out, or you can't go anywhere!
##### Because this part is all about how to play the game.
##### Some Definitions
Definition 1 : A character is a person/animal/thing in the game of CC3k. This can be either the player
character (PC), who is controlled by the player of the game, or non-playable characters, who are strictly
enemies in CC3k.

Definition 2 : An item is something the player character can pick up or use. In CC3k, this is either gold
or potions. Potions offer potentially positive and negative effects to the player character.

Definition 3 : A chamber is an individual room in the game of CC3k. Chambers are connected by passages.

Definition 4 : A floor in CC3k is a predefined configuration of 5 chambers with connecting passageways.
Figure 1 depicts an empty floor. Note that the configuration is the same for every floor in a game of
CC3k.

Definition 5 : Health Points (HP) is the representation of a character抯 health (both enemies and the
player character). When a character抯 HP reaches 0, they are slain. For an enemy this means that they
are removed from the floor and a tidy sum of gold is given to the player character. When the player
character has 0 HP then the current game ends.

Definition 6 : Attack (Atk) is the representation of a character抯 strength. This is how hard a character can
hit another character. Though in CC3k conflict is solely between the player character and non-playable
characters.

Definition 7 : Defense (Def) is the representation of a character抯 toughness. This is how hard a character
can be hit by another character.

Definition 8 : A cell is either a wall, floor tile, doorway, stairway, or passage.

Definition 9 : Something being spawned means that the particular something (an enemy, gold, etc) should
be generated and placed on the board.

Definition 10 : A 1 block radius denotes the 8 cells adjacent to the character or item.

##### Player Character
The default player character race is a shade4 that has starting stats (125 HP, 25 Atk, 25 Def). However,
players have the option of choosing an alternate (but no less heroic) race: drow (150 HP, 25 Atk , 15 Def,
all potions have their effect magnified by 1.5), vampire (50 HP, 25 Atk, 25 Def, gains 5 HP every successful
attack and has no maximum HP), troll (120 HP, 25 Atk, 15 Def, regains 5 HP every turn; HP is capped at
120 HP), and goblin (110 HP, 15 Atk, 20 Def, steals 5 gold from every slain enemy). Max HP for all races
is the starting HP, except for vampire which has no max.
In the game board, the player character is always denoted by the ‘@’ symbol.

##### Enemies
Enemies are the mortal foes of our illustrious player character. In a traditional rogue-like, the enemy
character would have some degree of artificial intelligence. However, for simplicity in CC3k, enemies, except
for dragons, move one square randomly within the confines of the chamber they were spawned in. Dragons
are stationary and always guard a treasure hoard.

Enemies can be one of human (140 HP, 20 Atk, 20 Def, drops 2 normal piles of gold), dwarf (100 HP, 20
Atk, 30 Def, Vampires are allergic to dwarves and lose 5HP rather than gain), elf (140 HP, 30 Atk, 10 Def,
gets two attacks against every race except drow), orcs (180 HP, 30 Atk, 25 Def, does 50% more damage to
goblins), merchant (30 HP, 70 Atk, 5 Def), dragon (150 HP, 20 Atk, 20 Def, always guards a treasure hoard),
and halfling (100 HP, 15 Atk, 20 Def, has a 50% chance to cause the player character to miss in combat, i.e.
takes priority over player character’s ability to never miss).

By default, merchants are neutral to all parties5. However, merchants can be attacked and slain by the
player character. Attacking or slaying a Merchant will cause every Merchant from that point forward to
become hostile to the player character for the rest of the game even on future floors (and will attack them
if they pass within a one block radius).

Dragons always spawn in a one block radius of its dragon hoard(see Treasure). That is, if a dragon hoard
is spawned then a dragon is spawned.

Upon their demise, any enemy that is not a dragon, human, or merchant will drop either a small pile or
normal pile of gold (discussed below). This gold is immediately added to the player character’s total.

Enemies (except dragons, who are stationary) move randomly 1 floor tile at a time, assuming the floor
tile is unoccupied (see Section 3 for floor tile description). An enemy can never leave the room it was spawned (created) in. 
Note that enemies should be moved in a line-by-line fashion. That is, starting at the leftmost enemy, 
move all enemies on that row and then move to the next row starting with the leftmost. 
Any particular enemy should only be moved once per player action (e.g. moving to a line that has not been
processed does not grant an extra move). However, should the player character be within a 1 block radius
of an enemy then the enemy will always attack the player character.

Enemies are denoted on the map as follows: (H)uman, d(W)arf, (E)lf, (O)rc, (M)erchant, (D)ragon,
Half(L)ing.

### Building your own map/mod and play with it:
#### Maps:
  A default map file was given as cc3kfloor.txt, just follow the same format and build your own map! EASY!
  To activate your map, give it a cool name (e.g. "hyperloopMap.txt"), 
  then put it as a command line argument (e.g. "./cc3k hyperloopMap.txt").
#### Mods:
  The game came with a score board mod, just add a flag "-SB" on the command line (e.g. "./cc3k -SB") 
  and you can start a match with your friends/boy-friends/girl-friends or even your ex!

  You can also make your own by creating and modifying the main files... I am not doing it!
  
### Happy playing!

