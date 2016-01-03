#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 int carry = 0;
      int length = 0;
      int value = 0;
      ListNode *result;
      ListNode *now = result;
      bool first = true;
      while (l1 && l2) {
        value = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        ListNode *next = (ListNode *) malloc (sizeof(ListNode));
        next->val = value;
        next->next = NULL;
        if(first) {
            result = next;
            first = false;
        } else {
            now->next = next;
        }
        now = next;
        l1 = l1->next;
        l2 = l2->next;
      }

      while (l1) {
        value = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        ListNode *next = (ListNode *) malloc (sizeof(ListNode));
        next->val = value;
        next->next = NULL;
        now->next = next;
        now = next;
        l1 = l1->next;
      }
      while (l2) {
        value = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        ListNode *next = (ListNode *) malloc (sizeof(ListNode));
        next->val = value;
        next->next = NULL;
        now->next = next;
        now = next;
        l2 = l2->next;
      }

      if (carry) {
        value = carry;
        ListNode *next = (ListNode *) malloc (sizeof(ListNode));
        next->val = value;
        next->next = NULL;
        now->next = next;
        now = next;
      }

      return result;
}
