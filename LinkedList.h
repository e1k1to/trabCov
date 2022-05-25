// LinkedList.h
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "NodeLL.h"
#include <string>

class LinkedList{
	private:
		NodeLL *head;
	public:	
		LinkedList();
		~LinkedList();
		bool isEmpty();
		bool isFull();
		bool insertHead(int id, int sexo, int tipo_paciente, int intubado, int pneumonia, int idade, int gravidez, int diabetes, int asma, int imunossupressao, int hipertensao, int cardiovascular, int obesidade, int fumante, int teste_covid, int icu, int obito);
		bool insertTail(int id, int sexo, int tipo_paciente, int intubado, int pneumonia, int idade, int gravidez, int diabetes, int asma, int imunossupressao, int hipertensao, int cardiovascular, int obesidade, int fumante, int teste_covid, int icu, int obito);
		NodeLL *search(int id);
		bool remove(int id);
		void clear();
		void print();	
		
		NodeLL* getHead(void){ return head; };
		void setHead(NodeLL *head) { this->head = head;	}
};

#endif
