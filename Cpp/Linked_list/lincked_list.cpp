 #include <iostream>
#include <vector>
class Node{
    Node *next;
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

//удаляет все узлы с данным значением
    static void deleteNode(Node* &head, int data_){
        while ( head!=nullptr && head->data == data_){
            Node *temp = head->next;
            delete head;
            head = temp;
        }
        if (head==nullptr){
            return;
        }
        Node *newHead = head;
        while(newHead->next!=nullptr){
            if (newHead->next->data == data_){
                Node *temp = newHead->next->next;
                delete newHead->next;
                newHead->next = temp;
            }else{
                newHead = newHead->next;
            }
        }
    }
    
    static int sizeList(Node *head){
        int i = 0;
        for (i; head->next!=nullptr; i++){
        head = head->next;
        }
        i++;
        return i;
    }
    //удаляет повторы
    //static void deleteRepeats(Node* &head){
    //    std::vector<int> v1(si);
    //}
    
    void print(){
        std::cout<<"Односвязный список: "<<std::endl;
        if (this == nullptr){
            std::cout<<"Список пуст"<<std::endl;
            return;
        }
        Node* current = this;
        while (current->next!=nullptr){
            std::cout<< current->getData()<< " ";
            current = current->next;
        }  
        std::cout<< current->getData()<< " "<< std::endl;    
    }
};

int main(){
    Node *head = new Node(2);   
    head->append(2);
    head->append(1);
    head->append(3);
    head->append(1);
    head->append(1);
    head->print();
    std::cout<<"Длина списка: "<<Node::sizeList(head)<<std::endl;
    int i = 1;
    Node::deleteNode(head, i);
    std::cout<<"Удаляем узел "<<i<<std::endl;
    head->print();
    return 0;
};
