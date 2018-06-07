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
Because this part is all about how to play the game.

### Building your own map/mod and play with it:
#### Maps:
A default map file was given as cc3kfloor.txt, just follow the same format and build your own map! EASY!
To activate your map, give it a cool name (e.g. "hyperloopMap.txt"), 
then put it as a command line argument (e.g. "./cc3k hyperloopMap.txt").
#### Mods:
The game came with a score board mod, just add a flag "-SB" on the command line (e.g. "./cc3k -SB").
Or you can make your own by creating and modifying the main files by yourself...

### Happy playing!

