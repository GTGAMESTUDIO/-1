
## 🔹 **1. Основные категории алгоритмов**  
Алгоритмы можно разделить на несколько групп:  
1. **Немодифицирующие** (не изменяют данные)  
2. **Модифицирующие** (изменяют данные)  
3. **Сортировка и бинарный поиск**  
4. **Численные операции**  
5. **Куча (heap)**  
6. **Минимум/максимум**  
7. **Перестановки**  

---

## 🔹 **2. Немодифицирующие алгоритмы**  
### **2.1 `std::find` — поиск элемента**  
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
auto it = std::find(v.begin(), v.end(), 3); // возвращает итератор на 3
if (it != v.end()) std::cout << "Найден: " << *it; // Найден: 3
```

### **2.2 `std::count` — подсчёт элементов**  
```cpp
int cnt = std::count(v.begin(), v.end(), 2); // cnt = 1
```

### **2.3 `std::all_of`, `any_of`, `none_of` — проверка условий**  
```cpp
bool all_even = std::all_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; }); // false
bool has_negative = std::any_of(v.begin(), v.end(), [](int x) { return x < 0; }); // false
```

### **2.4 `std::search` — поиск подпоследовательности**  
```cpp
std::vector<int> sub = {3, 4};
auto it = std::search(v.begin(), v.end(), sub.begin(), sub.end()); // итератор на 3
```

---

## 🔹 **3. Модифицирующие алгоритмы**  
### **3.1 `std::copy` — копирование**  
```cpp
std::vector<int> dest(5);
std::copy(v.begin(), v.end(), dest.begin()); // dest = {1, 2, 3, 4, 5}
```

### **3.2 `std::fill` — заполнение значением**  
```cpp
std::fill(v.begin(), v.end(), 0); // v = {0, 0, 0, 0, 0}
```

### **3.3 `std::replace` — замена элементов**  
```cpp
std::replace(v.begin(), v.end(), 0, 42); // v = {42, 42, 42, 42, 42}
```

### **3.4 `std::remove` — удаление элементов**  
```cpp
auto new_end = std::remove(v.begin(), v.end(), 42); // "удаляет" 42, но физически не уменьшает вектор
v.erase(new_end, v.end()); // теперь v пуст
```

### **3.5 `std::reverse` — разворот последовательности**  
```cpp
std::reverse(v.begin(), v.end()); // v = {5, 4, 3, 2, 1}
```

### **3.6 `std::unique` — удаление дубликатов**  
```cpp
std::vector<int> dup = {1, 1, 2, 2, 3};
auto last = std::unique(dup.begin(), dup.end()); // dup = {1, 2, 3, ?, ?}
dup.erase(last, dup.end()); // dup = {1, 2, 3}
```

---

## 🔹 **4. Сортировка и бинарный поиск**  
### **4.1 `std::sort` — сортировка**  
```cpp
std::sort(v.begin(), v.end()); // по возрастанию
std::sort(v.begin(), v.end(), std::greater<int>()); // по убыванию
```

### **4.2 `std::stable_sort` — стабильная сортировка**  
Сохраняет порядок равных элементов.  
```cpp
std::stable_sort(v.begin(), v.end());
```

### **4.3 `std::binary_search` — бинарный поиск**  
```cpp
bool found = std::binary_search(v.begin(), v.end(), 3); // true
```

### **4.4 `std::lower_bound` и `std::upper_bound`**  
```cpp
auto low = std::lower_bound(v.begin(), v.end(), 3); // первое число ≥ 3
auto up = std::upper_bound(v.begin(), v.end(), 3);  // первое число > 3
```

### **4.5 `std::merge` — слияние двух отсортированных массивов**  
```cpp
std::vector<int> v1 = {1, 3, 5};
std::vector<int> v2 = {2, 4, 6};
std::vector<int> merged(6);
std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), merged.begin()); // {1, 2, 3, 4, 5, 6}
```

---

## 🔹 **5. Численные алгоритмы**  
### **5.1 `std::accumulate` — сумма элементов**  
```cpp
int sum = std::accumulate(v.begin(), v.end(), 0); // 15
```

### **5.2 `std::inner_product` — скалярное произведение**  
```cpp
int dot = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0); // 1*2 + 3*4 + 5*6 = 44
```

### **5.3 `std::partial_sum` — частичные суммы**  
```cpp
std::vector<int> out(3);
std::partial_sum(v1.begin(), v1.end(), out.begin()); // out = {1, 4, 9}
```

### **5.4 `std::adjacent_difference` — разность соседей**  
```cpp
std::adjacent_difference(v1.begin(), v1.end(), out.begin()); // out = {1, 2, 2}
```

---

## 🔹 **6. Работа с кучей (heap)**  
### **6.1 `std::make_heap` — создание кучи**  
```cpp
std::make_heap(v.begin(), v.end()); // превращает вектор в кучу
```

### **6.2 `std::push_heap` и `std::pop_heap`**  
```cpp
v.push_back(6);
std::push_heap(v.begin(), v.end()); // добавляет элемент в кучу

std::pop_heap(v.begin(), v.end()); // перемещает максимум в конец
v.pop_back(); // удаляет последний элемент
```

---

## 🔹 **7. Минимум и максимум**  
### **7.1 `std::min_element` и `std::max_element`**  
```cpp
auto min_it = std::min_element(v.begin(), v.end()); // итератор на минимум
auto max_it = std::max_element(v.begin(), v.end()); // итератор на максимум
```

### **7.2 `std::minmax_element`**  
```cpp
auto [min_it, max_it] = std::minmax_element(v.begin(), v.end());
```

---

## 🔹 **8. Генерация и перестановки**  
### **8.1 `std::generate` — заполнение с помощью функции**  
```cpp
std::vector<int> nums(5);
std::generate(nums.begin(), nums.end(), []() { return rand() % 10; }); // случайные числа
```

### **8.2 `std::next_permutation` — следующая перестановка**  
```cpp
std::string s = "abc";
do {
    std::cout << s << " "; // abc acb bac bca cab cba
} while (std::next_permutation(s.begin(), s.end()));
```

---

## 🔹 **9. Полезные лайфхаки**  
### **9.1 Удаление дубликатов после сортировки**  
```cpp
std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());
```

### **9.2 Быстрая проверка на отсортированность**  
```cpp
bool is_sorted = std::is_sorted(v.begin(), v.end());
```

### **9.3 Поиск первого несовпадения**  
```cpp
auto mismatch_pair = std::mismatch(v1.begin(), v1.end(), v2.begin());
```

---

## 🔹 **10. Итог**  
- `<algorithm>` содержит **более 100 алгоритмов** для работы с данными.  
- Основные группы: **поиск, сортировка, модификация, численные операции**.  
- Чаще всего используются:  
  - `std::sort`, `std::find`, `std::copy`, `std::accumulate`, `std::unique`.  
- **Лямбда-функции** делают алгоритмы гибкими.  

Если освоишь `<algorithm>`, сможешь писать код **короче, быстрее и безопаснее**! 🚀
