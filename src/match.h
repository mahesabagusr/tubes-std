#ifndef MATCH_H
#define MATCH_H

#include <string>
using namespace std;

typedef struct ElmMatch* adrMatch;
typedef struct ElmTournament* adrTournament;

struct Match {
    int matchID;
    string matchName;
    string team1;
    string team2;
    int scoreTeam1;
    int scoreTeam2;
    string matchDate;
    string status;
};

struct ElmMatch {
    Match info;
    adrMatch next;
};

adrMatch createElmMatch(Match data);
void insertFirstMatch(adrTournament P, adrMatch M);
void insertLastMatch(adrTournament P, adrMatch M);
void deleteMatch(adrTournament P, int matchID);
adrMatch findMatchByID(adrTournament P, int matchID);
adrMatch findMatchByName(adrTournament P, string matchName);
void showAllMatches(adrTournament P);
void updateMatch(adrTournament P, int matchID);
void deleteAllMatches(adrTournament P);
int countMatchesByTournament(adrTournament P);

#endif
