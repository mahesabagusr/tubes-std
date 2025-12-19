#ifndef MENU_H
#define MENU_H

#include "tournament.h"

// Fungsi Display Menu
void displayMainMenu();
void displayTournamentMenu();
void displayMatchMenu();

// Fungsi Menu Tournament
void menuTournament(ListTournament &L);
void addTournament(ListTournament &L);
void searchTournamentByIDWithList(ListTournament L);
void searchTournamentByName(ListTournament L);
void handleUpdateTournament(ListTournament &L);
void handleDeleteTournament(ListTournament &L);

// Fungsi Menu Match
void menuMatch(ListTournament &L);
void addMatch(ListTournament &L);
void handleShowMatches(ListTournament L);
void searchMatchByIDWithList(ListTournament L);
void handleUpdateMatch(ListTournament L);
void handleDeleteMatch(ListTournament L);

// Fungsi Search & Query
void searchTournament(ListTournament L);
void queryTournament(ListTournament L);

// Fungsi Statistik
void showStatistics(ListTournament L);

// Fungsi Load Sample Data
void loadSampleData(ListTournament &L);

#endif
