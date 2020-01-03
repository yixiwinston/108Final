#include "FunlinBreakfast.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void playgame(int board[9][3][3],int *player,int *now,int *nowtemp){
	int i,j,k;
	int x=0;
	int y=0;
	int a=0,b=0;
	int input,nowt;
	int num=0;
		srand(time(NULL));
		nowt=*now;
		convertlocation(&nowt);
		jump :
		printf("player ");
			if (*player==1)
				printf("O");
			else
				printf("X");
			printf(",enter your choice (1~9): ");
			scanf("%d",&input);	
			x=convertx(input);	
			y=converty(input);
			shit:			
		if(input>=1&&input<10&&board[nowt][x][y]==0){//檢查input是否為1~9 
			
			if(*player==1)
				board[nowt][x][y]=1;
			else
				board[nowt][x][y]=-1;
			*player=-*player;//玩家交換
		}else{
			for(int l=0;l<3;l++)
			{
				for(int m=0;m<3;m++)
				{
					if(board[nowt][l][m]!=0)
						num++;
					if(num==9)
					{
						for(int i=0;i<3;i++){
							for(int j=0;j<3;j++){
								board[nowt][i][j]=0;	
							}	
						}
						num=0;
						goto shit;
					}
				}	
			}
			printf("輸入錯誤或該位置已被填寫\n");
			goto jump;
		}
		*nowtemp=*now;
		*now=input;
}
void convertlocation(int *input){//轉換鍵盤位置與陣列位置 
	switch(*input){
		case 1:
			*input=6;
			break;
		case 2:
			*input=7;
			break;
		case 3:
			*input=8;
			break;
		case 4:
			*input=3;
			break;
		case 5:
			*input=4;
			break;
		case 6:
			*input=5;
			break;
		case 7:
			*input=0;
			break;
		case 8:
			*input=1;
			break;
		case 9:
			*input=2;
			break;
	} 
}
int convertx(int input){
    switch(input){
        case 1:
        case 2:	
        case 3:
            return 2;
            break;
        case 4:
        case 5:	
        case 6:
            return 1;
            break;
        case 7:
        case 8:	
        case 9:
            return 0;
            break;
    }
}

int converty(int input){
    switch(input){
        
        case 3:
        case 6:
		case 9:	
            return 2;
            break; 
        case 2:	
        case 5:	
        case 8:	
            return 1;
            break;
        case 1:
        case 4:
        case 7:
            return 0;
            break;
    }
}
