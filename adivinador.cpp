#include <string>
#include <cstring>
#include "cifrados.h"
using namespace std;

void adivinarAfin(string mensaje) {
	affine Adivinador;
	string posibleMSG;
	int xTemp, yTemp, Num = 0;
	char algo = '"';
	for (int a = 1; a <= abc_mayus.length(); a++) {
		for (int b = 0; b <= abc_mayus.length(); b++) {
			if (euclides_largo(a, abc_mayus.length(), xTemp, yTemp) == 1) {
				cout << "Clave A: " << a << "\tClave B: " << b << endl;
				Adivinador.setPrivateKey(a, b);
				posibleMSG = Adivinador.descifrar(mensaje);
				cout << posibleMSG << endl;
				cout << "-------------------------------------" << endl;
				Num++;
			}
		}

	}
	cout << endl << "Posibles frases: " << Num << endl;
	cout << "Claves corretas -> a: 23    b: 17" << endl;
	Adivinador.setPrivateKey(23, 17);
	posibleMSG = Adivinador.descifrar(mensaje);
	cout << posibleMSG << endl;
}


int main() {

	string msg_largo = "SLBCMVRBSHZBT_NSRQVVMSZBVH_NBVRQVLALHZBT_NSRQVWQAXLZW_NAQFQV";
	adivinarAfin(msg_largo);

	return 0;
}