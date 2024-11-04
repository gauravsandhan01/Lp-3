class Node:
    def __init__(self, freq, symbol, left=None, right=None):
        # Node initialization with frequency, symbol, left, and right child nodes
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
        self.huff = ''

# Function to print the Huffman codes
def printNodes(node, val=''):
    # `val` is the Huffman code for the current node
    newVal = val + str(node.huff)

    # If left child exists, explore it
    if node.left:
        printNodes(node.left, newVal)

    # If right child exists, explore it
    if node.right:
        printNodes(node.right, newVal)

    # If this is a leaf node, print its symbol and Huffman code
    if not node.left and not node.right:
        print(f"{node.symbol} --> {newVal}")

# Characters and their corresponding frequencies
chars = ['a', 'b', 'c', 'd', 'e', 'f']
freq = [5, 9, 12, 13, 16, 45]

# List of nodes to hold each character and its frequency
nodes = []
for x in range(len(chars)):
    nodes.append(Node(freq[x], chars[x]))

# Build the Huffman Tree
while len(nodes) > 1:
    # Sort nodes based on frequency
    nodes = sorted(nodes, key=lambda x: x.freq)

    # Take the two nodes with the lowest frequency
    left = nodes[0]
    right = nodes[1]

    # Assign binary values (0 to left, 1 to right)
    left.huff = 0
    right.huff = 1

    # Combine the two nodes into a new node with combined frequency
    newNode = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)

    # Remove the processed nodes and add the new node to the list
    nodes.remove(left)
    nodes.remove(right)
    nodes.append(newNode)

# Print the Huffman codes for each character
print("Huffman Codes:")
printNodes(nodes[0])
