#include "tournament.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void createListTournament(ListTournament &L) {
    L.first = nullptr;
}

adrTournament createElmTournament(Tournament data) {
    adrTournament P = new ElmTournament;
    P->info = data;
    P->info.firstMatch = nullptr;
    P->next = nullptr;
    return P;
}

void insertFirstTournament(ListTournament &L, adrTournament P) {
    if(L.first == nullptr){
        L.first = P;
    }else{
        P->next = L.first;
        L.first = P;
    }
}

void insertLastTournament(ListTournament &L, adrTournament P) 
{
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrTournament Q = L.first;
        while(Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfterTournament(ListTournament &L, adrTournament Prec, adrTournament P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteTournament(ListTournament &L, int tournamentID) {
    adrTournament P = L.first;
    adrTournament Prec = nullptr;
    
    while(P != nullptr && P->info.tournamentID != tournamentID){
        Prec = P;
        P = P->next;
    }
    
    if (P != nullptr) {
        deleteAllMatches(P);
        
        if (Prec == nullptr) {
            L.first = P->next;
        } else {
            Prec->next = P->next;
        }
        delete P;
        cout<<"Tournament berhasil dihapus"<<endl;
    } else {
        cout<<"Tournament dengan ID "<<tournamentID<<" tidak ditemukan!"<<endl;
    }
}

//query
adrTournament findTournamentByID(ListTournament L, int tournamentID) {
    adrTournament P = L.first;
    while (P != nullptr) {
        if (P->info.tournamentID == tournamentID) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

adrTournament findTournamentByName(ListTournament L, string name) {
    adrTournament P = L.first;
    while (P != nullptr) {
        if (P->info.tournamentName == name) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void showAllTournaments(ListTournament L) 
{
    if(L.first == nullptr){
        cout<<"Belum ada tournament yang terdaftar."<<endl;
        return;
    }
    
    adrTournament P = L.first;
    cout<<"\n========================================"<<endl;
    cout<<"         DAFTAR TOURNAMENT ESPORT       "<<endl;
    cout<<"========================================"<<endl;
    
    while (P != nullptr) {
        cout<<"ID Tournament  : "<<P->info.tournamentID<<endl;
        cout<<"Nama           : "<<P->info.tournamentName<<endl;
        cout<<"Game           : "<<P->info.game<<endl;
        cout<<"Tanggal Mulai  : "<<P->info.startDate<<endl;
        cout<<"Tanggal Selesai: "<<P->info.endDate<<endl;
        cout<<"Total Hadiah   : $"<<P->info.totalPrize<<endl;
        cout<<"Jumlah Match   : "<<countMatchesByTournament(P)<<endl;
        cout<<"----------------------------------------"<<endl;
        P = P->next;
    }
    pauseScreen();
}

void showTournamentsSortedByPrize(ListTournament L) {
    if(L.first == nullptr){
        cout<<"Belum ada tournament yang terdaftar."<<endl;
        return;
    }

    vector<adrTournament> arr;
    adrTournament P = L.first;
    while(P != nullptr){
        arr.push_back(P);
        P = P->next;
    }

    sort(arr.begin(), arr.end(), [](adrTournament a, adrTournament b){
        return a->info.totalPrize > b->info.totalPrize; // descending
    });

    cout<<"\n=== DAFTAR TOURNAMENT (Diurutkan berdasarkan Total Prize) ==="<<endl;
    for(auto &t : arr){
        cout<<"ID Tournament  : "<<t->info.tournamentID<<endl;
        cout<<"Nama           : "<<t->info.tournamentName<<endl;
        cout<<"Game           : "<<t->info.game<<endl;
        cout<<"Tanggal Mulai  : "<<t->info.startDate<<endl;
        cout<<"Tanggal Selesai: "<<t->info.endDate<<endl;
        cout<<"Total Hadiah   : $"<<t->info.totalPrize<<endl;
        cout<<"Jumlah Match   : "<<countMatchesByTournament(t)<<endl;
        cout<<"----------------------------------------"<<endl;
    }
    pauseScreen();
}

void updateTournament(ListTournament &L, int tournamentID) {
    adrTournament P = findTournamentByID(L, tournamentID);
    if (P != nullptr) {
        cout<<"\n=== Update Tournament ==="<<endl;
        cout<<"Data saat ini:"<<endl;
        cout<<"Nama: "<<P->info.tournamentName<<endl;
        cout<<"Game: "<<P->info.game<<endl;
        cout<<"Hadiah: $"<<P->info.totalPrize<<endl;
        
        cout<<"\nMasukkan data baru:"<<endl;
        cout<<"Nama Tournament: ";
        cin >> P->info.tournamentName;
        cout<<"Game: ";
        cin >> P->info.game;
        cout<<"Tanggal Mulai (DD/MM/YYYY): ";
        cin >> P->info.startDate;
        cout<<"Tanggal Selesai (DD/MM/YYYY): ";
        cin >> P->info.endDate;
        cout<<"Total Hadiah ($): ";
        cin >> P->info.totalPrize;
        
        cout<<"Tournament berhasil diupdate!"<<endl;
    } else {
        cout<<"Tournament tidak ditemukan!"<<endl;
    }
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

void deleteAllTournaments(ListTournament &L) {
    adrTournament P = L.first;
    while (P != nullptr) {
        deleteAllMatches(P);
        adrTournament temp = P;
        P = P->next;
        delete temp;
    }
    L.first = nullptr;
}
