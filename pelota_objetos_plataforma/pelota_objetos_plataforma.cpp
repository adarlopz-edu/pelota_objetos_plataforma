//PROGRMA PELOTITA CON PLATAFORMA 22100190

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

class Plataformita;

class Pelota {
private: //atributos
    string caracterPelota;
    int xPelota;
    int yPelota;

public:
    Pelota(string, int, int); //constructor
    void moverPelota();
    void bordes();
    void rebotar();
    int compartirX();
    int compartirY();
};


Pelota::Pelota(string _caracterPelota, int _xPelota, int _yPelota) {
    caracterPelota = _caracterPelota;
    xPelota = _xPelota;
    yPelota = _yPelota;
}

int j = 1, k = 1, l = 1;

void Pelota::moverPelota() { //mueve la pelota de 1 en 1 x y y al mismo tiempo
    system("cls");
    gotoxy(xPelota, yPelota);
    cout << caracterPelota;
    xPelota = xPelota + k;
    yPelota = yPelota + l;
    Sleep(50);
}

int Pelota::compartirX() { return xPelota; } // para pasar al main las coordenadas x de la pelota

int Pelota::compartirY() { return yPelota; } // para pasar al main las coordenadas y de la pelota

void Pelota::rebotar() { //inversa las direcciones de la pelota en x(k) y en y(l)
    k = -k;
    l = -l;
}

void Pelota::bordes() { //rebota la pelota cuando toca los limites en x (80) y en y(25)
    if (xPelota == 80 || xPelota == 1) { k = -k; }
    if (yPelota == 1 || yPelota == 25) { l = -l; }
}

class Plataformita {
private:
    string caracterPlataformita;
    int xPlataformita;

public:
    Plataformita(string, int);
    int moverPlataformita();
};

Plataformita::Plataformita(string _caracterPlataformita, int _xPlataformita) {
    caracterPlataformita = _caracterPlataformita;
    xPlataformita = _xPlataformita;
}

int Plataformita::moverPlataformita() { //mueve la plataforma solo en los ejes x

    gotoxy(xPlataformita, 22);
    cout << caracterPlataformita;
    Sleep(50);


    if (_kbhit()) {
        char _input = _getch();

        if (_input == 'a') {

            if (xPlataformita == 2) {
                //system("cls");
                gotoxy(xPlataformita, 22);
                cout << caracterPlataformita;
                xPlataformita = xPlataformita + j;
                //Sleep(50);
            }

            //system("cls");
            gotoxy(xPlataformita, 22);
            cout << caracterPlataformita;
            xPlataformita = xPlataformita - j;
            //Sleep(50);

        }

        if (_input == 'd') {

            if (xPlataformita == 80) {
                system("cls");
                gotoxy(xPlataformita, 22);
                cout << caracterPlataformita;
                xPlataformita = xPlataformita - j;
                //Sleep(50);
            }

            system("cls");
            gotoxy(xPlataformita, 22);
            cout << caracterPlataformita;
            xPlataformita = xPlataformita + j;
            Sleep(50);
        }
    }
    return xPlataformita;
}

int main() {

    Pelota pelota = Pelota("DVD", 1, 1);
    Plataformita plataformita = Plataformita("-----", 40);

    do {
        pelota.moverPelota();
        pelota.bordes();

        int xPl = plataformita.moverPlataformita();
        int yPl = 22;
        int xPe = pelota.compartirX();
        int yPe = pelota.compartirY();

        cout << xPe;

        //Intervalos
        int iX = xPe + 1;
        int ix = xPe - 1;


        if (ix >= xPl && yPl == yPe) { //cuando colisiona la pelota con la plataforma
            pelota.rebotar();
        }

    } while (1 == 1);
}