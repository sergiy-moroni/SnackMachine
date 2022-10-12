#include <iostream>
#include <string>
#include "snacks.h"
using namespace std;

namespace SnackMachine {
	Snack::Snack(string nameSnack) {
		this->nameSnack = nameSnack;
	}

	Snack::Snack(string nameSnack, short calories, short price){
		if (calories > 0) {
			
			this->nameSnack = nameSnack;
			this->calories = calories;
		}
		else {
			this->nameSnack = nameSnack;
			this->calories = 0;
		}
		if (price > 0){ this->price = price; }
		else{
			this->price = 0; 
		}
	}

	Snack::Snack(string nameSnack, short calories) {
		if (calories > 0) {
			this->nameSnack = nameSnack;
			this->calories = calories;
		}
		else {
			this->nameSnack = nameSnack;
			this->calories = 0;
		}
	}
	string Snack::getNameSnack(){

		return nameSnack;
	}

	ostream& operator<<(ostream& output, const Snack& nameSnack) {
		output << "Имя снека: " << nameSnack.nameSnack << endl
			<< "Калорийность снека: " << nameSnack.calories << "ккал" << endl
			<< "Цена снека: " << nameSnack.price << " руб." << endl;
		return output;
	}

		SnackSlot::SnackSlot(short snackCount)
	{
		if (snackCount > 0 && snackCount < 20) {
			this->snackCount = snackCount;
		}
		else { cout << "Incorrect count" << endl; }
	}
		
	SnackSlot::SnackSlot(const SnackSlot& other) {
		this->x = other.x;
		this->snackCountBuzy = other.snackCountBuzy;
		this->snackCount = other.snackCount;
	}

	SnackSlot& SnackSlot::operator ++() {
		++snackCountBuzy;
		return *this;
			}

	SnackSlot& SnackSlot::operator --() {
		--snackCountBuzy;
		return *this;
			}

	bool SnackSlot::operator > (const SnackSlot& other) {
		return this->snackCountBuzy > other.snackCountBuzy;
	}

	void SnackSlot::operator = (const SnackSlot& other) {
		this->x = other.x;
		this->snackCountBuzy = other.snackCountBuzy;
		this->snackCount = other.snackCount;
	}

	bool SnackSlot::operator < (const SnackSlot& other) {
		return this->snackCountBuzy < other.snackCountBuzy;
	}

	void SnackSlot::addSnack(Snack* x, short count) {
				this->x = x;
				this->snackCountBuzy = this->snackCountBuzy+count;
			}

	bool SnackSlot::isemptySlot() {
		if (snackCount == 0) {
			return true;
		}
		else { return false; }
	}


		void SnackSlot::extraditeSnack() { // если снеки есть, то уменьшить занятые слоты на 1
		if (snackCountBuzy == 0) {  // если слот пуст, выдать сообщение
			cout << "Слот для снеков пуст";
		}
		if (snackCountBuzy > 0) {
			--snackCountBuzy;
		}
	}

	ostream& operator<<(ostream& output, const SnackSlot& Slot) {
		output  << "Количество товара внутри слота: " << Slot.snackCountBuzy << endl;
		return output;
	}

	VendingMachine::VendingMachine(short slotsCountTotal) {
		if (slotsCountTotal > 0 && slotsCountTotal <= 50) {
			this->slotsCountTotal = slotsCountTotal;
		}
	}

	VendingMachine::VendingMachine(string nameMachine, short slotsCountTotal){
		if (slotsCountTotal > 0 && slotsCountTotal <= 50) {
			this->slotsCountTotal = slotsCountTotal;
			this->nameMachine = nameMachine;
		}
	}

	void VendingMachine::addSlot(SnackSlot* other) {
		for (int i = 0; i < slotsCountTotal; ++i){
			SnackSlot *s = other;
			Slot[i] = s;
			slotsCountBuzy++;
			break;
		}
	}

		short VendingMachine::getEmptySlotsCount() {
			return slotsCountBuzy;
	}

	ostream &operator<<(ostream &output, const VendingMachine &machine) {
		output << "Имя машины для снеков: " << machine.nameMachine << endl
			<< "Количество слотов внутри машины: " << machine.slotsCountTotal << endl;
		return output;
	}
}
