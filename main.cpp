#include <iostream>
#include "player_ship.h"
#include "AI_ship.h"
#include "funkcje.h"

int main()
{
	srand((unsigned)time(NULL));
	char nick[128];
	std::cout << "\t\t\tWITAJ W GRZE W STATKI.\nGRA ODBYWA SIE PRZECIWKO KOMPUTEROWI. ABY ROZPOCZAC ROZGRYWKE PODAJ SWOJ NICK: ";
	scanf_s("%127s", nick, 128);																											//pobranie nicku
	char player_board[12][12];
	char player_shoot_board[12][12];
	char AI_board[12][12];
	char AI_shoot_board[12][12];
	create_boards(player_board, player_shoot_board, AI_board, AI_shoot_board);																//stworzenie plansz dla gracza i komputera
	int i, r, AI_i, AI_r;
	char c, k, AI_c, AI_k;
	player_ship* player_head = NULL;
	player_ship* AI_head = NULL;
	for (int j = 0; j < 10; j++)																											//umieszczanie statkow na plansze przez gracza i AI
	{
		if (j < 1)																															//umieszczanie czteromasztowca
		{
			do
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
				if (!(if_ship_input_ok(i, c, r, k)))
					std::cout << "Niepoprawne dane wejsciowe. Sprobuj jeszcze raz:" << std::endl;
			} while (!(if_ship_input_ok(i, c, r, k)));																						//sprawdza czy podane wartosci sa odpowiednie dla obiektu player_ship (zwraca 0 jesli cokolwiek jest zle)
			player_ship* S4 = new player_ship(i, c, r, k);
			player_ship* ptr = player_head;
			if (player_head == NULL)																										//dodawanie statku do listy
			{
				player_head = S4;
			}
			else
			{
				while (ptr->nast != NULL)
					ptr = ptr->nast;
				ptr->nast = S4;
			}
			S4->add_to_board(player_board);																									//dodawanie statku na plansze (x - statek ; . - morze)
			std::cout << "Twoja plansza na ten moment to:";
			wypisz_tab(player_board);																										//wypisanie planszy gracza po prawidlowym dodaniu na nia statku
			do
			{																																//losowanie wartosci dla statku gracza AI
				int a1, a2, a3;
				a1 = rand() % 10;
				a2 = rand() % 10;
				a3 = rand() % 4;
				AI_i = a1;
				AI_c = a2 + 'a';
				AI_r = 4;
				if (a3 == 0)
					AI_k = 'g';
				else if (a3 == 1)
					AI_k = 'd';
				else if (a3 == 2)
					AI_k = 'p';
				else
					AI_k = 'l';
			} while (!(if_ship_input_ok(AI_i, AI_c, AI_r, AI_k)));																			//sprawdza czy wylosowane wartosci sa odpoweidnie dla obiektu AI_ship
			AI_ship* A1 = new AI_ship(AI_i, AI_c, AI_r, AI_k);
			player_ship* AI_ptr = AI_head;
			if (AI_head == NULL)																											//dodawanie statku do listy
			{
				AI_head = A1;
			}
			else
			{
				while (AI_ptr->nast != NULL)
					AI_ptr = AI_ptr->nast;
				AI_ptr->nast = A1;
			}
			A1->add_to_board(AI_board);																										//dodanie wylosowanego statku do planszy gracza AI
		}
		else if (j < 3)																														//analogiczny kod dla trojmasztowcow
		{
			
			do
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
				if (!(if_ship_input_ok(i, c, r, k)))
					std::cout << "Niepoprawne dane wejsciowe. Sprobuj jeszcze raz:" << std::endl;
			} while (!(if_ship_input_ok(i, c, r, k)));
			player_ship* S3 = new player_ship(i, c, r, k);
			player_ship* ptr = player_head;
			if (player_head == NULL)
			{
				player_head = S3;
			}
			else
			{
				while (ptr->nast != NULL)
					ptr = ptr->nast;
				ptr->nast = S3;
			}
			S3->add_to_board(player_board);
			std::cout << "Twoja plansza na ten moment to:";
			wypisz_tab(player_board);
			do
			{
				int a1, a2, a3;
				a1 = rand() % 10;
				a2 = rand() % 10;
				a3 = rand() % 4;
				AI_i = a1;
				AI_c = a2 + 'a';
				AI_r = 3;
				if (a3 == 0)
					AI_k = 'g';
				else if (a3 == 1)
					AI_k = 'd';
				else if (a3 == 2)
					AI_k = 'p';
				else
					AI_k = 'l';
			} while (!(if_ship_input_ok(AI_i, AI_c, AI_r, AI_k)));
			AI_ship* A1 = new AI_ship(AI_i, AI_c, AI_r, AI_k);
			player_ship* AI_ptr = AI_head;
			if (AI_head == NULL)
			{
				AI_head = A1;
			}
			else
			{
				while (AI_ptr->nast != NULL)
					AI_ptr = AI_ptr->nast;
				AI_ptr->nast = A1;
			}
			A1->add_to_board(AI_board);
		}
		else if (j < 6)																															//analogiczny kod dla dwumasztowcow
		{
		do
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
			if (!(if_ship_input_ok(i, c, r, k)))
				std::cout << "Niepoprawne dane wejsciowe. Sprobuj jeszcze raz:" << std::endl;
		} while (!(if_ship_input_ok(i, c, r, k)));
		player_ship* S2 = new player_ship(i, c, r, k);
		player_ship* ptr = player_head;
		if (player_head == NULL)
		{
			player_head = S2;
		}
		else
		{
			while (ptr->nast != NULL)
				ptr = ptr->nast;
			ptr->nast = S2;
		}
		S2->add_to_board(player_board);
		std::cout << "Twoja plansza na ten moment to:";
		wypisz_tab(player_board);
		do
		{
			int a1, a2, a3;
			a1 = rand() % 10;
			a2 = rand() % 10;
			a3 = rand() % 4;
			AI_i = a1;
			AI_c = a2 + 'a';
			AI_r = 2;
			if (a3 == 0)
				AI_k = 'g';
			else if (a3 == 1)
				AI_k = 'd';
			else if (a3 == 2)
				AI_k = 'p';
			else
				AI_k = 'l';
		} while (!(if_ship_input_ok(AI_i, AI_c, AI_r, AI_k)));
		AI_ship* A1 = new AI_ship(AI_i, AI_c, AI_r, AI_k);
		player_ship* AI_ptr = AI_head;
		if (AI_head == NULL)
		{
			AI_head = A1;
		}
		else
		{
			while (AI_ptr->nast != NULL)
				AI_ptr = AI_ptr->nast;
			AI_ptr->nast = A1;
		}
		A1->add_to_board(AI_board);
		}
		else if (j < 10)																														//analogiczny kod dla jednomasztowcow
		{
			do
			{
				std::cout << "Podaj wspolrzedne pola na ktorym ma stac jednomasztowiec (najpierw cyfra np 8g): ";
				if (j != 0)
				{
					while (getchar() != '\n')
						;
				}
				scanf_s("%d", &i);
				scanf_s("%c", &c, 1);
				c = tolower(c);
				r = 1;
				k = '0';
				if (!(if_ship_input_ok(i, c, r, k)))
					std::cout << "Niepoprawne dane wejsciowe. Sprobuj jeszcze raz:" << std::endl;
			} while (!(if_ship_input_ok(i, c, r, k)));
			player_ship* S1 = new player_ship(i, c, r, k);
			player_ship* ptr = player_head;
			if (player_head == NULL)
			{
				player_head = S1;
			}
			else
			{
				while (ptr->nast != NULL)
					ptr = ptr->nast;
				ptr->nast = S1;
			}
			S1->add_to_board(player_board);
			std::cout << "Twoja plansza na ten moment to:";
			wypisz_tab(player_board);
			do
			{
				int a1, a2;
				a1 = rand() % 10;
				a2 = rand() % 10;
				AI_i = a1;
				AI_c = a2 + 'a';
				AI_r = 1;
				AI_k = '0';
			} while (!(if_ship_input_ok(AI_i, AI_c, AI_r, AI_k)));
			AI_ship* A1 = new AI_ship(AI_i, AI_c, AI_r, AI_k);
			player_ship* AI_ptr = AI_head;
			if (AI_head == NULL)
			{
				AI_head = A1;
			}
			else
			{
				while (AI_ptr->nast != NULL)
					AI_ptr = AI_ptr->nast;
				AI_ptr->nast = A1;
			}
			A1->add_to_board(AI_board);
		}
	}
	int gra = 1;
	int pom = 0;
	std::cout << "\n\n\t\tROZPOCZYNAMY GRE!" << std::endl;
	while (gra==1)
	{																																			//pojedyncza kolejka ruchow
		std::cout << "\n\t\tTWOJ RUCH:\nTwoja plansza ze statkami to:" << std::endl;
		wypisz_tab(player_board);
		std::cout << "\nTwoja plansza ze strzalami w statki przeciwnika to:" << std::endl;
		wypisz_tab(player_shoot_board);
		do
		{
			player_head->shoot(player_shoot_board, AI_board, i, c);																				//strzal oddawany przez gracza - kolejka gracza
			if (if_hit(i, c, player_shoot_board))
			{
				std::cout << "\n\t\tTRAFIONY!!!" << std::endl;																					//jesli trafiony wyswietla komunikat i sprawdza pozniej czy nie jest zatopiony
				if (if_sink(i, c, AI_board, player_shoot_board))
				{
					std::cout << "\t\tZATOPIONY!!!!!" << std::endl;
				}
				wypisz_tab(player_shoot_board);																									//wypisuje plansze po trafieniu aby moc strzelic jeszcze raz
				if (player_head->get_trafienia() == 20)																							//sprawdzenie czy gra sie nie zakonczyla po trafieniu
				{
					gra = 0;
					break;
				}
			}
			else
				std::cout << "\n\t\tPudlo!" << std::endl;
		} while (if_hit(i, c, player_shoot_board));																								//sprawdzenie czy strzal byl celny jesli tak mozna strzelac ponownie
		if (gra)
		{
			do
			{
				AI_head->shoot(AI_shoot_board, player_board,AI_i,AI_c);																			//strzal oddawany przez AI - kolejka AI analogiczna do gracza
				if (if_hit(AI_i, AI_c, AI_shoot_board))
				{
					if (if_sink(AI_i, AI_c, player_board, AI_shoot_board))
						;
					if (AI_head->get_trafienia() == 20)																							//sprawdzenie czy gra sie nie zakonczyla po trafieniu
					{
						gra = 2;
						break;
					}
				}
			} while (if_hit(AI_i, AI_c, AI_shoot_board));
		}
	}
	if (gra == 0)																																//jesli gracz wygral wypisywanie powiadomienia do konsoli i wyniku gry razem z czasem i nickiem do pliku
	{
		std::cout << "\n\t\tZWYCIESTWO!!!" << std::endl;
		save_score(nick, AI_head->get_trafienia(),gra);
	}
	else if (gra == 2)																															//analogicznie jesli wygral AI
	{
		std::cout << "\n\t\tPORAZKA!!!" << std::endl;
		save_score(nick, player_head->get_trafienia(),gra);
	}
	delete player_head;
	delete AI_head;
	std::cout << "\nKONIEC GRY. WYNIK ZAPISANY DO PLIKU Z WYNIKAMI. DZIEKUJE ZA GRE!" << std::endl;												//zakonczenie programu
	std::cout << "\nKoniec programu." << std::endl;
	return 0;
}