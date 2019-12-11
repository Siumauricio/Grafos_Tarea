
#include "Grafo.h"
#include <iostream>

int main(){
	Grafo g;
	g.agregarVertice ('A');
	g.agregarVertice ('B');
	g.agregarVertice ('C');
	g.agregarVertice ('D');
	g.agregarVertice ('E');

	g.agregarArista ('A','B',1);
	g.agregarArista ('A','C',2);
	g.agregarArista ('B','C',6);
	g.agregarArista ('B','E',4);
	g.agregarArista ('C','E',5);
	g.agregarArista ('E','D',3);
	g.ImprimirGrafo ();
	std::cout << "\n\n";
	g.floyds ();
	std::cout << "\n\n";
	g.Dijksra (0);
	return 0;
}