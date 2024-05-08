#pragma once
class player_ship
{
protected:
	int polozenie_i;
	char polozenie_c;
	const int rozmiar;
	char kierunek;
	int trafienia;
public:
	player_ship* nast;
	player_ship();
	player_ship(int i, char c, int r, char k);
	virtual ~player_ship();
	void set_polozenie_i(int i);
	void set_polozenie_c(char c);
	void set_kierunek(char k);
	int get_trafienia();
	int can_add_to_board(char tab[12][12]);
	virtual void add_to_board(char tab[12][12]);
	virtual void shoot(char shoot_tab[12][12],char enemy_tab[12][12], int &i, char &c);

};

