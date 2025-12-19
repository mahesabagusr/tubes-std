#include <iostream>
#include "src/tournament.h"
#include "src/menu.h"
using namespace std;

int main() {
    ListTournament L;
    createListTournament(L);

    cout << "=== Sistem Manajemen Tournament Esport ===" << endl;
    cout << "Memuat data sample..." << endl;
    loadSampleData(L);
    cout << "Data sample berhasil dimuat!" << endl;

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
                searchTournament(L);
                break;
            case 4:
                queryTournament(L);
                break;
            case 5:
                showStatistics(L);
                break;
            case 0:
                cout << "\nMenghapus semua Tournament!" << endl;
                deleteAllTournaments(L);
                running = false;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }
    }
    return 0;
}
