void clear();
void display(int board[9][3][3],int bigboard[3][3],int now);
void convertlocation(int *input);
void playgame(int board[9][3][3],int *player,int *now,int *nowtemp);
void checkgame(int board[9][3][3],int bigboard[3][3],int input,int *winner); 
int convertx(int input);
int converty(int input);
void checkbigboard(int win,int input,int bigboard[3][3]);
