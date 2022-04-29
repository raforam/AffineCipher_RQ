#include <string>
#include <cstring>
#include "cifrados.h"
#include "adivinador.h"
using namespace std;

int main() {

	int claveA, claveB;
	cout << "Ingresar la clave 'a': "; cin >> claveA;
	cout << "Ingresar la clave 'b': "; cin >> claveB;

	string msj = "";
	cout << "Ingrese el texto a encriptar: "; cin >> msj; cout << endl;

	affine A_emisor;
	A_emisor.setPrivateKey(claveA, claveB);
	string msg_encriptado = A_emisor.encrypt(msj);
	cout << "Mensaje encriptado: " << msg_encriptado << endl << endl;

	affine B_receptor;
	B_receptor.setPrivateKey(claveA, claveB);
	string msg_decriptado = B_receptor.descifrar(msg_encriptado);
	cout << "Menaje decriptado: " << msg_decriptado << endl;

	cout << endl << "----------------------------------------------------" << endl;
	
	//string largo = "SLBCMVRBSHZBT_NSRQVVMSZBVH_NBVRQVLALHZBT_NSRQVWQAXLZW_NAQFQV";
	//adivinarAfin(largo);
	

	return 0;
}