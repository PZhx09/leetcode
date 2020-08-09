#include<iostream>
#include<map>
using namespace std;

//LRU  最近最少使用
//借用map来实现  get能够达到O(1)
//put的溢出机制要不然使用一个队列？但是这样的话get每次都要更新队列，find+erase  时间复杂度就成了O(n)
//put也是操作，意思就是put也会修改更新队列，get和put的时间复杂度都是O(n)

//先用自己的方法做一遍
//测试用例17/18   暴力方法超出时间限制
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


//算是不小心看到题解了，那么就直接按照看的思路写写把
//为了get的速度O(1),肯定要有一个哈希表   同时还要有一个数据结构来维护更新队列
//我上面想的是队列，但是队列搜索和删除都是O(n)  很烦，使用双向链表就行了(查找利用hash，删除插到末尾就行了，显然O(1))

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
    myNode* front;//永远指向双向链表首部
    myNode* back;//永远指向双向链表尾部
    map<int, myNode*> data;//通过key索引到节点哦
    int capacity;
public:
    LRUCache(int capacity) {
        //初始化变量
        //为了编写时方便，front和back设置为哨兵节点好了(删除结点的时候，不需要考虑空的问题)
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
        //把current给挪到队列尾部，表示是最近使用的
        myNode* current = data[key];
        if (current->next != back)
        {
            //删除
            deleteNode(current);

            //插入
            pushNode(current);
        }
        return current->val;


    }

    void put(int key, int value) {
        //插入   修改数据，更新队列，如果溢出，还要考虑删除
        if (data.find(key) != data.end())
        {
            //已经有key了
            myNode* current = data[key];
            current->val = value;
            deleteNode(current);
            pushNode(current);
        }
        else
        {
            //没有key 需要添加
            if (data.size() == capacity)
            {
                //满了
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
    cache.put(2,3);       // 返回  1
    cache.put(4, 1);    // 该操作会使得密钥 2 作废
    cache.get(1);       // 返回 -1 (未找到)
    //cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4

}*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */