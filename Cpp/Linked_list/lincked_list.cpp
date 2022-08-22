 #include <iostream>

class Node{
    public: Node *next;
    int data;
    public:
    Node(int data_){
        data = data_;
        next = nullptr;
    }
    void append (int data_){
        Node* current = this;
        while (current->next!=nullptr){
            current = current->next;
        }
        current->next = new Node(data_);
    }
    int getData(){
        return this->data;
    }
    Node* getNext(){
        return this->next;
    }
    void print(){
        std::cout<<"Односвязный список: "<<std::endl;
        Node* current = this;
        while (current->next!=nullptr){
            std::cout<< current->getData()<< " ";
            current = current->next;
        }  
        std::cout<< current->getData()<< " "<< std::endl;    
    }
};



int main(){
    Node *node = new Node(1);
    node->append(2);
    node->append(3);
    node->print();
    return 0;
};
