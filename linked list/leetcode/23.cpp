#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* head = NULL;
    struct ListNode* cur = NULL;
    while (1){
        int min = 10001;
        int min_index = -1;
		
        // 현재 k 개의 포인터가 가리키고 있는 노드들 중 최소값을 구함.
        for (int i = 0; i < listsSize; i++){
            if (lists[i] && lists[i]->val < min){
                min = lists[i]->val;
                min_index = i;
            }
        }

        if (min_index < 0) break; // 종료 조건
        
        if (!head){
            head = cur = lists[min_index];
        }
        else{
            cur->next = lists[min_index];
            cur = cur->next;
        }

        lists[min_index] = lists[min_index]->next;
    }
    return head;
}


// Let’s see how to merge two sorted lists first and then generalize it to k lists
// => a loop of finding the minimum element

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	struct ListNode* head = NULL;
	struct ListNode* cur = NULL;
	if (!l1) return l2;
	if (!l2) return l1;
	
	if (l1->val < l2->val) { // 최소값을 첫번째 노드로
		head = cur = l1;
		l1 = l1->next;
	}
	else{
		head = cur = l2;
		l2 = l2->next;
	}

	while (l1 && l2){
		if (l1 -> val < l2-> val){
			cur->next = l1;
			l1 = l1 -> next;
		}
		else{
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}

	if (!l1) cur->next = l2;
	else cur->next = l1;

	return head;
}

// https://leetcode.com/problems/merge-k-sorted-lists/