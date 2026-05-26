#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
order_of_key(k) - returns count of elements smaller than k
find_by_order(k) - returns iterator for ks element
ss.erase(ss.find_by_order(ss.order_of_key(x))) - removes one x element
*/
