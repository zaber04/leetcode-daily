class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """

        # acyclic
        # undirected
        # connected
        # complete



        root = -1

        # all childrens
        nodesWithParent = set(leftChild+rightChild)

        # discard -1 if exists
        nodesWithParent.discard(-1)

        # root nodes don't have parents
        if (len(nodesWithParent) == n):
            return False

        # find root
        for i in range(n):
            if i not in nodesWithParent:
                root = i
                break

        # track visited nodes
        visitedNodes = set()

        def dfs(i):
            if (i == -1):
                return True

            # fails if revisit
            if (i in visitedNodes):
                return False
            visitedNodes.add(i)
            
            return dfs(leftChild[i]) and dfs(rightChild[i])

        return dfs(root) and len(visitedNodes) == n


        