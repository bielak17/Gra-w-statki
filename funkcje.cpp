#include "funkcje.h"
#include <iostream>
#include <fstream>

void create_boards(char player_board[12][12], char player_shoot_board[12][12], char AI_board[12][12], char AI_shoot_board[12][12])
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == 0 || i == 11)
			{
				player_board[i][j] = '_';
				player_shoot_board[i][j] = '_';
				AI_board[i][j] = '_';
				AI_shoot_board[i][j] = '_';
			}
			else if (j == 0 || j == 11)
			{
				player_board[i][j] = '|';
				player_shoot_board[i][j] = '|';
				AI_board[i][j] = '|';
				AI_shoot_board[i][j] = '|';
			}
			else
			{
				player_board[i][j] = '.';
				player_shoot_board[i][j] = '?';
				AI_board[i][j] = '.';
				AI_shoot_board[i][j] = '?';
			}
		}
	}																																					//uzupelnia 4 tablice 12x12 w taki sposob, ze 1 i 12 kolumna oraz wiersz jest sciana ( | lub _ )
}																																						//srodek jest . w przypadku zwyklej planszy a ? w przypadku planszy do strzelania

int if_ship_input_ok(int i, char c, int r, char k)
{
	if (i < 1 || i>10)
	{
		return 0;
	}
	if (r < 1 || r>4)
	{
		return 0;
	}
	if (c < 'a' || c>'j')
	{
		return 0;
	}
	if (k != 'g' && k != 'd' && k != 'p' && k != 'l' && k != '0')
	{
		return 0;
	}
	return 1;
}																																						//funkcja zwraca 1 jesli wszystkie 4 wartosci sa poprawne a zwraca 0 gdy chociaz jedna jest niepoprawna

void wypisz_tab(char tab[12][12])
{
	int c = 0;
	putchar('\n');
	std::cout << "   A B C D E F G H I J" << std::endl;
	for (int i = 1; i < 11; i++)
	{
		if (i > 0 && i < 11)
		{
			c++;
			std::cout << c << " ";
			if (c < 10)
				std::cout << " ";
		}
		else
			std::cout << "   ";
		for (int j = 1; j < 11; j++)
		{
			std::cout << tab[i][j] << " ";
		}
		putchar('\n');
	}
}																																						//funkcja wypisuje w konsoli srodki tablic 12x12 (tylko wiersze i kolumny od 2 do 11)

int if_hit(int i, char c, char shoot_tab[12][12])
{
	int pom1 = i;
	int pom2 = c - 'a' + 1;
	if (shoot_tab[pom1][pom2] == 'x')
		return 1;
	else
		return 0;
}																																						//funkcja sprawdza czy w podanym punkcie w ktory zostal oddany strzal stoi statek zwraca 1 jesli byl i 0 jesli pole bylo puste

void change_board_to_blank(int i, int j, char shoot_tab[12][12])
{
	if (shoot_tab[i + 1][j - 1] == '?')
		shoot_tab[i + 1][j - 1] = '.';
	if (shoot_tab[i + 1][j] == '?')
		shoot_tab[i + 1][j] = '.';
	if (shoot_tab[i + 1][j + 1] == '?')
		shoot_tab[i + 1][j + 1] = '.';
	if (shoot_tab[i][j - 1] == '?')
		shoot_tab[i][j - 1] = '.';
	if (shoot_tab[i][j + 1] == '?')
		shoot_tab[i][j + 1] = '.';
	if (shoot_tab[i - 1][j - 1] == '?')
		shoot_tab[i - 1][j - 1] = '.';
	if (shoot_tab[i - 1][j] == '?')
		shoot_tab[i - 1][j] = '.';
	if (shoot_tab[i - 1][j + 1] == '?')
		shoot_tab[i - 1][j + 1] = '.';
}																																						//funkcja zamenia wszystkie ? na . na planszy do strzelania wokol punktu [i][j]

int if_sink(int i, char c, char enemy_tab[12][12], char shoot_tab[12][12])
{
	int j = 1, p = 0;
	int pom1 = i;
	int pom2 = c - 'a' + 1;
	if (enemy_tab[pom1 - 1][pom2] != 'x' && enemy_tab[pom1 + 1][pom2] != 'x' && enemy_tab[pom1][pom2 - 1] != 'x' && enemy_tab[pom1][pom2 + 1] != 'x')
	{
		if (enemy_tab[pom1 - 1][pom2] == 'o')
		{
			if (enemy_tab[pom1 - 2][pom2] == 'o')
			{
				if (enemy_tab[pom1 - 3][pom2] != 'x')
					p = 1;
			}
			else if (enemy_tab[pom1 - 2][pom2] != 'x')
				p = 1;
		}
		else if (enemy_tab[pom1 + 1][pom2] == 'o')
		{
			if (enemy_tab[pom1 + 2][pom2] == 'o')
			{
				if (enemy_tab[pom1 + 3][pom2] != 'x')
					p = 1;
			}
			else if (enemy_tab[pom1 + 2][pom2] != 'x')
				p = 1;
		}
		else if (enemy_tab[pom1][pom2 - 1] == 'o')
		{
			if (enemy_tab[pom1][pom2 - 2] == 'o')
			{
				if (enemy_tab[pom1][pom2 - 3] != 'x')
					p = 1;
			}
			else if (enemy_tab[pom1][pom2 - 2] != 'x')
				p = 1;
		}
		else if (enemy_tab[pom1][pom2 + 1] == 'o')
		{
			if (enemy_tab[pom1][pom2 + 2] == 'o')
			{
				if (enemy_tab[pom1][pom2 + 3] != 'x')
					p = 1;
			}
			else if (enemy_tab[pom1][pom2 + 2] != 'x')
				p = 1;
		}
		else
			p = 1;
	}
	if (p)
	{
		j = 1;
		change_board_to_blank(pom1, pom2, shoot_tab);
		while (shoot_tab[pom1 - j][pom2] == 'x')
		{
			change_board_to_blank(pom1 - j, pom2, shoot_tab);
			j++;
		}
		j = 1;
		while (shoot_tab[pom1 + j][pom2] == 'x')
		{
			change_board_to_blank(pom1 + j, pom2, shoot_tab);
			j++;
		}
		j = 1;
		while (shoot_tab[pom1][pom2 - j] == 'x')
		{
			change_board_to_blank(pom1, pom2 - j, shoot_tab);
			j++;
		}
		j = 1;
		while (shoot_tab[pom1][pom2 + j] == 'x')
		{
			change_board_to_blank(pom1, pom2 + j, shoot_tab);
			j++;
		}
		return 1;
		}
	else
		return 0;																																		//funkcja sprawdza czy statek na polu [i][c] zostal zatopiony jesli tak zwraca 1 a jesli nie zwraca 0
}																																						//jesli tak to dodatkowo uzywajac funkcji change_board_to_blank zamienia wszystkie ? wokol zatopionego statku na puste pola .

int if_shoot_input_ok(int i, char c)
{
	if (i > 0 && i < 11 && c >= 'a' && c <= 'j')
		return 1;
	else
		return 0;
}																																						//funkcja srpawdza czy podane wspolrzedne punktu na planszy sa poprawne zwraca jeden jesli tak

void save_score(char nick[],int trafienia,int wynik)
{
	std::ifstream in("Wyniki.txt");
	std::ofstream out("Wyniki.txt", std::ios::app);
	int pom = 0;
	char buf[100];
	while (in.getline(buf, sizeof(buf)))
	{
		pom++;
	}
	pom = pom / 2 + 1;
	time_t czas;
	struct tm timeinfo;
	char buf_time[100];
	time(&czas);
	localtime_s(&timeinfo, &czas);
	asctime_s(buf_time, 100, &timeinfo);
	int zycie = 20 - trafienia;
	if (wynik == 0)
	{
		out << pom << ". " << buf_time << "\tGRACZ " << nick << " wygral pozostalo mu "<<zycie <<" pol statkow na planszy." << std::endl;
	}
	else if (wynik == 2)
	{
		out << pom << ". " << buf_time << "\tGRACZ " << nick << " przegral pozostalo mu " << zycie << " pol statkow do trafienia." << std::endl;
	}
}																																					//funkcja otwiera plik Wyniki do zapisu zlicza poprzednie gry i potem zapisuje w nowej linijce
																																					//w kolejnosci numer gry, data, wygrana/przegrana i ile zostalo/zabraklo pol statkow.