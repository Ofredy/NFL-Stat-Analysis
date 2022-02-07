#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

/*
    This will be the entries for the hash table. 
    For the head of each list only the mean and 
    standard deviation variable will be defined. 
    The head will store the information that describes 
    the list.
*/
struct HashTableEntry{
    HashTableEntry *next;
    HashTableEntry *prev;
    string name;
    int yards;
    int td;
    float score;
    float zscore;
    // Head only
    float mean;
    float standardDeviation;
    int players;
    int year;
};

class HashTable{
    private:
        int tablesize=10;
        int totalplayers;
        HashTableEntry **head;
        HashTableEntry **tail;
    public:
        HashTable();
        int HashFunction(int year);
        void insert(int year, string name, int td, int yards);
        void insert(int year, HashTableEntry* player);
        // Statistic functions
        void mean_score();
        void standard_deviation_score();
        void calculate_score();
        void z_score();
        // Print the table statistics
        void print();
        // Makes a new hash table with the top player from each year
        void top(HashTable& newTable);
        // Read from csv file
        void read(ifstream& file, int numYears);
        // Write results to a .txt
        void write(ofstream& file, string position);
};

#endif