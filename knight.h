#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void readFile(const string& filename, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, string& events, string& packages);
int* modifyEvents(string& events, int& eSize);
#endif // __KNIGHT_H__