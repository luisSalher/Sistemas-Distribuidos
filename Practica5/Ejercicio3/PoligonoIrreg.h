#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>

#define MAXVERT 50
#define MAXCOORD 20
#define NPOLIGONOS 1000000

using namespace std;
class PoligonoIrreg{
	private:
		vector<Coordenada> vertices;
		static int verticesTotales;
	public:
		PoligonoIrreg();
		static int getVerticesTotales();
		void anadeVertice(Coordenada);
		void imprimeVertices();
};
#endif
