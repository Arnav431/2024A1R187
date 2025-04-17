int getDecimalValue(struct ListNode* head) {
    int r=0;
    while (head!=NULL) {
        r=(r<<1)|head->val;
        head=head->next;
    }
    return r;
}