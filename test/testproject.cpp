#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

int score;
int eat_flag;


/*the following are snake*/
//
//
//
struct body
    {        
        int body_x;
        int body_y;
        body* next;
        body* previous;      
    };

/*up = 0, down = 1, left = 2, right = 3*/
enum direction
{
        UP,
        DOWN,
        LEFT,
        RIGHT
};

class snake {
public:
    body* snake_tail;
    body* snake_head;
    direction dir;
    int length;
    
    /*return 1 if snake is dead, 0 otherwise*/
    int snake_dead();      
    
    /*move and make the snake longer*/
    void snake_move(int &eat_flag);

    /*append snake into map*/
    void print_snake(char [30][30]);

    /*initialize the snake with 4 nodes*/
    void snake_init();

    /*change the direction of the snake*/
    void snake_change_dir(direction direct);
} snak;

void snake::snake_init()
{
    // initialize the first body's infomation
    body* pbody = new body();
    pbody->body_x = 10;
    pbody->body_y = 13;
    pbody->next = pbody;
    pbody->previous = pbody;

    // set the first body as the snake head
    snake_head = pbody;
    snake_tail = pbody;

    // append 3 bodies
    for (int i = 1; i < 4; i++)
    {
        body* ptr = new body();
        ptr->body_y = 13 - i;
        ptr->body_x = 10;
        ptr->next = pbody;
        pbody->previous = ptr;
        pbody = ptr;
    }

    snake_tail = pbody; // set snake tail

    length = 4; // set initial length of snake
    dir = DOWN; // set initial direction
}

void snake::snake_move(int &flag_ptr)
{
    body* ptr = new body(); // create a new body

    // new body's coodinate is determined by previous head position and moving direction
    switch (dir)
    {
    case UP:
    {
        ptr->body_y = snake_head->body_y;
        ptr->body_x = snake_head->body_x - 1;
        break;
    }
    case DOWN:
    {
        ptr->body_y = snake_head->body_y;
        ptr->body_x = snake_head->body_x + 1;
        break;
    }
    case RIGHT:
    {
        ptr->body_x = snake_head->body_x;
        ptr->body_y = snake_head->body_y + 1;
        break;
    }
    case LEFT:
    {
        ptr->body_x = snake_head->body_x;
        ptr->body_y = snake_head->body_y - 1;
        break;
    }
    default:
        break;
    }
    
    ptr->previous = snake_head; // link new body to the whole snake
    snake_head->next = ptr;
    ptr->next = ptr;
    
    snake_head = ptr; // set new body as snake head

    if (flag_ptr == 0) {// snake head doesn't touch the beam, delete the tail to move forward
        snake_tail = snake_tail->next;
        snake_tail->previous = snake_tail;
    }
    else if (flag_ptr == 1) //  snake head touches the beam, length plus 1
    {
        flag_ptr = 0;
        length += 1;
    }
}

void snake::print_snake(char map[30][30])
{
    body* current = snake_head;
    
    map[current->body_x][current->body_y] = '*'; // set head as "*"
    current = current->previous;

    // set remain bodies as "&"
    while(current != snake_tail)
    {
        map[current->body_x][current->body_y]='&';
        current = current->previous;
    }
    map[current->body_x][current->body_y]='&';
}

int snake::snake_dead()       //return 1 if snake is dead, 0 otherwise
{   
    body* current = snake_head->previous;
    while(current != snake_tail)
    {
        if ((current->body_x==snake_head->body_x) &&(current->body_y==snake_head->body_y))
        {
           return 1;
        }
        current = current->previous;
    }
    if ((current->body_x==snake_head->body_x) &&(current->body_y==snake_head->body_y))
    {
        return 1;
    }
    if (snake_head->body_x == 29 || snake_head->body_x == 0 || snake_head->body_y == 0 || snake_head->body_y == 29)
        return 1;
    return 0;
}

void snake::snake_change_dir(direction ipdir)
{
    // snake can just turn their head 90 degrees
    if ((dir==UP&&ipdir==DOWN) || (dir==DOWN&&ipdir==UP) || (dir==LEFT&&ipdir==RIGHT) || (dir==RIGHT&&ipdir==LEFT))
    {}
    else
    {
        dir = ipdir;
    }
    
}


/*the following are beams*/
//
//
//

class beam{
    public:
        int x;
        int y;

        //randomly generate the position of the beam
        void beam_generate();

        //write the beam into the map
        void beam_print(char map[30][30]);
} be ;

void beam::beam_generate()
{
    srand(time(NULL)); // randomly generate the position of the beam
    x = rand() % 28 +1;
    y = rand() % 28 +1;
}

void beam::beam_print(char map[30][30])
{
    map[x][y] = '*';
}



/*this is the time delay function, the unit of input should be ms*/
void delay(int time)//ms
{
    clock_t init_time=clock();
    while(clock()<(init_time+time))
    {}
      
}

/*the following are map functions*/
//
//
//

void init_map(char map[30][30]){
    for(int i=0;i<30;++i){
        for(int j=0;j<30;++j){
            if(i==0 || j==0 || i==29 || j==29){
                map[i][j]='#';
            }
            else{
                map[i][j]=' ';
            }
        }
    }
}
void print_map(char map[30][30]){
    for(int i=0;i<30;++i){
        for(int j=0;j<30;++j){
            cout << map[i][j];
        }
        cout<<endl;
    }
}

/*save & load*/
void save(snake skobj,beam bobj,int score,int flag)
{
    string num;
    cout << "number your game, please check documentary \"process\" to find a number doesn't appear"<<endl;
    cin >> num;
    ofstream fout;
    fout.open("process"+num+".txt");
    body *current= skobj.snake_head; 
    while(current != skobj.snake_tail){
        fout << current->body_x << ' ';
    }
    fout <<endl;
    while(current != skobj.snake_tail){
        fout << current->body_y << ' ';
    }
    fout <<endl;
    fout << bobj.x <<' '<<bobj.y;
    fout <<endl;
    fout <<score;
    fout.close();
}
void load()
{
    string num;
    cout <<"Which number of process do you want to load?"<<endl;
    cin >> num;
    ifstream fin;
}


//initialize snake and beam
void game_init()
{
    snak.snake_init();
    be.beam_generate();
    score = 0;
    eat_flag = 0;
}

void game_execute(){

    char input;
    
    // initialize map
    char map[30][30];
    init_map(map);
    be.beam_print(map);
    snak.print_snake(map);

    print_map(map);
    delay(500);

    //this is the basic game continue function 
    while(1)
    {
        
        if(snak.snake_dead()==1){
            cout <<"Game over!"<<endl;
            break;
        } 

        if (_kbhit())
        {
            input = getch();
            direction direct;
            if (input == 'w')
                direct = UP;
            else if (input == 's')
                direct = DOWN;
            else if (input == 'a')
                direct = LEFT;
            else if (input == 'd')
                direct = RIGHT;
            else if (input == 0x1B){// if hit "esc", quit game
                cout << "Do you want to save? if so answer yes"<<endl;
                string ans;
                cin >> ans;
                if (ans == "yes"){
                    save(snak,be,score,eat_flag);
                }
                break;
            }
            snak.snake_change_dir(direct);
        }

        if(snak.snake_head->body_x == be.x && snak.snake_head->body_y == be.y){
            eat_flag = 1;
            score += 1;
            be.beam_generate();
        }
        snak.snake_move(eat_flag);
        
        init_map(map);
        snak.print_snake(map);
        be.beam_print(map);
        
        //need to clear the scream by printf("\033[2J");
        //need to hide the cursor by printf("\033[?251")
        print_map(map);
        
        //delay 500ms
        delay(500);
        
    }
    //need to show the cursor by printf("\033[?25h")
    cout << "your score is "<< score << endl;
    delay(1000);
}

void help_execute()
{
    while (1)
    {
        system("cls");
        cout<<"-------------Help----------------"
            <<"W: up       S: down"<<endl
            <<"A: left     D: right"<<endl
            <<"if you eat a beam, then you will"<<endl
            <<"be longer."<<endl
            <<"if your head touch the wall and"<<endl
            <<"your body, then game over."<<endl
            <<"---------------------------------"<<endl
            <<"Press 'Esc' to exit"<<endl
            <<"---------------------------------"<<endl;

        while (!_kbhit()) // waiting for command
        {

        }

        int bit;
        if (_kbhit())
        {
            bit = _getch();
            if (bit == 27)
                break;
        }
    }
}


int main()
{
    while (1)
    {
        system("cls");
        cout<<"-------------------------------"<<endl
            <<"/---Welcome to Eating Snake---/"<<endl
            <<"-------------------------------"<<endl<<endl
            <<"1  start game"<<endl
            <<"2  mode"<<endl
            <<"3  help"<<endl
            <<"4  exit"<<endl;

        while (!_kbhit()) // if hitting detected, then execute following
        {

        }
        if (_kbhit())
        {
            int bit;
            bit = _getch();
            if (bit == 49){ // if press "1", start game
                game_init();
                game_execute();
            }
            else if (bit == 50) // if press "2", change mode
            {} //  mode_change_execute();
            else if (bit == 51) // if press "3", open help
                help_execute();
            else if (bit == 52) // exit game
                break;
        }
    }

    cout<<"successfully quit!"<<endl;
    system("pause");
}
