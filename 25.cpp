struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseKNode(ListNode* head, int k) {
  //ListNode* beforeHead = new ListNode(0);
  ListNode *privious, *now, *next;
  privious = head;
  if(head) now = head->next;
  
  for (int i = 0; i < k - 1; i++) {
    if(now) next = now->next;
    now->next = privious;
    privious = now;
    now = next;
  }
  head->next = reverseKNode(next, k);
  head = privious;
  return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {

  
        
}
