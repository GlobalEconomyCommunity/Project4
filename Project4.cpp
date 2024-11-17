#include <iostream>

template <typename T>
class Node {
public:
    T data;          // Данные узла
    Node* next;     // Указатель на следующий узел

    Node(T val) : data(val), next(nullptr) {} // Конструктор
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Указатель на первый узел
    Node<T>* tail;  // Указатель на последний узел

public:
    LinkedList() : head(nullptr), tail(nullptr) {} // Конструктор

    // Метод добавления элемента в конец списка
    void add(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Метод удаления элемента по значению
    bool remove(T val) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current != nullptr) {
            if (current->data == val) {
                if (previous == nullptr) {
                    head = current->next; // Удаляем первый узел
                }
                else {
                    previous->next = current->next; // Удаляем узел в середине или в конце
                }
                if (current == tail) {
                    tail = previous; // Если удаляем последний узел
                }
                delete current; // Освобождаем память
                return true; // Элемент был найден и удален
            }
            previous = current;
            current = current->next;
        }
        return false; // Элемент не найден
    }

    // Метод поиска элемента по значению
    Node<T>* find(T val) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return current; // Элемент найден
            }
            current = current->next;
        }
        return nullptr; // Элемент не найден
    }

    // Метод вывода всех элементов списка
    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl; // Конец списка
    }

    // Деструктор для освобождения памяти
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Пример использования
int main() {
    LinkedList<int> list;

    // Добавление элементов
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    // Вывод всех элементов списка
    std::cout << "Содержимое списка: ";
    list.printList();

    // Поиск элемента
    int searchValue = 3;
    Node<int>* foundNode = list.find(searchValue);
    if (foundNode) {
        std::cout << "Элемент " << searchValue << " найден." << std::endl;
    }
    else {
        std::cout << "Элемент " << searchValue << " не найден." << std::endl;
    }

    // Удаление элемента
    int removeValue = 2;
    if (list.remove(removeValue)) {
        std::cout << "Элемент " << removeValue << " удален." << std::endl;
    }
    else {
        std::cout << "Элемент " << removeValue << " не найден для удаления." << std::endl;
    }

    // Вывод всех элементов списка после удаления
    std::cout << "Содержимое списка после удаления: ";
    list.printList();

    return 0;
}