#include<iostream>

using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    //������ε�˼��ÿ�δ���k����Ȼ��ÿ����һ�𲻾�����
    //һ��ac����ǿ
    /*ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode* iterator = head;
        int group = 0;//ÿk����Ϊһ�飬group��¼���
        ListNode* lastGroupEnd = NULL;
        while (iterator != NULL)
        {
            ListNode* start = iterator;//�����ͷ
            int count = 1;
            while (count < k)
            {
                iterator = iterator->next;
                if (iterator == NULL)
                    break;
                else
                    count++;
                
            }
            if (count < k)
                return head;
            ListNode* end = iterator;
            if (lastGroupEnd != NULL)//�����startָ������end�����������ϵ��һ��    ������Կ��ǲ�ʹ�������ж�   �Լ���һ��ͷ�ڵ�Ϳ�����   group�����������Ҫ��
                lastGroupEnd->next = end;
            //��k���ڵ��γ�һ���ͷstart��βend���Ѿ��õ���
            iterator = end->next;//��¼��һ��Ŀ�ͷ

            
            group++;//�����¼group��ʵ����Ϊ��ȷ��ͷ�ڵ㣬��һ��֮�����������û������
            if (group == 1)
                head = end;
            //��ʼstart��end֮��ķ�ת
            ListNode* first = start;
            ListNode* second = start->next;
            ListNode* third = start->next->next;

            for (int i = 1; i < k; i++)
            {
                second->next = first;
                first = second;
                second = third;
                if(third!=NULL)
                    third = third->next;
                
            }
            start->next = iterator;//��һ���startӦ��ָ����һ���end�Ŷ�,������Ϊ�˷�ֹ��һ��û��end���õ�
            lastGroupEnd = start;
        }
        return head;
    }*/

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode* myHead = new ListNode(0);
        myHead->next = head;
        ListNode* iterator = head;
        ListNode* lastGroupEnd = myHead;
        while (iterator != NULL)
        {
            ListNode* start = iterator;//�����ͷ
            int count = 1;
            while (count < k)
            {
                iterator = iterator->next;
                if (iterator == NULL)
                    return myHead->next;
                else
                    count++;

            }
            ListNode* end = iterator;
            lastGroupEnd->next = end;
            //��k���ڵ��γ�һ���ͷstart��βend���Ѿ��õ���
            iterator = end->next;//��¼��һ��Ŀ�ͷ

            //��ʼstart��end֮��ķ�ת
            ListNode* first = start;
            ListNode* second = start->next;
            ListNode* third = start->next->next;

            for (int i = 1; i < k; i++)
            {
                second->next = first;
                first = second;
                second = third;
                if (third != NULL)
                    third = third->next;

            }
            start->next = iterator;//��һ���startӦ��ָ����һ���end�Ŷ�,������Ϊ�˷�ֹ��һ��û��end���õ�
            lastGroupEnd = start;
        }
        return myHead->next;
    }
};
/*int main()
{
    ListNode* test1 = new ListNode(1);
    ListNode* test2 = new ListNode(2);
    ListNode* test3 = new ListNode(3);
    ListNode* test4 = new ListNode(4);
    ListNode* test5 = new ListNode(5);
    test1->next = test2;
    test2->next = test3;
    test3->next = test4;
    test4->next = test5;
    Solution s1;
    ListNode* ans = s1.reverseKGroup(test1,2);
    while (ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
        
}*/