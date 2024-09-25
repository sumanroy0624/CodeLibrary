//2416. Sum of Prefix Scores of Strings

class Solution {
public:
    struct Node {
	Node* links[26];
	int ct1 = 0;
	bool containsKey(char ch) {
		return links[ch - 'a'] != NULL;
	}
	void put(char ch) {
		links[ch - 'a'] = new Node();
	}
	Node* getRef(char ch) {
		return links[ch - 'a'];
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node();
	}
	void insert(string word) {
		Node* node = root;
		for (auto ch : word) {
			if (!node->containsKey(ch)) {
				node->put(ch);
			}
			node = node->getRef(ch);
			node->ct1++;
		}

	}
	int search(string word) {
		Node* node = root;
		int count = 0;
		for (auto ch : word) {
			if (!node->containsKey(ch))break;
			node = node->getRef(ch);
			count += node->ct1;
		}
		return count;
	}
};

vector<int> sumPrefixScores(vector<string>& words) {
	Trie t;
	for (auto el : words) {
		t.insert(el);
	}
	vector<int>ans;
	for (auto el : words) {
		ans.push_back(t.search(el));
	}
	return ans;
}
};
