#include "Perceptron.h"

void Perceptron::readFile() {
    string filePath = "XOR_trn.csv";
    ifstream file;
    file.open(filePath);
    if (file.fail()) {
        cout << "Error" << endl;
    }
    else {
        while (file.peek() != EOF) {
            string data;
            getline(file, data, '\n');
            int pos0 = data.find(',');
            float x0 = stof(data.substr(0, pos0));
            int pos1 = data.find(',', pos0+1);

            float x1 = stof(data.substr(pos0+1,pos1-pos0-1));
            float yd = stof(data.substr(pos1 + 1));
            float sum = sumatoria(x0, x1);
            float y = fnActivacion(sum);
            float error = obtenerError(y, yd);

            if (error != 0) {
                ajustarPesos(error, x0, x1);
                cout <<"Peso 0:" << w0 << endl;
                cout << "Peso 1:" << w1 << endl;
                cout << "-------------------------------" << endl;
            }
        }
    }
    file.close();
    readFilePrueba();
}

void Perceptron::readFilePrueba() {
    string filePath = "XOR_tst.csv";
    ifstream file;
    file.open(filePath);
    if (file.fail()) {
        cout << "Error" << endl;
    }
    else {
        while (file.peek() != EOF) {
            string data;
            getline(file, data, '\n');
            int pos0 = data.find(',');
            float x0 = stof(data.substr(0, pos0));
            int pos1 = data.find(',', pos0 + 1);

            float x1 = stof(data.substr(pos0 + 1, pos1 - pos0 - 1));
            float yd = stof(data.substr(pos1 + 1));
            float sum = sumatoria(x0, x1);
            float y = fnActivacion(sum);
            float error = obtenerError(y, yd);
            cout << "x0:" << x0 << endl;
            cout << "x1:" << x1 << endl;
            cout << "Sumatoria:" << x1 << endl;
            cout << "Resultado:" << fnActivacion(sum) << endl;
            cout << "Resultado esperado:" << yd << endl;
            cout << "Error:" << error << endl;

            cout << "-------------------------------" << endl;

        }
    }
    file.close();
}

void Perceptron::start() {
    Math math;
    // Pesos y valor de aprendizaje aleatorios
    float w0 = math.RandomFloat(0, 1);
    float w1 = math.RandomFloat(0, 1);
    float a = math.RandomFloat(0, 1);


    // Print the random number
    cout << w0 << endl;
    cout << w1 << endl;
    cout << a << endl;
}

float Perceptron::sumatoria(float x0, float x1) {
    return x0 * w0 + x1 * w1;
}

int Perceptron::fnActivacion(float sum) {
    if (sum < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

float Perceptron::obtenerError(int y, float yd) {
    return yd - y;
}

void Perceptron::ajustarPesos(int error, float x0, float x1) {
    w0 = w0 + (a * error * x0);
    w1 = w1 + (a * error * x1);
}