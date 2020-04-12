//
// Created by mauri on 09-Apr-20.
//

#include "List.h"
namespace linkedLists {
    template<typename T>
    class LinkedList : protected List<T> {
    protected:
        Node<T> * tail;
    public:
        LinkedList(List<T> const &list) : List<T>(list) {
        }

        LinkedList(T *t) : List<T>(t) {

        }

        LinkedList(Node<T> *node) : List<T>(node) {

        }

        LinkedList(int i) : List<T>(i) {
        }

        LinkedList() : List<T>() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        ~LinkedList() override {
            clear();
        }

        T front() override {
            return this->head->value;
        }

        T back() override {
            return this->tail->value;
        }

        void push_back(const T &element) override {
            if (empty()) {
                this->head = new Node<T>;
                this->head->value = element;
                this->head->next = nullptr;
                this->tail = this->head;
                this->tail->next = nullptr;
            } else {
                auto *ptr = new Node<T>;
                ptr->value = element;
                this->tail->next = ptr;
                this->tail = ptr;
                this->tail->next = nullptr;
            }
        }

        void push_front(const T &element) override {
            if (empty()) {
                this->head = new Node<T>;
                this->head->value = element;
                this->head->next = nullptr;
                this->tail = this->head;
                this->tail->next = nullptr;
            } else {
                auto *node = new Node<T>;
                node->value = element;
                node->next = this->head;
                this->head = node;
            }
        }

        T pop_back() override {
            T temp = this->tail->value;
            auto ptr = this->head;
            for (int i = 0; i < this->size() - 2; i++)
                ptr = ptr -> next;
            this->tail = ptr;
            ptr = ptr->next;
            delete ptr;
            this->tail->next = nullptr;
            return temp;
        }

        T pop_front() override {
            T temp = this->head->value;
            auto *ptr = this->head->next;
            delete this->head;
            this->head = ptr;
            return temp;
        }

        T &operator[](const int &i) override {
            auto *ptr = this->head;
            for (int j = 0; j < i; j++)
                ptr = ptr->next;
            return ptr->value;
        }

        bool empty() override {
            return (this->head == nullptr && this->tail == nullptr);
        }

        unsigned int size() override {
            if (empty())
                return 0;
            else {
                int count = 0;
                auto *ptr = this->head;
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
            auto ptr = this -> head;
            int count = 0;
            while (ptr != nullptr) {
                auto ptr2 = this -> head;
                if (ptr -> value == t) {
                    if (ptr == this -> head) {
                        pop_front();
                        ptr = this -> head;
                    }
                    if (ptr == this -> tail) {
                        pop_back();
                        break;
                    }
                    else{
                        for (int i = 0; i < count - 1; i++) {
                            ptr2 = ptr2 -> next;
                        }
                       ptr2 -> next = ptr -> next;
                       delete ptr;
                       ptr = ptr2;
                    }
                }
                count+=1;
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