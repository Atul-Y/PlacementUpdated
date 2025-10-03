// Without structured bindings (old way)
// pair<int,int> p = pq.top();
// int freq = p.first;
// int num  = p.second;


// or shorter:

// int freq = pq.top().first;
// int num  = pq.top().second;

// With structured bindings (C++17+ way)
// auto [freq, num] = pq.top();


// Here:

// auto lets compiler deduce the type (pair<int,int>).

// [freq, num] destructures the pair into two variables.

// Equivalent to creating two local variables freq and num.

// Where you can use this

// Structured bindings work for:

// pairs

// pair<int, string> p = {1, "hello"};
// auto [id, name] = p;
// cout << id << " " << name; // 1 hello


// tuples

// tuple<int,string,double> t = {1, "pi", 3.14};
// auto [a, b, c] = t;
// cout << a << " " << b << " " << c;


// maps (inside loops)

// unordered_map<int, string> mp = {{1,"one"}, {2,"two"}};
// for (auto [key, value] : mp) {
//     cout << key << " -> " << value << "\n";
// }


// 🚀 Much cleaner than for (auto it : mp) { it.first; it.second; }.



//------------------------------------------

// 1. Default behavior recap

// By default, a priority_queue<T> in C++ is a max heap (largest element is at top()).

// priority_queue<int> pq; // max heap


// If you want a min heap, you use:

// priority_queue<int, vector<int>, greater<int>> pq; 


// For pairs:

// priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


// That uses the default > comparator for pairs, which compares pairs lexicographically:

// (a.first, a.second) < (b.first, b.second) means:

// compare a.first vs b.first

// if equal, compare a.second vs b.second.

// So greater<pair<int,int>> just gives you min heap based on .first then .second.

// 2. Problem with default greater<pair<int,int>>

// In your frequency sorting problem:

// You want to sort by frequency ascending.

// If frequency is equal, you want to sort by value descending.

// But greater<pair<int,int>> only knows “compare first, then second ascending.”
// That’s why you can’t express “descending order on tie-break” with just greater<pair<int,int>>.

// 3. Enter custom comparator Compare

// That’s why we wrote:

// struct Compare {
//     bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
//         if (a.first == b.first) {
//             return a.second < b.second; // larger number first
//         }
//         return a.first > b.first; // smaller frequency first
//     }
// };


// Key ideas:

// A comparator for priority_queue must define “is a lower priority than b”.

// Meaning: if Compare(a,b) returns true, then a goes below b in the heap.

// So:

// return a.first > b.first; → element with smaller frequency gets higher priority (goes to top).

// If frequencies tie → return a.second < b.second; → element with larger value gets priority.

// This perfectly matches the problem statement.

// 4. How this changes heap filling

// When you push elements:

// Heap internally uses Compare every time to reorder.

// With greater<pair<int,int>>, ties are resolved ascending by value.

// With Compare, ties are resolved descending by value.

// That’s why your heap pops elements in exactly the desired order.

// 5. Example walk-through

// Suppose input is:

// nums = [2,3,1,3,2]
// freq = {2:2, 3:2, 1:1}


// Heap inserts:

// (2,2), (2,3), (1,1)

// Now check tie behavior:

// (2,2) vs (2,3):

// Same frequency

// a.second < b.second → return true

// So smaller value (2) is considered lower priority → larger number (3) rises to top.

// Thus top() = (2,3) instead of (2,2).

// That’s exactly why you get [1,3,3,2,2] instead of [1,2,2,3,3].

// ✅ So the comparator changes the tie-breaking behavior, nothing else.
// Default greater<pair> = ascending tie.
// Custom Compare = descending tie.

// Summary:
// Structured bindings = cleaner syntax for unpacking pairs/tuples.
// Custom comparator = needed when default pair comparison doesn’t match problem requirements.
// Custom comparator lets you define exactly how to order elements in the heap.
// In your case, it lets you sort by frequency ascending, then value descending on ties.

