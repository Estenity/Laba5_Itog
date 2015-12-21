#pragma once

#include <cstddef>           // size_t
#include <initializer_list>  // std::initializer_list<T>
#include <iosfwd>            // std::ostream

typedef double Data;

class LinkedList
{
    // Ќеоб€зательно, нужно дл€ "copy & swap", если вы помните, что это.
    friend void swap(LinkedList& left, LinkedList& right);

    // ѕолезно дл€ отладки, об€зательно.
    friend std::ostream& operator<<(std::ostream& output, const LinkedList& xs);

public:
    LinkedList();
    LinkedList(const std::initializer_list<Data> values);

    LinkedList(const LinkedList& source);
    LinkedList& operator=(LinkedList rhs);

    LinkedList(LinkedList&& source);
    LinkedList& operator=(LinkedList&& rhs);

    virtual ~LinkedList();

public:
    size_t size() const;

    void push_back(const Data& value);
    void push_front(const Data& value);
    void pop_back();
    void pop_front();

    // ѕри некорректном индексе должны возбужадать std::out_of_range.
    void remove_at(size_t index);
    void insert_before(size_t index, const Data& value);
    void insert_after(size_t index, const Data& value);
    Data& value_at(size_t index);

    bool operator==(const LinkedList& other) const;
    bool operator!=(const LinkedList& other) const;

private:

    struct Node
    {
        double value;
        Node* previous;
        Node* next;
    };


private:
    // ¬озвращает указатель на узел с заданным индексом.
    Node* node_at(size_t index);

    // —оздают и добавл€ют в список узел до (после) указанного.
    // ≈сли указанный --- nullptr, добавл€ют узел в начало (в конец).
    Node* insert_before(Node* before);
    Node* insert_after(Node* after);

    // ”дал€ет узел по указателю на него.
    void erase(const Node* node);
    void clear();

private:

    Node* first;
    Node* last;
    size_t size_;
};
