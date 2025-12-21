#include <iostream>
#include "src/tournament.h"
#include "src/menu.h"
#include "src/data_loader.h"
using namespace std;

int main() 
{
    ListTournament L;
    createListTournament(L);

    cout<<"=== Sistem Manajemen Tournament Esport ==="<<endl;
    cout<<"Memuat data sample..."<<endl;
    loadSampleData(L);
    cout<<"Data sample berhasil dimuat!"<<endl;

    startMenu(L);
    return 0;
}
