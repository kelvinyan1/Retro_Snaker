/* map should be something like this: */
//  #####################
//  #                   #
//  #                   #
//  #                   #
//  #                   #
//  #                   #
//  #####################     
// snack is something like this : &&&&&&&&&&&&&&&            
#include <map.h>
using namespace std;

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