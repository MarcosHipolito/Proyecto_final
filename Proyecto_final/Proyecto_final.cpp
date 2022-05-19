//Entrega_final.cpp
//Segundo Avance de citras dentales: Marcos Zahid Hipolito Garcia 2086061

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

struct citas
{
	int num;//numero de cita
	string nombre;//nombre del paciente
	string hr;//hora de la cita
	int nom_trat;//nombre del tratamiento
	float PU;// precio unitario
	int cant; //cantidad de tratamiento
	float PT;//precio total
	citas* anterior = nullptr;
	citas* siguiente = nullptr;
};

citas* primera_cita = nullptr;
citas* ultima_cita = nullptr;
citas* aux_citas = nullptr;

string Blanq = "1.- Blanqueamiento dental:\nConsiste en quitar todas las manchas dentales que puedan tener los dientes, ya sean provocadas por\ncausas naturales o por factores externos como la cafeina o la nicotina.";
float P_Blanq = 150;
string Brack = "2.- Ortodoncia brackets:\nEste tipo de tratamiento bucal lo utilizamos para corregir los problemas de la mordida, de tal manera\nque tiene como principal objetivo alinear los dientes y la mandibula.";
float P_Brack = 200;
string Impla = "3.- Implantes dentales:\nLos implantes dentales se hacen con el fin de que sean a largo plazo, de tal forma que se intenta no\ncrear ningun malestar al paciente despues de su colocacion.";
float P_Impla = 1000;
string Prote = "4.- Protesis dentales removibles\nLos implantes dentales se hacen con el fin de que sean a largo plazo, de tal forma que se\nintenta no crear ningun malestar al paciente despues de su colocacion.";
float P_Prote = 900;

int cita_inicial = 1;

int cita_actual = 1;

void leer_registros();

void elegir_tratemiento();

void imprimir_tratamientos();

void registrar_cita(string nombre, string hr, int nom_trat, float PU, int cant);

void imp_citas();

void guardar_registros();

void modificar_cita();

void eliminar_cita();

void banner();

string nombre;
string hr;
int nom_trat;
float PU;
int cant;
float PT;
int trat;
bool salir = true;
int op;
int NCM;
int NCE;

int main()
{
	leer_registros();

	bool salir = false;//cerrar aplicacion

	do {
		system("CLS");

		cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Agenda de citas dentales" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~\n " << endl;

		cout << "     ~~~~~~~~~~~~~~~~" << endl;
		cout << "     Menu de opciones" << endl;
		cout << "     ~~~~~~~~~~~~~~~~\n " << endl;

		cout << "1.- Agendar cita" << endl;
		cout << "2.- Modificar cita" << endl;
		cout << "3.- Eliminar cita" << endl;
		cout << "4.- Lista de citas vigentes" << endl;
		cout << "5.- Salir" << endl;

		do
		{
			cout << "Digite el numero de la accion que desea realizar: ";
			cin >> op;
		} while (op > 5);

		system("CLS");

		switch (op)
		{
		case 1:
			banner();

			cout << "Ingrese el nombre del paciente: ";
			cin.ignore();
			getline(cin, nombre);
			cout << "ingrese la hora de la cita en formato 24 horas(ej. 14:30):";
			cin >> hr;

			elegir_tratemiento();

			cout << "Digite la cantidad del tratamiento: ";
			cin >> cant;

			switch (trat)
			{
			case 1:
				nom_trat = 1;
				PU = P_Blanq;
				PT = P_Blanq * cant;

				break;
			case 2:
				nom_trat = 2;
				PU = P_Brack;
				PT = P_Brack * cant;

				break;
			case 3:
				nom_trat = 3;
				PU = P_Impla;
				PT = P_Impla * cant;

				break;
			case 4:
				nom_trat = 4;
				PU = P_Prote;
				PT = P_Prote * cant;

				break;
			default:
				break;
			}

			registrar_cita(nombre, hr, nom_trat, PU, cant);

			system("pause");

			break;
		case 2:
			banner();

			modificar_cita();

			system("pause");

			break;
		case 3:
			banner();

			eliminar_cita();

			system("pause");

			break;
		case 4:
			banner();

			imp_citas();

			system("pause");

			break;

		case 5:
			banner();

			salir = true;

			break;
		default:
			break;
		}

	}while (salir == false);

	guardar_registros();

}

void banner() {

	switch (op)
	{
	case 1:
		cout << "\n~~~~~~~~~~~~" << endl;
		cout << "Agendar cita" << endl;
		cout << "~~~~~~~~~~~~\n " << endl;

		break;
	case 2:
		cout << "~~~~~~~~~~~~~~" << endl;
		cout << "Modificar cita" << endl;
		cout << "~~~~~~~~~~~~~~\n " << endl;

		break;
	case 3:
		cout << "~~~~~~~~~~~~~" << endl;
		cout << "Eliminar cita" << endl;
		cout << "~~~~~~~~~~~~~\n " << endl;

		break;
	case 4:
		cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Lista de citas vigentes" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~\n " << endl;

		break;
	case 5:
		cout << "~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Que tenga buen dia" << endl;
		cout << "~~~~~~~~~~~~~~~~~~\n " << endl;

		break;
	}

}

void imprimir_tratamientos() {

	cout << "\n" << Blanq << endl;
	cout << "\n" << Brack << endl;
	cout << "\n" << Impla << endl;
	cout << "\n" << Prote << endl;

}

void elegir_tratemiento() {
	cout << "Elige el tratamiento:" << endl;

	imprimir_tratamientos();

	do
	{
		cout << "Digite el nombre del tratamiento que desea: ";
		cin >> trat;

	} while (op > 5);
}

void registrar_cita(string nombre, string hr, int nom_trat, float PU, int cant) {

	citas* nva_cita = new citas;

	nva_cita->num = cita_actual;
	nva_cita->nombre = nombre;
	nva_cita->hr = hr;
	nva_cita->nom_trat = nom_trat;
	nva_cita->PU = PU;
	nva_cita->cant = cant;
	nva_cita->PT = PU * cant;


	if (cita_actual == cita_inicial)
	{
		primera_cita = nva_cita;
		ultima_cita = nva_cita;

	}
	else
	{

		nva_cita->anterior = ultima_cita;
		ultima_cita->siguiente = nva_cita;
		ultima_cita = nva_cita;

	}

	cita_actual++;

}

void modificar_cita() {

	aux_citas = primera_cita;

	if (!aux_citas)
	{

		cout << "No hay citas agendadas" << endl;

	}
	else
	{

		cout << "Ingrese el numero de la cita a modiicar: ";
		cin >> NCM;

		if (aux_citas->num == NCM)
		{

			int opmo;//opcion modificar

			cout << "\n\n1.- Nombre del paciente" << endl;
			cout << "2.- Hora del tratamiento" << endl;
			cout << "3.- Tratamiento a recibir" << endl;
			cout << "4.- cantidad del tratamiento" << endl;
			cout << "Digite el número de la opcion que desee modificar: ";
			cin >> opmo;

			switch (opmo)
			{
			case 1:

				system("cls");

				cout << "nombre actual: " << aux_citas->nombre << endl;
				cout << "ingrese el nombre corregido del paciente: " << endl;
				cin.ignore();
				getline(cin, aux_citas->nombre);

				break;
			case 2:

				system("cls");

				cout << "Hora registrada actualmente: " << aux_citas->hr << endl;
				cout << "Ingrese la hora correcta: ";
				cin >> aux_citas->hr;

				break;
			case 3:

				system("cls");

				cout << "tratameinto registado actualmente: " << endl;
				imprimir_tratamientos();
				cout << "Ingrese el tratamiento correcto: ";
				cin >> aux_citas->nom_trat;
				break;

			case 4:

				system("cls");

				cout << "cantidad del tratamiento actual: " << aux_citas->cant << endl;
				cout << "Ingrese la cantidad correcta del tratamietno: ";
				cin >> aux_citas->cant;
				break;


			default:
				break;
			}


		}
		aux_citas = aux_citas->siguiente;

	}
}

void imp_citas() {

	aux_citas = primera_cita;

	if (!aux_citas) {

		cout << "no hay citas agendadas" << endl;

	}
	else {

		while (aux_citas)
		{

			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "\nCita #" << aux_citas->num << endl;
			cout << "nombre: " << aux_citas->nombre << endl;
			cout << "hora: " << aux_citas->hr << endl << endl;
			switch (aux_citas->nom_trat)
			{
			case 1:cout << Blanq;
			case 2:cout << Brack;
			case 3:cout << Impla;
			case 4:cout << Prote;
			default:
				break;
			}

			cout << "Precio unitario por el tratamiento: " << aux_citas->PU << endl;
			cout << "cantidad del tratmiento que se realizara: " << aux_citas->cant << endl;
			cout << "Precio total a pagar: " << aux_citas->PU * aux_citas->cant << endl << endl;

			aux_citas = aux_citas->siguiente;

		}

	}

}

void guardar_registros() {

	ofstream archivo;

	archivo.open("citas_dentales.txt");

	if (archivo.is_open())
	{

		aux_citas = primera_cita;
		while (aux_citas)
		{

			archivo << aux_citas->num << endl;
			archivo << aux_citas->nombre << endl;
			archivo << aux_citas->hr << endl;
			archivo << aux_citas->nom_trat << endl;
			archivo << aux_citas->PU << endl;;
			archivo << aux_citas->cant << endl;

			aux_citas = aux_citas->siguiente;

		}
		archivo.close();
	}
	else
	{
		cout << "Error al crear archivo de guardado." << endl;
	}

}

void eliminar_cita() {

	aux_citas = primera_cita;

	if (!aux_citas)
	{
		cout << "No hay citas agendadas" << endl;
	}
	else
	{

		cout << "Ingresse el numero de la cita a eliminar: ";
		cin >> NCE;

		while (aux_citas)
		{

			if (NCE == primera_cita->num)
			{

				if (primera_cita->siguiente)
				{
					primera_cita = primera_cita->siguiente;
				}
				else
				{
					primera_cita = nullptr;
					cita_actual = 1;
					cita_inicial = 1;
				}

			}
			else {

				if (NCE == aux_citas->num)
				{


					if (aux_citas->siguiente)
					{
						aux_citas->anterior->siguiente = aux_citas->siguiente;
						aux_citas->siguiente->anterior = aux_citas->anterior;
						aux_citas = aux_citas->siguiente;
					}
					else
					{
						ultima_cita = aux_citas->anterior;
						aux_citas = aux_citas->anterior;
						aux_citas->siguiente = nullptr;
						cita_actual--;
					}

				}
			}

			aux_citas = aux_citas->siguiente;
		}


	}

}

void leer_registros() {

	ifstream leer;

	leer.open("citas_dentales.txt");

	if (leer.is_open())
	{
		int primera = 1;
		string linea;

		while (getline(leer, linea))
		{
			if (primera == 1)
			{

				cita_inicial = stoi(linea);

				primera++;
			}
			cita_actual = stoi(linea);
			getline(leer, linea);
			nombre = linea;
			leer >> linea;
			hr = linea;
			leer >> linea;
			nom_trat = stoi(linea);
			leer >> linea;
			PU = stof(linea);
			leer >> linea;
			cant = stoi(linea);
			leer.ignore();

			registrar_cita(nombre, hr, nom_trat, PU, cant);

		}

	}

}