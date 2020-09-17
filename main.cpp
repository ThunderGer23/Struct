#include <iostream>
#include <vector>
using namespace std;

struct Plumon{
    string color;
};

class Persona{
private:
    string nombre;
    string apellidos;
    float altura;
public:
    //Constructor
    Persona(string, string, float);
    string getnombre();
    //Metodos y/o acciones
    void Dibujar();

};

Persona::Persona(string _nombre, string _apellidos, float _altura) {
    nombre = _nombre;
    apellidos = _apellidos;
    altura = _altura;
}

void Persona::Dibujar() {
    int opc;
    char B;//de break;
    int NumColor;

    cout<<"¿Cuantos colores vas a utilizar?"<<endl;
    cin>>NumColor;

    struct Plumon P[NumColor];
    for (int i = 0; i < NumColor; ++i) {
        cout<<"Ingrese el color "<<i+1<<endl;
        cin>>P[i].color;
    }

    do {
        cout<<"Seleccione un color de su tira de colores"<<endl;
        for (int i = 0; i < NumColor; ++i) {
            cout<<i+1<<". "<<P[i].color<<endl;
        }
        cin>>opc;

        for (int i = 0; i < NumColor; ++i) {
            if (i == opc-1){
                cout<<"Coloreando con el plumon "<<P[i].color<<endl;
            }
        }

        cout<<"¿Desea seguir dibujando? s/n"<<endl;
        cin>>B;
    }while (B != 'n');

}

string Persona::getnombre() {
    return nombre;
}

vector <Persona> P1;
void Menu();
void RegPersona();
void Dibuja();

int main() {
    Menu();
    return 0;
}

void Menu(){
    char opc;

    do {
        cout<<"Ingresa una opcción"<<endl<<"1.Registrar persona para colorear"<<endl;
        cout<<"2.Colorear"<<endl<<"E.Salir"<<endl;
        cin>>opc;

        switch (opc) {
            case '1':
                RegPersona();
                break;
            case '2':
                Dibuja();
                break;
            case 'E':
                cout<<"Chao chao"<<endl;
                break;
            default:
                cout<<"Valor no permitido en el sistema"<<endl;
                break;
        }

    }while(opc != 'E');
}

void RegPersona(){
    string nombre;
    string apellidos;
    float altura;

    cout<<"Ingrese su nombre"<<endl;
    cin>>nombre;
    cout<<"Ingrese su apellido"<<endl;
    cin>>apellidos;
    cout<<"Ingrese su altura"<<endl;
    cin>>altura;
    Persona p1(nombre,apellidos,altura);
    P1.push_back(p1);
}

void Dibuja(){
    string Nombre;
    int cont = 0;
    cout<<"Ingresa el nombre de la persona que va dibujar"<<endl;
    cin>>Nombre;

    for (int i = 0; i < P1.size(); i++){
        if (P1.at(i).getnombre() == Nombre){
            cont++;
            P1.at(i).Dibujar();
            break;
        } else if (i == P1.size()-1 && cont == 0){
            cout<<"No existe ese nombre en los registros"<<endl;
        }
    }
}