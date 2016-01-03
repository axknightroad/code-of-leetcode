#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int reRemove(ListNode *now, int lastTurn, int n) {
  int thisTurn = lastTurn + 1;
  int max;
  if (!now->next) {
    return thisTurn;
  }
  
  else{
    max = reRemove(now->next, thisTurn, n);
  }

  if (thisTurn + n == max) {
    now->next = now->next->next;
  }

  return max;
  
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *beforeHead = (ListNode *)malloc(sizeof(ListNode));
  beforeHead->next = head;
  reRemove(beforeHead, -1, n);

  return beforeHead->next;
  
}
