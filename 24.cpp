struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* head) {
  ListNode *beforeHead = new ListNode(0);
  ListNode *privious, *now, *next;

  beforeHead->next = head;
  privious = head;
  if(head) now = head->next;
  if(head && head->next) beforeHead->next = head->next; 

  while (privious && now) {
    next = now->next;
    now->next = privious;
    if (next && next->next) {
      privious->next = next->next;
      now = next->next;
      privious = next;
    } else if(next) {
      privious->next = next;
      now = NULL;
      privious = next;
    } else {
      privious->next = NULL;
      now = NULL;
      privious = NULL;
    }
  }

  return beforeHead->next;
}
