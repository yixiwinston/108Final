#include "FunlinBreakfast.h"
#include <stdio.h>
#include <stdlib.h>
void display (int board[][3][3],int bigboard[3][3],int now)
{
	system("cls");
	int temp1[81]={0};
	int temp2[9]={0};
	int count;
	char bc;
	char nets[29]={' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char netl[29]={'-','-','-','-','-','-','-','-','-','|','-','-','-','-','-','-','-','-','-','|','-','-','-','-','-','-','-','-','-'};
	char dp[29][29];
	//預設表格 
	for(int i=0;i<29;i++)
	{
		for(int j=0;j<29;j++)
		{
			dp[i][j]=nets[j]; 
		}
	}
	for(int i=0;i<29;i++)
	{
		dp[9][i]=netl[i];
		dp[19][i]=netl[i];
	}
	
	//解析三維資料陣列	
	count=0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				temp1[count]=board[i][j][k];
				count++;
			}
		}
	}
	//解析二維資料陣列 
	
	count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			temp2[count]=bigboard[i][j];
			count++;
		}
	}
	//重組矩陣編碼繪成二維陣列圖像 
	count=0;
	for(int i=0;i<=20;i=i+10)
	{
		for(int j=0;j<=20;j=j+10)
		{
				bc=' ';
				if(temp2[count]==1)
					bc='O';
				else if(temp2[count]==-1)
					bc='X';
				
				for(int m=j+1;m<=j+7;m++)
				{
					dp[i][m]=bc;
					dp[i+8][m]=bc;
				}	
				for(int n=1;n<8;n++)
				{
					for(int o=j;o<j+9;o=o+8)
					{
						dp[i+n][o]=bc;
					}
				}
				count++;	
		}
	}
	count=0;
    convertlocation(&now);
    for(int i=1;i<=21;i=i+10){
        for(int j=1;j<=21;j=j+10){
            if(now==count){
                for(int m=1;m<6;m++){
                    dp[i][j+m]='-';
                    dp[i+6][j+m]='-';
                }
                for(int n=1;n<6;n++){
                    for(int o=0;o<7;o=o+6){
                        dp[i+n][j+o]='|';
                    }
                }
            }
            count++;
        }
    }
	count=0;
	for(int m=2;m<=22;m=m+10)
	{
		for(int n=2;n<=22;n=n+10)
		{
			for(int o=m;o<m+6;o=o+2)
			{
				for(int p=n;p<n+6;p=p+2)
				{
					if(temp1[count]==1)
					{
						dp[o][p]='O';
					}
					else if(temp1[count]==-1)
					{
						dp[o][p]='X';
					}	
					count++;
				}
			}
		}
	}
	//輸出二維陣列 
	for(int i=0;i<29;i++)
	{
		for(int j=0;j<29;j++)
		{
			printf("%c",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

