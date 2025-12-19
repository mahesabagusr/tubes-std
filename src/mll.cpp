#include "tournament.h"
#include <iostream>
#include <iomanip>
using namespace std;

// ==================== FUNGSI QUERY ====================

void queryTournamentByPrize(ListTournament L, int minPrize) {
    adrTournament P = L.first;
    bool found = false;
    
    cout << "\n=== Tournament dengan Hadiah >= $" << minPrize << " ===" << endl;
    
    while (P != nullptr) {
        if (P->info.totalPrize >= minPrize) {
            cout << "\nNama: " << P->info.tournamentName << endl;
            cout << "Game: " << P->info.game << endl;
            cout << "Hadiah: $" << P->info.totalPrize << endl;
            cout << "Jumlah Match: " << countMatchesByTournament(P) << endl;
            cout << "----------------------------------------" << endl;
            found = true;
        }
        P = P->next;
    }
    
    if (!found) {
        cout << "Tidak ada tournament dengan hadiah >= $" << minPrize << endl;
    }
}

// ==================== FUNGSI COUNTING ====================

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

// ==================== FUNGSI UTILITY ====================

void deleteAllMatches(adrTournament P) {
    adrMatch M = P->info.firstMatch;
    while (M != nullptr) {
        adrMatch temp = M;
        M = M->next;
        delete temp;
    }
    P->info.firstMatch = nullptr;
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
