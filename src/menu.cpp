#include "menu.h"
#include "utils.h"
#include <iostream>
using namespace std;

void displayMainMenu() 
{
    cout<<"\n============================================"<<endl;
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
    cout<<"\n========================================"<<endl;
    cout<<"         MENU TOURNAMENT"<<endl;
    cout<<"========================================"<<endl;
    cout<<"1. Tambah Tournament Baru"<<endl;
    cout<<"2. Lihat Semua Tournament"<<endl;
    cout<<"3. Cari Tournament by ID"<<endl;
    cout<<"4. Cari Tournament by Nama"<<endl;
    cout<<"5. Update Tournament"<<endl;
    cout<<"6. Hapus Tournament"<<endl;
    cout<<"0. Kembali ke Menu Utama"<<endl;
    cout<<"========================================"<<endl;
    cout<<"Pilih menu: ";
}

void displayMatchMenu() {
    cout<<"\n========================================"<<endl;
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
                cout<<"\nMenghapus semua Tournament!"<<endl;
                deleteAllTournaments(L);
                running = false;
                break;
            default:
                cout<<"\nPilihan tidak valid!"<<endl;
                break;
        }
    }
}

void addTournament(ListTournament &L) {
    Tournament t;
    adrTournament P = nullptr;
    cout<<"\n=== Tambah Tournament Baru ==="<<endl;
    cout<<"ID Tournament: ";
    cin >> t.tournamentID;
    cin.ignore();

    if (findTournamentByID(L, t.tournamentID) != nullptr) {
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
    cout<<"\nTournament berhasil ditambahkan!"<<endl;
}

void searchTournamentByIDWithList(ListTournament L) {
    int id = selectTournamentFromList(L);
    if(id == -1) return;
    
    adrTournament P = findTournamentByID(L, id);
    if(P){
        displayTournamentInfo(P);
    }else{
        cout<<"Tournament tidak ditemukan!"<<endl;
    }
}

void searchTournamentByName(ListTournament L) {
    string name;
    cout<<"\nMasukkan Nama Tournament: ";
    cin.ignore();
    getline(cin, name);
    adrTournament P = findTournamentByName(L, name);
    if(P){
        displayTournamentInfo(P);
    }else{
        cout<<"Tournament tidak ditemukan!"<<endl;
    }
}

void handleUpdateTournament(ListTournament &L) {
    int id = selectTournamentFromList(L);
    if(id == -1) return;
    updateTournament(L, id);
}

void handleDeleteTournament(ListTournament &L) {
    int id = selectTournamentFromList(L);
    if(id == -1) return;
    
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

void addMatch(ListTournament &L) {
    int tournamentID = selectTournamentFromList(L);
    if(tournamentID == -1) return;
    
    adrTournament T = findTournamentByID(L, tournamentID);
    if(!T){
        cout<<"Tournament tidak ditemukan!"<<endl;
        return;
    }

    Match m;
    cout<<"ID Match: ";
    cin>>m.matchID;
    if(findMatchByID(T, m.matchID)){
        cout<<"ID match sudah ada!"<<endl;
        return;
    }
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
    cout<<"\nMatch berhasil ditambahkan!"<<endl;
}

void handleShowMatches(ListTournament L) {
    int tournamentID = selectTournamentFromList(L);
    if(tournamentID == -1) return;
    
    adrTournament T = findTournamentByID(L, tournamentID);
    if(!T){
        cout<<"Tournament tidak ditemukan!"<<endl;
        return;
    }
    showAllMatches(T);
}

void searchMatchByIDWithList(ListTournament L) {
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
    cout<<"\nMasukkan ID Match: ";
    cin >> matchID;
    M = findMatchByID(T, matchID);
    if (M) {
        cout<<"\nID Match   : "<<M->info.matchID<<endl;
        cout<<"Nama Match : "<<M->info.matchName<<endl;
        cout<<"Tim 1      : "<<M->info.team1<<" (Score: "<<M->info.scoreTeam1<<")"<<endl;
        cout<<"Tim 2      : "<<M->info.team2<<" (Score: "<<M->info.scoreTeam2<<")"<<endl;
        cout<<"Tanggal    : "<<M->info.matchDate<<endl;
        cout<<"Status     : "<<M->info.status<<endl;
    } else {
        cout<<"Match tidak ditemukan!"<<endl;
    }
}

void handleUpdateMatch(ListTournament L) {
    adrTournament temp = nullptr;
    int tournamentID = 0;
    adrTournament T = nullptr;
    adrMatch m = nullptr;
    int matchID = 0;
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
    cout<<"\nDaftar Match:"<<endl;
    m = T->info.firstMatch;
    while (m != nullptr) {
        cout<<"ID: "<<m->info.matchID<<" - "<<m->info.matchName<<endl;
        m = m->next;
    }
    cout<<"\nMasukkan ID Match: ";
    cin >> matchID;
    updateMatch(T, matchID);
}

void handleDeleteMatch(ListTournament L) {
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
        cout<<"ID: "<<m->info.matchID<<" - "<<m->info.matchName<<endl;
        m = m->next;
    }
    cout<<"\nMasukkan ID Match: ";
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
    int minPrize;
    cout<<"\n=== Query Tournament by Prize ===";
    cout<<"\nMinimal hadiah ($): ";
    cin >> minPrize;
    queryTournamentByPrize(L, minPrize);
}

void menuAverage(ListTournament L) {
    cout<<"\n=== AVERAGE MENU ==="<<endl;
    cout<<"1. Rata-rata Prize Tournament"<<endl;
    cout<<"2. Rata-rata Match per Tournament"<<endl;
    cout<<"0. Kembali"<<endl;
    cout<<"Pilih: ";
    int choice;
    cin>>choice;
    
    if(choice == 1){
        float avg = getAveragePrize(L);
        cout<<"\n=== Rata-rata Prize ==="<<endl;
        cout<<"Average Prize: $"<<avg<<endl;
    }else if(choice == 2){
        float avg = getAverageMatchPerTournament(L);
        cout<<"\n=== Rata-rata Match ==="<<endl;
        cout<<"Average Match per Tournament: "<<avg<<endl;
    }
}

void menuGroupBy(ListTournament L) {
    cout<<"\n=== GROUP BY MENU ==="<<endl;
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
    cout<<"\n=== STATISTIK SISTEM ==="<<endl;
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
                searchTournamentByIDWithList(L);
                break;
            case 4:
                searchTournamentByName(L);
                break;
            case 5:
                handleUpdateTournament(L);
                break;
            case 6:
                handleDeleteTournament(L);
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
                handleShowMatches(L);
                break;
            case 3:
                searchMatchByIDWithList(L);
                break;
            case 4:
                handleUpdateMatch(L);
                break;
            case 5:
                handleDeleteMatch(L);
                break;
            case 0:
                run = false;
                break;
            default:
                cout<<"Pilihan tidak valid!"<<endl;
        }
    }
}


