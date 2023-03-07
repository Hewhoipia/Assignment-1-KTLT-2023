#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

class adventure{
    private:
        string file_input;
        int maxHP, HP, level, remedy, maidenkiss, phoenixdown, rescue=-1;
        string events;
        string packages;
        int eSize=0;
        int* eventsArr=nullptr;
    public:
        adventure(string &_file_input, int& _HP, int& _level, int& _remedy, int& _maidenkiss, int& _phoenixdown, int& _rescue){
            this->file_input=_file_input;
            readFile();
            eventsArr = modifyEvents();
            displayBegin(); // display status at begin
            actionEvents(keepTrackE(0), 0);
            
            //pass value to origin
            _HP = HP;
            _level = level;
            _remedy = remedy;
            _maidenkiss = maidenkiss;
            _phoenixdown = phoenixdown;
            _rescue = rescue;
        }
    public:
        void readFile(){
            ifstream myfile(file_input);
            if (myfile.is_open()) {
                myfile >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
                maxHP=HP;
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

        // modify
        int* modifyEvents(){
            int* arr = new int ();
            stringstream s (events);
            while (s >> arr[eSize]){
                eSize++;
            }
            return &(*arr);
        }
        bool modifyPac(string& packages);

        // action
        void actionEvents(int eventsName, int num){
            if (eventsName == -1){
                return;
            }
            //events

            if (eventsName == 0){
                rescue=1;
                displayEach(eventsName);
                return;
            }
            else if (eventsName == 1){
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(1*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName);
                        return;
                    }
                }
                displayEach(eventsName);
            }
            else if (eventsName == 2){
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(1.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName);
                        return;
                    }
                }
                displayEach(eventsName);
            }
            else if (eventsName == 3){
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(4.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName);
                        return;
                    }
                }
                displayEach(eventsName);
            }
            else if (eventsName == 4){
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(7.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName);
                        return;
                    }
                }
                displayEach(eventsName);
            }
            else if (eventsName == 5){
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(9.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName);
                        return;
                    }
                }
                displayEach(eventsName);
            }
            else if (eventsName == 6){
                displayEach(eventsName);
            }
            else if (eventsName == 7){
                displayEach(eventsName);
            }
            else if (eventsName == 11){
                displayEach(eventsName);
            }
            else if (eventsName == 12){
                displayEach(eventsName);
            }
            else if (eventsName == 13){
                displayEach(eventsName);
            }
            else if (eventsName == 15){
                displayEach(eventsName);
            }
            else if (eventsName == 16){
                displayEach(eventsName);
            }
            else if (eventsName == 17){
                displayEach(eventsName);
            }
            else if (eventsName == 18){
                displayEach(eventsName);
            }
            else if (eventsName == 19){
                displayEach(eventsName);
            }
            else if (eventsName == 99){
                displayEach(eventsName);
            }

            return actionEvents(keepTrackE(num+1),num+1);
        }

        // keep tracks
        int keepTrackE(int num){
            if (num >= eSize){
                rescue = 1;
                return -1;
            }
            else return eventsArr[num];
        }
        bool HPCheck(){
            if (HP <= 0){
                if (phoenixdown >=1){
                    HP = maxHP;
                    phoenixdown--;
                    return 1;
                }
                else {
                    rescue = -1;
                    return 0;
                }
            }
            else return 1;
        }
        void levelCheck(){
            if (level >= 10){
                level=10;
            }
        }

        // display
        void displayBegin(){
            cout << HP << " " << level << " " << remedy << " " << maidenkiss << " " << phoenixdown << endl;
            
            for (int i=0; i<eSize; i++){
                cout << eventsArr[i] << " ";
            }
            cout << endl;
            cout << packages << endl;
        }
        void displayEach(int eventsName){
            cout << "eventsName: " << eventsName << endl;
            cout << HP << " " << level << " " << remedy << " " << maidenkiss << " " << phoenixdown << endl;
        }
};
#endif // __KNIGHT_H__