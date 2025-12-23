#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
#include "match.h"
using namespace std;

typedef struct ElmTournament* adrTournament;

struct Tournament {
    int tournamentID;
    string tournamentName;
    string game;
    string startDate;
    string endDate;
    int totalPrize;
    adrMatch firstMatch;
};

struct ElmTournament {
    Tournament info;
    adrTournament next;
};

struct ListTournament {
    adrTournament first;
};


// Tournament
void createListTournament(ListTournament &L);
adrTournament createElmTournament(Tournament data);
void insertFirstTournament(ListTournament &L, adrTournament P);
void insertLastTournament(ListTournament &L, adrTournament P);
void insertAfterTournament(ListTournament &L, adrTournament Prec, adrTournament P);
void deleteTournament(ListTournament &L, int tournamentID);
adrTournament findTournamentByID(ListTournament L, int tournamentID);
adrTournament findTournamentByName(ListTournament L, string name);
void showAllTournaments(ListTournament L);
void showTournamentsSortedByPrize(ListTournament L);
void updateTournament(ListTournament &L, int tournamentID);

void queryTournamentByPrize(ListTournament L, int minPrize);
void queryTournamentByPrizeAndMatches(ListTournament L, int minPrize, int minMatches);
int countAllTournaments(ListTournament L);
int countAllMatches(ListTournament L);
int countMatchesByTournament(adrTournament P);

void deleteFirstTournament(ListTournament &L);
void deleteLastTournament(ListTournament &L);
float getAveragePrize(ListTournament L);
float getAverageMatchPerTournament(ListTournament L);
void groupTournamentByGame(ListTournament L);

void deleteAllTournaments(ListTournament &L);

#endif
