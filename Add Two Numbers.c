/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// typedef struct ListNode ListNode;

struct ListNode* createNode(int val){
    struct ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) return NULL;

    newNode -> next = NULL;
    newNode -> val = val;
    return newNode;
}

struct ListNode* InsertTail(struct ListNode *root, int val){
    struct ListNode *newNode = createNode(val);
    if (root == NULL) return newNode;
    
    struct ListNode *q;
    for ( q = root; q->next != NULL; q = q->next);
    q->next = newNode;
    return root;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3 = NULL;    //root
    int rem = 0, sum = 0;

    struct ListNode* q3 = l3;
    struct ListNode* q1 = l1;
    struct ListNode* q2 = l2;
    
    int count = 0;
    int num1, num2;
    while(!((q1 == NULL) && (q2 == NULL))){
        num1 = num2 = 0;
        if (q1 != NULL) num1 = q1 -> val;
        if (q2 != NULL) num2 = q2 -> val;
        sum = num1 + num2 + rem;
        rem = 0;
        if (sum >= 10){
            rem = sum / 10;
            sum = sum % 10;
        }
        l3 = InsertTail(l3, sum);
        sum = 0;
        if (q2 != NULL) q2 = q2 -> next;
        if (q1 != NULL) q1 = q1 -> next;
        if ((q1 == NULL) && (q2 == NULL) && rem != 0) l3 = InsertTail(l3, rem);
        ++count;
    }
    return l3;
}