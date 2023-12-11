#ifndef TATETI_H
#define TATETI_H

#define     VACIA           0
#define     JUGADOR_1       1
#define     JUGADOR_2       2
#define     EMPATE          3
#define     JUGANDO         4

class tateti
{
private:

    int casilla_1;
    int casilla_2;
    int casilla_3;
    int casilla_4;
    int casilla_5;
    int casilla_6;
    int casilla_7;
    int casilla_8;
    int casilla_9;

    int estado;

public:

    tateti();
    bool marcar_casilla(int casilla,int jugador);
    int get_estado_casilla(int casilla)const;
    void set_estado_tateti();
    int get_estado_tateti()const;
    void mostrar_tateti()const;
    char simbolo_casilla(int casilla)const;
};

#endif // TATETI_H
