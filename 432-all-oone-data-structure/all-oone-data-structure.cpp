class AllOne {
// Augmented Trie
private:
    constexpr static int MaxInt{50000};
    struct Node {
        Node* children[26];
        int count, max_count, min_count;
        Node(int count = 0)
        : count(count), max_count(0), min_count(MaxInt) {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

    void update(Node* node) {
        node->max_count = node->count;
        node->min_count = node->count > 0 ? node->count : MaxInt;
        for (int i = 0; i < 26; i++) {
            const auto& child = node->children[i];
            if (child) {
                node->max_count = max(node->max_count, child->max_count);
                if (child->min_count > 0) {
                    node->min_count = min(node->min_count, child->min_count);
                }
            }
        }
    }

    void insert_string(Node* node, const string& key, int pos) {
        if (pos == key.size()) {
            node->count++;
        }
        else {
            int idx = key[pos] - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Node();
            }
            const auto& child = node->children[idx];
            insert_string(child, key, pos + 1);
        }
        update(node);
        // cout << node->count << ", " << node->max_count << ", " << node->min_count << endl;
    }

    void delete_string(Node* node, const string& key, int pos) {
        if (pos == key.size()) {
            node->count--;
        }
        else {
            int idx = key[pos] - 'a';
            const auto& child = node->children[idx];
            delete_string(child, key, pos + 1);
        }
        update(node);
        // cout << node->count << ", " << node->max_count << ", " << node->min_count << endl;
    }

    void get_max_key(string& res, Node* node) {
        if (node->count == node->max_count) {
            return;
        }
        for (int i{0}; i < 26; i++) {
            const auto& child = node->children[i];
            if (child && child->max_count == node->max_count) {
                res += 'a' + i;
                get_max_key(res, child);
                return;
            }
        }
    }

    void get_min_key(string& res, Node* node) {
        if (node->count == node->min_count || node->min_count == 50000) {
            return;
        }
        for (int i{0}; i < 26; i++) {
            const auto& child = node->children[i];
            if (child && child->min_count == node->min_count) {
                res += 'a' + i;
                get_min_key(res, child);
                return;
            }
        }
    }

public:
    AllOne() : root(new Node()) {}

    void inc(string key) {
        insert_string(root, key, 0);
    }

    void dec(string key) {
        delete_string(root, key, 0);
    }

    string getMaxKey() {
        string res;
        get_max_key(res, root);
        return res;
    }

    string getMinKey() {
        string res;
        get_min_key(res, root);
        return res;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */