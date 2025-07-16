//Level Order 

//https://youtu.be/86g8jAQug04?si=vNObg9RhvO4_vkyv


void LevelOrder(Node *root) {
    if(root == NULL) return; // If the tree is empty, return

    queue<Node*> Q; // Create a queue to store nodes
    Q.push(root);   // Push the root node into the queue

    // While there is at least one discovered node
    while(!Q.empty()) {
        Node* current = Q.front(); // Get the front node of the queue
        Q.pop(); // Remove the element at the front of the queue
        cout << current->data << " "; // Print the data of the current node

        // If the current node has a left child, push it into the queue
        if(current->left != NULL)
            Q.push(current->left);

        // If the current node has a right child, push it into the queue
        if(current->right != NULL)
            Q.push(current->right);
    }
}
