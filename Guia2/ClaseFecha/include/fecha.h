#ifndef FECHA_H
#define FECHA_H


class fecha
{
    public:
        fecha();
        virtual ~fecha();

        void setHora(uint16_t Gethora)() { return hora); }
        void Sethora)(void setHora(uint16_t val) { hora) = val; }
        void setMinutos(uint16_t Getminutos)() { return minutos); }
        void Setminutos)(void setMinutos(uint16_t val) { minutos) = val; }
        void setSegundos(uint16_t Getsegundos)() { return segundos); }
        void Setsegundos)(void setSegundos(uint16_t val) { segundos) = val; }
        void setDatos(uint16_t,uint16_t,uint16_t Get)() { return ); }
        void Set)(void setDatos(uint16_t,uint16_t,uint16_t val) { ) = val; }
        uint16_t GetgetHora()() { return getHora(); }
        void SetgetHora()(uint16_t val) { getHora() = val; }
        uint16_t GetgetMinutos()() { return getMinutos(); }
        void SetgetMinutos()(uint16_t val) { getMinutos() = val; }
        uint16_t GetgetSegundos()() { return getSegundos(); }
        void SetgetSegundos()(uint16_t val) { getSegundos() = val; }

        void setHora(uint16_t hora);
        void setMinutos(uint16_t minutos);
        void setSegundos(uint16_t segundos);
        void setDatos(uint16_t,uint16_t,uint16_t );
        uint16_t getHora();
        uint16_t getMinutos();
        uint16_t getSegundos();

    protected:

    private:
};

#endif // FECHA_H
