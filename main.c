#include <stdio.h>
#include <stdlib.h>
#include "FunlinBreakfast.h"

int main() 
{
	int player=1;            // 1為player O,-1為player X 
	int board[9][3][3]={0};  //陣列 全部設0 
	int bigboard[3][3]={0}; 
	int now=5,nowtemp;
	int winner=0;
	while(winner==0)
	{
		display(board,bigboard,now);
		playgame(board,&player,&now,&nowtemp);
		checkgame(board,bigboard,nowtemp,&winner);
	}
	if(winner==1)
		printf("恭喜O玩家贏得比賽!\n");
	else
		printf("恭喜X玩家贏得比賽!\n");
	system("pause");	
	return 0;
}
