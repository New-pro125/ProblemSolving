#include <bits/stdc++.h>
using namespace std;

struct DS {
    int longSbstr = 0;
    char leftChar;
    char rightChar;
    int prefixLen = 1;
    int suffixLen = 1;
    int totalLen = 1;
};

template <typename T = DS>
struct Node {
    T val;
    Node(T val = T()) : val(val) {}
    void change(T x) {
        val = x;
    }
};

template <typename T = DS, int Base = 0>
class SegmentTree {
private:
    int sz;
    std::vector<Node<T>> tree;

    Node<T> merge(const Node<T>& l, const Node<T>& r) {
        Node<T> res;
        if (l.val.longSbstr == 0) 
            res = r;
        else if (r.val.longSbstr == 0) 
            res = l;
        else {
            res.val.leftChar = l.val.leftChar;
            res.val.rightChar = r.val.rightChar;
            res.val.totalLen = l.val.totalLen + r.val.totalLen;
            res.val.longSbstr = max(l.val.longSbstr, r.val.longSbstr);
            res.val.prefixLen = l.val.prefixLen;
            res.val.suffixLen = r.val.suffixLen;

            if (l.val.rightChar == r.val.leftChar) {
                res.val.longSbstr = max(res.val.longSbstr, l.val.suffixLen + r.val.prefixLen);
                if (l.val.prefixLen == l.val.totalLen)
                    res.val.prefixLen = l.val.totalLen + r.val.prefixLen;
                if (r.val.prefixLen == r.val.totalLen)
                    res.val.suffixLen = l.val.suffixLen + r.val.totalLen;
            }
        }
        return res;
    }

    void set(int idx, T val, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            tree[ni].change(val);
            return;
        }
        int mid = (lx + rx) / 2;
        if (idx < mid)
            set(idx, val, 2 * ni + 1 - Base, lx, mid);
        else
            set(idx, val, 2 * ni + 2 - Base, mid, rx);
        tree[ni] = merge(tree[2 * ni + 1 - Base], tree[2 * ni + 2 - Base]);
    }

public:
    SegmentTree(int n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(2 * sz, Node<T>(T()));
    }

    void update(int idx, T val) {
        set(idx, val, Base, Base, sz + Base);
    }

    T query() {
        return tree[0].val;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        SegmentTree<DS> segTree(n);
        for (int i = 0; i < n; ++i) {
            DS node;
            node.longSbstr = 1;
            node.leftChar = s[i];
            node.rightChar = s[i];
            segTree.update(i, node);
        }

        vector<int> res;
        for (int i = 0; i < queryIndices.size(); i++) {
            DS node;
            node.longSbstr = 1;
            node.leftChar = queryCharacters[i];
            node.rightChar = queryCharacters[i];
            segTree.update(queryIndices[i], node);
            res.push_back(segTree.query().longSbstr);
        }
        return res;
    }
};
