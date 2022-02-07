#include "HashTable.h"

HashTable::HashTable(){
    head = new HashTableEntry* [tablesize];
    tail = new HashTableEntry* [tablesize];
    totalplayers = 0;
    for(int i=0; i<tablesize; i++){
        HashTableEntry *temp = new HashTableEntry;
        temp->next = nullptr;
        temp->prev = nullptr;
        tail[i] = temp;
        head[i] = temp;
        head[i]->mean = 0;
        head[i]->standardDeviation = 0;
        head[i]->players = 0;
    }
}

int HashTable::HashFunction(int year){
    return (year-1)%tablesize;
}

void HashTable::insert(int year, string name, int td, int yards){
    int key = HashFunction(year);
    head[key]->year = year;
    HashTableEntry *newPlayer = new HashTableEntry;
    newPlayer->name = name;
    newPlayer->td = td;
    newPlayer->yards = yards;
    newPlayer->prev = tail[key];
    newPlayer->next = nullptr;
    tail[key]->next = newPlayer; 
    tail[key] = newPlayer;
    ++totalplayers;
    ++head[key]->players;
}

void HashTable::insert(int year, HashTableEntry* player){
    int key = HashFunction(year);
    head[key]->year = year;
    player->prev = tail[key];
    player->next = nullptr;
    tail[key]->next = player;
    tail[key] = player;
    ++totalplayers;
    ++head[key]->players;
}

void HashTable::mean_score(){
    int temp1;
    HashTableEntry* temp2;
    for(int i=0; i<tablesize; i++){
        temp1 = 0;
        temp2 = head[i]->next;
        while(temp2!=nullptr){
            temp1 = temp1 + temp2->score;
            temp2 = temp2->next;
        }
        // calculates the average score for the year
        head[i]->mean = (float)temp1 / (float)head[i]->players; 
    }
}

void HashTable::standard_deviation_score(){
    float temp1;
    HashTableEntry* temp2;
    for(int i=0; i<tablesize; i++){
        temp1 = 0;
        temp2 = head[i]->next;
        while(temp2!=nullptr){
            temp1 = temp1 + pow((temp2->score - head[i]->mean), 2);
            temp2 = temp2->next;
        }
        // finds the standard deviation of each year
        head[i]->standardDeviation = pow((temp1/(head[i]->players)), 0.5);
    }
}

void HashTable::calculate_score(){
    HashTableEntry *temp;
    for(int i=0; i<tablesize; i++){
        temp = head[i]->next;
        while(temp!=nullptr){
            // 0.1 point per yard and 6 points per touchdown
            temp->score = (float)temp->yards * 0.1 + (float)temp->td * 6;
            temp = temp->next;
        }
    }
}

void HashTable::print(){
    HashTableEntry* temp;
    for(int i=0; i<tablesize; i++){
        temp = head[i]->next;
        if(head[i]==tail[i]){
            cout << "No data for this year" << endl;
        } 
        else{
            cout << "For year " << head[i]->year << ", mean score: " << head[i]->mean << ", standard deviation of scores: " << 
            head[i]->standardDeviation << ", and " << head[i]->players << " players" << endl;
            while(temp!=nullptr){
                cout << temp->name << ", yards: " << temp->yards << ", touchdowns: " << temp->td << " ,a score of: " << temp->score <<
                ", and a z score of:" << temp->zscore << endl;
                temp = temp->next;
            }
        }
    }
}

void HashTable::z_score(){
    HashTableEntry* temp;
    for(int i=0; i<tablesize; i++){
        temp = head[i]->next;
        while(temp!=nullptr){
            temp->zscore = (temp->score - head[i]->mean) / head[i]->standardDeviation;
            temp = temp->next;
        }
    }
}

void HashTable::top(HashTable& newTable){
    HashTableEntry* temp;
    HashTableEntry* max;
    for(int i=0; i<tablesize; i++){
        if(head[i]!=tail[i]){
            max = head[i]->next;
            temp = head[i]->next->next;
            while(temp!=nullptr){
                if(max->zscore < temp->zscore){
                    max = temp;
                }
                temp = temp->next;
            }                    
            newTable.insert(head[i]->year, max);
            // remove(head[i]->year, max);
        }
    }
}

void HashTable::read(ifstream& file, int numYears){
    // Variables need to parse the file
    string positionTemp;
    string line;
    string yearTemp;
    string nameTemp;
    string tdsTemp;
    string yardsTemp;
    int counter1=0;
    int counter2=0;

    getline(file, positionTemp, ',');
    getline(file, line);

    while(file.good() && counter2<numYears){
        if(counter1==0){    
            getline(file, yearTemp, ',');
            getline(file, line);
        }
        else{
            getline(file, line, ',');
            getline(file, nameTemp, ',');
            getline(file, tdsTemp, ',');
            getline(file, yardsTemp);
            insert(stoi(yearTemp), nameTemp, stoi(tdsTemp), stoi(yardsTemp));
        }
        if(counter1==25){
            getline(file, line);
            ++counter2;
        }
        counter1 = (counter1+1)%26;
    }
}

void HashTable::write(ofstream& file, string position){
    HashTableEntry* temp;
    for(int i=0; i<tablesize; i++){
        if(head[i]!=tail[i]){
            temp = head[i]->next;
            file << "The top " << position << " for the year " << head[i]->year << ", ";
            while(temp!=nullptr){
                file << temp->name << ", with a score of: " << temp->score << ", and a zscore of: " << temp->zscore << endl;
                temp = temp->next;
            }
        }
    }
}