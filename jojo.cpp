#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(){
	int V[6] = {0};									//Cria array que servirá como auxiliar para a criação de pacientes
	int id = 0;										//Id de cada paciente
	int categoriaAtual = 1;							//Armazena o index da categoria da lista (sexo, idade, doençaA, doençaB,...)
	int elemAtual = 0;								//Cria int que receberá valor convertido de string para int da variável 'atual'
	int fumanteCovidObito = 0;						//Cria int que armazenará quantidade de fumantes com covid e que foram a obito
	int fumante = 0;								//Cria int que armazenará quantidade de fumantes
	int asmaCovidIntubado = 0;				//Cria int que armazenará quantidade de pessoas com asma, covid e que foram entubados
	int asma = 0;							//Cria int que armazenará quantidade de pessoas com asma
	int obito = 0;						//Cria int que armazenará quantidade de pacientes que foram à obito com covid.
	int testePositivo = 0;					//Cria int que armazenará quantidade de testes positivos de covid
	int intubado = 0;						//Cria int que armazenará quantidade de pessoas intubadas
	int escolha = -1;
	string linha;									//Cria string que armanezará a linha temporária do arquivo
	string atual;									//Cria string que armanezará saída de cada elemento de 'linha'
	LinkedList * ll = new LinkedList();				//Cria a lista encadeada
	NodeLL * pAnda = nullptr;						//Cria ponteiro que anda pela LL

	stringstream ss; 								//Cria buffer de dados
	while(1){
	escolha = -1;
	while(escolha < 0 || escolha > 3){
		cout << "Menu dados covid:\n1- Carregar dados da tabela.\n2- Fazer cálculos da tabela.\n3- Mostrar resultados.\n0- Sair do aplicativo" << endl;
		cin >> escolha;
	}

	ifstream arquivo ("df_covid.csv", ios::out); 	//Seleciona e abre o arquivo para leitura
	
	if(escolha == 0){ return 0; }
	else if(escolha == 1) {
		int pontinhos = 0;
		if(arquivo.is_open()){							//Verifica se arquivo está aberto
			while(getline(arquivo,linha)){ 				//Enquanto receber linhas, passa a linha atual para leitura de cada elemento
				ss.clear();								//Limpa o buffer
				ss << linha;							//Adiciona o conteúdo da string linha para o buffer
				categoriaAtual = 1;						//Reseta o index de V para 1
				V[0] = id;								//Adiciona o id como primeiro elemento da lista
				while(getline(ss, atual, ',')){			//Para cada elemento (separado por virgula) coloca na array V,
														//que será usada para passar argumentos para a criação de um paciente
					elemAtual = atoi(atual.c_str());	//Converte string de retorno para int
					//cout << elemAtual << endl;			//Imprime elemento atual
					V[categoriaAtual] = elemAtual;		//Adiciona elemento na array auxiliar V
					categoriaAtual++;					//Aumenta o index da array V
				}
				if(id % 1000 == 0){ pontinhos++; }
				
				if(pontinhos > 3){ pontinhos = 0;}

				if(pontinhos == 0) { cout << "Carregando dados   " << '\r' << flush; }
					
				if(pontinhos == 1) { cout << "Carregando dados.  " << '\r' << flush; }
				
				if(pontinhos == 2) { cout << "Carregando dados.. " << '\r' << flush; }
				
				if(pontinhos == 3) { cout << "Carregando dados..." << '\r' << flush; }

				id++;									//Aumenta o ID para o próximo paciente
				ll->insertTail(V[0],V[1],V[2],V[3],V[4],V[5]);	//Adiciona elementos na Lista Encadeada
				/*
				0 - id
				1 - intubado
				2 - asma
				3 - fumante
				4 - teste_covid
				5- obito
				*/
					
			}

		cout << "Carregamento completado" << endl;
		arquivo.close();		//Fecha arquivo
		}
		else{
			cout << "Não foi possivel abrir o arquivo." << endl;
			return 1;
		}
	}
		
	else if(escolha == 2){
		pAnda = ll->getHead();
		int fumanteAtual, covidAtual, obitoAtual, asmaAtual, intubadoAtual;
		while(pAnda != nullptr){
			fumanteAtual = 0;
			covidAtual = 0;
			obitoAtual = 0;
			asmaAtual = 0;
			intubadoAtual = 0;

			if( pAnda->getTeste_covid() == 1 ){
				covidAtual++;
				testePositivo++;
				
				if( pAnda->getFumante() == 1){
					fumante++;
					fumanteAtual++;
				}
				if( pAnda->getObito() == 1 ){
					obito++;
					obitoAtual++;
				}
				if( pAnda->getIntubado() == 1 ){
					intubadoAtual++;
					intubado++;
				}
				if( pAnda->getAsma() == 1 ){
					asmaAtual++;
					asma++;
				}
				if( fumanteAtual == 1 && obitoAtual == 1 ){
					fumanteCovidObito++;
				}
				if( asmaAtual == 1 && intubadoAtual == 1 ){
					asmaCovidIntubado++;
				}
			}
			if(pAnda->getProx()->getId() == ll->getHead()->getId()){
				break;
			}
			pAnda = pAnda->getProx();
		}
		cout << "Dados Calculados." << endl;
	}
	else if(escolha == 3){
		cout << "==================================================" << endl;
		cout << "Total de testes positivos: " << testePositivo << endl;
		cout << endl;
		cout << "Total de fumantes com covid: " << fumante << endl;
		cout << "Total de pacientes com covid que foram a obito: " << obito << endl;
		cout << endl;
		cout << "Total de fumantes com covid que foram a obito: " << fumanteCovidObito << endl;
		cout << endl;
		cout << "Total de pessoas com asma e covid: " << asma << endl;
		cout << "Total de pessoas intubadas com covid: " << intubado << endl;
		cout << endl;
		cout << "Total de pessoas intubadas com covid que tem asma: " << asmaCovidIntubado << endl;
		cout << "==================================================" << endl;
	}
	}
}
