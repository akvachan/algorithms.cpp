#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

namespace ak_algos {

class DynamicArray {
public:
    // Constructor
    explicit DynamicArray(int capacity);

    // Destructor
    ~DynamicArray();

    // Copy Constructor
    DynamicArray(const DynamicArray& other);

    // Copy Assignment Operator
    DynamicArray& operator=(const DynamicArray& other);

    // Move Constructor
    DynamicArray(DynamicArray&& other) noexcept;

    // Move Assignment Operator
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    // Iterator Definitions
    using iterator = int*;
    using const_iterator = const int*;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    // Element Access
    int get(int i) const;
    void set(int i, int n);
    int& operator[](int i);
    const int& operator[](int i) const;

    // Modification
    void pushback(int n);
    int popback();
    void resize();

    // Size and Capacity
    int getSize() const;
    int getCapacity() const;

private:
    int _size;
    int _capacity;
    int* _array;
};

}
#endif // DYNAMICARRAY_H

