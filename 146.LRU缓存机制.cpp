#include<iostream>
#include<map>
using namespace std;

//LRU  �������ʹ��
//����map��ʵ��  get�ܹ��ﵽO(1)
//put���������Ҫ��Ȼʹ��һ�����У����������Ļ�getÿ�ζ�Ҫ���¶��У�find+erase  ʱ�临�ӶȾͳ���O(n)
//putҲ�ǲ�������˼����putҲ���޸ĸ��¶��У�get��put��ʱ�临�Ӷȶ���O(n)

//�����Լ��ķ�����һ��
//��������17/18   ������������ʱ������
/*class LRUCache {
    map<int, int> data;
    deque<int> seq;
    int capacity;
public:
    LRUCache(int capacity) {
        data = map<int, int>();
        seq = deque<int>();
        this->capacity = capacity;
    }

    int get(int key) {
        if (data.find(key) == data.end())
            return -1;
        int i = 0;
        for (; i < seq.size(); i++)
        {
            if (seq[i] == key)
                break;
        }
        seq.erase(seq.begin() + i);
        seq.push_back(key);
        

        return data[key];

    }

    void put(int key, int value) {
        if (data.find(key) != data.end())
        {
            int i = 0;
            for (; i < seq.size(); i++)
            {
                if (seq[i] == key)
                    break;
            }
            seq.erase(seq.begin() + i);
            seq.push_back(key);
            data[key] = value;
        }
        else
        {
            if (seq.size() == capacity)
            {
                data.erase(data.find(seq.front()));
                seq.pop_front();

            }
            data[key] = value;
            seq.push_back(key);
        }

    }
};*/


//���ǲ�С�Ŀ�������ˣ���ô��ֱ�Ӱ��տ���˼·дд��
//Ϊ��get���ٶ�O(1),�϶�Ҫ��һ����ϣ��   ͬʱ��Ҫ��һ�����ݽṹ��ά�����¶���
//����������Ƕ��У����Ƕ���������ɾ������O(n)  �ܷ���ʹ��˫�����������(��������hash��ɾ���嵽ĩβ�����ˣ���ȻO(1))

class LRUCache {
    class myNode
    {
    public:
        myNode(int k,int v) :key(k),val(v), previous(NULL), next(NULL){};
        int key;
        int val;
        myNode* previous;
        myNode* next;
    };
    myNode* front;//��Զָ��˫�������ײ�
    myNode* back;//��Զָ��˫������β��
    map<int, myNode*> data;//ͨ��key�������ڵ�Ŷ
    int capacity;
public:
    LRUCache(int capacity) {
        //��ʼ������
        //Ϊ�˱�дʱ���㣬front��back����Ϊ�ڱ��ڵ����(ɾ������ʱ�򣬲���Ҫ���ǿյ�����)
        front = new myNode(INT_MIN,INT_MIN);
        back = new myNode(INT_MAX,INT_MAX);
        front->next = back;
        back->previous = front;

        data = map<int, myNode*>();
        this->capacity = capacity;
    }

    int get(int key) {
        if (data.find(key) == data.end())
            return -1;
        //��current��Ų������β������ʾ�����ʹ�õ�
        myNode* current = data[key];
        if (current->next != back)
        {
            //ɾ��
            deleteNode(current);

            //����
            pushNode(current);
        }
        return current->val;


    }

    void put(int key, int value) {
        //����   �޸����ݣ����¶��У�����������Ҫ����ɾ��
        if (data.find(key) != data.end())
        {
            //�Ѿ���key��
            myNode* current = data[key];
            current->val = value;
            deleteNode(current);
            pushNode(current);
        }
        else
        {
            //û��key ��Ҫ���
            if (data.size() == capacity)
            {
                //����
                data.erase(data.find(front->next->key));
                deleteNode(front->next);

            }
             myNode* current = new myNode(key,value);
             data[key] = current;
             pushNode(current);

        }
    }

    void deleteNode(myNode* current)
    {
        current->previous->next = current->next;
        current->next->previous = current->previous;
    }
    void pushNode(myNode* current)
    {
        back->previous->next = current;
        current->previous = back->previous;
        back->previous = current;
        current->next = back;
    }


};


/*int main()
{
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2,3);       // ����  1
    cache.put(4, 1);    // �ò�����ʹ����Կ 2 ����
    cache.get(1);       // ���� -1 (δ�ҵ�)
    //cache.put(4, 4);    // �ò�����ʹ����Կ 1 ����
    cache.get(2);       // ���� -1 (δ�ҵ�)
    cache.get(3);       // ����  3
    cache.get(4);       // ����  4

}*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */