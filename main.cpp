#include <iostream>
#include "HashTable.h"
using namespace std;

int main(){

    int numYears=2;

    // Passing Statistics
    HashTable Passing;
    HashTable PassingTop;
    ifstream RpassingFile("Passing.csv");
    ofstream WpassingFile("passing.txt");
    
    Passing.read(RpassingFile, numYears);
    Passing.calculate_score();
    Passing.mean_score();
    Passing.standard_deviation_score();
    Passing.z_score();
    Passing.top(PassingTop);
    PassingTop.write(WpassingFile, "quaterback");

    // Receiving Statistics
    HashTable Receiving;
    HashTable ReceivingTop;
    ifstream Rreceiving("Recieving.csv");
    ofstream Wreceiving("receiving.txt");

    Receiving.read(Rreceiving, numYears);
    Receiving.calculate_score();
    Receiving.mean_score();
    Receiving.standard_deviation_score();
    Receiving.z_score();
    Receiving.top(ReceivingTop);
    ReceivingTop.write(Wreceiving, "receiver");

    // Rushing Statistics
    HashTable Rushing;
    HashTable RushingTop;
    ifstream Rrushing("Rushing.csv");
    ofstream Wrushing("rushing.txt");

    Rushing.read(Rrushing, numYears);
    Rushing.calculate_score();
    Rushing.mean_score();
    Rushing.standard_deviation_score();
    Rushing.z_score();
    Rushing.top(RushingTop);
    Rushing.write(Wrushing, "running back");

    return 0;
}