#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;


struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }


    bool isLeaf() {
        return left == nullptr && right == nullptr;
    }
};


struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};


HuffmanNode* buildHuffmanTree(map<char, int>& frequencyTable) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    for (const auto& pair : frequencyTable) {
        cout<<pair.first<<" : "<< pair.second<<" ";
        pq.push(new HuffmanNode(pair.first, pair.second));
    }
cout<<endl;
    while (pq.size() > 1) {
        cout<<"two nodes taken:"<<endl;

        HuffmanNode* left = pq.top();
        cout<<"left node "<<left->data<<" : "<<left->frequency<<" and " ;
        pq.pop();
        HuffmanNode* right = pq.top();
         cout<<"right node "<<right->data<<" : "<<right->frequency<<" \n\n";
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}


void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->isLeaf()) {
        huffmanCodes[root->data] = code;
      
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    map<char, int> frequencyTable;
    map<char, string> huffmanCodes;

    
    frequencyTable['a'] = 10;
    frequencyTable['b'] = 15;
    frequencyTable['c'] = 12;
    frequencyTable['d'] = 3;
    frequencyTable['e'] = 4;
    frequencyTable['f'] = 13;

    HuffmanNode* root = buildHuffmanTree(frequencyTable);
    generateHuffmanCodes(root, "", huffmanCodes);

   
    cout << "Huffman Codes:" << endl;
    int totalCost=0;
    for (const auto& pair : huffmanCodes) {
        totalCost+=pair.second.length()*frequencyTable[pair.first];
        cout << pair.first << ": " << pair.second << endl;
    }

cout<<"Tatal bits required to store :"<<totalCost;

    return 0;
}