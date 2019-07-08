#include "Head.hpp"

void Print(int lol[][4])
{
	system("CLS");
	char MatrixOfSymbols[12][12];//12 = 3*4, cause every number is printed as 3*3 console pseudographic picture
	int i,j;
	for(i=0; i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			MatrixOfSymbols[i*3][j*3]=(char)(201);//angles are same for all
			MatrixOfSymbols[i*3+2][j*3]=(char)(200);
			MatrixOfSymbols[i*3][j*3+2]=(char)(187);
			MatrixOfSymbols[i*3+2][j*3+2]=(char)(188);
			if(lol[i][j]==0)//painting arrows if its an empty cell
			{
				MatrixOfSymbols[i*3+1][j*3]=(char)(17);
				MatrixOfSymbols[i*3+1][j*3+2]=(char)(16);
				MatrixOfSymbols[i*3][j*3+1]=(char)(30);
				MatrixOfSymbols[i*3+2][j*3+1]=(char)(31);
				MatrixOfSymbols[i*3+1][j*3+1]=' ';
			}
			else
			{
				MatrixOfSymbols[i*3+1][j*3]=(char)(186);
				MatrixOfSymbols[i*3+1][j*3+2]=(char)(186);
				MatrixOfSymbols[i*3][j*3+1]=(char)(205);
				MatrixOfSymbols[i*3+2][j*3+1]=(char)(205);
				if(lol[i][j]<10)
				{
					MatrixOfSymbols[i*3+1][j*3+1]=(char)(48+lol[i][j]);
				}
				else
				{
					switch(lol[i][j])
					{
						case 10: 
						{
							MatrixOfSymbols[i*3+1][j*3+1]='A';
							break;
						}
						case 11: 
						{
							MatrixOfSymbols[i*3+1][j*3+1]='B';
							break;
						}
						case 12: 
						{
							MatrixOfSymbols[i*3+1][j*3+1]='C';
							break;
						}
						case 13: 
						{
							MatrixOfSymbols[i*3+1][j*3+1]='D';
							break;
						}
						case 14: 
						{
							MatrixOfSymbols[i*3+1][j*3+1]='E';
							break;
						}
						case 15: 
						{
							MatrixOfSymbols[i*3+1][j*3+1]='F';
							break;
						}
					}
				}
			}
		}
	}
	//prining the result
	for(i=0; i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			cout<<(char)(MatrixOfSymbols[i][j]);
		}
		cout<<endl;
	}
}
