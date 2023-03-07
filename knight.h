#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

class adventure{
    private:
        string file_input;
        int HP, level, remedy, maidenkiss, phoenixdown, rescue;
        string events;
        string packages;
        int eSize=0;
        int* eventsArr=nullptr;
    public:
        adventure(string &_file_input, int& _HP, int& _level, int& _remedy, int& _maidenkiss, int& _phoenixdown, int& _rescue){
            this->file_input=_file_input;
            readFile();
            eventsArr = modifyEvents();
            actionEvents(keepTrackE(0));
            
            //pass value to origin
            _HP = HP;
            _level = level;
            _remedy = remedy;
            _maidenkiss = maidenkiss;
            _phoenixdown = phoenixdown;
            _rescue = rescue;
            display();
        }
    public:
        void readFile(){
            ifstream myfile(file_input);
            if (myfile.is_open()) {
                myfile >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
                getline (myfile, events);
                getline (myfile, events);
                getline(myfile, packages);
                getline(myfile, packages);
                myfile.close();
                return;
            }
            else {
                cout << "Cannot read input file";
                return;
            }
        }
        int* modifyEvents(){
            int* arr = new int ();
            stringstream s (events);
            while (s >> arr[eSize]){
                eSize++;
            }
            return &(*arr);
        }
        void actionEvents(int eventsName){
            if (eventsName == -1){
                return;
            }
        }
        int keepTrackE(int num){
            if (num == eSize){
                return -1;
            }
            else return eventsArr[num];
        }
        bool modifyPac(string& packages);
        void display(){
            cout << HP << " " << level << " " << remedy << " " << maidenkiss << " " << phoenixdown << endl;
            cout << packages << endl;
            for (int i=0; i<eSize; i++){
                cout << eventsArr[i] << " ";
            }
            cout << endl;
        }
};
#endif // __KNIGHT_H__