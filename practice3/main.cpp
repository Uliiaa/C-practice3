#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

void print_vector(std::vector<int> vec) // функция, которая выводит элементы вектора
{
    for (int v : vec)
    {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    //compound types (сложные типы)
    // "abc\0" так выглядит строка, ее последний символ всегда '\0', поэтому 
    // в данном случае операция str[3] - валидна
    std::string str = "abc";
    // std::string
    std::cout << str << std::endl;
    // char
    std::cout << str[0] << std::endl;

    std::string strSecond;
    // складываем две строки (получается еще одна строка) и записываем в strSecond
    strSecond = strSecond + str; // extra copy
    // прибавляем к strSecond str
    strSecond += str; // non extra copy, более эффективно

    // так как строка - это массив, есть функции push-добавить и pop-удалить
    strSecond.push_back('H');
    std::cout << strSecond << std::endl; // abcabcH

    strSecond.pop_back(); // не принимает аргументов, потому что просто удаляет один символ с конца
    std::cout << strSecond << std::endl; // abcabc

    strSecond.insert(0, "Hello, World!"); // insert с iтого символа добавляет в строку подстроку
    std::cout << strSecond << std::endl; // Hello, World!abcabc

    // откусывет от строки кусочек и возвращает строку без кусочка
    strSecond.erase(0, 5);
    std::cout << strSecond << std::endl;

    std::cout << strSecond.front() << std::endl; // возвращает начальный символ строки
    std::cout << strSecond.back() << std::endl; // возвращает последний символ строки (не нультерминированный)
    std::cout << strSecond.size() << std::endl; // возвращает длину строки

    // std::vector - динамический массив, самый ходовой контейнер, хранит любые типы
    std::vector<int> vec {1, 2, 3}; // синтаксический сахар, но используем осторожно, чтобы код выглядел
    // адекватно, кладем в вектор 1, 2, 3

    //std::cout << vec[2] << vec[3] << std::endl; // UB-индекс вышел за границу
    //std::cout << vec[2] << vec.at(3) << std::endl; // метод-проверка на out of range

    // old school for
    // выводим все элементы вектора через пробел
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;

    // new school since C++ 11
    // v - element
    // более предпочтительный вариант, к тому же есть контейнеры без индексации
    for (int v : vec)
    {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    vec.push_back(5);
    std::cout << vec.front() << " " << vec.back() << std::endl;

    vec.pop_back();
    std::cout << vec.front() << " " << vec.back() << std::endl;

    std::cout << vec.size() << std::endl;

    // мы можем задать размер вектору, если изначально знаем, сколько элементов хотим в него положить
    //vec.resize(4); теперь в векторе 4 места
    
    vec.clear(); // удалит все элементы из вектора, очистит его
    std::cout << vec.size() << std::endl; // 0

    std::vector<int> vecSecond = vec; // создали копию вектора, если делаем что-то с vecSize, то оригинальный
    // вектор меняться не будет
    vecSecond.push_back(0); // 0

    // std::array
    std::array<int, 5> arr {1, 2, 3, 4, 5};
    // std::cout << arr[0] << arr[5] << std::endl; // UB out of range
    // std::cout << arr[0] << arr.at[5] << std::endl; // подстелили соломку
    std::cout << arr.front() << ' ' << arr.back() << std::endl; // 1 5


    // while
    // есть break, continue
    size_t idx = 0;
    while (idx != arr.size())
    {
        std::cout << arr[idx] << std::endl;
        ++idx;
    }

    // std::map - словарь, где есть ключ и значение
    std::map<size_t, std::string> dict {{1, "Abc"}, {2, "Bcd"}};
    // Since C++ 14 [key, value]
    // удобный вывод ключей и значений словаря
    for (auto [key, value] : dict)
    {
        std::cout << key << " " << value << std::endl;
    }

    // if 
    int var = 5;
    if (var == 5)
    {
        std::cout << var << std::endl;
    }

    // можно проще
    if (int var = 5; var == 5)
    {
        std::cout << var << std::endl;
    }
}