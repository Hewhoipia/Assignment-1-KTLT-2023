#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void readFile(const string& filename, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int*& events, string& packages);
#endif // __KNIGHT_H__