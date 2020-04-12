//
// Created by mauri on 10-Apr-20.
//

#include "List.h"
namespace linkedLists {
    template<typename T>
    class circleLinkedList : protected List<T> {
    protected:
        Node<T> *head;
        doublyNode<T> *tail;
    public:
        circleLinkedList(circleLinkedList<T> const &list) : circleLinkedList<T>(list) {
        }

        circleLinkedList(T *t) : List<T>(t) {

        }

        circleLinkedList(Node<T> *node) : List<T>(node) {

        }

        circleLinkedList(int i) : List<T>(i) {
        }

        circleLinkedList() : List<T>() {
            head = nullptr;
            tail = nullptr;
        }

        ~circleLinkedList() override {
            clear();
        }

        T front() override {
            return head -> value;
        }

        T back() override {
            return tail -> value;
        }

        void push_back(const T &element) override {
            if (empty()) {
                head = new doublyNode<T>;
                head->value = element;
                head->next = nullptr;
                head -> back = nullptr;
                tail = head;
                tail->next = nullptr;
                tail -> back = nullptr;
            } else {
                auto *ptr = new doublyNode<T>;
                ptr->value = element;
                tail -> next = ptr;
                auto it = tail;
                tail = ptr;
                tail -> next = nullptr;
                tail -> back = it;
            }
        }

        void push_front(const T &element) override {
            if (empty()) {
                head = new doublyNode<T>;
                head -> value = element;
                head -> next = nullptr;
                head -> back = nullptr;
                tail = head;
                tail -> next = nullptr;
                tail -> back = nullptr;
            } else {
                auto *node = new doublyNode<T>;
                node -> value = element;
                node -> next = head;
                node -> back = nullptr;
                head = node;
            }
        }

        T pop_back() override {
            T temp = tail -> value;
            auto ptr =tail;
            tail = tail -> back;
            delete ptr;
            tail -> next = nullptr;
            return temp;
        }

        T pop_front() override {
            T temp = head -> value;
            auto *ptr = head;
            head = head -> next;
            delete ptr;
            head -> back = nullptr;
            return temp;
        }

        T &operator[](const int &i) override {
            auto *ptr = this -> head;
            for (int j = 0; j < i; j++)
                ptr = ptr->next;
            return ptr->value;
        }

        bool empty() override {
            return (head == nullptr && tail == nullptr);
        }

        unsigned int size() override {
            if (empty())
                return 0;
            else {
                int count = 0;
                auto *ptr = head;
                while (ptr != nullptr) {
                    count += 1;
                    ptr = ptr->next;
                }
                return count;
            }
        }

        void clear() override {
            auto *ptr = this->head;
            auto *ptr1 = this->head;
            while (ptr != nullptr) {
                ptr1 = ptr1->next;
                delete ptr;
                ptr = ptr1;
            }
            this->head = nullptr;
            this->tail = nullptr;
        }

        void erase(Node<T> *node) override {

        }

        void insert(Node<T> *node, const T &t) override {

        }

        void remove(const T &t) override {
            auto ptr = head;
            while (ptr != nullptr) {
                if (ptr -> value == t ) {
                    if (ptr -> back != NULL){
                        ptr -> back -> next = ptr -> next;
                        ptr -> next -> back = ptr -> back;
                    }
                    else
                        pop_front();
                }
                ptr = ptr -> next;
            }
        }

        /* List<T> &sort(void) {
             return this;
         }

         List<T> &reverse(void) {
             return this;
         }

         template<typename __T>
         std::ostream &operator<<(std::ostream &, const List<__T> &) {
             return <#initializer#>;*/

    };
}