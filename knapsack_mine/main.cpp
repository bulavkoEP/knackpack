#include "conditions.h"
#include "knapsack.h"
#include "solver.h"
#include <vector>
#include <iostream>

int main() {

    freopen("./input_knapsack/input18", "r", stdin);
    vector<unsigned> costs; //вектор ценностей
	vector<unsigned> weights; //вектор весов
	unsigned capacity;       //максимально допустимый вес
	unsigned n_items;         //размер входных данных(сколько товаров в магазине)
    cin >> n_items >> capacity;
	costs.resize(n);
	weights.resize(n);
	for (int i = 0; i < n_items; i++) {
		cin >> costs[i] >> weights[i];
	}
    
    Knapsack knapsack(capacity, n_items);
    Conditions conditions(&weights, &costs);
    Solver solver(&knapsack, &conditions);
    cout <<  
}