import heapq

# Huffman Tree Node class
class Node:
    def __init__(self, freq, char=None):
        self.freq = freq
        self.char = char
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

# Huffman encoding
def huffman_encoding(frequencies):
    heap = [Node(freq, char) for char, freq in frequencies.items()]
    heapq.heapify(heap)
    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged = Node(left.freq + right.freq)
        merged.left = left
        merged.right = right
        heapq.heappush(heap, merged)
    encoding_dict = {}
    def build_encoding_dict(node, code=""):
        if node.char:
            encoding_dict[node.char] = code
        else:
            build_encoding_dict(node.left, code + "0")
            build_encoding_dict(node.right, code + "1")
    if heap:
        build_encoding_dict(heap[0])
    return encoding_dict

# Huffman encoded text
def huffman_encoding_text(text, encoding_dict):
    encoded_text = "".join(encoding_dict[char] for char in text)
    return encoded_text

# Huffman decoding
def huffman_decoding_text(encoded_text, decoding_dict):
    current_code = ""
    decoded_text = ""
    for bit in encoded_text:
        current_code += bit
        if current_code in decoding_dict:
            decoded_text += decoding_dict[current_code]
            current_code = ""
    return decoded_text

# Three input texts
text1 = """Bluejean baby
L.A. Lady
Seamstress for the band"""
text2 = """It's a little bit funny, this feeling inside
I'm not one of those who can easily hide
I don't have much money, but, boy, if I did"""
text3 = """She packed my bags last night pre flight
Zero hour, nine A.M.
And I'm gonna be high as a kite by then"""

# Part I: Huffman Encoding/Decoding using input text1
print("\nPart I: Huffman Encoding/Decoding")

# Display input text1
print("\nInput: \n", text1)

# Determining frequency of each character in input
frequency = {}
for char in text1:
    frequency[char] = frequency.get(char, 0) + 1

# Encoding text1 using Huffman Encoding
encoding_dict = huffman_encoding(frequency)
encoded_text = huffman_encoding_text(text1, encoding_dict)

# Display encoding
print("\nEncoded: ")
print(encoded_text)

# Decode encoded text
decoding_dict = {code: char for char, code in encoding_dict.items()}
decoded_text = huffman_decoding_text(encoded_text, decoding_dict)

# Display decoded text
print("\nDecoded: ")
print(decoded_text)

# Part II: ASCII Encoding/Decoding using input text1
print("\nPart II: ASCII Encoding/Decoding")

# Display input text1
print("\nInput: \n", text1)

# Encode text1 using ASCII Encoding
encoded_text4 = "".join(format(ord(char), '08b') for char in text1)

# Decode ASCII encoded text1
decoded_text = "".join(chr(int(encoded_text4[i:i+8], 2)) for i in range(0, len(encoded_text4), 8))

# Display ASCII encoding of text1
print("\nEncoded: ")
print(encoded_text4)

# Display ASCII decoding of text1
print("\nDecoded: ")
print(decoded_text)

# Part III: Comparison of Huffman and ASCII encoding bit quantities for three texts 
print("\nPart III")

# Display the three texts
print("\nInputs: \ntext1: \n", text1, "\ntext2: \n", text2, "\ntext3: \n", text3)

# Huffman encoding of text2 (text1 determined in Part I)
frequency2 = {}
for char in text2:
    frequency2[char] = frequency2.get(char, 0) + 1
encoding_dict = huffman_encoding(frequency2)
encoded_text2 = huffman_encoding_text(text2, encoding_dict)

# Huffman encoding of text3
frequency3 = {}
for char in text3:
    frequency3[char] = frequency3.get(char, 0) + 1
encoding_dict = huffman_encoding(frequency3)
encoded_text3 = huffman_encoding_text(text3, encoding_dict)

# ASCII encoding of text2 (text1 determine in Part II)
encoded_text5 = "".join(format(ord(char), '08b') for char in text2)

# ASCII encoding of text3
encoded_text6 = "".join(format(ord(char), '08b') for char in text3)

# Display table comparing Huffman and ASCII encoding bit quantities
table = f"""
Input\tHuffman\t\tASCII 8-Bit 
Text 1\t{len(encoded_text)} bits\t{len(encoded_text4)} bits
Text 2\t{len(encoded_text2)} bits\t{len(encoded_text5)} bits
Text 3\t{len(encoded_text3)} bits\t{len(encoded_text6)} bits
"""
print("Comparison Table:")
print(table)
