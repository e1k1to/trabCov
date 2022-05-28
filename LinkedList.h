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
		bool insertHead(int id, int intubado, int asma, int fumante, int teste_covid, int obito);
		bool insertTail(int id, int intubado, int asma, int fumante, int teste_covid, int obito);
		NodeLL *search(int id);
		bool remove(int id);
		void clear();
		void print();	
		
		NodeLL* getHead(void){ return head; };
		void setHead(NodeLL *head) { this->head = head;	}
};

#endif
