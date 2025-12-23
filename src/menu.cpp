#include "menu.h"
#include "utils.h"
#include <iostream>
using namespace std;

void displayMainMenu() 
{
    cout<<endl;
    cout<<"============================================"<<endl;
    cout<<"   SISTEM MANAJEMEN TOURNAMENT ESPORT"<<endl;
    cout<<"============================================"<<endl;
    cout<<"1. Menu Tournament"<<endl;
    cout<<"2. Menu Match"<<endl;
    cout<<"3. Query Tournament"<<endl;
    cout<<"4. Average Menu"<<endl;
    cout<<"5. Group By Menu"<<endl;
    cout<<"6. Statistik Tournament"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"============================================"<<endl;
    cout<<"Pilih menu: ";
}

void displayTournamentMenu() {
    cout<<endl;
    cout<<"========================================"<<endl;
    cout<<"         MENU TOURNAMENT"<<endl;
    cout<<"========================================"<<endl;
    cout<<"1. Tambah Tournament Baru"<<endl;
    cout<<"2. Lihat Semua Tournament"<<endl;
    cout<<"3. Cari Tournament by ID"<<endl;
    cout<<"4. Cari Tournament by Nama"<<endl;
    cout<<"5. Update Tournament"<<endl;
    cout<<"6. Hapus Tournament"<<endl;
    cout<<"7. Lihat Tournament Diurutkan berdasarkan Prize"<<endl;
    cout<<"0. Kembali ke Menu Utama"<<endl;
    cout<<"========================================"<<endl;
    cout<<"Pilih menu: ";
}

void displayMatchMenu() {
    cout<<endl;
    cout<<"========================================"<<endl;
    cout<<"           MENU MATCH"<<endl;
    cout<<"========================================"<<endl;
    cout<<"1. Tambah Match ke Tournament"<<endl;
    cout<<"2. Lihat Semua Match dalam Tournament"<<endl;
    cout<<"3. Cari Match by ID"<<endl;
    cout<<"4. Update Match"<<endl;
    cout<<"5. Hapus Match"<<endl;
    cout<<"0. Kembali ke Menu Utama"<<endl;
    cout<<"========================================"<<endl;
    cout<<"Pilih menu: ";
}

void startMenu(ListTournament &L) {
    bool running = true;
    while (running) {
        displayMainMenu();
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                menuTournament(L);
                break;
            case 2:
                menuMatch(L);
                break;
            case 3:
                queryTournament(L);
                break;
            case 4:
                menuAverage(L);
                break;
            case 5:
                menuGroupBy(L);
                break;
            case 6:
                showStatistics(L);
                break;
            case 0:
                cout<<endl;
                cout<<"Menghapus semua Tournament!"<<endl;
                deleteAllTournaments(L);
                running = false;
                break;
            default:
                cout<<endl;
                cout<<"Pilihan tidak valid!"<<endl;
                break;
        }
    }
}

void addTournament(ListTournament &L) {
    Tournament t;
    adrTournament P = nullptr;
    int id = -1;
    cout<<endl;
    cout<<"=== Tambah Tournament Baru ==="<<endl;
    cout<<"ID Tournament: ";
    cin >> t.tournamentID;
    cin.ignore();

    id = findTournamentByID(L, t.tournamentID) ? t.tournamentID : -1;
    if (id != -1) {
        cout<<"Error: Tournament dengan ID tersebut sudah ada!"<<endl;
        return;
    }

    cout<<"Nama Tournament: ";
    cin >> t.tournamentName;
    cout<<"Game (contoh: ML, PUBG, Valorant): ";
    cin >> t.game;
    cout<<"Tanggal Mulai (DD/MM/YYYY): ";
    cin >> t.startDate;
    cout<<"Tanggal Selesai (DD/MM/YYYY): ";
    cin >> t.endDate;
    cout<<"Total Hadiah ($): ";
    cin >> t.totalPrize;

    P = createElmTournament(t);
    insertLastTournament(L, P);
    cout<<endl;
    cout<<"Tournament berhasil ditambahkan!"<<endl;
}

void searchTournamentByID(ListTournament L) {
    int id = selectTournamentFromList(L);
    if(id != -1){
        adrTournament P = findTournamentByID(L, id);
        if(P){
            displayTournamentInfo(P);
        }else{
            cout<<"Tournament tidak ditemukan!"<<endl;
        }
    }
}

void searchTournamentByName(ListTournament L) {
    string name;
    cout<<endl;
    cout<<"Masukkan Nama Tournament: ";
    cin.ignore();
    getline(cin, name);
    adrTournament P = findTournamentByName(L, name);
    if(P){
        displayTournamentInfo(P);
    }else{
        cout<<"Tournament tidak ditemukan!"<<endl;
    }
}

void UpdateTournament(ListTournament &L) {
    int id = selectTournamentFromList(L);
    if(id != -1){
        updateTournament(L, id);
    }
}

void DeleteTournament(ListTournament &L) {
    int id = selectTournamentFromList(L);
    if(id != -1){
        adrTournament P = findTournamentByID(L, id);
        if(P){
            cout<<"Tournament yang akan dihapus: "<<P->info.tournamentName<<endl;
            cout<<"Apakah Anda yakin? (y/n): ";
            char c;
            cin>>c;
            if(c == 'y' || c == 'Y') deleteTournament(L, id);
            else cout<<"Penghapusan dibatalkan."<<endl;
        }else{
            cout<<"Tournament tidak ditemukan!"<<endl;
        }
    }
}

void addMatch(ListTournament &L) {
    int tournamentID = selectTournamentFromList(L);
    if(tournamentID != -1){
        adrTournament T = findTournamentByID(L, tournamentID);
        if(T){
            Match m;
            cout<<"ID Match: ";
            cin>>m.matchID;
            if(!findMatchByID(T, m.matchID)){
                cout<<"Nama Match: ";
                cin>>m.matchName;
                cout<<"Tim 1: ";
                cin>>m.team1;
                cout<<"Tim 2: ";
                cin>>m.team2;
                cout<<"Score Tim 1: ";
                cin>>m.scoreTeam1;
                cout<<"Score Tim 2: ";
                cin>>m.scoreTeam2;
                cout<<"Tanggal Match (DD/MM/YYYY): ";
                cin>>m.matchDate;
                cout<<"Status (Scheduled/Ongoing/Completed): ";
                cin>>m.status;

                adrMatch M = createElmMatch(m);
                insertLastMatch(T, M);
                cout<<endl;
                cout<<"Match berhasil ditambahkan!"<<endl;
            }else{
                cout<<"ID match sudah ada!"<<endl;
            }
        }else{
            cout<<"Tournament tidak ditemukan!"<<endl;
        }
    }
}

void ShowMatches(ListTournament L) {
    int tournamentID = selectTournamentFromList(L);
    if(tournamentID != -1){
        adrTournament T = findTournamentByID(L, tournamentID);
        if(T){
            showAllMatches(T);
        }else{
            cout<<"Tournament tidak ditemukan!"<<endl;
        }
    }
}

void searchMatchByID(ListTournament L) {
    adrTournament temp = nullptr;
    int tournamentID = 0;
    adrTournament T = nullptr;
    adrMatch m = nullptr;
    int matchID = 0;
    adrMatch M = nullptr;
    if (L.first == nullptr) {
        cout<<"Belum ada tournament."<<endl;
        return;
    }
    cout<<"\nDaftar Tournament:"<<endl;
    temp = L.first;
    while (temp != nullptr) {
        cout<<"ID: "<<temp->info.tournamentID<<" - "<<temp->info.tournamentName<<endl;
        temp = temp->next;
    }
    cout<<"\nMasukkan ID Tournament: ";
    cin >> tournamentID;
    T = findTournamentByID(L, tournamentID);
    if (!T) {
        cout<<"Tournament tidak ditemukan!"<<endl;
        return;
    }
    if (T->info.firstMatch == nullptr) {
        cout<<"Belum ada match."<<endl;
        return;
    }
    cout<<"\nDaftar Match:"<<endl;
    m = T->info.firstMatch;
    while (m != nullptr) {
        cout<<"ID: "<<m->info.matchID<<" - "<<m->info.matchName
           <<" ("<<m->info.team1<<" vs "<<m->info.team2<<")"<<endl;
        m = m->next;
    }
    cout<<endl;
    cout<<"Masukkan ID Match: ";
    cin >> matchID;
    M = findMatchByID(T, matchID);
    if (M) {
        cout<<endl;
        cout<<"ID Match   : "<<M->info.matchID<<endl;
        cout<<"Nama Match : "<<M->info.matchName<<endl;
        cout<<"Tim 1      : "<<M->info.team1<<" (Score: "<<M->info.scoreTeam1<<")"<<endl;
        cout<<"Tim 2      : "<<M->info.team2<<" (Score: "<<M->info.scoreTeam2<<")"<<endl;
        cout<<"Tanggal    : "<<M->info.matchDate<<endl;
        cout<<"Status     : "<<M->info.status<<endl;
    } else {
        cout<<"Match tidak ditemukan!"<<endl;
    }
}

void UpdateMatch(ListTournament L) {
    adrTournament temp = nullptr;
    int tournamentID = 0;
    adrTournament T = nullptr;
    adrMatch m = nullptr;
    int matchID = 0;
    if (L.first == nullptr) {
        cout<<"Belum ada tournament."<<endl;
        return;
    }
    cout<<endl;
    cout<<"Daftar Tournament:"<<endl;
    temp = L.first;
    while (temp != nullptr) {
        cout<<"ID: "<<temp->info.tournamentID<<" - "<<temp->info.tournamentName<<endl;
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Masukkan ID Tournament: ";
    cin >> tournamentID;
    T = findTournamentByID(L, tournamentID);
    if (!T) {
        cout<<"Tournament tidak ditemukan!"<<endl;
        return;
    }
    cout<<endl;
    cout<<"Daftar Match:"<<endl;
    m = T->info.firstMatch;
    while (m != nullptr) {
        cout<<"ID: "<<m->info.matchID<<" - "<<m->info.matchName<<endl;
        m = m->next;
    }
    cout<<endl;
    cout<<"Masukkan ID Match: ";
    cin >> matchID;
    updateMatch(T, matchID);
}

void DeleteMatch(ListTournament L) {
    adrTournament temp = nullptr;
    int tournamentID = 0;
    adrTournament T = nullptr;
    adrMatch m = nullptr;
    int matchID = 0;
    adrMatch M = nullptr;
    char c = 0;
    if (L.first == nullptr) {
        cout<<"Belum ada tournament."<<endl;
        return;
    }
    cout<<endl;
    cout<<"Daftar Tournament:"<<endl;
    temp = L.first;
    while (temp != nullptr) {
        cout<<"ID: "<<temp->info.tournamentID<<" - "<<temp->info.tournamentName<<endl;
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Masukkan ID Tournament: ";
    cin >> tournamentID;
    T = findTournamentByID(L, tournamentID);
    if (!T) {
        cout<<"Tournament tidak ditemukan!"<<endl;
        return;
    }
    if (T->info.firstMatch == nullptr) {
        cout<<"Belum ada match."<<endl;
        return;
    }
    cout<<endl;
    cout<<"Daftar Match:"<<endl;
    m = T->info.firstMatch;
    while (m != nullptr) {
        cout<<"ID: "<<m->info.matchID<<" - "<<m->info.matchName<<endl;
        m = m->next;
    }
    cout<<endl;
    cout<<"Masukkan ID Match: ";
    cin >> matchID;
    M = findMatchByID(T, matchID);
    if (M) {
        cout<<"Hapus match: "<<M->info.matchName<<"? (y/n): ";
        cin >> c;
        if (c == 'y' || c == 'Y') {
            deleteMatch(T, matchID);
        } else {
            cout<<"Dibatalkan."<<endl;
        }
    } else {
        cout<<"Match tidak ditemukan!"<<endl;
    }
}

void queryTournament(ListTournament L) {
    while (true) {
        cout<<endl;
        cout<<"=== QUERY TOURNAMENT ==="<<endl;
        cout<<"1. Query by Prize"<<endl;
        cout<<"2. Complex Query"<<endl;
        cout<<"0. Kembali"<<endl;
        cout<<"Pilih: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int minPrize;
            cout<<endl;
            cout<<"=== Query Tournament by Prize ==="<<endl;
            cout<<"Minimal hadiah ($): ";
            cin >> minPrize;
            queryTournamentByPrize(L, minPrize);
        } else if (choice == 2) {
            int minPrize, minMatches;
            cout<<endl;
            cout<<"=== Complex Query (Prize + Matches) ==="<<endl;
            cout<<"Minimal hadiah ($): ";
            cin >> minPrize;
            cout<<"Minimal jumlah match: ";
            cin >> minMatches;
            queryTournamentByPrizeAndMatches(L, minPrize, minMatches);
        } else {
            break;
        }
    }
}

void menuAverage(ListTournament L) {
    cout<<endl;
    cout<<"=== AVERAGE MENU ==="<<endl;
    cout<<"1. Rata-rata Prize Tournament"<<endl;
    cout<<"2. Rata-rata Match per Tournament"<<endl;
    cout<<"0. Kembali"<<endl;
    cout<<"Pilih: ";
    int choice;
    cin>>choice;
    
    if(choice == 1){
        float avg = getAveragePrize(L);
        cout<<endl;
        cout<<"=== Rata-rata Prize ==="<<endl;
        cout<<"Average Prize: $"<<avg<<endl;
    }else if(choice == 2){
        float avg = getAverageMatchPerTournament(L);
        cout<<endl;
        cout<<"=== Rata-rata Match ==="<<endl;
        cout<<"Average Match per Tournament: "<<avg<<endl;
    }
}

void menuGroupBy(ListTournament L) {
    cout<<endl;
    cout<<"=== GROUP BY MENU ==="<<endl;
    cout<<"1. Group Tournament by Game"<<endl;
    cout<<"0. Kembali"<<endl;
    cout<<"Pilih: ";
    int choice;
    cin>>choice;
    
    if(choice == 1){
        groupTournamentByGame(L);
    }
}

void showStatistics(ListTournament L) {
    cout<<endl;
    cout<<"=== STATISTIK SISTEM ==="<<endl;
    cout<<"Total Tournament: "<<countAllTournaments(L)<<endl;
    cout<<"Total Match     : "<<countAllMatches(L)<<endl;
}

void menuTournament(ListTournament &L) {
    bool run = true;
    int c = 0;
    while (run) {
        displayTournamentMenu();
        cin >> c;
        switch (c) {
            case 1:
                addTournament(L);
                break;
            case 2:
                showAllTournaments(L);
                break;
            case 3:
                searchTournamentByID(L);
                break;
            case 4:
                searchTournamentByName(L);
                break;
            case 5:
                UpdateTournament(L);
                break;
            case 6:
                DeleteTournament(L);
                break;
            case 7:
                showTournamentsSortedByPrize(L);
                break;
            case 0:
                run = false;
                break;
            default:
                cout<<"Pilihan tidak valid!"<<endl;
        }
    }
}

void menuMatch(ListTournament &L) {
    bool run = true;
    int c = 0;
    while (run) {
        displayMatchMenu();
        cin >> c;
        switch (c) {
            case 1:
                addMatch(L);
                break;
            case 2:
                ShowMatches(L);
                break;
            case 3:
                searchMatchByID(L);
                break;
            case 4:
                UpdateMatch(L);
                break;
            case 5:
                DeleteMatch(L);
                break;
            case 0:
                run = false;
                break;
            default:
                cout<<"Pilihan tidak valid!"<<endl;
        }
    }
}


