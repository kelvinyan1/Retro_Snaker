# ENGG1340_project_group242
text-based game created by Wuhuan/Yanzipeng;
Wu Huan 3035638545, Yan Zipeng 3035637826;
text-based game: Retro Snaker;
game rules: Retro snaker is a common game that controlling a "snake" is moving in a certain area, eating "beams" to earn more points (the position repeats) and become bigger (only head move forward). The "snake" will "die" when it hits the wall or its body, and every "death" means game over;
functions/features:
data for storing snack's position, length, score;
a function to print the map;
a function to delay the time;
a function to make the snack move;
a function to read in player's typing(W,S,A,D);
a function to identify whether game over;
a function to save (S) and load the game;

modified:
class:  snake
member function: move snake; turn directions; initialize; print the snake;whether snake is dead; 

class: beam 
member function: randomly generate beam; destroy beam;




map and snack sample:
##############################################
#              (beans)                       #
#             *          *  (head)           #
#                        &                   #
#                        &                   #
#                        &                   #            
#                        &&&&&&&&            #
#                                            #
#                                            #
#                                            #
##############################################


non-standard c library:  <conio.h>
We use this library to track players input(using kbhit() and getch())
With it's help, we can let user only press keyboard to control the snake (instead of pressing enter)
When user doesn't tpye, we can still make the snake move instead of waiting until player input something.




