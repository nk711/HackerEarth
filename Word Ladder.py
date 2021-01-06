class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # Convert to set, due to O(log n) search operation
        wordList = set(wordList)
        # Returns 0 if there is no such transformation sequence
        if endWord not in wordList:
            return 0
        # Collections.deque creates a linked list. O(1) pop and append operations.
        queue = collections.deque([[beginWord, 1]])
        # While the queue is not empty
        while queue:
            # Get Node Values - word & current level
            word, level = queue.popleft()
            # Checks if the transformation is complete
            if word == endWord:
                return level # Returns the number of transformations
            for i in range(len(word)):
                for char in 'abcdefghijklmnopqrstuvwxyz':
                    # Transform the current word
                    new_word = word[:i] + char + word[i+1:]
                    if word[i]==char:
                        continue
                    # If the transformed word is in the list then add to queue
                    if new_word in wordList:
                        queue.append([new_word, level+1])
                        wordList.remove(new_word)
        return 0
