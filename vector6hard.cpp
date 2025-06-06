
## **1. Что такое вектор?**  
**Вектор (`std::vector`)** — это динамический массив, который:  
- Может изменять свой размер во время выполнения программы.  
- Хранит элементы в непрерывной области памяти (как обычный массив).  
- Автоматически управляет памятью (не нужно вручную `new`/`delete`).  

Подключается так:  
```cpp
#include <vector>
```

---

## **2. Создание вектора**  
### **2.1 Пустой вектор**  
```cpp
std::vector<int> vec;  // пустой вектор (размер = 0)
```

### **2.2 С заданным размером**  
```cpp
std::vector<int> vec(10);  // вектор из 10 нулей: {0, 0, 0, ..., 0}
```

### **2.3 С размером и начальным значением**  
```cpp
std::vector<int> vec(5, 42);  // {42, 42, 42, 42, 42}
```

### **2.4 Копирование из другого вектора**  
```cpp
std::vector<int> vec1 = {1, 2, 3};
std::vector<int> vec2(vec1);  // vec2 = {1, 2, 3}
```

### **2.5 Из C-массива**  
```cpp
int arr[] = {4, 5, 6};
std::vector<int> vec(arr, arr + 3);  // vec = {4, 5, 6}
```

---

## **3. Основные операции**  
### **3.1 Добавление элементов**  
- `push_back()` – добавляет элемент в конец.  
```cpp
vec.push_back(7);  // {1, 2, 3} → {1, 2, 3, 7}
```
- `emplace_back()` – то же, но эффективнее для сложных объектов.  
```cpp
vec.emplace_back(8);  // {1, 2, 3, 7} → {1, 2, 3, 7, 8}
```
- `insert()` – вставляет элемент в любое место.  
```cpp
vec.insert(vec.begin() + 2, 99);  // {1, 2, 3, 7, 8} → {1, 2, 99, 3, 7, 8}
```

### **3.2 Удаление элементов**  
- `pop_back()` – удаляет последний элемент.  
```cpp
vec.pop_back();  // {1, 2, 99, 3, 7, 8} → {1, 2, 99, 3, 7}
```
- `erase()` – удаляет элемент(ы) по итератору.  
```cpp
vec.erase(vec.begin() + 2);  // {1, 2, 99, 3, 7} → {1, 2, 3, 7}
vec.erase(vec.begin() + 1, vec.begin() + 3);  // {1, 2, 3, 7} → {1, 7}
```
- `clear()` – полностью очищает вектор.  
```cpp
vec.clear();  // {}
```

### **3.3 Доступ к элементам**  
- `operator[]` – доступ по индексу (без проверки границ!).  
```cpp
int x = vec[0];  // первый элемент
vec[1] = 42;     // изменение второго элемента
```
- `at()` – доступ с проверкой границ (кидает `std::out_of_range`).  
```cpp
int y = vec.at(2);  // если выйдем за границы – исключение!
```
- `front()` и `back()` – первый и последний элементы.  
```cpp
int first = vec.front();  // = vec[0]
int last = vec.back();    // = vec[vec.size() - 1]
```

### **3.4 Размер и ёмкость**  
- `size()` – текущее количество элементов.  
```cpp
size_t s = vec.size();  // например, 3
```
- `capacity()` – сколько памяти выделено (≥ `size()`).  
```cpp
size_t cap = vec.capacity();  // например, 4
```
- `resize(new_size)` – изменяет размер.  
```cpp
vec.resize(5);  // если было {1, 2}, станет {1, 2, 0, 0, 0}
```
- `reserve(new_cap)` – резервирует память (уменьшает переаллокации).  
```cpp
vec.reserve(100);  // выделит память под 100 элементов
```
- `empty()` – проверяет, пуст ли вектор.  
```cpp
if (vec.empty()) { /* ... */ }
```

### **3.5 Итераторы**  
- `begin()` – итератор на начало.  
- `end()` – итератор на конец (элемент **после** последнего).  
```cpp
for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << " ";
}
```
- `rbegin()` / `rend()` – обратные итераторы (для обхода с конца).  

---

## **4. Многомерные векторы**  
### **4.1 Двумерный вектор (матрица)**  
```cpp
std::vector<std::vector<int>> matrix(3, std::vector<int>(4, 0));
// 3 строки, 4 столбца, заполнено нулями:
// {
//   {0, 0, 0, 0},
//   {0, 0, 0, 0},
//   {0, 0, 0, 0}
// }
```

### **4.2 Трёхмерный вектор (как в твоём коде)**  
```cpp
std::vector<std::vector<std::vector<bool>>> dp(
    N, 
    std::vector<std::vector<bool>>(
        W + 2, 
        std::vector<bool>(H + 2, false)
    )
);
// dp[i][x][y] – трёхмерный массив
```

---

## **5. Важные особенности**  
### **5.1 Скорость операций**  
| Операция       | Сложность       |
|---------------|----------------|
| `push_back()` | O(1) (амортизированная) |
| `pop_back()`  | O(1)           |
| `insert()`    | O(n)           |
| `erase()`     | O(n)           |
| `operator[]`  | O(1)           |
| `at()`        | O(1)           |

### **5.2 Переаллокация памяти**  
- Когда `size() == capacity()`, вектор выделяет **новый блок памяти** (обычно ×2) и копирует элементы.  
- Чтобы избежать частых переаллокаций, используйте `reserve()`.  

### **5.3 Вектор vs C-массив**  
| Вектор (`std::vector`)       | Обычный массив (`int[]`) |
|-----------------------------|-------------------------|
| Динамический размер         | Фиксированный размер    |
| Автоматическое управление памятью | Ручное управление (`new`/`delete`) |
| Есть проверка границ (`at()`) | Нет проверки границ |
| Медленнее для мелких массивов | Быстрее для мелких массивов |

---

## **6. Полезные методы**  
- `std::swap(vec1, vec2)` – обменять два вектора.  
- `vec.assign(n, value)` – перезаписать вектор.  
- `vec.shrink_to_fit()` – уменьшить `capacity()` до `size()`.  

---

## **7. Примеры использования**  
### **7.1 Сортировка вектора**  
```cpp
std::vector<int> nums = {5, 3, 1, 4, 2};
std::sort(nums.begin(), nums.end());  // {1, 2, 3, 4, 5}
```

### **7.2 Поиск элемента**  
```cpp
auto it = std::find(nums.begin(), nums.end(), 3);
if (it != nums.end()) {
    std::cout << "Найдено: " << *it;
}
```

### **7.3 Удаление дубликатов**  
```cpp
std::sort(nums.begin(), nums.end());
nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
```

---

## **8. Итог**  
- Вектор — это **гибкий аналог массива** с автоматическим управлением памятью.  
- Подходит для большинства задач, где нужен динамический размер.  
- **Основные методы**: `push_back()`, `pop_back()`, `insert()`, `erase()`, `operator[]`, `size()`.  
- **Многомерные векторы** полезны для матриц и 3D-структур (как в твоём коде).  

Если будешь активно использовать вектора, быстро привыкнешь к их синтаксису и возможностям! 🚀
