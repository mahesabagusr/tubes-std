#include <iostream>
#include "src/tournament.h"
#include "src/menu.h"
#include "src/data_loader.h"
using namespace std;

int main() 
{
    ListTournament L;
    createListTournament(L);

    cout<<"Import data dulsss..."<<endl;
    loadSampleData(L);
    cout<<"Data berhasil di import cuyyy..!"<<endl;

    cout<<"=== Sistem Manajemen Tournament Esport ==="<<endl;


    startMenu(L);
    return 0;
} 
