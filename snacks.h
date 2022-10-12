#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace SnackMachine {

	
	class Snack {
	private:
		string nameSnack; //имя снэка
		short calories = 0;
		short price = 0;
	public:
		Snack(string nameSnack, short calories, short price); //конструктор снека имя+каллории+цена
		Snack(string nameSnack, short calories);
		Snack(string nameSnack);
		Snack();
		friend ostream& operator<<(ostream& output, const Snack& nameSnack); //вывод в консоль имя снека
		string getNameSnack();
	};

		class SnackSlot { // слот для напитков или снеков, в котрый помещается до snackCount штук товара
	private:
		Snack* x; // тип снека внутри
		short snackCountBuzy =0; //колличество занятых мест в слоте для снеков
		short snackCount; // Общее коллисество помещающихся снеков в слоте
	public:
		SnackSlot(short snackCount); //создать слот на snackCount колличество мест
		SnackSlot();
		SnackSlot(const SnackSlot & other); //конструктор копирования
		SnackSlot& operator ++(); // добавить в слот еще один снек данного типа
		SnackSlot& operator --(); // убрать из слота один снек
		bool isemptySlot();
		bool operator < (const SnackSlot& other); //сравнение слотов по количеству товаров в них
		bool operator > (const SnackSlot& other);
		void operator = (const SnackSlot& other); //присвоение параметров одного слота другому
		void addSnack(Snack* x, short count); // добавить в слот снэк, количество добавляемых снеков
		void extraditeSnack(); //выдать один снек со слота
		string getNameSnackInSlot();
		friend ostream& operator<<(ostream& output, const SnackSlot& Slot); // вывод информации о снеке
	};

	class VendingMachine {
	private:
		string nameMachine;
		short slotsCountTotal;
		SnackSlot *Slot[50];
		short slotsCountBuzy = 0;
	public:
		VendingMachine();
		VendingMachine(short slotsCountTotal);
		VendingMachine(string nameMachine, short slotsCountTotal);
		void addSlot(SnackSlot* Slot);
		friend ostream &operator<<(ostream &output, const VendingMachine &machine); // вывод информации о машине
		short getEmptySlotsCount();
	};
}
