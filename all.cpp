5. std::accumulate — сумма/произведение элементов
Зачем: Вычисление суммы, произведения или свёртки.

cpp
int sum = std::accumulate(v.begin(), v.end(), 0); // 15
int product = std::accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; }); // 120
6. std::remove + erase — удаление элементов
Зачем: Удаление всех вхождений значения (без изменения размера вектора!).

cpp
v.erase(std::remove(v.begin(), v.end(), 3), v.end()); // удаляет все 3
Аналог: std::remove_if (удаление по условию).

7. std::unique — удаление дубликатов
Зачем: Удаление соседних дубликатов (требуется сортировка).

cpp
std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());
8. std::reverse — разворот последовательности
Зачем: Переворот массива/строки за O(n).

cpp
std::reverse(v.begin(), v.end()); // {5, 4, 3, 2, 1}
9. std::max_element / std::min_element — поиск максимума/минимума
Зачем: Поиск max/min за O(n).

cpp
auto max_it = std::max_element(v.begin(), v.end());
std::cout << "Максимум: " << *max_it;
10. std::next_permutation — генерация перестановок
Зачем: Получение следующей перестановки (полезно в задачах комбинаторики).

cpp
std::string s = "abc";
do {
    std::cout << s << " "; // abc acb bac bca cab cba
} while (std::next_permutation(s.begin(), s.end()));
