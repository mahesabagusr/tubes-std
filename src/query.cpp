#include "tournament.h"
#include "match.h"
#include "utils.h"
#include <iostream>
using namespace std;

void queryTournamentByPrize(ListTournament L, int minPrize) 
{
    adrTournament P = L.first;
    bool found = false;
    
    cout<<"\n=== Tournament dengan Hadiah >= $"<<minPrize<<" ==="<<endl;
    
    while (P != nullptr) {
        if (P->info.totalPrize >= minPrize) {
            cout<<"\nNama: "<<P->info.tournamentName<<endl;
            cout<<"Game: "<<P->info.game<<endl;
            cout<<"Hadiah: $"<<P->info.totalPrize<<endl;
            cout<<"Jumlah Match: "<<countMatchesByTournament(P)<<endl;
            cout<<"----------------------------------------"<<endl;
            found = true;
        }
        P = P->next;
    }
    
    if (!found) {
        cout<<"Tidak ada tournament dengan hadiah >= $"<<minPrize<<endl;
    }
    pauseScreen();
}

int countAllTournaments(ListTournament L) {
    int count = 0;
    adrTournament P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

int countAllMatches(ListTournament L) {
    int count = 0;
    adrTournament P = L.first;
    while (P != nullptr) {
        count += countMatchesByTournament(P);
        P = P->next;
    }
    return count;
}

int countMatchesByTournament(adrTournament P) {
    int count = 0;
    adrMatch M = P->info.firstMatch;
    while (M != nullptr) {
        count++;
        M = M->next;
    }
    return count;
}

void deleteFirstTournament(ListTournament &L) {
    if(L.first != nullptr){
        adrTournament temp = L.first;
        deleteAllMatches(temp);
        L.first = L.first->next;
        delete temp;
        cout<<"Tournament pertama berhasil dihapus!"<<endl;
    }else{
        cout<<"List kosong!"<<endl;
    }
}

void deleteLastTournament(ListTournament &L) {
    if(L.first == nullptr){
        cout<<"List kosong!"<<endl;
        return;
    }
    if(L.first->next == nullptr){
        deleteAllMatches(L.first);
        delete L.first;
        L.first = nullptr;
        cout<<"Tournament terakhir berhasil dihapus!"<<endl;
        return;
    }
    adrTournament P = L.first;
    while(P->next->next != nullptr){
        P = P->next;
    }
    deleteAllMatches(P->next);
    delete P->next;
    P->next = nullptr;
    cout<<"Tournament terakhir berhasil dihapus!"<<endl;
}

float getAveragePrize(ListTournament L) {
    if(L.first == nullptr) return 0;
    int total = 0;
    int count = 0;
    adrTournament P = L.first;
    while(P != nullptr){
        total += P->info.totalPrize;
        count++;
        P = P->next;
    }
    return (float)total / count;
}

float getAverageMatchPerTournament(ListTournament L) {
    if(L.first == nullptr) return 0;
    int totalMatch = countAllMatches(L);
    int totalTournament = countAllTournaments(L);
    return (float)totalMatch / totalTournament;
}

void groupTournamentByGame(ListTournament L) {
    if(L.first == nullptr){
        cout<<"Belum ada tournament!"<<endl;
        return;
    }
    
    cout<<"\n=== GROUP BY GAME ==="<<endl;
    adrTournament P = L.first;
    string games[100];
    int prizes[100];
    int counts[100];
    int gameCount = 0;
    
    while(P != nullptr){
        bool found = false;
        for(int i = 0; i < gameCount; i++){
            if(games[i] == P->info.game){
                prizes[i] += P->info.totalPrize;
                counts[i]++;
                found = true;
                break;
            }
        }
        if(!found){
            games[gameCount] = P->info.game;
            prizes[gameCount] = P->info.totalPrize;
            counts[gameCount] = 1;
            gameCount++;
        }
        P = P->next;
    }
    
    for(int i = 0; i < gameCount; i++){
        cout<<"\nGame: "<<games[i]<<endl;
        cout<<"Total Tournament: "<<counts[i]<<endl;
        cout<<"Total Prize: $"<<prizes[i]<<endl;
        cout<<"Avg Prize: $"<<(prizes[i]/counts[i])<<endl;
        cout<<"----------------------------------------"<<endl;
    }
    pauseScreen();
}
