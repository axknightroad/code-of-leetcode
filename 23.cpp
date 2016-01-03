#include <vector>

using namespace std;


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


ListNode* mergeKLists(vector<ListNode*>& lists) {
  int k = lists.size();
  vector <ListNode *> temp;
  while (k > 1) {
    temp.clear();
    if (k % 2) temp.push_back(lists[k-1]); 
    for(int i = 0; i < k / 2; i++) {
      ListNode* tempList = mergeTwoLists(lists[2 * i], lists[2 * i + 1]);
      temp.push_back(tempList);
    }
    lists.clear();
    k = temp.size();
    for (int i = 0; i < k; i++) {
      lists.push_back(temp[i]);
    }
  }

  if (k) return lists[0];
  else return NULL;
}

int main() {
  vector<ListNode*> lists;
  ListNode *n1 = new ListNode(0);
  ListNode *n2 = new ListNode(1);
  lists.push_back(n1);
  lists.push_back(n2);
  ListNode *ans = mergeKLists(lists);
  
  return 0;
}
