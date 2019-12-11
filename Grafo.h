#pragma once
#ifndef GRAFO_H
#define GRAFO_H
class Grafo {
private:
	char *vertices;
	int nVertices;
	int **aristas;
	int **costo;
public:
	Grafo ();
	void agregarVertice (char);
	void agregarArista (char,char,int);
	int obtenerIdVertice (char);
	void ImprimirGrafo ();
	void floyds ();
	void Dijksra (int);
	int minimumDist (int dist[],bool Tset[]);
};

#endif // !GRAFO_H
