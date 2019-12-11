#include "Grafo.h"
#include <iomanip>
#include <iostream>
using std::setw;
using namespace std;
#define INFINITO 9999;

Grafo::Grafo ():vertices (0),nVertices (0),aristas (0),costo(0) {}

void Grafo::agregarVertice (char id) {
	char *verticesQpy = new char[nVertices + 1];

	for(int i = 0; i < nVertices; i++) {
		verticesQpy[i] = vertices[i];
	}
	verticesQpy[nVertices] = id;
	if(vertices != 0) {
		delete vertices;
	}
	vertices = verticesQpy;

	//Seccion de aristas
	int **aristasFilasQpy = new int *[nVertices + 1];
	int **costoFilasQpy = new int *[nVertices + 1];
	for(int i = 0; i < nVertices; i++) {
		aristasFilasQpy[i] = aristas[i];
		costoFilasQpy[i] = costo[i];
	}

	if(aristas != 0) {
		delete aristas;
	}
	if(costo!=0) {
		delete costo;
	}
	aristas = aristasFilasQpy;
	costo = costoFilasQpy;
	//Aristas Columnas

	for(int i = 0; i < nVertices; i++) {
		int *aristasColQpy = new int[nVertices + 1];
		int *costosColQpy = new int[nVertices + 1];
		for(int j = 0; j < nVertices; j++) {
			aristasColQpy[j] = aristas[i][j];
			costosColQpy[j] = costo[i][j];
		}
		if(aristas[i] != 0) {
			delete aristas[i];
		}
		if(costo[i]!=0) {
			delete costo[i];
		}
		aristasColQpy[nVertices] = 0;
		costosColQpy[nVertices] = INFINITO;
		aristas[i] = aristasColQpy;
		costo[i] = costosColQpy;
	}
	int *aristaUltimaFila = new int[nVertices + 1];
	int *costosUltimaFila = new int[nVertices + 1];
	for(int i = 0; i <= nVertices; i++) {
		aristaUltimaFila[i] = 0;
		costosUltimaFila[i] = INFINITO;
	}
	aristas[nVertices] = aristaUltimaFila;
	costo[nVertices] = costosUltimaFila;
	nVertices++;

}

void Grafo::agregarArista(char origen,char destino,int costo){
	int fila = obtenerIdVertice (origen);
	int columna = obtenerIdVertice (destino);
	if(fila!=-1&& columna!=-1) {
		aristas[fila][columna] = 1;
		aristas[columna][fila] = 1;
		this->costo[fila][columna] = costo;
		this->costo[columna][fila] = costo;
	}
}

int Grafo::obtenerIdVertice(char id){
	for(int i = 0; i < nVertices; i++) {
		if(vertices[i]==id){
			return i;
		}
	}
	return -1;
}
void Grafo::ImprimirGrafo(){
	cout << setw (2) << " ";
	for(int i = 0; i < nVertices; i++) {
		cout << setw (2) << vertices[i];
	}
	cout << "\n";
	for(int i = 0; i < nVertices; i++) {
		cout << setw (2) << vertices[i];
		for(int j = 0; j < nVertices; j++) {
			cout << setw (2) << aristas[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
	cout << setw (6) << " ";
	for(int i = 0; i < nVertices; i++) {
		cout << setw (6) << vertices[i];
	}
	cout << "\n";
	for(int i = 0; i < nVertices; i++) {
		cout << setw (6) << vertices[i];
		costo[i][i] = 0;
		for(int j = 0; j < nVertices; j++) {
			cout << setw (6) << costo[i][j];
		}
		cout << "\n";
	}
}

void Grafo::floyds () {
	int i,j,k;
	for(k = 0; k < nVertices; k++) {
		for(i = 0; i < nVertices; i++) {
			for(j = 0; j < nVertices; j++) {
				if(costo[i][k] + costo[k][j] < costo[i][j]) {
					costo[i][j] = costo[i][k] + costo[k][j];
				}
			}
		}
	}
	for(int i = 0; i < nVertices; i++) {
		cout << "\Costo Minimo De Vertices:" << i+1 << endl;
		for(int j = 0; j < nVertices; j++) {
			cout << costo[i][j] << "\t";
		}

	}
}
int Grafo::minimaDistancia (int dist[],bool Tset[]) {
	int min = INT_MAX,index;

	for(int i = 0; i < nVertices; i++) {
		if(Tset[i] == false && dist[i] <= min) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}
void Grafo::Dijksra(int valor){
	int dist[5];
	bool Dset[5];
	for(int i = 0; i < nVertices; i++)                   
	{
		dist[i] = INT_MAX;
		Dset[i] = false;
	}
	dist[4] = 0;                                   
	for(int c = 0; c < nVertices; c++) {
		int u = minimaDistancia (dist,Dset);           
		Dset[u] = true;                            
		for(int v = 0; v < nVertices; v++)
		{
			if(!Dset[v] && costo[u][v] && dist[u] != INT_MAX && dist[u] + costo[u][v] < dist[v])
				dist[v] = dist[u] + costo[u][v];
		}
	}
	cout << "Vertice\t\tDistancia " << endl;
	for(int i = 0; i < nVertices; i++)                     
	{
		char c = 65 + i;
		cout << c << "\t\t" << dist[i] << endl;
	}
}
