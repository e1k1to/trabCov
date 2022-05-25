#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(){
	int V[17] = {0};								//Cria array que servirá como auxiliar para a criação de pacientes
	int id = 0;										//Id de cada paciente
	int categoriaAtual = 1;							//Armazena o index da categoria da lista (sexo, idade, doençaA, doençaB,...)
	int elemAtual = 0;								//Cria int que receberá valor convertido de string para int da variável 'atual'
	string linha;									//Cria string que armanezará a linha temporária do arquivo
	string atual;									//Cria string que armanezará saída de cada elemento de 'linha'
	LinkedList* ll = new LinkedList();				//Cria a lista encadeada

	stringstream ss; 								//Cria buffer de dados

	ifstream arquivo ("df_covid.csv", ios::out); 	//Seleciona e abre o arquivo para leitura

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
			id++;									//Aumenta o ID para o próximo paciente
		}
			
		arquivo.close();							//Fecha arquivo
	}
	else{											//Caso não seja possível abrir o arquivo, imprime uma string de erro.
		cout << "Não foi possível abrir o arquivo" << endl;
	}
	return 0;
}
