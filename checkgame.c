#include <stdio.h>
#include <stdlib.h>
#include "FunlinBreakfast.h"
void checkgame(int board[9][3][3],int bigboard[3][3],int input,int *winner)
{
    int i,j;
    int win = 0;//check win =3or-3
	int bigwin=0;//check bigwin =3or-3
	int nowtemp=input;
	convertlocation(&nowtemp);
//=========================smallboardそ어==================================
    for(i=0;i<3;i++)
	{
       for (j=0;j<3;j++)
	   {
        	win+=board[nowtemp][i][j];                     
       }
    	checkbigboard(win,input,bigboard);
       win=0;                 
    }
    for(i=0;i<3;i++)
	{
       for (j=0;j<3;j++)
	    {
          win += board[nowtemp][j][i];                     
        }
		checkbigboard(win,input,bigboard);
       win = 0;                       
    }
//=============================그=====================
    win = board[nowtemp][0][0] + board[nowtemp][1][1] + board[nowtemp][2][2];
	checkbigboard(win,input,bigboard);
	win = 0;    
   	win = board[nowtemp][0][2] + board[nowtemp][1][1] + board[nowtemp][2][0];
	checkbigboard(win,input,bigboard);
	win = 0;
	
	
//===============================bigboard======================================     
   for(i=0;i<3;i++)
	{
       for (j=0;j<3;j++)
	    {
          bigwin += bigboard[j][i];                     
        }
       if(bigwin ==3)
	    {
    		*winner=1;
    		
        }
       else if(bigwin == -3) 
	    {
 			*winner=-1;
        }
       bigwin = 0;                       
    }
    for(i=0;i<3;i++)
	{
       for (j=0;j<3;j++)
	    {
          bigwin += bigboard[i][j];                     
        }
       if(bigwin ==3)
	    {
        	*winner=1;
        }
       else if(win == -3) 
	    {
         	*winner=-1;
        }
       bigwin = 0;                       
    }
   //========================그퐑=====================
	bigwin=bigboard[0][0]+bigboard[1][1]+bigboard[2][2];
	if(bigwin == 3)
	{
        *winner=1;
    }
    else if(bigwin == -3)  
	{
        *winner=-1;
    }
    bigwin=0;
  	bigwin=bigboard[0][3]+bigboard[1][1]+bigboard[2][0];
	if(win == 3)
	{
        *winner=1;
	}
    else if(win == -3)
	{
        *winner=-1;
	}
	bigwin=0;
}

void checkbigboard(int win,int z,int bigboard[3][3])
{
	int x,y; 
	x=convertx(z);	
	y=converty(z);
	if(bigboard[x][y]==0)
    {		
       	if(win == 3)
		{
    		switch(z)
       		{
       		case 1:
				bigboard[2][0]=1;
				break;	
			case 2:
				bigboard[2][1]=1;
				break;
			case 3:
				bigboard[2][2]=1;
				break;
			case 4:
				bigboard[1][0]=1;					
				break;
			case 5:
				bigboard[1][1]=1;
				break;
			case 6:
				bigboard[1][2]=1;
				break;
			case 7:
				bigboard[0][0]=1;
				break;
			case 8:
				bigboard[0][1]=1;
				break;
			case 9:
				bigboard[0][2]=1;
				break;					
			}					
       	}
		else if(win == -3)  
	    {
			switch(z)
       		{
       		case 1:
				bigboard[2][0]=-1;
				break;	
			case 2:
				bigboard[2][1]=-1;
				break;
			case 3:
				bigboard[2][2]=-1;
				break;
			case 4:
				bigboard[1][0]=-1;
				break;
			case 5:
				bigboard[1][1]=-1;
				break;
			case 6:
				bigboard[1][2]=-1;
				break;
			case 7:
				bigboard[0][0]=-1;
				break;
			case 8:
				bigboard[0][1]=-1;
				break;
			case 9:
				bigboard[0][2]=-1;
				break;				
			}					
        } 
	}
       		
}

