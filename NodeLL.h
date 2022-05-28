// NodeLL.h
#ifndef __NODE_LL_H__
#define __NODE_LL_H__

#include <string>
class NodeLL  // ll = linked List
{
public:
	NodeLL(){ id =0; prox = nullptr;	};
	NodeLL(int id, int intubado, int asma, int fumante, int teste_covid, int obito, NodeLL* prox){
			this->id = id;
			this->intubado = intubado;
			this->asma = asma;
			this->fumante = fumante;
			this->teste_covid = teste_covid;
			this->obito = obito;
			this->prox = prox;
	};
	~NodeLL();

	NodeLL *getProx() { return prox; };
	int getId(){ return id;};
	int getIntubado(){return intubado;};
	int getAsma(){return asma;};
	int getFumante(){return fumante;};
	int getTeste_covid(){return teste_covid;};
	int getObito(){return obito;};
	
	void setProx(NodeLL *prox) { this->prox = prox; };
	void setId(int id) { this->id = id;	};
	
private:
    int id;
	int intubado;
	int asma;
	int fumante;
	int teste_covid;
	int obito;
	NodeLL *prox;
};

#endif
