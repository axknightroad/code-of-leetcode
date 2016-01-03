struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

  ListNode *head = new ListNode(0);
  ListNode *now = head;

  while (l1 && l2) {
    if(l1->val < l2->val) {
      now->next = l1;
      now = now->next;
      l1 = l1->next;
    } else {
      now->next = l2;
      now = now->next;
      l2 = l2->next;
    }
  }

  if (l1) now->next = l1;
  else now->next = l2;

  return head->next;
}

  
