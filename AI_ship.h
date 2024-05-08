#pragma once
#include "player_ship.h"

class AI_ship :public player_ship
{
protected:
	;
public:
	AI_ship();
	AI_ship(int i, char c, int r, char k);
	void add_to_board(char tab[12][12]);
	void shoot(char shoot_tab[12][12], char enemy_tab[12][12],int &AI_I,char &AI_c);
};

