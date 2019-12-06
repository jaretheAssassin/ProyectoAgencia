#include <iostream>

/*mi programa es una agencia para autos hata el momento he creado 5 clases:
Las primeras 5 clases estan correlacionadas y contien informacion relevande de el auto
La clase padre Motor la cual contiene atributos importantes de un motor
Sus dos hijas MotorElectrico y MotorGasolina
La clase padre Auto  cuyos atributos son marca modelo  color transmision y precio
La clase hija AutoGasolinaRegular hereda los atributos de la clase padre Auto y tiene sus propio atributos: motor,acilindrada,turbo
el atributo motor ala vez es un objeto de la clase MotorGasolina por lo que podemos que hay una relacion de composicion
La clase hija AutoElectrico a su vez tambien tiene lo atributos de la clase padre y ademas tiene motor
el atributo motor ala vez es un objeto de la clase MotorElectrico por lo que podemos que hay una relacion de composicion
Aparte de estas 5 que estan relacionadas tabien hize la clase Agencia y la clase Cliente
La clase agencia servira en el futuro pues sera el conjunto de todos los autos
 de momento solo tiene los atributos nombre,telefono, correo electronico,domicilio y capacidad de alma
 cenamiento
La clase cliente tiene todos los datos de el comprador nombre,edad,telefono, correo electronico,rfc y domicilio

La clase base de datos es un conjunto de agencias y clientes
*/
using namespace std;
class  Motor{
    private:
    string modelo;
    string marca;
    int caballosDeFuerza;
	int torque;
    public:
	Motor();
    Motor(string,string,int,int);

    string getModelo();
    string getMarca();
    int getCaballosDeFuerza();
    int getTorque();

};
class MotorGasolina: public Motor{
    private:
        float acilidradrada;
        bool turbo;
        int cilindros;
    public:
        MotorGasolina ();
        MotorGasolina (string,string,int,int,float,bool,int);
        int getCilindros();
        bool getTurbo();
        float getAcilindrada();

};
class MotorElectrico: public Motor{
    private:
         float tiempoDeAceleracion;

    public:
        MotorElectrico ();
        MotorElectrico(string,string,int,int,float);
        float getTiempoDeAceleracion();

};
class Auto{
    private:
        string estado;
		string marca;
		string modelo;
		string color;
		string transmision;
		float precio;
		string tipoDeCombustible;
		float rendimiento;
		float capacidadAl;
		string direccion;
        int puertas;
        string traccion;
    public:
		Auto ();
		Auto(string mar , string mod,string col , string tran, string est ,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac);
		string getEstado();
		string getMarca();
		string getColor();
		string getModelo();
		string getTransmision();
		float getPrecio();
		float getRendimiento();
		float getCapacidadAl();
		string getTipoDeCombustible();
		string getDireccion();
		int getPuertas();
		string getTraccion();

		void setPrecio(float nuevoPrecio);
		void setEstado(string nuevoEstado);
		//virtual void imprimeAtributos();



};
class AutoGasolinaRegular : public Auto {
    private:

		MotorGasolina motor;
    public:
		AutoGasolinaRegular();
        AutoGasolinaRegular(string ,string ,int ,int , float ,  bool  ,int ,string ,string  , string ,string  , string ,	float ,string , float , float,string,int,string  );

		MotorGasolina getMotorGasolina();
		void imprimeAtributos();

};
class AutoElectrico : public Auto {
    private:
        int autonomia;
        float tiempoDeRecarga;
        MotorElectrico motor;
    public:
		AutoElectrico();
        AutoElectrico(string ,string ,int ,int,float ,string ,string  , string ,string  , string ,	float ,string , float , float,string,int,string,int,float );

        int getAutonomia();
        float getTiempoDeRecarga();
        MotorElectrico getMotorElectrico();

        void imprimeAtributos();

};
class Cliente{
	private:
	string nombre;
	int edad;
	long long int telefono;
	string correoElectronico;
	string rfc;
	string domicilio;
	public:
	Cliente ();
    Cliente(string nom,int ed, long long int tel, string cE, string r, string dom);

    void setEdad(int nuevaEdad);
	void setTelefono(long long int nuevoTelefono);
	void setCorreoElectronico(string nuevoCorreoElectronico);
	void setRfc(string nuevoRfc);
	void setDomicilio(string nuevoDomicilio);
	void imprimeDatos();

	string getNombre();
	int  getEdad();
	long long int getTelefono();
	string getCorreoElectronico();
	string getRfc();
	string getDomicilio();

};

class Agencia {
	private:
	string nombre;
	long long int telefono;
	string correoElectronico;
	string domicilio;
	int autosActuales;
	int capacidadAl;
	Auto autos[100];

	public:
	Agencia ();
    Agencia(string nom, long long int tel, string cE, string dom,int cap,int au);

    void setNombre(string nuevoNombre);
	void setTelefono(long long int nuevoTelefono);
	void setCorreoElectronico(string nuevoCorreoElectronico);
	void setDomicilio(string nuevoDomicilio);
	void setCapacidadAl(int nuevaCapacidadAl);
	void imprimeDatos();
	void agregaAuto(Auto a);
	void busca(float precioI,float precioF);
	void busca(string marca);

	string getNombre();
	long long int getTelefono();
	string getCorreoElectronico();
	string getDomicilio();
	int getCapacidadAl();
	int getAutosActuales();



};
class BaseDeDatos{
private:
    Agencia agencias[50];
    Cliente clientes[50];
    int agenciasActuales;
    int agenciasMaximas;
    int clientesActuales;
    int clientesMaximos;

public:
    BaseDeDatos();
    BaseDeDatos (int,int,int,int);
    void agregaAgencia(Agencia a);
    void agregaCliente(Cliente c);
    void agregaAuto(int i,AutoGasolinaRegular a);
    void agregaAuto(int i,AutoElectrico a);
    void imprimeDatos();
    void muestraNombresAgencias();
    int getAgenciasActuales();
    int getClientesActuales();
    void buscaAutoMar(int,string);
    void buscaAutoP(int,int,int);



};
Motor :: Motor (){
	modelo = "";
	marca = "";
	caballosDeFuerza = 0;
	torque = 0;
}
Motor :: Motor( string mod ,string mar ,int cDF,int tor){
    modelo = mod;
    marca = mar;
    caballosDeFuerza = cDF;
    torque = tor;
}
string Motor :: getModelo(){
    return modelo;
}
string Motor :: getMarca(){
    return marca;
}
int Motor :: getCaballosDeFuerza(){
    return caballosDeFuerza;
}

int Motor :: getTorque(){
	return torque;
}

MotorGasolina :: MotorGasolina (){
acilidradrada = 0.0;
turbo = false;
cilindros  = 0;

}

MotorGasolina :: MotorGasolina (string mod ,string mar ,int cDF,int tor, float ac,  bool tur ,int cil): Motor(mod ,mar , cDF, tor){
     acilidradrada = ac;
     turbo = tur;
     cilindros = cil;
}
bool MotorGasolina :: getTurbo(){
	return turbo;
}
float MotorGasolina :: getAcilindrada(){
	return acilidradrada;
}
int MotorGasolina :: getCilindros(){
    return cilindros;
}
MotorElectrico :: MotorElectrico (){
    tiempoDeAceleracion = 0.0;
}
MotorElectrico :: MotorElectrico(string mod ,string mar ,int cDF,int tor,float tDA): Motor (mod,mar,cDF,tor){

    tiempoDeAceleracion = tDA;

}
float MotorElectrico :: getTiempoDeAceleracion(){
    return tiempoDeAceleracion;
}
Auto :: Auto(){
    estado = "";
	marca = "";
	modelo = "";
	color = "";
	transmision = "";
	precio = 0 ;
}
Auto:: Auto( string mar , string mod,string col , string tran,string est,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac){

    estado = est;
    marca = mar;
    modelo = mod;
    color = col;
    transmision = tran;
    precio = pr;
    direccion = dir;
    puertas = pue;
    traccion = trac;
    tipoDeCombustible =tdc;
    rendimiento = ren;
    capacidadAl= cap;
    direccion = dir;
    puertas = pue;

}
string Auto :: getEstado(){
     return estado;
}
string Auto :: getMarca(){
    return marca;
}
string Auto :: getModelo(){
    return modelo;
}
string Auto :: getColor(){
    return color;
}

string Auto :: getTransmision(){
    return transmision;
}
float Auto :: getRendimiento(){
    return rendimiento;
}
float Auto :: getCapacidadAl(){
    return capacidadAl;
}
string Auto :: getTipoDeCombustible(){
    return tipoDeCombustible;
 }

float Auto :: getPrecio(){
    return precio;
}
string Auto :: getDireccion(){
    return direccion;
}
int Auto :: getPuertas(){
    return puertas;
}
string Auto :: getTraccion(){
    return traccion;
}
void Auto :: setPrecio(float nuevoPrecio){
    precio = nuevoPrecio;
}
void Auto :: setEstado (string nuevoEstado)
{
    estado = nuevoEstado;
}

/*void Auto :: imprimeAtributos(){
    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Modelo: " <<getMotor().getModelo()<<endl;
    cout <<"Marca: " <<getMotor().getMarca()<<endl;
    cout <<"Caballos de fuerza: " << getMotor().getCaballosDeFuerza()<<endl;
    cout <<"Cilindros: " <<getMotor().getCilindros()<<endl;
    cout <<"Turbo: " <<getMotor().getTurbo()<<endl;
    cout <<"Torque: " <<getMotor().getTorque()<<endl;
    cout <<"Acilidrada: " <<getMotor().getAcilindrada()<<endl;
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout << getMarca()<<endl;
    cout << getColor()<<endl;
    cout << getModelo()<<endl;
    cout << getTipoDeCombustible()<<endl;
    cout << getTransmision()<<endl;
    cout << getPrecio()<<endl;
    cout << getRendimiento()<<"km/L"<<endl;
    cout << getCapacidadAl()<<"L"<<endl;
    cout << "-----------------------------------"<<endl;

}
*/
AutoGasolinaRegular :: AutoGasolinaRegular(): Auto(),motor(){

}
AutoGasolinaRegular :: AutoGasolinaRegular(string modm, string marm,int cDF,int tor,float ac,bool tur,int cil,string mar , string mod,string col , string tran,string est,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac ) : Auto(mod ,mar,col,tran,est,pr,tdc,ren,cap,dir,pue,trac) ,motor(modm,marm,cDF,tor,ac,tur,cil)
{

}

MotorGasolina AutoGasolinaRegular :: getMotorGasolina(){
    return motor;
}


void AutoGasolinaRegular :: imprimeAtributos(){
    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Modelo: " <<getMotorGasolina().getModelo()<<endl;
    cout <<"Marca: " <<getMotorGasolina().getMarca()<<endl;
    cout <<"Caballos de fuerza: " << getMotorGasolina().getCaballosDeFuerza()<<endl;
    cout <<"Cilindros: " <<getMotorGasolina().getCilindros()<<endl;
    cout <<"Turbo: " <<getMotorGasolina().getTurbo()<<endl;
    cout <<"Torque: " <<getMotorGasolina().getTorque()<<endl;
    cout <<"Acilidrada: " <<getMotorGasolina().getAcilindrada()<<endl;
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Marca:" <<getMarca()<<endl;
    cout << "Color:"<<getColor()<<endl;
    cout << "Modelo:"<<getModelo()<<endl;
    cout <<"Tipo de Combustible:" <<getTipoDeCombustible()<<endl;
    cout <<"Transmision:" <<getTransmision()<<endl;
    cout << "Precio:"<<getPrecio()<<endl;
    cout << "Rendimeinto:"<<getRendimiento()<<"km/L"<<endl;
    cout <<"Capacidad:" <<getCapacidadAl()<<"L"<<endl;
    cout <<"Direccion: " <<getDireccion()<<endl;
    cout <<"Numero de Puertas:" <<getPuertas()<<endl;
    cout <<"Traccion:" <<getTraccion()<<endl;
    cout << "-----------------------------------"<<endl;
}
AutoElectrico :: AutoElectrico(): Auto (),motor(){
    autonomia = 0;
    tiempoDeRecarga = 0.0;

}
AutoElectrico :: AutoElectrico(string modm, string marm,int cDF,int tor,float tDA,string mar , string mod,string col , string tran,string est,	float pr,string tdc, float ren, float cap,string dir,int pue,string trac,int aut,float tDR) : Auto( mod ,mar,col,tran,est,pr,tdc,ren,cap,dir,pue,trac), motor(modm,marm,cDF,tor,tDA)
{
    autonomia = aut;
    tiempoDeRecarga = tDR;
}

int AutoElectrico :: getAutonomia(){
    return autonomia;
}
float AutoElectrico :: getTiempoDeRecarga(){
    return tiempoDeRecarga;
}
MotorElectrico AutoElectrico :: getMotorElectrico(){
    return motor;
}
void AutoElectrico :: imprimeAtributos(){
    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Modelo: " <<getMotorElectrico().getModelo()<<endl;
    cout <<"Marca: " <<getMotorElectrico().getMarca()<<endl;
    cout <<"Caballos de fuerza: " << getMotorElectrico().getCaballosDeFuerza()<<endl;
    cout <<"Torque: " <<getMotorElectrico().getTorque()<<endl;
    cout <<"Tiempo de aceleracion: " <<getMotorElectrico().getTiempoDeAceleracion()<<"segundos de 0 a 100km/h"<<endl;
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Marca:" <<getMarca()<<endl;
    cout << "Color:"<<getColor()<<endl;
    cout << "Modelo:"<<getModelo()<<endl;
    cout <<"Tipo de Combustible:" <<getTipoDeCombustible()<<endl;
    cout <<"Transmision:" <<getTransmision()<<endl;
    cout << "Precio:"<<getPrecio()<<endl;
    cout << "Rendimeinto:"<<getRendimiento()<<"km/L"<<endl;
    cout <<"Capacidad:" <<getCapacidadAl()<<"kWh"<<endl;
    cout <<"Direccion: " <<getDireccion()<<endl;
    cout <<"Numero de Puertas:" <<getPuertas()<<endl;
    cout <<"Traccion:" <<getTraccion()<<endl;
    cout << "-----------------------------------"<<endl;
}

Cliente :: Cliente(){
	nombre = "";
	edad = 0;
	telefono = 0;
	correoElectronico = "";
	rfc = "";
	domicilio = "";

}

Cliente :: Cliente(string nom,int ed, long long int tel, string cE, string r, string dom){
    nombre = nom;
    edad = ed;
    telefono = tel;
    correoElectronico = cE;
    rfc = r;
    domicilio = dom;
}
string Cliente :: getNombre(){
  return nombre;
}
int Cliente :: getEdad(){
 return edad;
}
long long int Cliente :: getTelefono(){
 return telefono;
}
string Cliente :: getCorreoElectronico(){
 return correoElectronico;
}
string Cliente :: getRfc(){
 return rfc;
}
string Cliente :: getDomicilio(){
return domicilio;
}

void Cliente :: setEdad(int nuevaEdad){
    edad = nuevaEdad;
}
void Cliente :: setTelefono(long long int nuevoTelefono){
    telefono = nuevoTelefono;
}
void Cliente :: setCorreoElectronico(string nuevoCorreoElectronico){
    correoElectronico = nuevoCorreoElectronico;
}
void Cliente :: setRfc(string nuevoRfc){
    rfc = nuevoRfc;
}
void Cliente :: setDomicilio(string nuevoDomicilio){
    domicilio = nuevoDomicilio;
}
void  Cliente :: imprimeDatos(){
    cout << getNombre()<<endl;
    cout << getEdad()<<endl;
    cout << getTelefono()<<endl;
    cout << getCorreoElectronico()<<endl;
    cout << getRfc()<<endl;
    cout << getDomicilio()<<endl;
}

Agencia :: Agencia (){
	nombre = "";
	telefono = 0;
	correoElectronico = "";
	domicilio = "";
	capacidadAl = 0 ;
	autosActuales = 0;
}
Agencia:: Agencia (string nom, long long int tel, string cE, string dom,int cap,int au){
    nombre = nom;
    telefono = tel;
    correoElectronico = cE;
    domicilio = dom;
    capacidadAl = cap;
    autosActuales = au;
}
string Agencia :: getNombre(){
  return nombre;
}
long long int Agencia :: getTelefono(){
 return telefono;
}
string Agencia :: getCorreoElectronico(){
 return correoElectronico;
}

string Agencia :: getDomicilio(){
return domicilio;
}
int Agencia :: getCapacidadAl(){
return capacidadAl;
}
int Agencia :: getAutosActuales(){
return autosActuales;
}

void Agencia :: setNombre( string nuevoNombre){
    nombre = nuevoNombre;
}

void Agencia :: setTelefono(long long int nuevoTelefono){
    telefono = nuevoTelefono;
}
void Agencia :: setCorreoElectronico(string nuevoCorreoElectronico){
    correoElectronico = nuevoCorreoElectronico;
}
void Agencia :: setDomicilio(string nuevoDomicilio){
    domicilio = nuevoDomicilio;
}
void Agencia :: setCapacidadAl(int nuevaCapacidadAl){
    domicilio = nuevaCapacidadAl;
}
void Agencia :: imprimeDatos(){
    cout <<"Nombre de la Agencia:     "<< getNombre()<<endl;
	cout << "Telefono:                 "<<getTelefono()<<endl;
	cout << "Correo Electronico:       "<<getCorreoElectronico()<<endl;
	cout << "Ubicacion de la Agencia:  "<<getDomicilio()<<endl;
	cout <<"Capacidad maxima:         "<<getCapacidadAl()<<" autos"<<endl;
	cout << "Autos en stock:          "<<getAutosActuales()<<endl;
}
void  Agencia :: agregaAuto(Auto a){

    if (capacidadAl > autosActuales){
        autos[autosActuales] = a;
        autosActuales++;
    }

}
void Agencia :: busca(float precioI,float precioF){
   int i,c=0;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i].getPrecio()>= precioI && autos[i].getPrecio() < precioF ) {
           cout << "Modelo " << autos[i].getModelo() << "Nombre: " << autos[i].getMarca()<<endl;
           c++;
       }
   }
   if (c == 0)
      cout << " No hay autos con las cacarteristicas buscadas"<< endl;

}

void Agencia :: busca(string modelo){
   int i,c=0;
   for (i=0;i<autosActuales;i++)
   {
       if (autos[i].getModelo()== modelo ) {
           cout << "Modelo " << autos[i].getModelo() << "Nombre: " << autos[i].getMarca()<<endl;
           c++;
       }
   }
   if (c == 0)
      cout << " No hay autos con las caracteristicas buscadas"<< endl;
}

BaseDeDatos:: BaseDeDatos(){
    agenciasActuales = 0;
    agenciasMaximas = 0;
    clientesActuales = 0;
    clientesMaximos = 0;
}

BaseDeDatos :: BaseDeDatos (int aA,int aM,int cA,int cM){
    agenciasActuales = aA;
    agenciasMaximas = aM;
    clientesActuales = cA;
    clientesMaximos = cM;
}
int BaseDeDatos :: getClientesActuales(){
    return clientesActuales;
}
int BaseDeDatos :: getAgenciasActuales(){
    return agenciasActuales;
}

void  BaseDeDatos :: agregaAgencia(Agencia a){

    if (agenciasActuales < agenciasMaximas){
        agencias[agenciasActuales] = a;
        agenciasActuales++;
    }

}
void  BaseDeDatos :: agregaCliente(Cliente c){

    if (clientesActuales < clientesMaximos){
        clientes[clientesActuales] = c;
        clientesActuales++;
    }

}
void BaseDeDatos :: agregaAuto(int i,AutoGasolinaRegular a){
    agencias[i].agregaAuto(a);
}
void BaseDeDatos :: agregaAuto(int i,AutoElectrico a){
    agencias[i].agregaAuto(a);
}
void  BaseDeDatos:: muestraNombresAgencias(){
    int i;
    for (i=0;i<=(getAgenciasActuales()-1);i++)
    {
        cout <<" " <<i+1<<"  \n"<<agencias[i].getNombre();
    }

}
void  BaseDeDatos :: imprimeDatos(){
    cout<<"clientes actuales:"<<clientesActuales<<endl;
    cout<<"agencias actuales:"<<agenciasActuales<<endl;
}
void BaseDeDatos :: buscaAutoMar(int i,string mar){
    agencias[i].busca(mar);
}
void BaseDeDatos:: buscaAutoP(int i,int pmin,int pmax)
{
    agencias[i].busca(pmin,pmax);
}

void registraCliente(BaseDeDatos& b);
void registraAgencia(BaseDeDatos& b);
void registraAutoG(BaseDeDatos& b,int i);
void registraAutoE(BaseDeDatos& b,int i);
void buscaAuto( BaseDeDatos& b,int,int,string,int,int);

int main(){
    BaseDeDatos base(0,50,0,50);
    Agencia BMW ("BMW",4422135678,"BMW@hotmail.com","Bernardo Quintana #345",28,0);
    base.agregaAgencia(BMW);
    AutoGasolinaRegular sentra("1.8l","Nissan",180,6,true,12,3, "Sentra 2005","Nissan","Blanco","manual","disponible",40000,"gasolina premium",10,43,"hidraulica",4,"llantas delanteras");
    sentra.imprimeAtributos();
    cout << "\n";
    AutoElectrico leaf("1.36","Nissan",110,7,2.1,"Nissan","Leaf 2017","rojo","autumatico","disponible",300000,"electricidad",12,30,"electro-hidraulica",2,"todas las llantas",200,2.3);
    leaf.imprimeAtributos();
    Cliente jorge ("Jorge Alan Ramirez Elias",18,4425762074,"jorge21@hotmail.com","GEC850101415","Paseo de la Reforma # 218");
    jorge.imprimeDatos();//imprimimos datos de el cliente
	cout << "\n";
    BMW.imprimeDatos();
    BMW.agregaAuto(sentra);//aqui agrego un objeto de la clase AutoGasolin regular el objeto clase Agencia BMW
    BMW.agregaAuto(leaf);
    BMW.imprimeDatos();
    //en la clase agencia tenemos u overlod pues existen 2 fuciones que tienen el mismo nobre pero  reciven diferentes parametros
    BMW.busca("Nissan");//aqui usamos la funcion busca y le pasamos solo un parametro de tipo string por lo que  buscara por marca
    BMW.busca(10000,50000);//aqui le pasamos 2 ints por lo que buscara por precio
    cout<<"\n-------------------------------"<<endl;

    bool salir = false;
    int op1,op2,op3,op4;

    cout<<"   Bienvenido al programa esta usted registrado?\n 1.Si\n 2. No\n 3.Salir\n escriba aqui la opcion  ";
    cin >> op1;
    while (op1!=3){
    if (op1 == 1){
        string nombre;
        cout << "escribe tu nombre porfavor  ";
        cin>> nombre;
        if (nombre == "Jorge"){
            cout<<"Bienvenido jorge" <<endl;
           while (op2!=4){
            cout << "que deseasa hacer\nRegistrar\n1.Cliente\n2.Agencia\n3.Auto\n4.Regresar"<<endl;
            cin >> op2;
            switch (op2){

            case 1:
                registraCliente(base);
                break;
            case 2:
                registraAgencia(base);
                break;
            case 3:
                cout<<"En que agencia desea registrar el auto\n----------------------\n";
                base.muestraNombresAgencias();
                cin >>op3;
                registraAutoG(base,(op3-1));
                break;
            }}
        }
        }

    else if(op1 == 2){
        cout << "Registrate aqui\n----------------------\n";
        registraCliente(base);
        cout <<"Bienvenido ";
        while (op4!=2){
        cout<<"\nQue deseas hacer\n 1.Buscar Auto\n 2. Salir"<<endl;
        cin >>op4;
        if (op4 == 1){
            int bus,ag,ag2,pmin,pmax;
            string marc;
            cout << "Por cual atributo quieres buscar\n 1. Marca \n 2. Precio"<<endl;
            cin >> bus;
            switch (bus)
            {
            case 1:
                cout<<"En que agencia desea bucar el auto\n----------------------\n";
                base.muestraNombresAgencias();
                cin >>ag;
                cout << "Cual es la marca  "<<endl;
                cin >> marc;
                buscaAuto(base,1,ag,marc,0,0);
                break;
            case 2:
                cout<<"En que agencia desea bucar el auto\n----------------------\n";
                base.muestraNombresAgencias();
                cin >>ag;
                cout <<"Cual es el precio minimo que buscas"<<endl;
                cin >> pmin;
                cout << "Cual es el precio maximo que bucas"<<endl;
                cin >> pmax;
                buscaAuto(base,2,ag2,"",pmin,pmax);
                break;
            }
        }}
    }
}

return 0;
}
void registraCliente(BaseDeDatos& base)
{
    string nombre;
	int edad;
	long long int telefono;
	string correoElectronico;
	string rfc;
	string domicilio;

    cout <<"Cual es tu nombre  ";
    getline(cin>>ws,nombre);
    cout << "\nCuantos anos tienes  ";
    cin >> edad;
    cout << "\nCual es tu telefono  ";
    cin >> telefono;
    cout << "\nCual es tu correo electronico  ";
    cin >> correoElectronico;
    cout<<"\nCual es tu RFC  ";
    cin >> rfc;
    cout <<"\n Cual es tu domicilio  ";
    cin >>domicilio;
    base.agregaCliente(Cliente(nombre,edad,telefono,correoElectronico,rfc,domicilio));
}

void registraAgencia(BaseDeDatos& base)
{
	string nombre;
	long long int telefono;
	string correoElectronico;
	string domicilio;
	int autosActuales;
	int capacidadAl;

    cout <<"Cual es el nombre de la agencia  ";
    cin >> nombre;
    cout << "\nCual es su telefono  ";
    cin >> telefono;
    cout << "\nCual es su correo electronico  ";
    cin >> correoElectronico;
    cout <<"\n Cual es su domicilio  ";
    cin >>domicilio;
    cout << "\n Cual es su capacidad";
    cin >> capacidadAl;
    base.agregaAgencia(Agencia(nombre,telefono,correoElectronico,domicilio,capacidadAl,0));
}

void registraAutoG(BaseDeDatos& base,int i)
{
    string modm;
    string marm;
    int cDF;
    int tor;
    float ac;
    bool tur;
    int cil;
    string mar;
    string mod;
    string col;
    string tran;
    float pr;
    string tdc;
    float ren;
    float cap;
    string dir;
    int pue;
    string trac;
    string est = "disponible";

    cout << "Atributos de el motor"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Cual es el Modelo : "<<endl;
    cin >> modm;
    cout <<"Cual es la Marca: "<<endl;
    cin >> marm;
    cout <<"Cuantos Caballos de fuerza tiene: " <<endl;
    cin >>cDF;
    cout <<"Cuantos Cilindros: " <<endl;
    cin >> cil;
    cout <<"Tiene Turbo: " <<endl;
    cin >> tur;
    cout <<"Cuanto Torque: " <<endl;
    cin >> tor;
    cout <<" Cual es la capacidad de Acilidrada: " <<endl;
    cin >> ac;
    cout << "-----------------------------------"<<endl;
    cout << "Atributos de el auto"<<endl;
    cout << "-----------------------------------"<<endl;
    cout <<"Marca:" <<endl;
    cin >> mar;
    cout << "Color:"<<endl;
    cin >> col;
    cout << "Modelo:"<<endl;
    cin>> mod;
    cout <<"Tipo de Combustible:" <<endl;
    cin >> tdc;
    cout <<"Transmision:" <<endl;
    cin >> tran;
    cout << "Precio:"<<endl;
    cin >> pr;
    cout << "Rendimiento:"<<"km/L"<<endl;
    cin >>ren;
    cout <<"Capacidad:" <<endl;
    cin >>cap;
    cout <<"Direccion: " <<endl;
    cin >> dir;
    cout <<"Numero de Puertas:" <<endl;
    cin >>pue;
    cout <<"Traccion:" <<endl;
    cin >> trac;
    cout << "-----------------------------------"<<endl;


     base.agregaAuto(i , AutoGasolinaRegular(modm, marm,cDF,tor,ac,tur, cil,mar ,mod,col ,tran,est,pr,tdc,ren,cap,dir,pue,trac ));

}
void buscaAuto(BaseDeDatos& base,int caso, int i, string marca,int pmax,int pmin){
    //esta funcion manda llamar el procedimiento buscar correspondiente de el objeto base de la clase Base de datos
    //El procedimiento de base busca en la gaencia que se seleccione

    switch(caso){
    case 1:
    base.buscaAutoMar(i,marca);
    break;

    case 2:
    base.buscaAutoP(i,pmin,pmax);
    break;

    }

}
