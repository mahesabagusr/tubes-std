#include "data_loader.h"
#include <iostream>
#include <fstream>
using namespace std;

void loadSampleData(ListTournament &L) {
    ifstream file("data.txt");
    if(!file.is_open()){
        cout<<"Error: File data.txt tidak ditemukan!"<<endl;
        return;
    }
    
    string line;
    getline(file, line);
    
    while(getline(file, line)){
        if(line == "MATCH") break;
        if(line.empty()) continue;
        
        Tournament t;
        size_t pos = 0;
        string token;
        int fieldCount = 0;
        
        while((pos = line.find('|')) != string::npos){
            token = line.substr(0, pos);
            if(fieldCount == 0) t.tournamentID = stoi(token);
            else if(fieldCount == 1) t.tournamentName = token;
            else if(fieldCount == 2) t.game = token;
            else if(fieldCount == 3) t.startDate = token;
            else if(fieldCount == 4) t.endDate = token;
            line.erase(0, pos + 1);
            fieldCount++;
        }
        t.totalPrize = stoi(line);
        t.firstMatch = nullptr;
        
        adrTournament T = createElmTournament(t);
        insertLastTournament(L, T);
    }
    
    while(getline(file, line)){
        if(line.empty()) continue;
        
        Match m;
        int tournamentID;
        size_t pos = 0;
        string token;
        int fieldCount = 0;
        
        while((pos = line.find('|')) != string::npos){
            token = line.substr(0, pos);
            if(fieldCount == 0) tournamentID = stoi(token);
            else if(fieldCount == 1) m.matchID = stoi(token);
            else if(fieldCount == 2) m.matchName = token;
            else if(fieldCount == 3) m.team1 = token;
            else if(fieldCount == 4) m.team2 = token;
            else if(fieldCount == 5) m.scoreTeam1 = stoi(token);
            else if(fieldCount == 6) m.scoreTeam2 = stoi(token);
            else if(fieldCount == 7) m.matchDate = token;
            line.erase(0, pos + 1);
            fieldCount++;
        }
        m.status = line;
        
        adrTournament T = findTournamentByID(L, tournamentID);
        if(T != nullptr){
            adrMatch M = createElmMatch(m);
            insertLastMatch(T, M);
        }
    }
    
    file.close();
}
