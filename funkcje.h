#pragma once

void create_boards(char player_board[12][12], char player_shoot_board[12][12], char AI_board[12][12], char AI_shoot_board[12][12]);
int if_ship_input_ok(int i, char c, int r, char k);
void wypisz_tab(char tab[12][12]);
void change_board_to_blank(int i, int j, char shoot_tab[12][12]);
int if_hit(int i, char c, char shoot_tab[12][12]);
int if_sink(int i, char c, char enemy_tab[12][12], char shoot_tab[12][12]);
int if_shoot_input_ok(int i, char c);
void save_score(char nick[], int trafienia,int wynik);