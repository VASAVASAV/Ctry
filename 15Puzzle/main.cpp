#include "Head.hpp"

using namespace::std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	srand( time( 0 ) ); 
	int lol[4][4];//it will be our game field
	int i,j;
	for(i =0; i<4;i++)
	{
		for(j =0; j<4;j++)
		{
			lol[i][j]=i*4+j+1;
		}	
	}
	lol[3][3]=0;
	int NumOfInitMoves = 500;//
	int IPos, JPos;
	int temp;
	int Direction; //0 goes for up, 1 - right, 2 - down, 3 - left
	//Firstly, we need to initialize our field. We create "right" firled and then do a lot of random moves
	for(i=0; i<NumOfInitMoves;i++ )
	{
		IPos = FindIPosition(lol);//fiding i and j position of empty cell
		JPos = FindJPosition(lol);
		RandomingDirections:
		Direction = rand() % 4;
		if(JPos==0&&Direction ==3)//means that its trying to go int wrong way
		{
			goto RandomingDirections;
		}
		if(JPos==3&&Direction ==1)
		{
			goto RandomingDirections;
		}
		if(IPos==0&&Direction ==0)
		{
			goto RandomingDirections;
		}
		if(IPos==3&&Direction ==2)
		{
			goto RandomingDirections;
		}
		switch(Direction)//depending of direction we swap empty cell and its neighbor
		{
			case 0 :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos-1][JPos];
				lol[IPos-1][JPos] = temp;
				break;
			}
			case 1 :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos][JPos+1];
				lol[IPos][JPos+1] = temp;
				break;
			}
			case 2 :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos+1][JPos];
				lol[IPos+1][JPos] = temp;
				break;
			}
			case 3 :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos][JPos-1];
				lol[IPos][JPos-1] = temp;
				break;
			}
		}
	}
	
	Print(lol);//just showing user the result
	int NumOfSteps = 0;
    char Dir; 
	while(!IsVictorious(lol))//until we will return to the winning condition
	{
		IPos = FindIPosition(lol);
		JPos = FindJPosition(lol);
		Print(lol);
		cout<<endl;
		EnteringDirections:
		cout<<"Use wasd to move empty cell \n W to move up, S - down, A - left, D - right. \n Total steps made - "<<NumOfSteps;
		cout<<endl;
		cin>>Dir;
		if(!(Dir=='a'||Dir=='s'||Dir=='d'||Dir=='w'))
		{
			cout<<endl;
			cout<<"Wrong input. Please, try again"<<endl;
			goto EnteringDirections;
		}
		if(JPos==0&&Dir =='a')
		{
			cout<<endl;
			cout<<"Youre moving in wrong direction. Please, try again"<<endl;
			goto EnteringDirections;
		}
		if(JPos==3&&Dir =='d')
		{
			cout<<endl;
			cout<<"Youre moving in wrong direction. Please, try again"<<endl;
			goto EnteringDirections;
		}
		if(IPos==0&&Dir =='w')
		{
			cout<<endl;
			cout<<"Youre moving in wrong direction. Please, try again"<<endl;
			goto EnteringDirections;
		}
		if(IPos==3&&Dir =='s')
		{
			cout<<endl;
			cout<<"Youre moving in wrong direction. Please, try again"<<endl;
			goto EnteringDirections;
		}
		switch(Dir)//same as before
		{
			case 'w' :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos-1][JPos];
				lol[IPos-1][JPos] = temp;
				break;
			}
			case 'd' :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos][JPos+1];
				lol[IPos][JPos+1] = temp;
				break;
			}
			case 's' :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos+1][JPos];
				lol[IPos+1][JPos] = temp;
				break;
			}
			case 'a' :
			{
				temp = lol[IPos][JPos];
				lol[IPos][JPos] = lol[IPos][JPos-1];
				lol[IPos][JPos-1] = temp;
				break;
			}
		}
	}
	Print(lol);
	cout<<endl;
	cout<<"Congratulations! You are the Victor!"<<endl;
	return 0;
}

//im using two functions to return i and j positions separately because i dont want to use more complex objects like vectors or pointer arrays
int FindIPosition(int lol[][4])
{
	int i,j;
	for(i =0; i<4;i++)
	{
		for(j =0; j<4;j++)
		{
			if(lol[i][j]==0)
			{
				return i;
			}
		}	
	}
	return -1;
}

int FindJPosition(int lol[][4])
{
	int i,j;
	for(i =0; i<4;i++)
	{
		for(j =0; j<4;j++)
		{
			if(lol[i][j]==0)
			{
				return j;
			}
		}	
	}
	return -1;
}

int IsVictorious(int lol[][4])
{
	int i,j;
	for(i =0; i<4;i++)
	{
		for(j =0; j<4;j++)
		{
			if(i==3&&j==3)
			{
				break;
			}
			if(lol[i][j]!=i*4+j+1)
			{
				return 0;
			}
		}	
	}
	return 1;
}
