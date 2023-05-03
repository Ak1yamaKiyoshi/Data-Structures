#include <iostream> // для вводу та виводу 
#include <windows.h> // встановлення кодування
#include <string.h> // для роботи з рядками 


using namespace std; // аби не писати std::


int main()
{
    SetConsoleCP(65001); // Встановлення кодування
    SetConsoleOutputCP(65001); // Встановлення кодування

    string s1; // рядок s1
    string s2; // рядок s2

    // Введення обох рядків 
    cout << "Введіть рядок 1:";
    getline(cin, s1); // Введення першого рядку
    cout << "Введіть рядок 2:";
    cin.sync(); // Очищення буферу після першого вводу 
    // Інакше може сприйняти за рядок лише "\n"
    getline(cin, s2);// Введення другого рядку 

    // видалення кожного другого елементу після другого елементу у першому рядку
    int i = 2;
    while (i < s1.length()) {
        s1.erase(i-1, i);
        i++;
    }

    s2 += s1; // додавання рядку s1 у кінець s2
    cout << s2 << endl; // виведення рядку s2

    return 0;
}
