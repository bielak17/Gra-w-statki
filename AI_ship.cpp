#include "AI_ship.h"
#include "funkcje.h"
#include <iostream>

AI_ship::AI_ship():player_ship()																							//konstruktor domyslny
{
	;
}
AI_ship::AI_ship(int i, char c, int r, char k) :player_ship(i, c, r, k)														//konstruktor, kotry od razu ustawia pola protected na podane wartosci
{
	;
}
void AI_ship::add_to_board(char tab[12][12])
{
	int AI_i = polozenie_i;
	char AI_c = polozenie_c, AI_k = kierunek;
	int AI_r = rozmiar;
	while (!(this->can_add_to_board(tab)))																					//sprawdza czy mozna wstawic na plansze podany statek zgodnie z zasadami (zwraca 0 jesli nie mozna) (funkcja z klasy player_ship)
	{
		do
		{
			if (AI_r == 1)
			{
				int a1, a2;
				a1 = rand() % 10;
				a2 = rand() % 10;
				AI_i = a1;
				AI_c = a2 + 'a';
			}
			else if (AI_r == 2)
			{
				int a1, a2, a3;
				a1 = rand() % 10;
				a2 = rand() % 10;
				a3 = rand() % 4;
				AI_i = a1;
				AI_c = a2 + 'a';
				if (a3 == 0)
					AI_k = 'g';
				else if (a3 == 1)
					AI_k = 'd';
				else if (a3 == 2)
					AI_k = 'p';
				else
					AI_k = 'l';
			}
			else if (AI_r == 3)
			{
				int a1, a2, a3;
				a1 = rand() % 10;
				a2 = rand() % 10;
				a3 = rand() % 4;
				AI_i = a1;
				AI_c = a2 + 'a';
				if (a3 == 0)
					AI_k = 'g';
				else if (a3 == 1)
					AI_k = 'd';
				else if (a3 == 2)
					AI_k = 'p';
				else
					AI_k = 'l';
			}
			else if (AI_r == 4)
			{
				int a1, a2, a3;
				a1 = rand() % 10;
				a2 = rand() % 10;
				a3 = rand() % 4;
				AI_i = a1;
				AI_c = a2 + 'a';
				if (a3 == 0)
					AI_k = 'g';
				else if (a3 == 1)
					AI_k = 'd';
				else if (a3 == 2)
					AI_k = 'p';
				else
					AI_k = 'l';
			}
		} while (!(if_ship_input_ok(AI_i, AI_c, AI_r, AI_k)));
		this->set_polozenie_c(AI_c);
		this->set_polozenie_i(AI_i);
		this->set_kierunek(AI_k);
	}
	int pom1 = polozenie_i;
	int pom2 = polozenie_c - 'a' + 1;
	tab[pom1][pom2] = 'x';
	if (rozmiar > 1)
	{
		for (int i = 1; i < rozmiar; i++)
		{
			switch (kierunek)
			{
			case('g'):
				tab[pom1 - i][pom2] = 'x';
				break;
			case('d'):
				tab[pom1 + i][pom2] = 'x';
				break;
			case('l'):
				tab[pom1][pom2 - i] = 'x';
				break;
			case('p'):
				tab[pom1][pom2 + i] = 'x';
				break;
			}
		}
	}																														//funkcja sprawdza czy mozna wstawic statek o podanych parametrach na plansze jesli nie to losuje nowe wartosci
}																															//i sprawdza ponownie az do sukcesu po czym zamienia . na x na planszy tam gdzie powinien stac statek
void AI_ship::shoot(char shoot_tab[12][12], char enemy_tab[12][12],int &AI_i,char &AI_c)
{
	do
	{
		int a1, a2;
		a1 = rand() % 10;
		a2 = rand() % 10;
		AI_i = a1;
		AI_c = a2 + 'a';
	} while (!(if_shoot_input_ok(AI_i,AI_c)) || shoot_tab[AI_i][AI_c - 'a' + 1] != '?');
	int pom1 = AI_i;
	int pom2 = AI_c - 'a' + 1;
	shoot_tab[pom1][pom2] = enemy_tab[pom1][pom2];
	if (enemy_tab[pom1][pom2] == 'x')
	{
		enemy_tab[pom1][pom2] = 'o';
		trafienia++;
	}
}																															//funkcja losuje wspolrzedne tablicy i oddaje tam strzal jesli wartosci sa poprawne i nie oddano tam wczesniej strzalu
																															//w przeciwnym wypadku losuje jeszcze raz, zamienia ? na . lub x w zaleznosci od trafienia oraz jesli trafiono zamienia trafiony statek na o na planszy drugiego gracza i dodaje 1 do wartosci trafienia glowy listy