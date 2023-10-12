# View Writeup.pdf to view created graphs easily

How to run and use play-dreidel.c
================================


What does it do?
----------------
> Simulates games of dreidel with user inputted amount of players, starting coins, seed, and optional text telling
> you when a player was eliminated
> 


Command Line Options
--------------------
> 
> '-c #' Set the starting coins of all the players

> '-p #' Set the amount of players in the game

> '-s #' Set the seed used in the random number generator for the game

> '-v' Enable elimination messages


How to build and run the program.
=================================

Step One:
---------
> Ensure that the files:

> "Makefile"
> "dreidel.c"
> "dreidel.h"
> "play-dreidel.c"
> "mtrand.c"
> "mtrand.h"
>
> Are all inside the same directory.
>
Step Two:
---------
> Open the terminal in the directory and type "make"
>
Step Three:
-----------
> typing "./play-dreidel <args>"

> Replace the <args> with the corresponding inputs you would like from the above section

> You can include multiple inputs in a single run through of the function! (EX: "./play-dreidel -c 3 -p 4 -s 613")

Understanding the output:
------------------------
> The output is as follows 

> Winner_Name Players Starting_Coins Rounds_Taken Seed_Used



