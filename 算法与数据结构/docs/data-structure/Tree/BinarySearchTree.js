class TreeNode {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
    this._size = 0;
    this.left = null;
    this.right = null;
  }

  get size() {
    return this._size;
  }

  // 添加元素
  insert(e) {
    const __add = (node, e) => {
      if (!node) {
        this._size++;
        return new TreeNode(e);
      }

      if (node.value > e) {
        node.left = __add(node.left, e);
      } else if (node.value < e) {
        node.right = __add(node.right, e);
      }

      return node;
    }

    if (this.root) {
      __add(this.root, e);
    } else {
      this.root = new TreeNode(e);
      this._size++;
    }
  }

  // 查看是否含有某个元素
  contains(e) {
    const __contains = (node, e) => {
      if (node === null) {
        return false;
      }

      if (node.value === e) {
        return true;
      } else if (node.value < e) {
        return __contains(node.right, e);
      } else {
        return __contains(node.left, e);
      }
    };
    return __contains(this.root, e);
  }

  // 先序遍历
  preOrder() {
    const result = [];
    const __preOrder = node => {
      if (node) {
        result.push(node.value);
        __preOrder(node.left);
        __preOrder(node.right);
      }

    };
    __preOrder(this.root);
    return result;
  }

  // 中序遍历
  inOrder() {
    const result = [];
    const __inOrder = node => {
      if (node) {
        __inOrder(node.left);
        result.push(node.value);
        __inOrder(node.right);
      }

    };
    __inOrder(this.root);
    return result;
  }

  // 后序遍历
  postOrder() {
    const result = [];
    const __postOrder = node => {
      if (node) {
        __postOrder(node.left);
        __postOrder(node.right);
        result.push(node.value);
      }

    };
    __postOrder(this.root);
    return result;
  }

  // 层序遍历
  levelOrder() {
    const result = [];
    const __levelOrder = (node, depth) => {
      if (node) {
        if (!result[depth]) {
          result[depth] = [];
        }
        __levelOrder(node.left, depth + 1);
        result[depth].push(node.value);
        __levelOrder(node.right, depth + 1);
      }
    }

    __levelOrder(this.root, 0);
    return result;
  }

  // 获取树的最小值
  minimum() {
    const __minimum = node => {
      if (!node.left) {
        return node;
      }
      return __minimum(node.left);
    };

    return __minimum(this.root);
  }

  // 获取树的最大值
  maximum() {
    const __maximum = node => {
      if (!node.right) {
        return node;
      }
      return __maximum(node.right);
    };

    return __maximum(this.root);
  }

  // 删除树的最小值
  removeMaximum() {

  }

  // 删除树的最大值
  removeMinimum() {

  }

  // 删除树的任意值
  remove(value) {

  }

}
