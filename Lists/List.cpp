//
// Created by mauri on 14-Apr-20.
//
#pragma once

#include "../List.h"
#include "../Iterator.h"
namespace cs2100_singly {
    template<typename T>
    class linkedList : protected List<T> {
    protected:
        typedef Node<T> Node;
        typedef List<T> List;
        Node *tail;
        unsigned int len;
    public:
        typedef iterator<T> iterator;

        linkedList(List const &list) : List(list) {
            if (list.size() > 0) {
                auto ptr = this->head;
                for (auto it = list.begin(); it < list.end(); it++) {
                    ptr->value = *it;
                    ptr = ptr->next;
                    len++;
                }
            }
        }

        linkedList(Node *node) : List(node) {
            this->head = node;
            this->tail = node;
            this->len = 1;
        }

        linkedList() : List() {
            this->head = nullptr;
            tail = nullptr;
            len = 0;
        }

        ~linkedList() override {
            clear();
        }

        T front() override {
            if (!empty())
                return this->head->value;
        }

        T back() override {
            if (!empty())
                return tail->value;
        }

        void push_back(const T &element) override {
            if (empty()) {
                this->head = new Node{element, nullptr};
                tail = this->head;
            } else {
                tail->next = new Node{element, nullptr};
                tail = tail->next;
            }
            this->len += 1;
        }

        void push_front(const T &element) override {
            if (empty()) {
                this->head = new Node{element, nullptr};
                tail = this->head;
            } else {
                auto *node = new Node{element, this->head};
                this->head = node;
            }
            this->len += 1;
        }

        T pop_back() override {
            if (!empty()) {
                auto ptr = this->head;
                if (this->head == tail) {
                    this->head = nullptr;
                    this->tail = nullptr;
                    delete ptr;
                    this->len -= 1;
                    return ptr->value;
                } else {
                    while (ptr->next != tail)
                        ptr = ptr->next;
                    auto ret = tail->value;
                    delete tail;
                    tail = ptr;
                    tail->next = nullptr;
                    this->len -= 1;
                    return ret;
                }
            }
        }


        T pop_front() override {
            if (!empty()) {
                auto ret = this->head;
                if (this->head == tail)
                    this->tail = nullptr;
                this->head = this->head->next;
                delete ret;
                this->len -= 1;
                return ret->value;
            }
        }

        T &operator[](const int &i) override {
            if (!empty()) {
                auto ptr = this->head;
                for (auto j = 0; j < i; j++)
                    ptr = ptr->next;
                return ptr->value;
            }
        }

        bool empty() override {
            return (this->head == nullptr && this->tail == nullptr);;
        }

        unsigned int size() override {
            return len;
        }

        void clear() override {
            auto ptr = this->head;
            while (this->head != nullptr) {
                this->head = this->head->next;
                delete ptr;
                ptr = this->head;
            }
            this->head = nullptr;
            this->tail = nullptr;
            this->len = 0;
        }

        void erase(Node *node)  {
            if (!empty()) {
                auto ptr = this->head;
                while (ptr != nullptr) {
                    if (ptr->next == node) {
                        auto temp = ptr->next;
                        ptr->next = temp->next;
                        delete temp;
                        break;
                    }
                    ptr = ptr->next;
                }
            }
        }

        void insert(Node *node, const T &t)  {
            if (!empty()) {
                auto ptr = this->head;
                while (ptr != nullptr) {
                    if (ptr->next == node) {
                        ptr->next->value = t;
                        break;
                    }
                    ptr = ptr->next;
                }
            }
        }

        void remove(const T &t) override {
            if (!empty()) {
                auto ptr = new Node{0, this->head};
                while (ptr->next != nullptr) {
                    if (ptr->next->value == t) {
                        auto temp = ptr->next;
                        if (ptr->next == this->head)
                            this->head = temp->next;
                        if (ptr->next == this->tail){
                            this->tail = ptr;
                            this-> tail -> next = nullptr;
                            delete temp;
                            break;
                        }
                        ptr->next = temp->next;
                        delete temp;
                        len -= 1;
                    }
                    else
                        ptr = ptr->next;
                }
            }
        }

        void swap(Node *first, Node *second) {
            auto temp = first->value;
            first->value = second->value;
            second->value = temp;
        }

        void sort() override {
            if (!empty()) {
                Node *ptr;
                for (auto i = 0; i < this->len; i++) {
                    ptr = this->head;
                    for (auto j = 0; j < this->len - i - 1; j++) {
                        if (ptr->value > ptr->next->value)
                            swap(ptr, ptr->next);
                        ptr = ptr->next;
                    }
                }
            }
        }

        iterator begin() {
            return iterator(this->head);
        }

        iterator end() {
            return iterator(nullptr);
        }

        friend std::ostream &operator<<(std::ostream &os, const linkedList &linkedList) {
            Node *ptr = linkedList.head;
            os << "lista: ";
            while (ptr != nullptr) {
                os << ptr->value << " ";
                ptr = ptr->next;
            }
            return os;
        }
    };
}