//
// Created by vova3 on 29.11.2024.
//

#ifndef LABS_2_COURS_MYVECTOR_H
#define LABS_2_COURS_MYVECTOR_H
#include <stdexcept>
#include <algorithm>
#include <vector>

template <typename T>
class MyVector {
    T* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:

class Iterator {
        T* ptr;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(T* p);

        T& operator*();
        Iterator& operator++();

        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        bool operator<(const Iterator& other) const;
        bool operator>(const Iterator& other) const;
        bool operator<=(const Iterator& other) const;
        bool operator>=(const Iterator& other) const;

        Iterator operator+(int d);
        Iterator operator-(int d);
        int operator-(const Iterator& other);

        T* operator->() { return ptr; }
        const T* operator->() const { return ptr; }

        Iterator operator--() { return Iterator(--ptr); }
        const Iterator operator++(int) { return Iterator(ptr++); }
        const Iterator operator--(int) { return Iterator(ptr--); }
    };

    Iterator begin();
    Iterator end();

    MyVector();
    MyVector(const MyVector<T>& other);
    MyVector(MyVector<T>&& other) noexcept;
    MyVector& operator=(const MyVector<T>& other);
    MyVector& operator=(MyVector<T>&& other) noexcept;
    ~MyVector();

    void push_back(const T& value);
    void pop_back();
    size_t get_size() const;
    bool is_empty();
    void remove_at(size_t index);
    void remove(const T& value);
    std::vector<T> toStdVector() const;
    void fromStdVector(const std::vector<T>& vec);

    template<typename Predicate>
    MyVector<T> find(Predicate pred);

    template <typename Comparator>
    void sort(Comparator comp);

    T& operator[](size_t index);
};

template<typename T>
void MyVector<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size; ++i)
        new_data[i] = data[i];
    delete [] data;
    data = new_data;
    capacity = new_capacity;
}

template<typename T>
MyVector<T>::Iterator::Iterator(T *p) : ptr(p) {};

template<typename T>
T &MyVector<T>::Iterator::operator*() {
    return *ptr;
}

template<typename T>
MyVector<T>::Iterator &MyVector<T>::Iterator::operator++() {
    ++ptr;
    return *this;
}

template<typename T>
bool MyVector<T>::Iterator::operator!=(const MyVector::Iterator &other) const {
    return ptr != other.ptr;
}

template<typename T>
bool MyVector<T>::Iterator::operator==(const MyVector::Iterator &other) const {
    return ptr == other.ptr;
}

template<typename T>
bool MyVector<T>::Iterator::operator<(const MyVector::Iterator &other) const {
    return ptr < other.ptr;
}

template<typename T>
bool MyVector<T>::Iterator::operator>(const MyVector<T>::Iterator &other) const {
    return ptr > other.ptr;
}

template<typename T>
bool MyVector<T>::Iterator::operator<=(const MyVector::Iterator &other) const {
    return ptr <= other.ptr;
}

template<typename T>
bool MyVector<T>::Iterator::operator>=(const MyVector::Iterator &other) const {
    return ptr >= other.ptr;
}

template<typename T>
MyVector<T>::Iterator MyVector<T>::Iterator::operator+(int d) {
    return Iterator(ptr + d);
}

template<typename T>
MyVector<T>::Iterator MyVector<T>::Iterator::operator-(int d) {
    return Iterator(ptr - d);
}

template<typename T>
int MyVector<T>::Iterator::operator-(const Iterator& other) {
    return ptr - other.ptr;
}

template<typename T>
MyVector<T>::MyVector() : data(nullptr), capacity(0), size(0) {};

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other) : data(nullptr), capacity(0), size(0) {
    resize(other.size);
    for (size_t i = 0; i < other.size; ++i)
        data[i] = other.data[i];
    size = other.size;
}

template<typename T>
MyVector<T>::MyVector(MyVector<T>&& other) noexcept : data(other.data), capacity(other.capacity),
                                                      size(other.size) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other) {
    if (this != &other) {
        delete [] data;
        data = nullptr;
        resize(other.size);
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
        size = other.size;
    }

    return *this;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other) noexcept {
    if (this != &other) {
        delete [] data;
        data = other.data;
        capacity = other.capacity;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    return *this;
}

template<typename T>
MyVector<T>::~MyVector() {
    delete [] data;
}

template<typename T>
void MyVector<T>::push_back(const T &value) {
    if (size >= capacity) {
        // Увеличение емкости
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = std::move(data[i]); // Используйте std::move если T поддерживает перемещение
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[size++] = value; // Добавляем новый элемент
}

template<typename T>
void MyVector<T>::pop_back() {
    if (size > 0)
        --size;
    else
        throw std::out_of_range("Vector is empty");
}

template<typename T>
T &MyVector<T>::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
size_t MyVector<T>::get_size() const {
    return size;
}

template<typename T>
bool MyVector<T>::is_empty() {
    return size == 0;
}

template<typename T>
MyVector<T>::Iterator MyVector<T>::begin() {
    return Iterator(data);
}

template<typename T>
MyVector<T>::Iterator MyVector<T>::end() {
    return Iterator(data + size);
}

template<typename T>
void MyVector<T>::remove_at(size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");

    for (size_t i = index; i < size; ++i)
        data[i] = data[i + 1];

    --size;
}

template<typename T>
void MyVector<T>::remove(const T &value) {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) {
            for (size_t j = i; j < size - 1; ++j) {
                data[j] = data[j + 1];
            }
            --size;
            data[size] = T();
            return;
        }
    }
    throw std::runtime_error("Element not found");
}

template<typename T>
std::vector<T> MyVector<T>::toStdVector() const {
    return std::vector<T>(data, data + size);
}

template<typename T>
void MyVector<T>::fromStdVector(const std::vector<T> &vec) {
    size = vec.size();
    capacity = size;
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i)
        data[i] = std::move(vec[i]);
}

template<typename T>
template<typename Predicate>
MyVector<T> MyVector<T>::find(Predicate pred) {

    MyVector<T> vector_result;

    for (size_t i = 0; i < size; ++i) {
        if (find(data[i]))
            vector_result.push_back(data[i]);
    }

    return vector_result;
}

template<typename T>
template <typename Comparator>
void MyVector<T>::sort(Comparator comp) {
    std::sort(begin(), end(), comp);
}

#endif //LABS_2_COURS_MYVECTOR_H
