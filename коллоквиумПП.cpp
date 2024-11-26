#include <iostream> 
#include <vector> 
#include <cassert> 
#include <stdexcept> 
using namespace std;

long long fact(int n) {
    long long a = 1;
    for (int i = 1; i <= n; ++i) {
        a *= i;
    }
    return a;
}

vector<long long> createfactarray(int n) {
    if (n <= 0) {
        throw invalid_argument("Число должно быть натуральным");
    }
    vector<long long> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(fact(i));
    }
    return a;
}

void testfacts() {
    try {
        createfactarray(0);
        assert(false && "Ошибка о неправильном вводе не была отображена");
    }
    catch (const invalid_argument&) {
        assert(true);
    }
    assert((createfactarray(1) == vector<long long>{1}));
    assert((createfactarray(2) == vector<long long>{1, 1}));
    assert((createfactarray(3) == vector<long long>{1, 1, 2}));
    assert((createfactarray(5) == vector<long long>{1, 1, 2, 6, 24}));
    assert((createfactarray(7) == vector<long long>{1, 1, 2, 6, 24, 120, 720}));
    
}

int main() {
    setlocale(LC_ALL, "rus");
    try {
        int n;
        cout << "Введите натуральное число: ";
        cin >> n;
        vector<long long> res = createfactarray(n);
        cout << "Массив из " << n << " первых факториалов: " << endl;
        for (long long& fct : res) {
            cout << fct << " ";
        }
        cout << endl;
        testfacts();
        cout << "Все тесты пройдены" << endl;
    }
    catch (const exception& err) {
        cerr << "Ошибка: " << err.what() << endl;
    }
    return 0;
}