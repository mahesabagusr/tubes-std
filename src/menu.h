#ifndef MENU_H
#define MENU_H

#include "tournament.h"
#include "match.h"

void displayMainMenu();
void displayTournamentMenu();
void displayMatchMenu();

void menuTournament(ListTournament &L);
void addTournament(ListTournament &L);
void searchTournamentByIDWithList(ListTournament L);
void searchTournamentByName(ListTournament L);
void handleUpdateTournament(ListTournament &L);
void handleDeleteTournament(ListTournament &L);

void menuMatch(ListTournament &L);
void addMatch(ListTournament &L);
void handleShowMatches(ListTournament L);
void searchMatchByIDWithList(ListTournament L);
void handleUpdateMatch(ListTournament L);
void handleDeleteMatch(ListTournament L);

void searchTournament(ListTournament L);
void queryTournament(ListTournament L);

void showStatistics(ListTournament L);

void loadSampleData(ListTournament &L);

#endif
