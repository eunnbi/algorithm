#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


// 새 노드를 반환하는 함수
struct ListNode* makeNewNode(int data){
    struct ListNode * newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;
    return newNode;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* start = NULL; // 새로운 연결리스트의 시작 노드를 가리킴.
    struct ListNode* cur = NULL; // 새로운 연결리스트의 현재 노드를 가리킴.
    int sum = 0;
    int carry = 0;
    while (l1 || l2){
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        if (!start){
            start = cur = makeNewNode(sum % 10);
        }
        else{
            cur->next = makeNewNode(sum % 10);
            cur = cur->next;
        }
        carry = sum / 10;
        if (l1) l1 = l1->next; // 포인터 다루는 것이 중요
        if (l2) l2 = l2->next;
    }
    if (carry) cur->next = makeNewNode(carry); // 예외 상황 처리
    return start;
}

// https://leetcode.com/problems/add-two-numbers/