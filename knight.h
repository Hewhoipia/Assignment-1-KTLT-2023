#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

class adventure{
    private:
        // general
        string file_input;
        int maxHP, HP, level, remedy, maidenkiss, phoenixdown, rescue=-1;
        string events;
        string packages;
        int eSize=0;
        int* eventsArr=nullptr;

        // events
        size_t tiny=0;
        size_t frog=0;
        size_t levelFrog=1;
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
                tinyCheck();
                frogCheck();
                return;
            }
            //events

            if (eventsName == 0){
                rescue=1;
                displayEach(eventsName, num);
                return;
            }
            else if (eventsName == 1){
                tinyCheck();
                frogCheck();
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(1*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName, num);
                        return;
                    }
                }
                displayEach(eventsName, num);
            }
            else if (eventsName == 2){
                tinyCheck();
                frogCheck();
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(1.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName, num);
                        return;
                    }
                }
                displayEach(eventsName, num);
            }
            else if (eventsName == 3){
                tinyCheck();
                frogCheck();
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(4.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName, num);
                        return;
                    }
                }
                displayEach(eventsName, num);
            }
            else if (eventsName == 4){
                tinyCheck();
                frogCheck();
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(7.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName, num);
                        return;
                    }
                }
                displayEach(eventsName, num);
            }
            else if (eventsName == 5){
                tinyCheck();
                frogCheck();
                int b = num+1 % 10;
                int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                if (level > lvo){
                    level++;
                    levelCheck();
                }
                else if (level < lvo){
                    HP-=(9.5*lvo*10);
                    if (!HPCheck()){
                        displayEach(eventsName, num);
                        return;
                    }
                }
                displayEach(eventsName, num);
            }
            else if (eventsName == 6){
                if(!tinyCheck() || !frogCheck()){
                    int b = num+1 % 10;
                    int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                    if (level > lvo){
                        level=level+2;
                        levelCheck();
                    }
                    else if (level < lvo){
                        tiny=4;
                    }
                    displayEach(eventsName, num);
                }
                else{
                    displayEach(eventsName, num);
                }
            }
            else if (eventsName == 7){
                if(!tinyCheck() || !frogCheck()){
                    int b = num+1 % 10;
                    int lvo = num+1 > 6 ? (b > 5 ? b : 5) : b;
                    if (level > lvo){
                        level=level+2;
                        levelCheck();
                    }
                    else if (level < lvo){
                        frog=4;
                    }
                    displayEach(eventsName, num);
                }
                else{
                    displayEach(eventsName, num);
                }
            }
            else if (eventsName == 11){
                tinyCheck();
                frogCheck();
                int n1 = ((level + phoenixdown) % 5 + 1) * 3;
                int s1 = 0;
                int countNum = 0;
                for (int i = 99; i >= 1; i -= 2) {
                    if (countNum == n1) {
                        break;
                    }
                    s1 += i;
                    countNum++;
                }
                HP += (s1 % 100);
                while (!prime(HP)) {
                    HP++;
                }
                HPCheck();
                displayEach(eventsName, num);
            }
            else if (eventsName == 12){
                tinyCheck();
                frogCheck();
                if (HP > 1){
                    HP=fibo(HP);
                }
                displayEach(eventsName, num);
            }
            else if (eventsName == 13){
                // tiny frog
                displayEach(eventsName, num);
            }
            else if (eventsName == 15){
                // tiny frog
                displayEach(eventsName, num);
            }
            else if (eventsName == 16){
                // tiny frog
                displayEach(eventsName, num);
            }
            else if (eventsName == 17){
                // tiny frog
                displayEach(eventsName, num);
            }
            else if (eventsName == 18){
                // tiny frog
                displayEach(eventsName, num);
            }
            else if (eventsName == 19){
                // tiny frog
                displayEach(eventsName, num);
            }
            else if (eventsName == 99){
                // tiny frog
                displayEach(eventsName, num);
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
                    tiny=0;
                    phoenixdown--;
                    return 1;
                }
                else {
                    rescue = 0;
                    return 0;
                }
            }
            else if (HP > maxHP){
                HP=maxHP;
                return 1;
            }
            else return 1;
        }
        void levelCheck(){
            if (level >= 10){
                level=10;
            }
        }
        bool tinyCheck(){
            if (tiny>1){
                if (remedy>=1){
                    remedy--;
                    tiny=0;
                    return 0;
                }
                if (tiny==4){
                    if(HP<5)HP=1;
                    else HP/=5;
                }
                tiny--;
                return 1;
            }
            else if (tiny==1) {
                tiny=0;
                HP*=5;
                HPCheck();
                return 0;
            }
            return 0;
        }
        bool frogCheck(){
            if (frog>1){
                if (maidenkiss>=1){
                    maidenkiss--;
                    frog=0;
                    return 0;
                }
                if (frog==4){
                    levelFrog=level;
                    level=1;
                }
                frog--;
                return 1;
            }
            else if (frog==1) {
                frog=0;
                level=levelFrog;
                return 0;
            }
            return 0;
        }

        // Events Func
        bool prime(int hacPe) {
            if (hacPe < 2) {
                return false;
            }
            for (int i = 2; i <= sqrt(hacPe); i++) {
                if (hacPe % i == 0) {
                    return false;
                }
            }
            return true;
        }
        int fibo(int n) {
            int x1 = 0, x2 = 1, x3=0;
            while (x3 < n) {
                x1 = x2;
                x2 = x3;
                x3 = x1 + x2;
            }
            return x2;
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
        void displayEach(int eventsName, int num){
            cout << "~" << num << " eventsName: " << eventsName << endl;
            cout << HP << " " << level << " " << remedy << " " << maidenkiss << " " << phoenixdown << endl;
        }
};
#endif // __KNIGHT_H__