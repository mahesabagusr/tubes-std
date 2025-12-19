#include "match.h"
#include "tournament.h"
#include <iostream>
#include <iomanip>
using namespace std;

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
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
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
        cin >> M->info.matchName;
        cout << "Tim 1: ";
        cin >> M->info.team1;
        cout << "Tim 2: ";
        cin >> M->info.team2;
        cout << "Score Tim 1: ";
        cin >> M->info.scoreTeam1;
        cout << "Score Tim 2: ";
        cin >> M->info.scoreTeam2;
        cout << "Tanggal Match (DD/MM/YYYY): ";
        cin >> M->info.matchDate;
        cout << "Status (Scheduled/Ongoing/Completed): ";
        cin >> M->info.status;
        
        cout << "Match berhasil diupdate!" << endl;
    } else {
        cout << "Match tidak ditemukan!" << endl;
    }
}

void deleteAllMatches(adrTournament P) {
    adrMatch M = P->info.firstMatch;
    adrMatch temp = nullptr;
    while (M != nullptr) {
        temp = M;
        M = M->next;
        delete temp;
    }
    P->info.firstMatch = nullptr;
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
