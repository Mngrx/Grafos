// DFS por lista de adjacência

#include <iostream>
#include <list>
#include <algorithm> //função find
#include <stack>

using namespace std;

class Grafo {

	private:
		int V; // número de vértices
		list<int> *adj; // ponterio para um array contendo as listas de adjacências

	public:
		Grafo(int V); //Construtor
		void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
		void dfs(int v); // faz uma DFS a partir de um vértice

	

};

Grafo::Grafo(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::adicionarAresta (int v1, int v2) {
	// adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::dfs(int v) {
	
	stack<int> pilha;
	bool visitados[V];
	// zerando o vetor de visitados
	for (int i = 0; i < V; ++i)
		visitados[i] = false;

	while (true) {
	
		if (!visitados[v]) {
			cout << "Vistando o vértice " << v << endl;  
			visitados[v] = true; //marca "v" como visitado
			pilha.push(v); // insere "v" na pilha
		}

		bool achou = false;
		list<int>::iterator it;

		//busca por um vizinho não visitado
		for (it = adj[v].begin(); it != adj[v].end(); ++it) {
			if (!visitados[*it]) {
				achou = true;
				break;
			}
		}

		if (achou) {
			v = *it; // atualiza o "v"
		} else {
			// se todos os vizinhos estão vizitados ou não existem vizinhos
			// remove da pilha
			pilha.pop();

			if(pilha.empty()) 
				break;		
			//se chegou aqui, é porque pode pegar elemento do topo
			
			v = pilha.top();
		}

	}



}

int main () {

	int V = 8;

	//criação do grafo

	Grafo grafo(V);

	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.dfs(0);


	return EXIT_SUCCESS;
}