#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>

#define MAXVERT 10
#define MAXCOORD 10
#define NPOLIGONOS 1000

using namespace std;
class PoligonoIrreg{
	private:
		vector<Coordenada> vertices;
		static int verticesTotales;
	public:
		PoligonoIrreg();

	void anadeVertice(Coordenada);
	void imprimeVertices();
};
#endif
