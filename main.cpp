/*************************************************
* ADS Praktikum 1.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
        << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
        << "====================================" << endl
        << "1) Backup anlegen" << endl
        << "2) Backup suchen" << endl
        << "3) Alle Backups ausgeben" << endl
        << "4) Programm beenden" << endl
        << "?> ";
}

int main()
{
	int result = Catch::Session().run();
    int selection = 0;
    Ring* ring = new Ring();
    string description;
    string data;
    while(selection != 4)
    {
        print_menu();
        cin >> selection;
        switch (selection)
        {
        case 1:
            cout << "+Neuen Datensatz anlegen" << endl;
            cout << "Beschreibung <? ";
            cin >> description;
            cout << endl << "Daten <?";
            cin >> data;
            ring->addNewNode(description, data);
            cout << "+Ihr Datensatz wurde hinzugefügt" << endl;
            break;
        case 2:
            cout << "+Nach welchen Daten soll gesucht werden?" << endl;
            cout << "?>";
            cin >> data;
            if(ring->search(data)) ring->printNode(data);
            else cout << "+Datensatz nicht gefunden" << endl;
            break;
        case 3:
            cout << "Alle Backups ausgeben" << endl;
            ring->print();
            break;
        case 4:
            cout << "Programm beenden" << endl;
            break;
        }
    }
    

	system("Pause");
	return result;
}