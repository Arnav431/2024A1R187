struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL;
    struct ListNode *temp, *prev = NULL;
    int carry = 0, sum;
    while (l1 != NULL || l2 != NULL) {
        sum = carry + (l1 ? l1->val : 0) + (l2 ? l : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum;
        temp->next = NULL;
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry > 0) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = carry;
        temp->next = NULL;
        prev->next = temp;
    }
    return result;
    
}