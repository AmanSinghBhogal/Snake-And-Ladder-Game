//Snake And Ladder Game
//Project 1: Built Year- 2019


#include<iostream>
#include<cstdlib>
#include<random>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;



string square="01234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950";
string nul= "          ";
string ernul= "          ";
string erase="01234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950";

class game
{	
	int i,c,p,a,b,r,k,j,t;
	long int d;
	char mark;
	public:
		game()
		{       i=1;
			d=2;
			a=b=0;
		}
		void move();	//Used to make the move on Board.
		void board();	//Prints the Board.
		void play();	//Used to calculate the dice number.
		void win();		//Checks if any player has won.
		void marks();	//used to check which mark to use for which player and to mark it on board.
		void player();	//Selects which player's turn it is.
		void erase2();	//used to erase the mark from previous position once a new move is made.
		void Ladder();	//Prints the Ladder.
};

int main()		//Main Function.
{	
	game g1;
	g1.play();
	return 0;
}

void game::player()
{	p=(d%2==0?1:2);

		if(d%2==0)
			d++;
			else if(d>2)
				d--;
}
void game::play()
{	char j;
	//randomize();
	srand(time(NULL));
	do{
		board();
		player();
		cout<<"Player "<<p<<":";
		cin>>j;
		if(j=='Q'||j=='q')
			exit(0);
		else
		{	board();
			c=((rand()%6)+1);
			r=c;
			cout<<"Player "<<p<<":";
			cout<<c;
			getchar();
			getchar();
			move();
			board();
			if(r==6)
			{	if(p==1)
				{	d--; }
				else if(p==2)
				{	d++;  }
				continue;
			}
		}
	}while(i!=0);
}
void game::win()
{	system("cls");
	board();
	if(a==50||b==50)
	{	cout<<"\n\n";
		cout.width(37);
		cout<<"Player "<<(mark=='$'?1:2)<<" Wins!\n\t\t\t\tCONGRATS....."<<endl;
		getchar();
		i=0;
		exit(0);
	}
}

void game::board()
{	system("cls");
	cout.width(48);
	cout<<"Snake And Ladder\n\n";
	cout.width(54);
	cout<<"Player 1 ($)  -  Player 2 (#)" << endl ;
	cout<<"              ____ ____ ____ ____ ____ ____ ____ ____ ____ ____    ___________"  << endl;
	cout << "             |    |    |    |    |    |    |    |    |    |Win |  | Ladders:  |"<<endl;
	cout << "             | " << square[72] << square[73] << " | " << square[74] << square[75] << " | " << square[76] << square[77] << " | " << square[78] << square[79] << " | " << square[80] << square[81] << " | " << square[82] << square[83] << " | "<< square[84] << square[85] << " | " << square[86] << square[87] << " | " << square[88] << square[89] << " | "<< square[90] << square[91] <<" |  |   13-22   |"<<endl;
	cout << "             |____|___*|____|/___|____|___\\|____|____|___*|____|  |   16-38   |"<<endl;
	cout << "             |    |    |*  /|    |    |    | \\  |    |   *|*   |  |   19-46   |"<<endl;
	cout << "             | " << square[52] << square[53] << " | " << square[54] << square[55] << " | " << square[56] << square[57] << " | " << square[58] << square[59] << " | " << square[60] << square[61] << " | " << square[62] << square[63] << " | "<< square[64] << square[65] << "\\| " << square[66] << square[67] << " | " << square[68] << square[69] << " |*"<< square[70] << square[71] <<" |  |   33-44   |"<<endl;
	cout << "             |___*|____|___*|____|____|____|____|\\___|____|*___|  |___________|"<<endl;
	cout << "             |   *|    |    |*   |    |    |   /|  \\ |    |*   |   ___________" << endl;
	cout << "             | " << square[32] << square[33] << " | " << square[34] << square[35] << " | " << square[36] << square[37] << " | " << square[38] << square[39] << " | " << square[40] << square[41] << " | " << square[42] << square[43] << " | "<< square[44] << square[45] << " | " << square[46] << square[47] << "\\| " << square[48] << square[49] << " |*"<< square[50] << square[51] <<" |  | Snakes:   |"<<endl;
	cout << "             |____|___\\|____|____|____|*___|/___|____|\\___|*___|  |   26-4    |"<<endl;
	cout << "             |    |    |\\   |    |   *|   /|    |    |  \\ |*   |  |   31-21   |"<<endl;
	cout << "             | " << square[12] << square[13] << " | " << square[14] << square[15] << " | " << square[16] << square[17] << " | " << square[18] << square[19] << " | " << square[20] << square[21] << " | " << square[22] << square[23] << " | "<< square[24] << square[25] << " | " << square[26] << square[27] << " | " << square[28] << square[29] << " | "<< square[30] << square[31] <<" |  |   42-24   |"<<endl;
	cout << "             |____|____|____|____|*___|____|____|____|____|____|  |   49-20   |"<<endl;
	cout << "             |Home|    |    |   *|    |    |    |    |    |    |  |___________|"<<endl;
	cout << "             | " << square[1]<<nul[1] << " | " << square[2]<<nul[2] << " | " << square[3]<<nul[3]<< " | " << square[4]<<nul[4] << " | " << square[5] <<nul[5]<< " | " << square[6]<<nul[6]<< " | "<< square[7]<<nul[7] << " | " << square[8]<<nul[8] << " | " << square[9] <<nul[9]<< " | "<< square[10]<<square[11] <<" |" << endl;
	cout << "             |____|____|____|____|____|____|____|____|____|____|" << endl;
	cout.width(53);
	cout<<"PRESS P TO PLAY AND Q TO QUIT."<<endl;
}

void game::marks()
{	if(p==1)
	{	mark='$';
		j=a;
		a+=c;

		if(a>50)
			a-=c;
		c=a;
	}
	else if(p==2)
	{	mark='#';
		k=b;
		b+=c;
		if(b>50)
			b-=c;
		c=b;
	}
}

void game::erase2()
{	if(p==1&&c!=j&&j!=b)
	{	if(j<10)
		{	if(t==j)
			{	square[t]=erase[j];
				nul[t]=ernul[j];
			}
		}
		else if(j>=10)
		{	if(t==(10+((j-10)*2)))
			{	square[t]=erase[t];
				square[t+1]=erase[t+1];
			}
		}
	}
	if(p==2&&c!=k&&k!=a)
	{	if(k<10)
		{	if(t==k)
			{	square[t]=erase[k];
				nul[t]=ernul[k];
			}
		}
		else if(k>=10)
		{	if(t==(10+((k-10)*2)))
			{	square[t]=erase[t];
				square[t+1]=erase[t+1];
			}
		}
	}
}

void game::Ladder()
{	if(p==1)
	{	if(c==19)
		{	a=46;
			c=a;
		}
		else if(c==16)
		{	a=38;
			c=a;
		}
		else if(c==13)
		{	a=22;
			c=a;
		}
		else if(c==33)
		{	a=44;
			c=a;
		}
		else if(c==31)
		{	a=21;
			c=a;
		}
		else if(c==26)
		{	a=4;
			c=a;
		}
		else if(c==49)
		{	a=20;
			c=a;
		}
		else if(c==42)
		{	a=24;
			c=a;
		}
	}
	else
	{	if(c==19)
		{	b=46;
			c=b;
		}
		else if(c==16)
		{	b=38;
			c=b;
		}
		else if(c==13)
		{	b=22;
			c=b;
		}
		else if(c==33)
		{	b=44;
			c=b;
		}
		else if(c==42)
		{	b=24;
			c=b;
		}
		else if(c==49)
		{	b=20;
			c=b;
		}
		else if(c==26)
		{	b=4;
			c=b;
		}
		else if(c==31)
		{	b=21;
			c=b;
		}
	}
}

void game::move()
{	marks();
	Ladder();
	for(int l=0;l<=91;l++)
	{	t=l;
		if(c<10)
		{	if(l==c)
			{	if(a==b)
				{	square[l]=(p==1?'#':'$');
					nul[l]=mark;
				}
				else
				{	square[l]=mark;
					nul[l]=mark;
				}
			}
			erase2();
		}

		else if(c>=10)
		{	if(l==(10+((c-10)*2)))
			{	if(a==b)
				{	square[l]=(p==1?'#':'$');
					square[l+1]=mark;
				}
				else
				{	square[l]=mark;
					square[l+1]=mark;
				}
			}
			erase2();
		}
	}
	win();
}