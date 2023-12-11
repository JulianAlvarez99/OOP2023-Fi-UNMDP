#ifndef EMPLEADO_H
#define EMPLEADO_H


class empleado : public persona
{
    public:
        empleado();
        virtual ~empleado();

        enum TipoEmpleado_{Ejecutivo, Oficinista, Obrero};
        enum TipoContrato_{Temporal, Permante};

    protected:

    private:

};

#endif // EMPLEADO_H
