// NodeLL.h
#ifndef __NODE_LL_H__
#define __NODE_LL_H__

#include <string>
class NodeLL  // ll = linked List
{
public:
	NodeLL(){ id =0; prox = nullptr;	};
	NodeLL(int id, int sexo, int intubado, int pneumonia, int diabetes, int asma, int cardiovascular, int obesidade, int fumante, int teste_covid, int icu, int obito, NodeLL* prox){
			this->id = id;
			this->sexo = sexo;
			this->intubado = intubado;
			this->pneumonia = pneumonia;
			this->diabetes = diabetes;
			this->asma = asma;
			this->cardiovascular = cardiovascular;
			this->obesidade = obesidade;
			this->fumante = fumante;
			this->teste_covid = teste_covid;
			this->icu = icu;
			this->obito = obito;
			this->prox = prox;
	};
	~NodeLL();

	NodeLL *getProx() { return prox; };
	int getId(){ return id;};
	int getSexo(){return sexo;};
	int getIntubado(){return intubado;};
	int getPneumonia(){return pneumonia;};
	int getDiabetes(){return diabetes;};
	int getAsma(){return asma;};
	int getCardiovascular(){return cardiovascular;};
	int getObesidade(){return obesidade;};
	int getFumante(){return fumante;};
	int getTeste_covid(){return teste_covid;};
	int getIcu(){return icu;};
	int getObito(){return obito;};
	
	void setProx(NodeLL *prox) { this->prox = prox; };
	void setId(int id) { this->id = id;	};
	
private:
    int id;
    int sexo;
	int intubado;
	int pneumonia;
	int diabetes;
	int asma;
	int cardiovascular;
	int obesidade;
	int fumante;
	int teste_covid;
	int icu;
	int obito;
	NodeLL *prox;
};

#endif
