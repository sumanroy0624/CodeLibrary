struct Node {
	Node *links[26];
	bool flag = false;
	bool contains_Key(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	Node* get(char ch) {
		return links[ch - 'a'];
	}
	void set_End() {
		flag = true;
	}
	bool is_End() {
		return flag;
	}
};

class Trie {
private:
	Node *root;
public:
	/**Initialize data structure Here. **/
	Trie() {
		root = new Node();
	}

	/** Insert word Into The Trie. */
	void insert(string word) {
		Node* node = root;
		for (auto ch : word) {
			if (!node->contains_Key(ch)) {
				node->put(ch, new Node());
			}

			node = node->get(ch);
		}
		node->set_End();
	}

	/** Returns if the word is Present In the Trie ! O(word.len) */
	bool search(string word) {
		Node *node = root;
		for (auto ch : word) {
			if (!node->contains_Key(ch)) {
				return false;
			}
			node = node->get(ch);
		}
		return node->is_End();
	}

	/** Return if any any word in the trie starts with prefix.  O(prefix.len) */
	bool starts_With(string prefix) {
		Node* node = root;
		for (auto ch : prefix) {
			if (!node->contains_Key(ch)) {
				return false;
			}
			node = node->get(ch);
		}
		return true;
	}
};
