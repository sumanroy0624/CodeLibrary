
struct Node {
	Node *links[26];
	int cnt_End_With = 0;
	int cnt_Prefix = 0;

	bool contains_Key(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch) {
		links[ch - 'a'] = new Node();
	}
	Node* get(char ch) {
		return links[ch - 'a'];
	}
	void increase_End() {
		cnt_End_With++;

	}
	void increase_prefix() {
		cnt_Prefix++;
	}
	void delete_end() {
		cnt_End_With--;

	}
	void reduce_prefix() {
		cnt_Prefix--;
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

	void insert(string &word) {
		Node* node = root;
		for (auto ch : word) {
			if (!node->contains_Key(ch)) {
				node->put(ch);
			}
			node = node->get(ch);
			node->increase_prefix();
		}
		node->increase_End();
	}

	int countWordsEqualTo(string &word) {
		Node* node = root;
		for (auto ch : word) {
			if (!node->contains_Key(ch))return 0;
			node = node->get(ch);
		}
		return node->cnt_End_With;
	}

	int countWordsStartingWith(string &word) {
		// Write your code here.
		Node * node=root;
		for(auto ch:word){
			if(!node->contains_Key(ch))return 0;
			node=node->get(ch);
		}
		return node->cnt_Prefix;
	}

	void erase(string &word) {
		Node *node=root;
		for(auto ch:word){
			if(!node->contains_Key(ch))break;
			node=node->get(ch);
			node->reduce_prefix();
		}
		node->delete_end();
	}
};
