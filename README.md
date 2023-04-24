# RunningGame
 FG Running Game

I tried working with inheritance to the best of my ability.
I created base classes containing functionality relevant for all of the child classes.

I created my own character class in c++ and wrote some simple functionality for it, such as a movement function, and a function for taking damage. 

The moving platforms aren't spawned in any way. Whenever they reach a certain position they get relocated to the back of the level.

The game contains a projectile spawner which spawns projectiles in random intervals.
After five projectiles have been spawned into the world, the spawner reuses the previously spawned projectiles by moving the furthest one to the spawners position,
thus providing the illusion of a new projectile spawning. 
