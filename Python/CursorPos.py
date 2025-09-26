# Create a sample file with some text
with open("sample.txt", "w") as f:
    f.write("This is a sample text file for cursor movement example.")

# Open the file in read mode
with open("sample.txt", "r") as f:
    print("Initial Cursor Position:", f.tell())
    
    f.seek(4)
    print("\nCursor moved to 4th position:", f.tell())
    
    data = f.read(5)
    print("Next 5 characters from 4th position:", data)
    
    f.seek(f.tell() + 10)
    print("\nCursor moved 10 characters ahead. Current Position:", f.tell())
    
    print("Current Cursor Position:", f.tell())
    
    data = f.read(10)
    print("Next 10 characters:", data)