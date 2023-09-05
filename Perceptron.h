#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Math.h"
using namespace std;

class Perceptron {
private:
	float w0;
	float w1;
	float a;
public:
	void readFile();
	void readFilePrueba();
	void start();
	float sumatoria(float x0, float x1);
	int fnActivacion(float sum);
	float obtenerError(int y, float yd);
	void ajustarPesos(int error, float x0, float x1);
};
