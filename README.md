# ENGG1340_project_group242
text-based game created by Wuhuan/Yanzipeng;
Wu Huan 3035638545, Yan Zipeng 3035637826;
text-based game: Retro Snaker;
game rules: Retro snaker is a common game that controlling a "snack" is moving in a certain area, eating "coins" to earn more points (the position repeats) and become bigger (only head move forward). The "snack" will "die" when it hits the wall or its body, and every "death" means game over;
functions/features:
data for storing snack's position, length, score;
a function to print the map;
a function to make the snack move;
a function to read in player's typing(W,S,A,D);
a function to identify whether game over;
a function to pause(P), end (E) and continue(C) the game;
a function to save (S) and load the game;

new feature:
1, skin choose (1 character to form body)
2, multiple kinds of beans:
  "*" for 1 point,
  "@" for 2 point,
  "?" for -3 ~ 3 point.

map and snack sample:

----------------------------------------------
|     (head)  |(beans)|                      |
|    -----*   |  "*"  |  &&&&&&*             |
|    \        |  "@"  |  &                   |
|    /        |  "?"  |  &                   |
|    \        |       |  &                   |            
|    -----    ---------  &&&&&&&&            |
|      (tail)                                |
|                                            |
| (skin 1)             (skin 2)              |
----------------------------------------------
