#ifndef MENU_H
#define MENU_H

#include "tournament.h"
#include "match.h"

void displayMainMenu();
void displayTournamentMenu();
void displayMatchMenu();
void startMenu(ListTournament &L);

void menuTournament(ListTournament &L);
void addTournament(ListTournament &L);
void searchTournamentByID(ListTournament L);
void searchTournamentByName(ListTournament L);
void UpdateTournament(ListTournament &L);
void DeleteTournament(ListTournament &L);

void menuMatch(ListTournament &L);
void addMatch(ListTournament &L);
void ShowMatches(ListTournament L);
void searchMatchByID(ListTournament L);
void UpdateMatch(ListTournament L);
void DeleteMatch(ListTournament L);

void queryTournament(ListTournament L);
void menuAverage(ListTournament L);
void menuGroupBy(ListTournament L);

void showStatistics(ListTournament L);

#endif
