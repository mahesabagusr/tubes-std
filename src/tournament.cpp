#include "tournament.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ==================== FUNGSI TOURNAMENT (PARENT) ====================

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
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertLastTournament(ListTournament &L, adrTournament P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        adrTournament Q = L.first;
        while (Q->next != nullptr) {
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
    
    while (P != nullptr && P->info.tournamentID != tournamentID) {
        Prec = P;
        P = P->next;
    }
    
    if (P != nullptr) {
        // Hapus semua match terlebih dahulu
        deleteAllMatches(P);
        
        if (Prec == nullptr) {
            L.first = P->next;
        } else {
            Prec->next = P->next;
        }
        delete P;
        cout << "Tournament berhasil dihapus!" << endl;
    } else {
        cout << "Tournament dengan ID " << tournamentID << " tidak ditemukan!" << endl;
    }
}

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

void showAllTournaments(ListTournament L) {
    if (L.first == nullptr) {
        cout << "Belum ada tournament yang terdaftar." << endl;
        return;
    }
    
    adrTournament P = L.first;
    cout << "\n========================================" << endl;
    cout << "         DAFTAR TOURNAMENT ESPORT       " << endl;
    cout << "========================================" << endl;
    
    while (P != nullptr) {
        cout << "ID Tournament  : " << P->info.tournamentID << endl;
        cout << "Nama           : " << P->info.tournamentName << endl;
        cout << "Game           : " << P->info.game << endl;
        cout << "Tanggal Mulai  : " << P->info.startDate << endl;
        cout << "Tanggal Selesai: " << P->info.endDate << endl;
        cout << "Total Hadiah   : $" << P->info.totalPrize << endl;
        cout << "Jumlah Match   : " << countMatchesByTournament(P) << endl;
        cout << "----------------------------------------" << endl;
        P = P->next;
    }
}

void updateTournament(ListTournament &L, int tournamentID) {
    adrTournament P = findTournamentByID(L, tournamentID);
    if (P != nullptr) {
        cout << "\n=== Update Tournament ===" << endl;
        cout << "Data saat ini:" << endl;
        cout << "Nama: " << P->info.tournamentName << endl;
        cout << "Game: " << P->info.game << endl;
        cout << "Hadiah: $" << P->info.totalPrize << endl;
        
        cout << "\nMasukkan data baru:" << endl;
        cout << "Nama Tournament: ";
        cin.ignore();
        getline(cin, P->info.tournamentName);
        cout << "Game: ";
        getline(cin, P->info.game);
        cout << "Tanggal Mulai (DD/MM/YYYY): ";
        getline(cin, P->info.startDate);
        cout << "Tanggal Selesai (DD/MM/YYYY): ";
        getline(cin, P->info.endDate);
        cout << "Total Hadiah ($): ";
        cin >> P->info.totalPrize;
        
        cout << "Tournament berhasil diupdate!" << endl;
    } else {
        cout << "Tournament tidak ditemukan!" << endl;
    }
}

// ==================== FUNGSI MATCH (CHILD) ====================

adrMatch createElmMatch(Match data) {
    adrMatch M = new ElmMatch;
    M->info = data;
    M->next = nullptr;
    return M;
}

void insertFirstMatch(adrTournament P, adrMatch M) {
    if (P->info.firstMatch == nullptr) {
        P->info.firstMatch = M;
    } else {
        M->next = P->info.firstMatch;
        P->info.firstMatch = M;
    }
}

void insertLastMatch(adrTournament P, adrMatch M) {
    if (P->info.firstMatch == nullptr) {
        P->info.firstMatch = M;
    } else {
        adrMatch Q = P->info.firstMatch;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = M;
    }
}

void deleteMatch(adrTournament P, int matchID) {
    adrMatch M = P->info.firstMatch;
    adrMatch Prec = nullptr;
    
    while (M != nullptr && M->info.matchID != matchID) {
        Prec = M;
        M = M->next;
    }
    
    if (M != nullptr) {
        if (Prec == nullptr) {
            P->info.firstMatch = M->next;
        } else {
            Prec->next = M->next;
        }
        delete M;
        cout << "Match berhasil dihapus!" << endl;
    } else {
        cout << "Match dengan ID " << matchID << " tidak ditemukan!" << endl;
    }
}

adrMatch findMatchByID(adrTournament P, int matchID) {
    adrMatch M = P->info.firstMatch;
    while (M != nullptr) {
        if (M->info.matchID == matchID) {
            return M;
        }
        M = M->next;
    }
    return nullptr;
}

adrMatch findMatchByName(adrTournament P, string matchName) {
    adrMatch M = P->info.firstMatch;
    while (M != nullptr) {
        if (M->info.matchName == matchName) {
            return M;
        }
        M = M->next;
    }
    return nullptr;
}

void showAllMatches(adrTournament P) {
    if (P->info.firstMatch == nullptr) {
        cout << "Belum ada match dalam tournament ini." << endl;
        return;
    }
    
    adrMatch M = P->info.firstMatch;
    cout << "\n========================================" << endl;
    cout << "   DAFTAR MATCH: " << P->info.tournamentName << endl;
    cout << "========================================" << endl;
    
    while (M != nullptr) {
        cout << "ID Match   : " << M->info.matchID << endl;
        cout << "Nama Match : " << M->info.matchName << endl;
        cout << "Tim 1      : " << M->info.team1 << " (Score: " << M->info.scoreTeam1 << ")" << endl;
        cout << "Tim 2      : " << M->info.team2 << " (Score: " << M->info.scoreTeam2 << ")" << endl;
        cout << "Tanggal    : " << M->info.matchDate << endl;
        cout << "Status     : " << M->info.status << endl;
        cout << "----------------------------------------" << endl;
        M = M->next;
    }
}

void updateMatch(adrTournament P, int matchID) {
    adrMatch M = findMatchByID(P, matchID);
    if (M != nullptr) {
        cout << "\n=== Update Match ===" << endl;
        cout << "Data saat ini:" << endl;
        cout << "Match: " << M->info.team1 << " vs " << M->info.team2 << endl;
        cout << "Score: " << M->info.scoreTeam1 << " - " << M->info.scoreTeam2 << endl;
        
        cout << "\nMasukkan data baru:" << endl;
        cout << "Nama Match: ";
        cin.ignore();
        getline(cin, M->info.matchName);
        cout << "Tim 1: ";
        getline(cin, M->info.team1);
        cout << "Tim 2: ";
        getline(cin, M->info.team2);
        cout << "Score Tim 1: ";
        cin >> M->info.scoreTeam1;
        cout << "Score Tim 2: ";
        cin >> M->info.scoreTeam2;
        cin.ignore();
        cout << "Tanggal Match (DD/MM/YYYY): ";
        getline(cin, M->info.matchDate);
        cout << "Status (Scheduled/Ongoing/Completed): ";
        getline(cin, M->info.status);
        
        cout << "Match berhasil diupdate!" << endl;
    } else {
        cout << "Match tidak ditemukan!" << endl;
    }
}

// ==================== FUNGSI SEARCH/QUERY/UTILITY DIPINDAHKAN KE mll.cpp ====================
