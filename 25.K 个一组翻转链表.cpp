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
    //想想分治的思想每次处理k个，然后每组连一起不就行了
    //一遍ac，很强
    /*ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        ListNode* iterator = head;
        int group = 0;//每k个记为一组，group记录组号
        ListNode* lastGroupEnd = NULL;
        while (iterator != NULL)
        {
            ListNode* start = iterator;//这组的头
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
            if (lastGroupEnd != NULL)//上组的start指向改组的end，把组和组联系在一起    这里可以考虑不使用特殊判定   自己加一个头节点就可以了   group和这个都不需要了
                lastGroupEnd->next = end;
            //这k个节点形成一组的头start和尾end都已经得到了
            iterator = end->next;//记录下一组的开头

            
            group++;//这里记录group其实就是为了确定头节点，第一组之后，这个变量就没有用了
            if (group == 1)
                head = end;
            //开始start到end之间的反转
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
            start->next = iterator;//这一组的start应当指向下一组的end才对,这里是为了防止下一组没有end设置的
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
            ListNode* start = iterator;//这组的头
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
            //这k个节点形成一组的头start和尾end都已经得到了
            iterator = end->next;//记录下一组的开头

            //开始start到end之间的反转
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
            start->next = iterator;//这一组的start应当指向下一组的end才对,这里是为了防止下一组没有end设置的
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