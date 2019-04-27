#include<iostream>

using namespace std;

typedef struct node {
    int data;
    int lchild;
    int rchild;
} node;

void order(node *Node, int *i, int num, const int n, int *a) {     //先序 （左优先） 遍历二叉树

    int *temp = i;

    if (num == 0) {
        a[*temp] = 0;
        (*temp)++;
    }

    if (*temp <= n && num != 0) {
        a[*temp] = Node[num].data;
        (*temp)++;


        order(Node, temp, Node[num].lchild, n, a);

        order(Node, temp, Node[num].rchild, n, a);
    }
}


void order1(node *Node, int *i, int num, const int n, int *a) {     //先序 （右优先） 遍历二叉树

    int *temp = i;

    if (num == 0) {
        a[*temp] = 0;
        (*temp)++;
    }

    if (*temp <= n && num != 0) {
        a[*temp] = Node[num].data;
        (*temp)++;

        order1(Node, temp, Node[num].rchild, n, a);

        order1(Node, temp, Node[num].lchild, n, a);
    }
}

int main() {
    int T;
    int n;
    int i;
    int a, b, c;
    int value1;

    cin >> T;
    while (T--) {
        int q1 = 1;
        int q2 = 1;
        node N[100] = {0};
        node N1[100] = {0};
        int A[100] = {0};
        int B[100] = {0};

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a >> b >> c;
            N1[a].lchild = N[a].lchild = b;
            N1[a].rchild = N[a].rchild = c;
        }

        for (i = 1; i <= n; i++) {
            cin >> value1;
            N1[i].data = N[i].data = value1;
        }

        order(N, &q1, 1, 2 * n + 1, A);


        /*for (i = 1; i <= 2*n+1; i++)
            cout << A[i] << "   ";
        cout << endl;
        */

        order1(N1, &q2, 1, 2 * n + 1, B);

        /*for (i = 1; i <= 2*n+1; i++)
            cout << B[i] << "   ";
        */

        bool flag = true;
        for (i = 1; i < 2 * n + 1; i++) {
            if (A[i] != B[i]) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}



