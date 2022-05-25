#include <string>
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
	head = nullptr;
};
LinkedList::~LinkedList(){
	clear();
};

// Libera mem�ria 
void LinkedList::clear(){
	NodeLL *pAnt, *pAnda = head;
	do{
		pAnt = pAnda;
		pAnda = pAnda->getProx();
		pAnt->setProx(nullptr);
		delete pAnt;
		pAnt = nullptr;
	}while(pAnda != nullptr && pAnda->getId() != getHead()->getId());
	
	head = nullptr;	
}

bool LinkedList::isEmpty(){
	if (getHead() == nullptr) return true;
	else return false;
};

bool LinkedList::isFull(){
	NodeLL *aux = new NodeLL();
	
	if (aux == nullptr) return true;

	aux = nullptr;
	return false;
};
		
bool LinkedList::insertHead(int id, int sexo, int tipo_paciente, int intubado, int pneumonia, int idade, int gravidez, int diabetes, int asma, int imunossupressao, int hipertensao, int cardiovascular, int obesidade, int fumante, int teste_covid, int icu, int obito){
	NodeLL *aux, *pAnda=nullptr;
    if (!isFull()){
      aux = new NodeLL(id, sexo, tipo_paciente, intubado, pneumonia, idade, gravidez, diabetes, asma, imunossupressao, hipertensao, cardiovascular, obesidade, fumante, teste_covid, icu, obito, nullptr);
      if (isEmpty()){ // Lista est� vazia
        head = aux;
		aux->setProx(getHead());
      }else { // Insere no come�o e atualiza o ponteiro
      	aux->setProx(head);
      	head = aux;
      }
	  pAnda = head;
	  do{
	  	pAnda = pAnda->getProx();
	  }while(pAnda != nullptr && pAnda->getProx()->getId() != getHead()->getId());
	  pAnda->setProx(getHead());
      return true;
    }
    else return false; // std::cout << "Overflow � Sem mem�ria";
};

bool LinkedList::insertTail(int id, int sexo, int tipo_paciente, int intubado, int pneumonia, int idade, int gravidez, int diabetes, int asma, int imunossupressao, int hipertensao, int cardiovascular, int obesidade, int fumante, int teste_covid, int icu, int obito){
	NodeLL *aux, *pAnda;
    if (!isFull()){
      aux = new NodeLL(id, sexo, tipo_paciente, intubado, pneumonia, idade, gravidez, diabetes, asma, imunossupressao, hipertensao, cardiovascular, obesidade, fumante, teste_covid, icu, obito, nullptr);
      if (isEmpty()){ // Lista est� vazia
        head = aux;
		aux->setProx(getHead());
      }else { // Insere no final e atualiza o ponteiro
        pAnda = head;  // Ponteiro que anda at� o final da lista 
        while (pAnda->getProx() != nullptr && pAnda->getProx()->getId() != getHead()->getId())
           pAnda = pAnda->getProx();
        pAnda->setProx( aux );
      }
	  aux->setProx(getHead());
	  return true;
    }
    else return false; // std::cout << "Overflow � Sem mem�ria";
};

		
NodeLL* LinkedList::search(int id){
	NodeLL *pAnda;
	
    if (isEmpty()) {
		return nullptr; // Lista vazia
    }else{
      pAnda = head;
      // procura a posi��o do elemento na lista
      while ((pAnda != nullptr) && pAnda->getProx()->getId() != getHead()->getId() && (pAnda->getId() != id))
        pAnda = pAnda->getProx();
	  if(pAnda->getId() == id) return pAnda; // Retorna a refer�ncia para o elemento	encontrado
      else return nullptr;
	}	
}

bool LinkedList::remove(int id){
	NodeLL *pAnt = nullptr, *pAux = nullptr, *pAnda;
    if (isEmpty()) return false; // Lista vazia
    else{
      pAnda = head;
      // procura a posi��o do elemento na list
	  do{
	  	pAnt = pAnda;
		pAnda = pAnda->getProx();
	  }while ((pAnda != nullptr) && (pAnda->getId() != getHead()->getId()) && (pAnda->getId() != id));
      
	  if (pAnda == nullptr || pAnda->getId() == getHead()->getId() && pAnda->getId() != id) return false; // Se n�o encontrou o elemento
      // Se elemento encontrado remove da lista
      else {
      	// se o elemento encontrado est� na cabe�a da lista
		if(head == pAnda && pAnda->getProx()->getId() == getHead()->getId()){
			setHead(nullptr);
		}
			  
		else if (head == pAnda) {
			pAux = head;
			while(pAux->getProx() != nullptr && pAux->getProx()->getId() != getHead()->getId()){
				pAux = pAux->getProx();
			}
			setHead(pAnda->getProx());
			pAux->setProx(getHead());
	    }
		else if(pAnda->getProx()->getId() == getHead()->getId()){
			pAux = head;
			while(pAux->getProx() != nullptr && pAux->getProx()->getId() != id){
				pAux = pAux->getProx();
			}
			pAux->setProx(getHead());
		}
	   	else{ // remove elemento do meio
	    	pAnt->setProx(pAnda->getProx());
		}
		delete pAnda;
      	pAnda = nullptr;
      	return true;   
      }
    }
}

void LinkedList::print(){
	NodeLL *pAnda; 
    int i = 1;
    std::cout << "[ " ;
	if(head != nullptr){
    pAnda = head;
	do{
		std::cout << "[ " << pAnda->getId() << ",";
		std::cout << pAnda->getId() << "," << pAnda->getSexo() << "," << pAnda->getTipo_paciente() << "," << pAnda->getIntubado() << "," << pAnda->getPneumonia() << "," << pAnda->getIdade() << "," << pAnda->getGravidez() << "," << pAnda->getDiabetes() << "," << pAnda->getAsma() << "," << pAnda->getImunossupressao() << "," << pAnda->getHipertensao() << "," << pAnda->getCardiovascular() << "," << pAnda->getObesidade() << "," << pAnda->getFumante() << "," << pAnda->getTeste_covid() << "," << pAnda->getIcu() << "," << pAnda->getObito() << " ] ";
		pAnda = pAnda->getProx();
	}while(pAnda != nullptr && pAnda->getId() != getHead()->getId());
	}
	std::cout <<  "]\n";
}
		

/*  pAnda->getId() << "," <<
	pAnda->getSexo() << "," <<
    pAnda->getTipo_paciente() << "," <<
	pAnda->getIntubado() << "," <<
	pAnda->getPneumonia() << "," <<
	pAnda->getIdade() << "," <<
	pAnda->getGravidez() << "," <<
	pAnda->getDiabetes() << "," <<
	pAnda->getAsma() << "," <<
	pAnda->getImunossupressao() << "," <<
	pAnda->getHipertensao() << "," <<
	pAnda->getCardiovascular() << "," <<
	pAnda->getObesidade() << "," <<
	pAnda->getFumante() << "," <<
	pAnda->getTeste_covid() << "," <<
	pAnda->getIcu() << "," <<
	pAnda->getObito()			*/
