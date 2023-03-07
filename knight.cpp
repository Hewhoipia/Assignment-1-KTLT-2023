#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    string events;
    string packages;
    readFile(file_input, HP, level, remedy, maidenkiss, phoenixdown, events, packages);



    //display
    cout << HP << " " << level << " " << remedy << " " << maidenkiss << " " << phoenixdown << endl;
    cout << events << endl << packages;
    //display (HP, level, remedy, maidenkiss, phoenixdown, rescue);
}

void readFile(const string& filename, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, string& events, string& packages) {
    ifstream myfile(filename);
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

void actionEvents(int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue, string& eventsNum){
    
}

string modifyEvents(string& events){

}

bool modifyPac(string& packages);