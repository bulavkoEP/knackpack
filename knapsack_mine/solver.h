#include <knapsack.h>
#include <conditions.h>


class Solver {
    public:
        Solver(Knapsack * knapsack, Conditions * conditions);
        Knapsack * knapsack;
        Conditions * conditions;
        void solve();
        std::vector<bool> get_answer();
        bool is_solution_ready();
    private:
        bool is_solution_ready;
        std::vector<bool> answer;
}