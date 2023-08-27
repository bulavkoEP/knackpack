#include <iostream>
#include "conditions.h"
#include "knapsack.h"
#include  <vector>
#include <algorithm>
  

unsigned optimal (std::vector<bool> &in_or_not, int i, std::vector<unsigned> costs){
    unsigned sum = 0, n = in_or_not.size();
    
    for (int j = 0; j < i; j++)  { if(in_or_not[j]) sum += costs[j];}
    for (int j = i++; j < n; j++) sum += costs[j];
    
    return sum;
}

int last_one_to_zero(std::vector<bool> &vec, unsigned i) {
    unsigned n = vec.size();
    if (i == n) i = n - 1;
    int j = i;
    while (j >=0 && vec[j] == false) {
        j--;
    }
    return j;
}

void dfs (Conditions &conditions, unsigned i, Knapsack &knapsack, bool &flag1, bool &flag2, unsigned &max, int k) {

    if (k > 10000) {
        return;
    }

    if (flag2) return;
    unsigned opt_value = optimal((knapsack.items), i, conditions.costs);
    if(opt_value < max) {
        
        
    
        
        i = last_one_to_zero((knapsack.items), i);
        if (i == -1) { 
            flag2 = 1; return;
            }
        knapsack.take_out(i, conditions.weights[i], conditions.costs[i]);
        flag1 = 1;

        
    }

    if(knapsack.get_current_value() == opt_value) {

        
    
        if(knapsack.get_current_value() > max) max = knapsack.get_current_value();
        i = last_one_to_zero((knapsack.items), i);
    
        if (i == -1) { 
            flag2 = 1; return;
            }
        knapsack.take_out(i, conditions.weights[i], conditions.costs[i]);
        flag1 = 1;
    }

    

    if (conditions.weights[i] + knapsack.get_current_weight() <= knapsack.capacity && !(flag1)) {

        
    
    
        knapsack.put_item(i, conditions.weights[i], conditions.costs[i]);
        dfs(conditions, ++i, knapsack, flag1, flag2, max, ++k);
    } else {
       
        flag1 = 0;
    
        
        
        dfs(conditions, ++i, knapsack, flag1, flag2, max, ++k);
    }

}


int main() {

    unsigned i, n, capacity, p = 0, max = 0, j = 0;
    bool flag1 = 0; 
    bool flag2 = 0;
    std::cin >> n >> capacity;
    std::vector
    <unsigned> weights(n);
    std::vector
    <unsigned> costs(n);
    for (i = 0; i < n; i++) {
        std::cin >> costs[i] >> weights[i];
    }
    Knapsack knapsack(capacity, n);
    Conditions conditions(weights, costs);
    
    std::cout << "Starting" << std::endl;   

    dfs(conditions, j, knapsack, flag1, flag2, max, 0);

    std::cout << max << std::endl;
    return 0;
}