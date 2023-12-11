#include "ManejadorFiguras.h"

ManejadorFiguras::ManejadorFiguras()
{
    //ctor
}

ManejadorFiguras::~ManejadorFiguras()
{
    //dtor
}

void ManejadorFiguras::CargarFiguras()
{
    CRectangulo *MyRec = new CRectangulo();
    float base = 1.2, altura = 2.5;
    int color = 0x0A0BFE42;
    MyRec->SetBase(base);
    MyRec->SetAltura(altura);
    MyRec->vSetForeColor(color);
    color = 0x0BFE0A42;
    MyRec->vSetBackColor(color);
    Figuras.push_back(MyRec);

    CCirculo *MyCir = new CCirculo();
    float radio = 1.0;
    color = 0xFFFF0010;
    MyCir->SetBase(radio);
    MyCir->vSetForeColor(color);
    color = 0xFF00FF10;
    MyCir->vSetBackColor(color);
    Figuras.push_back(MyCir);

    MyRec = new CRectangulo();
    base = 0.7;
    altura = 0.3;
    color = 0x03FAAF00;
    MyRec->SetBase(base);
    MyRec->SetAltura(altura);
    MyRec->vSetForeColor(color);
    color = 0xFA03AF00;
    MyRec->vSetBackColor(color);
    Figuras.push_back(MyRec);

    CTriangulo *MyTri = new CTriangulo();
    base = 5;
    altura = 7;
    color = 0xFF06ED03;
    MyTri->SetBase(base);
    MyTri->SetAltura(altura);
    MyTri->vSetForeColor(color);
    color = 0xEA615507;
    MyTri->vSetBackColor(color);
    Figuras.push_back(MyTri);

}
void ManejadorFiguras::ImprimirFiguras(ostream& os)
{
    vector<CFigura*>::iterator ForIter;
    ForIter = Figuras.begin();                        // puntero al primer elemento
    os << endl;
    while (ForIter != Figuras.end() )                 // mientras no sea el ultimo elemento
    {
        os << *ForIter++;              // aumento el iterador
    }
    os << "\n\n";
}

double ManejadorFiguras::TotalArea()
{
    double result = 0.0;

    for(unsigned int i = 0; i<Figuras.size(); i++)
    {
        result += Figuras[i]->dCalcArea();
    }
    return result;
}

void ManejadorFiguras::AgregarFigura(CFigura* fig)
{
    Figuras.push_back(fig);

}
CFigura* ManejadorFiguras::Get(uint8_t index)
{
    return(this->Figuras.at(index));
}

bool cmp(CFigura* f1,CFigura* f2) /// COMPARA BUSCANDO EL VALOR DE AREA MINIMO
{
    return(f1->dCalcArea()<f2->dCalcArea());
}

void ManejadorFiguras::Ordenar()
{
    sort(Figuras.begin(),Figuras.end(),cmp);
}

void ManejadorFiguras::GuardarFiguras_txt(const char* file_name)
{
    ofstream out;
    out.exceptions ( ofstream::badbit );
    try
    {
        out.open(file_name);

        vector<CFigura*>::iterator ForIter;
        ForIter = Figuras.begin();                        // puntero al primer elemento

        while (ForIter != Figuras.end() )                 // mientras no sea el ultimo elemento
        {
            (**ForIter).file_write_txt(out);              // aumento el iterador
            *ForIter++;
        }
    }
    catch(const ofstream::failure& e)
    {
        cout << "Excepcion al abrir/escribir el archivo\n";
    }
    out.close();
}

void ManejadorFiguras::RecuperarFiguras_txt(const char* file_name)
{
    ifstream in;
    in.exceptions ( ifstream::badbit );
    try
    {
        in.open(file_name);
        string tipo_figura;
        uint32_t fore_color;
        uint32_t back_color;
        double base;
        double altura;
        string line = "";
        while(getline(in,line))
        {
            stringstream str_in(line);
            string str_temp;

            getline(str_in,str_temp,';');
            tipo_figura = str_temp;

            getline(str_in,str_temp,';');
            fore_color = stoul(str_temp);

            getline(str_in,str_temp,';');
            back_color = stoul(str_temp);

            getline(str_in,str_temp,';');
            base = stod(str_temp);

            if (tipo_figura == "Rectangulo")
            {
                getline(str_in,str_temp,';');
                altura = stod(str_temp);
                CRectangulo* aux = new CRectangulo(tipo_figura,fore_color,back_color,base,altura);
                Figuras.push_back(aux);
            }
            if (tipo_figura == "Circulo")
            {
                CCirculo* aux = new CCirculo(tipo_figura,fore_color,back_color,base);
                Figuras.push_back(aux);
            }
            if (tipo_figura == "Triangulo")
            {
                getline(str_in,str_temp,';');
                altura = stod(str_temp);
                CTriangulo* aux = new CTriangulo(tipo_figura,fore_color,back_color,base,altura);
                Figuras.push_back(aux);
            }
        }
    }
    catch(const ifstream::failure& e)
    {
        cout << "Excepcion al abrir/leer el archivo\n";
    }
    in.close();
}

/* ------------------------------------- BIN ------------------------------------- */
long long unsigned int fileSize(const char* fname)
{
   ifstream file(fname,ios::binary);
   file.seekg(0, ios::end);
   long long unsigned int size = file.tellg();
   file.close();
   return size;
}

void ManejadorFiguras::GuardarFiguras_bin(const char* file_name)
{
    int tam=this->Figuras.size();
    for(int i=0;i<tam;i++)
    {
        this->Get(i)->file_write_bin(file_name);
    }
}

void ManejadorFiguras::RecuperarFiguras_bin(const char* file_name)
{
    std::fstream in;
    in.exceptions ( fstream::badbit );
    try
    {
        in.open(file_name, ios::in|ios::binary);
        unsigned int file_size = fileSize(file_name);
        int tipo_figura;
        CColor fore_color;
        CColor back_color;
        float base;
        float altura;
        while(in.tellg()<file_size)
        {
            in.read((char*)&(tipo_figura),sizeof(tipo_figura));
            in.read((char*)&(fore_color),sizeof(fore_color));
            in.read((char*)&(back_color),sizeof(back_color));
            in.read((char*)&(base),sizeof(float));
            in.read((char*)&(altura),sizeof(float));

            if (tipo_figura == 1)
            {
                CCirculo* aux = new CCirculo("Circulo",fore_color.GetColor(),back_color.GetColor(),base);
                Figuras.push_back(aux);
            }
            if (tipo_figura == 2)
            {
                CTriangulo* aux = new CTriangulo("Triangulo",fore_color.GetColor(),back_color.GetColor(),base,altura);
                Figuras.push_back(aux);
            }
            if (tipo_figura == 3)
            {
                CRectangulo* aux = new CRectangulo("Rectangulo",fore_color.GetColor(),back_color.GetColor(),base,altura);
                Figuras.push_back(aux);
            }
        }
    }
    catch(const ifstream::failure& e)
    {
        cout << "Excepcion al abrir/leer el archivo\n";
    }
    in.close();
}

