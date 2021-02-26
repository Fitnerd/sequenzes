#include <iostream>

class my_string {
        public:
                bool is_equal(const char* c);

                char* s;
};

class sequenz {
        public:
                sequenz(const my_list<int>& l, const my_string& s) : ml(l), string(s) {};

                bool is_equal(const sequenz& seq) const {
                        if(ml.size() != seq.size()) {
                                return false;
                        }

                        for(unsigned int i = 0; i < ml.size(); ++i) {
                                if(ml[i] != seq[i]) {
                                        return false;
                                }
                        }
                        return true;
                };

                const my_list<int>& getMyList() const {
                        return ml;
                };

                void print(); //here??

                my_list<int> ml;
                my_string string;
};

template<class T>
class my_list {
        class Node {
                public:
                        Node(T& d, Node* n) : data(d), next(n) {};

                        T data;
                        Node* next;
        };

        public:
                my_list() : root(nullptr), m_size(0) {};
                virtual ~my_list() { delete[] root };

                void push_back(T element) {
                        ++m_size;
                        if(!root) {
                                root = new Node(element, nullptr);
                        } else {
                                Node* tmp = root;
                                while(tmp->next) {
                                        tmp = tmp->next;
                                }
                                tmp = new Node(element, nullptr);
                        }
                };

                unsigned int size() { return m_size; };

        private:
                Node<T>* root;
                unsigned int m_size;
};

class seq_list : public my_list<sequenz> {
        public:
                const my_list<seuqenz>& search(const sequenze& element) {
                        Node* tmp = root;
                        while(tmp) {
                                if(tmp->data.is_euqal(element) {
                                        break;
                                }
                                tmp = tmp->next;
                        }

                        my_list<sequenz> ls;
                        Node* tmps = root;
                        while(tmps) {
                                if(tmps->data.string.is_equal(tmp->data.string.s) {
                                        ls.push_back(tmps->data);
                                }
                        }
                        return ls:
                }
};


int main() {
        int mode = 0;
        int i = 0;
        seq_list<sequenz> sequenzes;
        my_list<int> int_list;
        char* s = new char[1024];

        std::cin >> mode;
        if(mode == 1 | mode == 2 | mode == 3) {
                while(std::cin >> i) {
                        if(i > -1) {
                                int_list.push_back(i);
                        } else {
                                break;
                        }
                }
                switch(mode) {
                        case 1:
                                std::cin >> s; //length of s???
                                sequenzes.push_back(new sequenz(int_list, s));
                        case 2:
                                my_list<sequenze> found_seq = sequenzes.search(int_list);
                                if(found_seq.size() > 0) {
                                        print(found_seq);
                                }
                        case 3:
                        default:
                                break;
                }
        }
        delete s;
}
