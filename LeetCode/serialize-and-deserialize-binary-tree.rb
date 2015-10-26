def serialize(root)
    return "nil" if root == nil
    root.val.to_s + ' ' + serialize(root.left) + ' ' + serialize(root.right)
end

def deserialize(data)
    def deserialize_sub(strs, idx)
        return nil, idx + 1 if strs[idx] == 'nil'
        node = TreeNode.new strs[idx].to_i
        node.left, idx = deserialize_sub strs, idx + 1
        node.right, idx = deserialize_sub strs, idx
        return node, idx
    end
    strs = data.split
    tree, idx = deserialize_sub strs, 0
    tree
end
