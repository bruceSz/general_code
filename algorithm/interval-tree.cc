/***************************************************************************
 * 
 * Copyright (c) 2016 jd.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file interval-tree.cc
 * @author brucesz(zhangsong5@jd.com)
 * @date 2016/07/24 11:50:02
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */
#include <iostream>

using namespace std;

struct Interval {
    int low, high;
};

struct ITNode {
    Interval  i;
    int max;
    ITNode * l, *r;
};

ITNode * newNode(int low, int high) {
    ITNode * tmp = new ITNode();
    tmp->i.low = low;
    tmp->i.high = high;
    tmp->max = high;
    tmp->l = tmp->r = NULL;
    return tmp;
}


ITNode * insert(ITNode* root, int low, int high) {
    if (root == NULL)
        return newNode(low, high);
    int l = root->i.low;
    if (low < l)
        root->l = insert(root->l, low, high);
    else
        root->r = insert(root->r, low, high);
    if (root->max < high)
        root->max = high;
    return root;
}

bool doOverlap(Interval i1, Interval& i2) {
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}

Interval intervalSearch(ITNode* root, Interval & i) {
    if (root == NULL) return Interval();
    if (doOverlap(root->i, i))
        return root->i;
    if (root->l != NULL && root->l->max >= i.low)
        return intervalSearch(root->l, i);
    else
        return intervalSearch(root->r, i);
}

void inorder(ITNode* root)
{
    if (root == NULL) return;
    inorder(root ->l);
    cout << root ->i.low << "=>" << root->i.high << endl;
    inorder(root->r);
}

int main() {
    Interval ints[] = {{15,20}, {10,30}, {17,19},
                      {5,20}, {12,15}, {30,40}};
    int n = sizeof(ints)/sizeof(Interval);
    ITNode * root = NULL;
    for(int i = 0; i< n; i++)
        root = insert(root, ints[i].low, ints[i].high); 
    inorder(root);
}
