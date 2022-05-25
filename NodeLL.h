// NodeLL.h
#ifndef __NODE_LL_H__
#define __NODE_LL_H__

#include <string>
class NodeLL  // ll = linked List
{
public:
	NodeLL(){ id =0; prox = nullptr;	};
	NodeLL(int id, int sexo, int tipo_paciente, int intubado, int pneumonia, int idade, int gravidez, int diabetes, int asma, int imunossupressao, int hipertensao, int cardiovascular, int obesidade, int fumante, int teste_covid, int icu, int obito, NodeLL* prox){
			this->id = id;
			this->sexo = sexo;
			this->tipo_paciente = tipo_paciente;
			this->intubado = intubado;
			this->pneumonia = pneumonia;
			this->idade = idade;
			this->gravidez = gravidez;
			this->diabetes = diabetes;
			this->asma = asma;
			this->imunossupressao = imunossupressao;
			this->hipertensao = hipertensao;
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
    int getTipo_paciente(){return tipo_paciente;};
	int getIntubado(){return intubado;};
	int getPneumonia(){return pneumonia;};
	int getIdade(){return idade;};
	int getGravidez(){return gravidez;};
	int getDiabetes(){return diabetes;};
	int getAsma(){return asma;};
	int getImunossupressao(){return imunossupressao;};
	int getHipertensao(){return hipertensao;};
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
    int tipo_paciente;
	int intubado;
	int pneumonia;
	int idade;
	int gravidez;
	int diabetes;
	int asma;
	int imunossupressao;
	int hipertensao;
	int cardiovascular;
	int obesidade;
	int fumante;
	int teste_covid;
	int icu;
	int obito;
	NodeLL *prox;
};

#endif
