#include <iostream>

#include "Heap.h"
#include "Array.h"
#include "DoublyLinkedList.h"
#include "BST.h"


void displayMenu(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void menu_array(){
    auto array = new Array();
    char opt;
    string fileName;
    int index, value;
    do{
        displayMenu("--- Tablica ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                array->readFromFile(fileName);
                std::cout << array->toString() << std::endl;
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                array->remove(index);
                std::cout << array->toString() << std::endl;
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                array->insert(index, value);
                std::cout << array->toString() << std::endl;
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (array->contains(value))
                    cout << "podana wartosc jest w tablicy";
                else
                    cout << "poadanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                array->makeRandom(value);
                std::cout << array->toString() << std::endl;
                break;

            case '6':  //tutaj wyświetlanie tablicy
                std::cout << array->toString() << std::endl;
                break;
        }
    } while (opt != '0');
}

void menu_heap(){
    auto heap = new Heap(1000);
    char opt;
    string fileName;
    int index, value;
    do{
        displayMenu("--- Kopiec ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                heap->readFromFile(fileName);
                std::cout << heap->toString() << std::endl;
                heap->print();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                heap->remove(index);
                std::cout << heap->toString() << std::endl;
                heap->print();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj wartosc:";
                cin >> value;
                heap->push(value);
                std::cout << heap->toString() << std::endl;
                heap->print();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (heap->contains(value))
                    cout << "podana wartosc jest w tablicy";
                else
                    cout << "poadanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                heap->makeRandom(value);
                std::cout << heap->toString() << std::endl;
                heap->print();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                std::cout << heap->toString() << std::endl;
                heap->print();
                break;
        }
    } while (opt != '0');
}

void menu_BST(){
    auto tree = new BST();
    char opt;
    string fileName;
    int index, value;
    do{
        displayMenu("--- Kopiec ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                tree->readFromFile(fileName);
                std::cout << tree->toString() << std::endl;
                tree->print();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj wartosc:";
                cin >> value;
                tree->remove(value);
                std::cout << tree->toString() << std::endl;
                tree->print();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj wartosc:";
                cin >> value;
                tree->push(value);
                std::cout << tree->toString() << std::endl;
                tree->print();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (tree->contains(value))
                    cout << "podana wartosc jest w tablicy";
                else
                    cout << "poadanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                tree->makeRandom(value, -100, 100);
                std::cout << tree->toString() << std::endl;
                tree->print();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                std::cout << tree->toString() << std::endl;
                tree->print();
                break;
        }
    } while (opt != '0');
}

void menu_list()
{
    DoublyLinkedList* list = new DoublyLinkedList();
    char opt;
    string fileName;
    int index, value;
    do{
        displayMenu("--- Lista ---");
        opt = getche();
        cout << endl;
        switch (opt){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe zbioru:";
                cin >> fileName;
                list->readFromFile(fileName);
                std::cout << list->toString() << std::endl;
                std::cout << list->toStringInv() << std::endl;
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                list->remove(index);
                std::cout << list->toString() << std::endl;
                std::cout << list->toStringInv() << std::endl;
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartosc:";
                cin >> value;

                list->insert(value, index);
                std::cout << list->toString() << std::endl;
                std::cout << list->toStringInv() << std::endl;
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (list->contains(value))
                    cout << "podana wartosc jest w tablicy";
                else
                    cout << "poadanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                list->makeRandom(value);
                std::cout << list->toString() << std::endl;
                std::cout << list->toStringInv() << std::endl;
                break;

            case '6':  //tutaj wyświetlanie tablicy
                std::cout << list->toString() << std::endl;
                std::cout << list->toStringInv() << std::endl;
                break;
        }
    } while (opt != '0');
}

void run_menu(){
    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "4.BST" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        option = getche();
        cout << endl;

        switch (option){
            case '1':
                menu_array();
                break;
            case '2':
                menu_list();
                break;
            case '3':
                menu_heap();
                break;
            case '4':
                menu_BST();
                break;
        }
    } while (option != '0');
}

int main(int argc, char* argv[])
{
    auto arr = new Array();
    arr->readFromFile("tab1.txt");
    run_menu();
    return 0;
}
