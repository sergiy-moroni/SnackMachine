#include <iostream>
#include "snacks.h"

using namespace std;
using namespace SnackMachine;

int main() {
	setlocale(LC_ALL, "");
	Snack* bounty = new Snack("Bounty", 400, 100);
	Snack* snikers = new Snack("Snikers");
	SnackSlot* slot1 = new SnackSlot(10);
	SnackSlot* slot2 = new SnackSlot(10);
	slot2->addSnack(bounty, 6);
	slot1->addSnack(snikers, 5);
	VendingMachine *machine = new VendingMachine("Ларек", 10);
	machine->addSlot(slot1);
	machine->addSlot(slot2);
	SnackSlot* slotwater1 = new SnackSlot(10);

	cout << *machine << endl;
	cout << *slot1 << endl;
	cout << *slot2 << endl;
	cout << *bounty;
	

	slot1->extraditeSnack();
	slot1->extraditeSnack();

	cout << *machine << endl;
	cout << *slot1 << endl;
	cout << *slot2 << endl;
	cout << *bounty;
	cout << machine->getEmptySlotsCount();
	
	delete bounty;
	delete snikers;
	delete machine;
	delete slot1;
	delete slot2;
	delete slotwater1;
	return 0;
}
