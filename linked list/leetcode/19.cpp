#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// 1. node 전체 개수 구하기
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int cnt = 0;  // node 전체 개수
    struct ListNode* cur = head;
    while (cur != NULL){
        cnt++;
        cur = cur->next;
    }
    int num = cnt - n - 1; // 삭제하려는 노드가 왼쪽에서 num번째에 위치함.
    cur = head;
    if (num < 0){ // 왼쪽에서 첫번째 노드를 삭제하려는 경우
        cur = cur -> next;
        free(head);
        return cur;
    }
    for (int i = 0; i < num; i++) cur = cur->next;
    struct ListNode* delNode = cur->next;
    cur->next = delNode->next;
    free(delNode);
    cur = head;
    return cur;
}
/*
"Single Linked List"는 한 방향으로만 node를 탐색할 수 있다. 이 문제의 경우 오른쪽에서  n번째에 있는 노드를 삭제하라고 하지만, 왼쪽 node부터 탐색할 수 있다.
그래서 왼쪽 기준으로 몇번째 노드를 삭제하는지 구하기 위해 node의 전체 개수를 구한다.
이때 주의할 점이 포인터가 "삭제하려는 노드의 전 노드"를 가리켜야 한다!
*/


// 2. Two Pointer (using one pass)
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    // 1. two pointer (left and right) 초기화
    struct ListNode* left = head;
    struct ListNode* right = head;

    // 2. right 포인터를 n만큼 옆으로 이동 → left와 right 사이에는 n개의 node 존재
    while (n--) {
        right = right->next;
        if (!right){  // 왼쪽에서 첫 번째 노드를 삭제하는 경우
            head = head->next;
            free(left);
            return head;
        }
    }

    // 3. right→next가 NULL이 될 때까지 left와 right 동시에 옆으로 이동
    while (right->next != NULL){
        left = left->next;
        right = right->next;
    }

    // 4. left→next에 있는 node 삭제
    struct ListNode* delNode = left->next;
    left->next = delNode->next;
    free(delNode);
    return head;
}

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/