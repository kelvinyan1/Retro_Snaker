int map[30][30];

void init_map(int map[30][30]){
    for(int i=0;i<30;++i){
        for(int j=0;j<30;++j){
            if(i==0 || j==0){
                map[i][j]='#';
            }
            else{
                map[i][j]=0;
            }
        }
    }
}