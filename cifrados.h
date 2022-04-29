#pragma once

#include <iostream>
using namespace std;

string const abc_mayus = "ABCDEFGHIJKLMN_OPQRSTUVWXYZ";
string const abc_minus = "abcdefghijklmn_opqrstuvwxyz";

//valor a para affine -> 0-27 (pero tambien tiene que tener inversa con 27)
//valor b para affine -> 0-26 (len del abecedario-1)

void swap(int* a, int* b) {
    int x = *a;
    *a = *b;
    *b = x;
}

int moduloFunc(int a, int b) {
    int q = a / b;
    int r = a - (q * b);

    if (r < 0) {
        q--;
        r = a - (q * b);
    }

    return r;
    /*
    return a % b;
    */
}

int euclides_largo(int a, int b, int& x, int& y) {

    if (a < b) swap(a, b);

    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int mcd = euclides_largo(b, a % b, x1, y1);


    x = y1;
    y = x1 - (a / b) * y1;

    return mcd;
}

int euclides_largo2(int a, int b, int& x, int& y) {
    //if(a<b) {swap(a,b)};
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int mcd = euclides_largo2(b, a % b, x1, y1);


    x = y1;
    y = x1 - (a / b) * y1;

    return x;
}

int inversa(int a, unsigned int b) {
    int xTemp, yTemp;
    if (euclides_largo(a, b, xTemp, yTemp) == 1) {
        int x_temp, y_temp, x;
        x = euclides_largo2(a, b, x_temp, y_temp);

        return ( moduloFunc(moduloFunc(x,b)+b , b) );
    }
    else {
        cout << a << " no tiene inverso." << endl;
        return 0;
    }
}


class cesar {
    int clave;
public:
    cesar() {
        int clave_0 = getsetPrivate();
    }


    int getsetPrivate() {
        int entrada;
        cout << "Ingresar clave: "; cin >> entrada;
        clave = entrada;
        return clave;
    }


    int modulo(int a, int b) {
        int q = a / b;
        int r = a - (q * b);

        if (r < 0) {
            q--;
            r = a - (q * b);
        }
        return r;
    }


    string encrypt(string msg) {
        string encriptado(msg.length(), ' ');
        int index;

        for (int i = 0; i < msg.length(); i++) {

            for (int j = 0; j < abc_minus.length(); j++) {

                if (msg[i] == abc_minus[j]) {

                    index = modulo(j + clave, abc_minus.length());
                    encriptado[i] = abc_minus[index];
                }

            }

            for (int j = 0; j < abc_mayus.length(); j++) {

                if (msg[i] == abc_mayus[j]) {
                    index = modulo(j + clave, abc_mayus.length());
                    encriptado[i] = abc_mayus[index];
                }
            }
        }
        return encriptado;
    }



    string descifrar(string msg) {
        string decrypt(msg.length(), ' ');
        int index;

        for (int i = 0; i < msg.length(); i++) {

            for (int j = 0; j < abc_minus.length(); j++) {

                if (msg[i] == abc_minus[j]) {
                    index = modulo(j - clave, abc_minus.length());
                    decrypt[i] = abc_minus[index];
                }
            }

            for (int j = 0; j < abc_mayus.length(); j++) {

                if (msg[i] == abc_mayus[j]) {

                    index = modulo(j - clave, abc_mayus.length());
                    decrypt[i] = abc_mayus[index];
                }
            }
        }
        return decrypt;
    }

};

/*-------------------------------------------------------------------------------*/

class affine {
    int clave_a;
    int clave_b;
public:
    /*
    affine(bool Default=false) {
        int clave_0 = getsetPrivate1();
        int clave_1 = getsetPrivate2();
    }
    */
    affine() {
        affine::clave_a = 1;
        affine::clave_b = 1;
    }


    void setPrivateKey(int a, int b) {
        clave_a = a;
        clave_b = b;
    }

    void printPrivateKey() {
        cout << clave_a << " " << clave_b << endl;
    }

    int getsetPrivate1() {
        int entrada1;
        cout << "Ingresar clave a: "; cin >> entrada1;
        clave_a = entrada1;
        return clave_a;
    }
    int getsetPrivate2() {
        int entrada2;
        cout << "Ingresar clave b: "; cin >> entrada2;
        clave_b = entrada2;
        return clave_b;
    }


    int modulo(int a, int b) {
        return moduloFunc(a, b);
    }



    string encrypt(string msg) {
        string encriptado(msg.length(), ' ');
        unsigned int index;

        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < abc_minus.length(); j++) {
                if (msg[i] == abc_minus[j]) {
                    index = modulo(((clave_a * j) + clave_b), abc_minus.length());
                    //cout << j << " " << index << endl;

                    //cout << abc_minus[index] << endl;
                    encriptado[i] = abc_minus[index];
                    //cout << msg[i] << " " << abc_minus[index] << endl;
                }
            }
            for (int j = 0; j < abc_mayus.length(); j++) {
                if (msg[i] == abc_mayus[j]) {
                    index = modulo(((clave_a * j) + clave_b), abc_mayus.length());
                    //cout << j << " " << index << endl;

                    //cout << abc_minus[index] << endl;
                    encriptado[i] = abc_mayus[index];
                    //cout << msg[i] << " " << abc_mayus[index] << endl;
                }
            }
        }
        return encriptado;
    }



    string descifrar(string msg) {
        string decrypt(msg.length(), ' ');
        int index;
        int a_inv = inversa(clave_a, abc_mayus.length());

        for (int i = 0; i < msg.length(); i++) {
            for (int j = 0; j < abc_minus.length(); j++) {

                if (msg[i] == abc_minus[j]) {
                    index = modulo( a_inv * ( modulo(j-clave_b,abc_minus.length()) ) , abc_minus.length() );        // modulo(j
                    //cout << a_inv << " " << j << " " << index << endl;
                    decrypt[i] = abc_minus[index];
                    //cout << msg[i] << " " << abc_minus[index] << endl;
                }
            }

            for (int j = 0; j < abc_mayus.length(); j++) {

                if (msg[i] == abc_mayus[j]) {

                    index = modulo( a_inv * (modulo(j-clave_b,abc_mayus.length()) ) , abc_mayus.length());
                    //cout << a_inv << " " << modulo(j - clave_b, abc_mayus.length()) << " " << index <<endl;
                    decrypt[i] = abc_mayus[index];
                    //cout << msg[i] << " " << abc_mayus[index] << endl;

                }
            }
        }
        return decrypt;
    }

};
