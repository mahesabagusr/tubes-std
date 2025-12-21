#include "utils.h"
#include <iostream>
using namespace std;

void pauseScreen() {
    cout<<"\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void displayTournamentInfo(adrTournament P) {
    cout<<"\nID             : "<<P->info.tournamentID<<endl;
    cout<<"Nama           : "<<P->info.tournamentName<<endl;
    cout<<"Game           : "<<P->info.game<<endl;
    cout<<"Tanggal Mulai  : "<<P->info.startDate<<endl;
    cout<<"Tanggal Selesai: "<<P->info.endDate<<endl;
    cout<<"Total Hadiah   : $"<<P->info.totalPrize<<endl;
    cout<<"Jumlah Match   : "<<countMatchesByTournament(P)<<endl;
}

int selectTournamentFromList(ListTournament L) {
    if(L.first == nullptr){
        cout<<"Belum ada tournament."<<endl;
        return -1;
    }
    
    cout<<"\nDaftar Tournament:"<<endl;
    adrTournament temp = L.first;
    while(temp != nullptr){
        cout<<"ID: "<<temp->info.tournamentID<<" - "<<temp->info.tournamentName
           <<" ("<<temp->info.game<<")"<<endl;
        temp = temp->next;
    }
    
    int id;
    cout<<"\nMasukkan ID Tournament: ";
    cin>>id;
    return id;
}
