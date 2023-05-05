# RunningGame
 FG Running Game
First Hand-in:
I tried working with inheritance to the best of my ability.
I created base classes containing functionality relevant for all of the child classes.

I created my own character class in c++ and wrote some simple functionality for it, such as a movement function, and a function for taking damage. 

The moving platforms aren't spawned in any way. Whenever they reach a certain position they get relocated to the back of the level.

The game contains a projectile spawner which spawns projectiles in random intervals.
After five projectiles have been spawned into the world, the spawner reuses the previously spawned projectiles by moving the furthest one to the spawners position,
thus providing the illusion of a new projectile spawning.

Second Hand-in:
I added multiplayer by having a player pawn that can receive inputs. This pawn spawns in two actor which it controlls through keyboard inputs (A and D for player1, and left and right keys for player2).
The game now checks when a projectile has passed the players and then, through rolling a random number, has a chance of "despawning" another projectile further up the play area.
For this hand-in I also implemented increasing difficulty which comes in the form of peridically increasing projectile speed and spawn rate.
Lastly I managed to implement a highscore system which saves the five best times and presents them in the main menu. This is done using the Unreal SaveGame class and functions.

