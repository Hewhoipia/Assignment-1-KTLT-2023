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
        string mush, asclepius, merlin; // packages
        int eSize=0;
        int* eventsArr=nullptr;

        // events
        size_t tiny=0; // event 6
        size_t frog=0; // event 7
        size_t levelFrog=1; // event 7
        string event13Arr; // event 13
        int n2=0; int* n2Arr=nullptr; // event 13
        size_t n9=0; string* n9Arr=nullptr; bool myMerlin=0;// event 18
    public:
        adventure(string &_file_input, int& _HP, int& _level, int& _remedy, int& _maidenkiss, int& _phoenixdown, int& _rescue){
            this->file_input=_file_input;
            readFile();
            eventsArr = modifyEvents();
            modifyPac();
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
                myfile.close();
                return;
            }
            else {
                cout << "Cannot read input file";
                exit(1);
            }
        }

        // modify and handle file errors
        int* modifyEvents(){
            int* arr = new int ();
            stringstream s (events);
            while (s >> arr[eSize]){
                eSize++;
            }
            return &(*arr);
        }
        void modifyPac(){
            for (int i=0; i<packages.size(); i++){
                if (packages[i]==',') packages[i]=' ';
            }
            stringstream ss(packages);
            ss >> mush >>  asclepius >> merlin;
            modifyMush();
            modifyAS();
            modifyMerlin();
        }
        void modifyMush(){
            ifstream file(mush);
            if (file.is_open()){
                file >> n2;
                string n2ArrStr;
                getline(file, n2ArrStr);
                getline(file, n2ArrStr);
                n2Arr=new int[n2];
                int j=0;
                for (int i=0; i<n2ArrStr.size(); i++){
                    if(n2ArrStr[i]==',')n2ArrStr[i]=' ';
                }
                stringstream ss(n2ArrStr);
                while (ss >> n2Arr[j]){
                    j++;
                }
                if(j != n2){
                    cout << "n2 and size of array n2 is not equal (package " << mush <<")";
                    exit(1);
                }
            }
            else {
                cout << "Cannot read input package file";
                exit(1);
            }
        }
        void modifyAS(){
            //hmm
        }
        void modifyMerlin(){
            ifstream file(merlin);
            if (file.is_open()){
                file >> n9;
                n9Arr = new string [n9];
                getline(file, n9Arr[0]);
                getline (file, n9Arr[0]);
                for (int i=1; i<n9; i++){
                    getline(file, n9Arr[i]);
                }
            }
            else {
                cout << "Cannot read input package file";
                exit(1);
            }
        }
        void handleFileError(); // example: when call event 13 but there are nothing in <file_mush_package>

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
                tinyCheck();
                frogCheck();
                for (int i=2; i<event13Arr.size(); i++){
                    if(event13Arr[i]=='1'){
                        int maxi=0,mini=0;
                        mush1(maxi, mini);
                        HP-=(maxi+mini);
                    }
                    else if(event13Arr[i]=='2'){
                        int mtx = n2Arr[0],mti = 0;
                        mush2(mtx, mti);
                        HP-=(mtx+mti);
                    }
                    else if(event13Arr[i]=='3'){
                        int* newArr=new int [n2];
                        for (int i=0; i<n2; i++){
                            if(n2Arr[i] < 0) newArr[i]=-n2Arr[i];
                            else newArr[i]=n2Arr[i];
                            newArr[i]=(17*newArr[i]+9)%257;
                        }
                        int maxi2=0, mini2=0;
                        mush3(newArr,maxi2, mini2);
                        HP-=(maxi2+mini2);
                        delete newArr;
                    }
                    else if (event13Arr[i]='4'){
                        int* newArr=new int [n2];
                        for (int i=0; i<n2; i++){
                            if(n2Arr[i] < 0) newArr[i]=-n2Arr[i];
                            else newArr[i]=n2Arr[i];
                            newArr[i]=(17*newArr[i]+9)%257;
                        }
                        int max2_3x=0, max2_3i=0;
                        mush4(newArr, max2_3x, max2_3i);
                        HP-=(max2_3x+max2_3i);
                        delete newArr;
                    }
                    if(!HPCheck()){
                        displayEach(eventsName, num);
                        return;
                    }
                    displayEach(eventsName, num);
                }
            }
            else if (eventsName == 15){
                tinyCheck();
                frogCheck();
                if(remedy<99) remedy++;
                displayEach(eventsName, num);
            }
            else if (eventsName == 16){
                tinyCheck();
                frogCheck();
                if (maidenkiss<99) maidenkiss++;
                displayEach(eventsName, num);
            }
            else if (eventsName == 17){
                tinyCheck();
                frogCheck();
                if (phoenixdown < 99) phoenixdown++;
                displayEach(eventsName, num);
            }
            else if (eventsName == 18){
                tinyCheck();
                frogCheck();
                
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
            else if (eventsArr[num]/10 >= 13){
                event13Arr=to_string(eventsArr[num]);
                return 13;
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
            if (x2==n)return x1;
            return x2;
        }
        void mush1(int& maxi, int& mini){
            int max=n2Arr[0], min=n2Arr[0];
            for (int i=0; i<n2; i++){
                if (min >= n2Arr[i]){
                    min=n2Arr[i];
                    mini=i;
                }
                if (max <= n2Arr[i]){
                    max=n2Arr[i];
                    maxi=i;
                }
            }
        }
        void mush2(int& mtx, int& mti){
            if (n2 == 1) {
                mtx=n2Arr[0];
                mti=0;
                return;
            }
            for (int i = 0; i < n2; i++) {
                if (n2Arr[i] > mtx) {
                    mtx = n2Arr[i];
                    mti = i;
                }
            }
            int i = 0;
            while (i < mti && n2Arr[i] < n2Arr[i + 1]) {
                i++;
            }
            int j=mti;
            while (j<n2-1 && n2Arr[j] > n2Arr[j+1]){
                j++;
            }
            if (!(i == mti && j == n2-1)) {
                mtx=-2;
                mti=-3;
                return;
            }
        }
        void mush3(int*& newArr,int& maxi2, int& mini2){
            int max=newArr[0], min=newArr[0];
            for (int i=0; i<n2; i++){
                if (min > newArr[i]){
                    min=newArr[i];
                    mini2=i;
                }
                if (max < newArr[i]){
                    max=newArr[i];
                    maxi2=i;
                }
            }
        }
        void mush4(int*& newArr, int& max2_3x, int& max2_3i){
            if (n2<2){
                max2_3x=-5;
                max2_3i=-7;
                return;
            }
            if (n2==2) {
                int max1 = newArr[0], max2 = newArr[1], max2i = 1;
                if (max1==max2){
                    max2_3x=-5;
                    max2_3i=-7;
                    return;
                }
                if (max2 > max1) {
                    swap(max1, max2);
                    max2i = 0;
                }
                max2_3x=max2;
                max2_3i=max2i;
                return;
            }
            if (newArr[0]==newArr[1] && newArr[0]==newArr[2]){
                max2_3x=-5;
                max2_3i=-7;
                return;
            }
            int max1 = newArr[0], max2 = newArr[1], max2i = 1;
            if (max2 >= max1) {
                swap(max1, max2);
                max2i = 0;
            }
            if (newArr[2] > max1) {
                if(max1!=max2){
                    max2 = max1;
                    max2i = (max1 == newArr[0] ? 1 : 0);
                }
            }
            else if (newArr[2] > max2) {
                if(newArr[2]!=max1){
                    max2 = newArr[2];
                    max2i = (max1 == newArr[0] ? 1 : 0);
                }
            }
            else if (max1==max2){
                max2=newArr[2];
                max2i=2;
            }
            max2_3x=max2;
            max2_3i=max2i;
        }

        // display
        void displayBegin(){
            cout << HP << " " << level << " " << remedy << " " << maidenkiss << " " << phoenixdown << endl;
            
            for (int i=0; i<eSize; i++){
                cout << eventsArr[i] << " ";
            }
            cout << endl;
            cout << packages << ": " << endl;
            cout << mush << ": " << endl << n2 << endl;
            for (int i=0; i<n2; i++){
                cout << n2Arr[i] << " ";
            }
            cout << endl;
            cout << merlin << ": " << endl << n9 << endl;
            for (int i=0; i<n9; i++){
                cout << n9Arr[i] << " ";
            }
            cout << endl;
        }
        void displayEach(int eventsName, int num){
            cout << "~" << num << " eventsName: " << eventsName << endl;
            cout << HP << " " << level << " " << remedy << " " << maidenkiss << " " << phoenixdown << endl;
        }
};
#endif // __KNIGHT_H__