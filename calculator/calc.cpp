#include <iostream> //вывод 
#include <vector> // вектора 
#include <string> // строки 
#include <algorithm> // сортировка
using namespace std;

// Функция для вычисления среднего арифметического
double Average(vector<double>& operands) {
    double sum = 0.0;
    for (const auto& op : operands) {
        sum += op;
    }
    return sum / operands.size();
}

// Функция для вычисления медианы
double Median(vector<double>& operands) {
    vector<double> sortOper = operands;
    sort(sortOper.begin(), sortOper.end());
    const int size = sortOper.size();
    if (size % 2 == 0) {
        return (sortOper[size/2 - 1] + sortOper[size/2]) / 2;
    } else {
        return sortOper[size/2];
    }
}

//текст help
void print_help(){
    cout << "\n\t\t  Использование calculator\n\n";
    cout << "\t [-o/--operation] <операция> op1 op2 op3 op4 op5 op6 \n\n Выбор операции(без <>):\n~ <average> (среднее арифметическое) \n~ <median>  (медиана)\n\n";
    }
    
    
    
int main(int argc, char* argv[]) {
    // проверяем количество введенных данных(<pusk> -о <операция> op1 ...; мин = 8 макс = 10 pyfxtybq
    if ((argc < 8) or (argc > 10)) { // от 5 до 7
        print_help();
        return 1;
    }
    
    //анализ введеного 
    string operation;
    vector<double> operands;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) {
                operation = argv[i + 1];
                i++; // Пропускаем следующий аргумент (значение операции)
            }
        } else {
            operands.push_back(stod(arg)); // строку в double 
        }
    }
    
    //вывод результата
    double result;
    if (operation == "average") {
        result = Average(operands);
    } else if (operation == "median") {
        result = Median(operands);
    } else {
        cout << "Неверная операция\n";
        return 1;
    }

    cout << "Результат: " << result << endl;
    return 0;
}
