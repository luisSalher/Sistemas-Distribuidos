#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>
#include <algorithm>

using namespace std;
class PoligonoIrreg{
	private:
		vector<Coordenada> vertices;
	public:
		PoligonoIrreg();

	static bool comparacion(Coordenada a, Coordenada b);
	void anadeVertice(Coordenada);
	void imprimeVertices();
	void ordenarVertices();
};
#endif
