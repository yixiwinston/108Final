#include <stdio.h>
#include <stdlib.h>
#include "FunlinBreakfast.h"

int main() 
{
	int player=1;            // 1��player O,-1��player X 
	int board[9][3][3]={0};  //�}�C �����]0 
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
		printf("����O���aĹ�o����!\n");
	else
		printf("����X���aĹ�o����!\n");
	system("pause");	
	return 0;
}
