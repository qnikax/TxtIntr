#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

double Average(vector<double>& operands) {
    double sum = 0.0;
    for (auto op : operands) sum += op;
    return sum / operands.size();
}

double Median(vector<double> operands) {
    sort(operands.begin(), operands.end());
    int size = operands.size();
    return (size % 2 == 0) ? (operands[size/2-1] + operands[size/2])/2 : operands[size/2];
}

int Count(vector<double>& operands) {
    return operands.size();
}

void print_help(){
    cout << "=== СТАТИСТИЧЕСКИЙ КАЛЬКУЛЯТОР ===" << endl;
    cout << "Использование: calculator -o <операция> [числа...]" << endl;
    cout << "Операции: average (среднее), median (медиана), count (количество)" << endl;
    cout << "Операндов: от 5 до 7" << endl;
    cout << "Пример: calculator -o average 10 20 30 40 50" << endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        print_help();
        return 0;
    }
    
    if (argc < 8 || argc > 10) {
        cout << "Ошибка: нужно от 5 до 7 операндов!" << endl;
        print_help();
        return 1;
    }
    
    string operation;
    vector<double> operands;
    
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-o" || arg == "--operation") {
            operation = argv[++i];
        } else {
            operands.push_back(stod(arg));
        }
    }
    
    cout << fixed << setprecision(2);
    cout << "=== РЕЗУЛЬТАТ ВЫЧИСЛЕНИЙ ===" << endl;
    cout << "Операция: " << operation << endl;
    cout << "Данные: ";
    for (size_t i = 0; i < operands.size(); i++) {
        cout << operands[i] << (i < operands.size()-1 ? ", " : "");
    }
    cout << endl;
    
    if (operation == "average") {
        cout << "Среднее арифметическое: " << Average(operands) << endl;
    } else if (operation == "median") {
        cout << "Медиана: " << Median(operands) << endl;
    } else if (operation == "count") {
        cout << "Количество операндов: " << Count(operands) << endl;
    } else {
        cout << "Неизвестная операция!" << endl;
        return 1;
    }
    
    return 0;
}
