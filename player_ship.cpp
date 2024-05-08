#include "player_ship.h"
#include "funkcje.h"
#include <iostream>

player_ship::player_ship() :rozmiar(1)																			//konstruktor domyslny (stawia statek jendomasztowy na polu A1)
{
	std::cout << "Tworze statek jednomasztowy na polu A1" << std::endl;
	polozenie_c = 'a';
	polozenie_i = 1;
	kierunek = '0';
	trafienia = 0;
	nast = NULL;
}
player_ship::player_ship(int i, char c, int r, char k):rozmiar(r)												//konstruktor, kotry od razu ustawia pola protected na podane wartosci
{
	polozenie_c = c;
	polozenie_i = i;
	kierunek = k;
	trafienia = 0;
	nast = NULL;
}
player_ship::~player_ship()																						//destruktor usuwajacy cala liste obiektow
{
	delete nast;
}
void player_ship::set_polozenie_i(int i)																		//funkcja ustawiajaca polozenie_i
{
	polozenie_i = i;
}
void player_ship::set_polozenie_c(char c)																		//funkcja ustawiajaca polozenie_c
{
	polozenie_c = c;
}
void player_ship::set_kierunek(char k)																			//funkcja ustawiajaca kierunek
{
	kierunek = k;
}
int player_ship::get_trafienia()																				//funkcja pobierajaca wartosc trafienia
{
	return trafienia;
}
int player_ship::can_add_to_board(char tab[12][12])
{
	int pom1 = polozenie_i;
	int pom2 = polozenie_c - 'a'+1;
	if (tab[pom1 - 1][pom2 - 1] == 'x' || tab[pom1 - 1][pom2] == 'x' || tab[pom1 - 1][pom2 + 1] == 'x' || tab[pom1][pom2 - 1] == 'x' || tab[pom1][pom2]=='x'|| tab[pom1][pom2 + 1] == 'x' || tab[pom1 + 1][pom2 - 1] == 'x' || tab[pom1 + 1][pom2] == 'x' || tab[pom1 + 1][pom2 + 1] == 'x')
		return 0;
	if (rozmiar > 1)
	{
		switch (kierunek)
		{
		case('g'):
			if (pom1 - rozmiar+1 < 1)
				return 0;
			for (int i = 1; i < rozmiar; i++)
			{
				pom1--;
				if (pom1 >= 1)
				{
					if (tab[pom1 - 1][pom2 - 1] == 'x' || tab[pom1 - 1][pom2] == 'x' || tab[pom1 - 1][pom2 + 1] == 'x')
						return 0;
				}
			}
			break;
		case('d'):
			if (pom1 + rozmiar-1 > 10)
				return 0;
			for (int i = 1; i < rozmiar; i++)
			{
				pom1++;
				if (pom1 <= 10)
				{
					if (tab[pom1 + 1][pom2 - 1] == 'x' || tab[pom1 + 1][pom2] == 'x' || tab[pom1 + 1][pom2 + 1] == 'x')
						return 0;
				}
			}
			break;
		case('l'):
			if (pom2 - rozmiar+1 < 1)
				return 0;
			for (int i = 1; i < rozmiar; i++)
			{
				pom2--;
				if (pom2 >= 1)
				{
					if (tab[pom1 - 1][pom2 - 1] == 'x' || tab[pom1][pom2 - 1] == 'x' || tab[pom1 + 1][pom2 - 1] == 'x')
						return 0;
				}
			}
			break;
		case('p'):
			if (pom2 + rozmiar-1 > 10)
				return 0;
			for (int i = 1; i < rozmiar; i++)
			{
				pom2++;
				if (pom2 <= 10)
				{
					if (tab[pom1 - 1][pom2 + 1] == 'x' || tab[pom1][pom2 + 1] == 'x' || tab[pom1 + 1][pom2 + 1] == 'x')
						return 0;
				}
			}
			break;
		}
	}
	return 1;																																			//funkcja sprawdza czy dany statek moze wejsc na plansze (czy nie dotyka innego statku i czy nie wychodzi poza nia)
}																																						//jesli nie ma problemu zwraca 1 a jesli choc jedna wartosc jest bledna zwraca 0
void player_ship::add_to_board(char tab[12][12])
{
	int i=polozenie_i;
	char c=polozenie_c, k=kierunek;
	int r = rozmiar;
	while (!(this->can_add_to_board(tab)))																												//sprawdza czy mozna wstawic na plansze podany statek zgodnie z zasadami (funkcja wyzej)
	{
		std::cout << "Statku nie mozna umiescic na planszy. Nielegalny ruch! Twoja plansza narazie to: " << std::endl;
		wypisz_tab(tab);																																//wypisuje tablice gracza ze statkami (z pliku funkcje.h)
		std::cout << "\nSprobuj wprowadzic dane jeszcze raz:" << std::endl;
		do
		{
			if (r == 1)
			{
				std::cout << "Podaj wspolrzedne pola na ktorym ma stac jednomasztowiec (najpierw cyfra np 8g): ";
				while (getchar() != '\n')
					;
				scanf_s("%d", &i);
				scanf_s("%c", &c, 1);
				c = tolower(c);
			}
			else if(r==2)
			{
				std::cout << "Podaj wspolrzedne jednego z pol na ktorym ma stac dwumasztowiec (najpierw cyfra np 8g): ";
				while (getchar() != '\n')
					;
				scanf_s("%d", &i);
				scanf_s("%c", &c, 1);
				std::cout << "Podaj kierunek w ktorym ma stac dwumasztowiec (dostepne kierunki to g-gora, d-dol, l-lewo, p-prawo): ";
				while (getchar() != '\n')
					;
				scanf_s("%c", &k, 1);
				c = tolower(c);
				k = tolower(k);
				r = 2;
			}
			else if (r == 3)
			{
				std::cout << "Podaj wspolrzedne jednego ze skrajnych pol na ktorym ma stac trojmasztowiec (najpierw cyfra np 8g): ";
				while (getchar() != '\n')
					;
				scanf_s("%d", &i);
				scanf_s("%c", &c, 1);
				std::cout << "Podaj kierunek w ktorym ma stac trojmasztowiec (dostepne kierunki to g-gora, d-dol, l-lewo, p-prawo): ";
				while (getchar() != '\n')
					;
				scanf_s("%c", &k, 1);
				c = tolower(c);
				k = tolower(k);
				r = 3;
			}
			else if (r == 4)
			{
				std::cout << "Podaj wspolrzedne jednego ze skrajnych pol na ktorym ma stac czteromasztowiec (najpierw cyfra np 8g): ";
				while (getchar() != '\n')
					;
				scanf_s("%d", &i);
				scanf_s("%c", &c, 1);
				std::cout << "Podaj kierunek w ktorym ma stac czteromasztowiec (dostepne kierunki to g-gora, d-dol, l-lewo, p-prawo): ";
				while (getchar() != '\n')
					;
				scanf_s("%c", &k, 1);
				c = tolower(c);
				k = tolower(k);
				r = 4;
			}
		} while (!(if_ship_input_ok(i, c, r, k)));
		this->set_polozenie_c(c);
		this->set_polozenie_i(i);
		this->set_kierunek(k);
	}
	int pom1 = polozenie_i;
	int pom2 = polozenie_c - 'a'+1;
	tab[pom1][pom2] = 'x';
	if (rozmiar > 1)
	{
		for (int i = 1; i < rozmiar; i++)
		{
			switch (kierunek)
			{
			case('g'):
				tab[pom1-i][pom2] = 'x';
				break;
			case('d'):
				tab[pom1+i][pom2] = 'x';
				break;
			case('l'):
				tab[pom1][pom2-i] = 'x';
				break;
			case('p'):
				tab[pom1][pom2+i] = 'x';
				break;
			}
		}
	}																																					//funkcja przy pomocy funkcji can_add_to_board dodaje statek na plansze, jesli nie moze tego zrobic pozwala uzytkownikowi na wpisanie
}																																						//poprawnych danych az do skutku po czym na planszy wymienia odpowiednie pola na x aby zaznaczyc gdzie jest statek
void player_ship::shoot(char shoot_tab[12][12], char enemy_tab[12][12],int &i,char &c)
{
	std::cout << "\nPodaj pole, w ktore chcesz oddac strzal (najpierw cyfra np 8g): ";
	while (getchar() != '\n')
		;
	scanf_s("%d", &i);
	scanf_s("%c", &c, 1);
	c = tolower(c);
	while (!(if_shoot_input_ok(i,c)) || shoot_tab[i][c-'a'+1]!='?')
	{
		std::cout << "Nie poprawne dane pola do oddania strzalu. Sprobuj ponownie" << std::endl;
		std::cout << "Podaj pole, w ktore chcesz oddac strzal (najpierw cyfra np 8g): ";
		while (getchar() != '\n')
			;
		scanf_s("%d", &i);
		scanf_s("%c", &c, 1);
		c = tolower(c);
	}
	int pom1 = i;
	int pom2 = c - 'a' + 1;
	shoot_tab[pom1][pom2] = enemy_tab[pom1][pom2];
	if (enemy_tab[pom1][pom2] == 'x')
	{
		enemy_tab[pom1][pom2] = 'o';
		trafienia++;
	}
}																																						//funkcja sprawdza czy podane wartosci do strzalu sa poprawne i czy wczesniej strzal nie zostal juz tam oddany i
																																						//pozwala uzytkownikowi na poprawe danych az do skutku po czym zamienia ? na . lub x w zaleznosci od trafienia oraz
																																						//jesli trafiono zamienia trafiony statek na o na planszy drugiego gracza i dodaje 1 do wartosci trafienia glowy listy