# Chamber Crawler 3000
## A game designed for those who don't like beautiful user interfaces :-)
![alt text](https://i.imgur.com/WisLEYJ.png)   

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
  You can now start the game by entering "./cc3k" to your command line.
  To activate mods or build your own maps, please refer to the end of "README.md".
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

By default, merchants are neutral to all parties. However, merchants can be attacked and slain by the
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

##### Potions
In the game of CC3k, there is only one type of usable item: a potion. Potions are of two types: positive and
negative. Potions can provide the player character with positive and negative bonuses as outlined below.
Regardless of the potion itself, all potions are denoted on the map with a P. A player may not hold any
potions6. Accordingly, a potion cannot be used unless a player is standing within a 1 block radius of it.
The effects of a particular potion are not known until it is used for the first time, e.g. the player character
will not know what a potion does until they use it for the first time in a session. However, they will only
learn about the effects of that particular potion. Other potions will not have their effects revealed. The
exception is for potions purchased from the Merchant7, which should have have their abilities displayed.

Positive Potions:

 Restore health (RH): restore up to 10 HP (cannot exceed maximum prescribed by race)

 Boost Atk (BA): increase Atk by 5

 Boost Def (BD): increase Def by 5

Negative Potions:

 Poison health (PH): lose up to 10 HP (cannot fall below 0 HP)

 Wound Atk (WA): decrease Atk by 5

 Wound Def (WD): decrease Def by 5

The effects of RH and PH are permanent while the effects of all other potions are limited to the floor they
are used on. For example, using a BA potion will only boost the player character’s Atk until the beginning
of the next floor.

##### Treasure
Treasure in CC3k consists only of gold. Gold can be in several types of piles: small (value 1), normal (value
2), merchant hoard (value 4), and dragon hoard (value 6). Recall, a dragon must always protect a dragon
hoard whenever it randomly spawns. A dragon hoard can only be picked up once the dragon guarding it has
been slain. Gold, regardless of type, is denoted by ‘G’ on the map.
A merchant hoard is dropped upon the death of a merchant. Gold dropped by a merchant (merchant
hoard, value 4) or a human (2 normal piles, value 2x2=4) is picked up only when the PC walks over it.

##### Floors
Levels are generated to consist of the 5 chambers connected in the manner outlined in Figure 1. It would be
more interesting to have randomly connected randomly generated chambers but that is more complicated
than the time frame allows.

The player character should spawn randomly in a chamber (every chamber is equally likely) but it should
never be the case that the player spawns in the chamber with the stairs going down to the next level. Stairs
are denoted by '\'? Note that the stairway and player character may be spawned with equal probability on
any floor tile in a chamber. That is, a larger chamber should be no more likely to spawn the PC/stairs than
a smaller chamber, where any floor tile in the selected chamber is equally likely to spawn the PC/stairs.
10 potions are spawned on each floor. A potion type is chosen at random, with each type having equal
(1/6) probability. The chamber the potion spawns in is also chosen at random, with each room having equal
(1/5) probability. Each square in the chamber a potion spawns in has an equal chance of containing the
potion. Note that this means in particular that small rooms are just as likely to spawn potions as large
rooms.

10 piles of gold are spawned on every floor.

With the exception of dragons, enemies have the following probability distribution of being spawned:

 Human: 2/9

 Dwarf: 3/18

 Halfling: 5/18

 Elf: 1/9

 Orc: 1/9

 Merchant: 1/9

20 enemies are spawned per floor (this number does not include dragons). Every chamber is equally likely
to spawn any particular monster (similarly for floor tiles).

Note that multiple objects (enemies, gold, and potions) cannot occupy the same cell on the game board.
That is, no two objects can ever occupy the same space. The one exception to this is the case of gold.
Typically, when a player character walks over gold, it is picked up. The exception to this is if the gold is
associated with a still alive dragon; in this case, the player simply walks over the gold, without picking it.
When the PC attempts to move on to a stairway, the next level is instead generated and displayed, with
the PC spawning in a random position on the new level.

##### Combat
By default, all enemies except for Merchants and Dragons are hostile to the player character. If the player
character enters within a 1 block radius of any hostile enemy, they will attempt to attack the player character
(even before the player character has had a chance to attack). Dragons are considered hostile when the player
is next to (read: in the 1 block radius of) its dragon hoard or itself, and will use their fire breath to defend
its hoard (i.e. will attack the enemy). This means that a Dragon might attack even if the player is not next
to the Dragon, but because it is next to a dragon hoard. If the player character is not within a 1 block
radius of the enemy then it will resume random movement (as previously described). Recall that Merchants
can become hostile when one is attacked/slain by the player character.

Combat is resolved as follows: Enemies will auto-attack players given the previously specified criteria,
however, there is a 50% chance their attack misses. The player character has the option of attacking any
of the 8 squares that are within a 1 block radius of them. The PC never misses (except when attacking a
halfling as discussed earlier). Recall, that the PC has initiative and always attacks first.

Damage is calculated as follows: Damage(Defender) = ceiling((100=(100+Def(Defender)))Atk(Attacker)),
where Attacker specifies the attacking character (enemy or PC) and defender specifies the character being
attacked. Thus, in a single round a character can be both an attacker and a defender.

##### Command Interpreter
Initially, the game will demand the player enter one of the specified races or quit. Entering 'q' or EOF (e.g.
Ctrl-D) at the race prompt will cause the program to terminate. Supplying a valid race selection (below)
will start that game using that race. Other values will be ignored.

Play will continue in the specified way until the player restarts, reaches the end of floor 5, the PC dies,
or the player quits. If the player reaches the end of the game or their character is slain, the game should
give them the option of playing again or quitting.

The following commands can be supplied to your command interpreter:

 no,so,ea,we,ne,nw,se,sw: moves the player character one block in the appropriate cardinal direction.

 u <direction>: uses the potion indicated by the direction (e.g. no, so, ea).
  
 a <direction>: attacks the enemy in the specified direction, if the monster is in the immediately
specified block (e.g. must be one block north of the @).
  
 s, d, v, g, t: specifies the race the player wishes to be when starting a game.

 f: stops enemies from moving until this key is pressed again.

 r: restarts the game. All stats, inventory, and gold are reset. A new race should be selected.

 q: allows the player to admit defeat and exit the game.


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

