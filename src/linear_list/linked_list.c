#include "linear_list.h"
#include <stdio.h>
#include <stdlib.h>

// ======================
//  单链表结构与操作示例
// ======================

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 创建新节点
Node* create_node(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 头插法创建链表
Node* create_list_head(int arr[], int n) {
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        Node *node = create_node(arr[i]);
        node->next = head;
        head = node;
    }
    return head;
}

// 尾插法创建链表
Node* create_list_tail(int arr[], int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node *node = create_node(arr[i]);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// 打印链表
void print_list(Node *head) {
    Node *p = head;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 释放链表
void free_list(Node *head) {
    Node *p = head;
    while (p) {
        Node *tmp = p->next;
        free(p);
        p = tmp;
    }
}

// 主测试函数
void linked_list(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Head insertion:\n");
    Node *head1 = create_list_head(arr, n);
    print_list(head1);
    free_list(head1);

    printf("\nTail insertion:\n");
    Node *head2 = create_list_tail(arr, n);
    print_list(head2);
    free_list(head2);
}
