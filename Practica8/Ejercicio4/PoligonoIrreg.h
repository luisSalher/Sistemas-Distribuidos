#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>

using namespace std;
class PoligonoIrreg{
	protected:
		vector<Coordenada> vertices;
	public:
		PoligonoIrreg();	
		void anadeVertice(Coordenada);
		void imprimeVertices();
};
#endif
