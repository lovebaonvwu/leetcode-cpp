/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
 public:
  virtual ~Node(){};
  virtual int evaluate() const = 0;

 protected:
  // define your fields here
};

class MyNode : public Node {
 public:
  MyNode() {}
  MyNode(vector<string>& postfix) {
    for (auto c : postfix) {
      if (isdigit(c[0])) {
        stk.push(stoi(c));
      } else {
        int op2 = stk.top();
        stk.pop();
        int op1 = stk.top();
        stk.pop();

        if (c == "+") {
          stk.push(op1 + op2);
        } else if (c == "-") {
          stk.push(op1 - op2);
        } else if (c == "*") {
          stk.push(op1 * op2);
        } else if (c == "/") {
          stk.push(op1 / op2);
        }
      }
    }

    val = stk.top();
    stk.pop();
  }

  virtual int evaluate() const override { return val; }

 private:
  stack<int> stk;
  int val;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
 public:
  Node* buildTree(vector<string>& postfix) {
    Node* myNode = new MyNode(postfix);

    return myNode;
  }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
// Runtime 0 ms
// Memory 8.2 MB
// 2023.2.7 at 奥盛大厦

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
 public:
  virtual ~Node(){};
  virtual int evaluate() const = 0;

 protected:
  // define your fields here
};

class NumNode : public Node {
 public:
  NumNode(int num) : val(num) {}
  virtual int evaluate() const override { return val; }

 private:
  int val;
};

class OpNode : public Node {
 public:
  OpNode(Node* op1, Node* op2) : op1_(op1), op2_(op2) {}
  virtual ~OpNode() {
    delete op1_;
    delete op2_;
  }

 protected:
  Node* op1_;
  Node* op2_;
};

class AddOpNode : public OpNode {
 public:
  AddOpNode(Node* op1, Node* op2) : OpNode(op1, op2) {}
  virtual int evaluate() const override {
    return op1_->evaluate() + op2_->evaluate();
  }
};

class SubOpNode : public OpNode {
 public:
  SubOpNode(Node* op1, Node* op2) : OpNode(op1, op2) {}
  virtual int evaluate() const override {
    return op1_->evaluate() - op2_->evaluate();
  }
};

class MultiOpNode : public OpNode {
 public:
  MultiOpNode(Node* op1, Node* op2) : OpNode(op1, op2) {}
  virtual int evaluate() const override {
    return op1_->evaluate() * op2_->evaluate();
  }
};

class DevidOpNode : public OpNode {
 public:
  DevidOpNode(Node* op1, Node* op2) : OpNode(op1, op2) {}
  virtual int evaluate() const override {
    return op1_->evaluate() / op2_->evaluate();
  }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
  Node* create(string op, Node* op1, Node* op2) {
    Node* node = nullptr;
    switch (op[0]) {
      case '+':
        node = new AddOpNode(op1, op2);
        break;
      case '-':
        node = new SubOpNode(op1, op2);
        break;
      case '*':
        node = new MultiOpNode(op1, op2);
        break;
      case '/':
        node = new DevidOpNode(op1, op2);
        break;
      default:
        break;
    }

    return node;
  }

 public:
  Node* buildTree(vector<string>& postfix) {
    stack<Node*> stk;
    for (auto s : postfix) {
      if (isdigit(s[0])) {
        stk.push(new NumNode(stoi(s)));
      } else {
        Node *op1, *op2;
        op2 = stk.top();
        stk.pop();
        op1 = stk.top();
        stk.pop();

        stk.push(create(s, op1, op2));
      }
    }

    return stk.top();
  }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
// Runtime 7 ms
// Memory 8.4 MB
// 2023.2.7 at 奥盛大厦