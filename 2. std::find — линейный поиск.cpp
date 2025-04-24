Зачем: Поиск первого вхождения элемента за O(n).


auto it = std::find(v.begin(), v.end(), 3);
if (it != v.end()) std::cout << "Найден: " << *it;
