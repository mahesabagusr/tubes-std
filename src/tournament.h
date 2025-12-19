#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
using namespace std;

// === DEFINISI TIPE ala Node/adr ===
// Parent = Tournament -> adrTournament
// Child  = Match      -> adrMatch
typedef struct ElmTournament* adrTournament;
typedef struct ElmMatch* adrMatch;

// Struktur untuk Match (Child)
struct Match {
    int matchID;
    string matchName;
    string team1;
    string team2;
    int scoreTeam1;
    int scoreTeam2;
    string matchDate;
    string status; // "Scheduled", "Ongoing", "Completed"
};

// Struktur untuk element child (Match)
struct ElmMatch {
    Match info;
    adrMatch next;
};

// Struktur untuk Tournament (Parent)
struct Tournament {
    int tournamentID;
    string tournamentName;
    string game;
    string startDate;
    string endDate;
    int totalPrize;
    adrMatch firstMatch; // Pointer ke list match
};

// Struktur untuk element parent (Tournament)
struct ElmTournament {
    Tournament info;
    adrTournament next;
};

// List Tournament
struct ListTournament {
    adrTournament first;
};

// Deklarasi fungsi untuk Tournament (Parent)
void createListTournament(ListTournament &L);
adrTournament createElmTournament(Tournament data);
void insertFirstTournament(ListTournament &L, adrTournament P);
void insertLastTournament(ListTournament &L, adrTournament P);
void insertAfterTournament(ListTournament &L, adrTournament Prec, adrTournament P);
void deleteTournament(ListTournament &L, int tournamentID);
adrTournament findTournamentByID(ListTournament L, int tournamentID);
adrTournament findTournamentByName(ListTournament L, string name);
void showAllTournaments(ListTournament L);
void updateTournament(ListTournament &L, int tournamentID);

// Deklarasi fungsi untuk Match (Child)
adrMatch createElmMatch(Match data);
void insertFirstMatch(adrTournament P, adrMatch M);
void insertLastMatch(adrTournament P, adrMatch M);
void deleteMatch(adrTournament P, int matchID);
adrMatch findMatchByID(adrTournament P, int matchID);
adrMatch findMatchByName(adrTournament P, string matchName);
void showAllMatches(adrTournament P);
void updateMatch(adrTournament P, int matchID);

// Fungsi Query
void queryTournamentByPrize(ListTournament L, int minPrize);

// Fungsi Counting
int countAllTournaments(ListTournament L);
int countAllMatches(ListTournament L);
int countMatchesByTournament(adrTournament P);

// Fungsi utility
void deleteAllMatches(adrTournament P);
void deleteAllTournaments(ListTournament &L);

#endif
