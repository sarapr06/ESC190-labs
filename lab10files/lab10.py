import sys
from notopenai import NotOpenAI
import json
API_KEY = "cWgA9iOZwFAEtOz3josq"
CLIENT = NotOpenAI(api_key=API_KEY)
def get_response(prompt):
    chat_completion = CLIENT.chat.completions.create(
    messages=[
        {
            "role": "user",
            "content": prompt,
        }
    ],
    model="gpt-3.5-turbo", # the GPT model to use
)
    response_str = chat_completion.choices[0].message.content
    return response_str

def check_result(generated_code, test_cases):
    """
Check which test cases failed from the generated code
generated_code - str
test_caes - dict
e.g., if the generated_code is:
def fun(x):
return x
"""
    exec(generated_code, globals())
    passed=0
    failed=0
    for test in test_cases:
        input_value = test["input"]
        expected_output=test["expected_output"]
        result=None
        if input_value is not None:
            result=fun(input_value)
            print("input_value:" + str(input_value))
            print("result:" + str(result))
        if result==expected_output:
            passed+=1
        else:
            failed+=1
    print(f"\nTotal test cases: {len(test_cases)}")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")  

prompt = "consider s = 'Date,Character,Age,HeightCm,AppleCount,MoodRating 2025-01-15,Snow White,14,157.5,1,8.5 Doc,200,91.4,3,7.2 Prince,25,185.3,2,9. 2025-01-20,Huntsman,38,178.4,1,6.7.' if you were to prompt an AI with Write Python code to parse a CSV stringformatted like the following, into a dictionary with inputs Date,Character,Age,HeightCm,AppleCount,MoodRating, where character inputs are in that order. Result needs to be a dictionary of dictionaries -- Note that here, some dates and character names are missing, so PLEASE remember to be able to store values that may be missing information. PLEASE NAME THE FUNCTION THAT DOES THIS AS 'fun'"
example ='''here is an example test case:  "input:
2025-01-15,Snow White,14,157.5,1,8.5
2025-01-16,Grumpy,199,89.0,0,3.4
2025-01-17,Sleepy,202,90.2,1,6.3
,
        "expected_output": {
            'Snow White': {'Date': '2025-01-15', 'Character': 'Snow White', 'Age': '14', 'HeightCm': '157.5', 'AppleCount': '1', 'MoodRating': '8.5'},
            'Grumpy': {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '199', 'HeightCm': '89.0', 'AppleCount': '0', 'MoodRating': '3.4'},
            'Sleepy': {'Date': '2025-01-17', 'Character': 'Sleepy', 'Age': '202', 'HeightCm': '90.2', 'AppleCount': '1', 'MoodRating': '6.3'}
        }
'''
#
code=get_response(prompt + example + " do NOT respond to this in words, only write hte code")
print(code)
test_cases1= [
{"input": 3, "expected_output": 4},
{"input": 4, "expected_output": 5},
]

test_cases2 = [
    {
        "input": '''
2025-01-15,Snow White,14,157.5,1,8.5
2025-01-16,Grumpy,199,89.0,0,3.4
2025-01-17,Sleepy,202,90.2,1,6.3
''',
        "expected_output": {
            'Snow White': {'Date': '2025-01-15', 'Character': 'Snow White', 'Age': '14', 'HeightCm': '157.5', 'AppleCount': '1', 'MoodRating': '8.5'},
            'Grumpy': {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '199', 'HeightCm': '89.0', 'AppleCount': '0', 'MoodRating': '3.4'},
            'Sleepy': {'Date': '2025-01-17', 'Character': 'Sleepy', 'Age': '202', 'HeightCm': '90.2', 'AppleCount': '1', 'MoodRating': '6.3'}
        }
    },
    {
        "input": '''
2025-01-15,Snow White,14,157.5,1,8.5
2025-01-16,Grumpy,199,89.0,0,3.4
2025-01-17,Sleepy,,90.2,1,6.3
''',
        "expected_output": {
            'Snow White': {'Date': '2025-01-15', 'Character': 'Snow White', 'Age': '14', 'HeightCm': '157.5', 'AppleCount': '1', 'MoodRating': '8.5'},
            'Grumpy': {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '199', 'HeightCm': '89.0', 'AppleCount': '0', 'MoodRating': '3.4'},
            'Sleepy': {'Date': '2025-01-17', 'Character': 'Sleepy', 'Age': '', 'HeightCm': '90.2', 'AppleCount': '1', 'MoodRating': '6.3'}
        }
    },
]

#
#check_result(code, test_cases1)

#check_result(code, test_cases2)
'''documenting the one time it worked:
def fun(s):
    result = {}
    lines = s.split('\n')
    for line in lines:
        if line.strip() == '':
            continue
        parts = line.split(',')
        if len(parts) < 6:
            continue
        character = parts[1].strip()
        result[character] = {
            'Date': parts[0].strip(),
            'Character': character,
            'Age': parts[2].strip(),
            'HeightCm': parts[3].strip(),
            'AppleCount': parts[4].strip(),
            'MoodRating': parts[5].strip()
        }
    return result

print(fun('2025-01-15,Snow White,14,157.5,1,8.5\n2025-01-16,Grumpy,199,89.0,0,3.4\n2025-01-17,Sleepy,202,90.2,1,6.3\n'))
{'Snow White': {'Date': '2025-01-15', 'Character': 'Snow White', 'Age': '14', 'HeightCm': '157.5', 'AppleCount': '1', 'MoodRating': '8.5'}, 'Grumpy': {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '199', 'HeightCm': '89.0', 'AppleCount': '0', 'MoodRating': '3.4'}, 'Sleepy': {'Date': '2025-01-17', 'Character': 'Sleepy', 'Age': '202', 'HeightCm': '90.2', 'AppleCount': '1', 'MoodRating': '6.3'}}
input_value:
2025-01-15,Snow White,14,157.5,1,8.5
2025-01-16,Grumpy,199,89.0,0,3.4
2025-01-17,Sleepy,202,90.2,1,6.3

result:{'Snow White': {'Date': '2025-01-15', 'Character': 'Snow White', 'Age': '14', 'HeightCm': '157.5', 'AppleCount': '1', 'MoodRating': '8.5'}, 'Grumpy': {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '199', 'HeightCm': '89.0', 'AppleCount': '0', 'MoodRating': '3.4'}, 'Sleepy': {'Date': '2025-01-17', 'Character': 'Sleepy', 'Age': '202', 'HeightCm': '90.2', 'AppleCount': '1', 'MoodRating': '6.3'}}
input_value:
2025-01-15,Snow White,14,157.5,1,8.5
2025-01-16,Grumpy,199,89.0,0,3.4
2025-01-17,Sleepy,,90.2,1,6.3

result:{'Snow White': {'Date': '2025-01-15', 'Character': 'Snow White', 'Age': '14', 'HeightCm': '157.5', 'AppleCount': '1', 'MoodRating': '8.5'}, 'Grumpy': {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '199', 'HeightCm': '89.0', 'AppleCount': '0', 'MoodRating': '3.4'}, 'Sleepy': {'Date': '2025-01-17', 'Character': 'Sleepy', 'Age': '', 'HeightCm': '90.2', 'AppleCount': '1', 'MoodRating': '6.3'}}

Total test cases: 2
Passed: 2
Failed: 0'''



#chatgpt graph:
import numpy as np  # makes it easier

class Graph:
    def __init__(self, num_nodes):  # needs to know size/number of nodes
        self.adj_matrix = np.zeros((num_nodes, num_nodes))  # sets up nxn matrix filled with zeros

    def is_edge(self, i, j):  # check if there is an edge (friendship)
        return self.adj_matrix[i][j] == 1  # true if 1, false if 0

    def put_edge(self, i, j):  # add an edge (friendship)
        self.adj_matrix[i][j] = 1
        self.adj_matrix[j][i] = 1  # since friendships are undirected, we also add the reverse edge

    def remove_edge(self, i, j):  # remove an edge (break a friendship)
        self.adj_matrix[i][j] = 0
        self.adj_matrix[j][i] = 0  # remove the reverse edge as well

# Example: Graph representing a social network
if __name__ == "__main__":
    g = Graph(5)  # Create a graph with 5 people

    # Add friendships (edges)
    g.put_edge(0, 1)  # Person 0 is friends with Person 1
    g.put_edge(0, 2)  # Person 0 is friends with Person 2
    g.put_edge(1, 3)  # Person 1 is friends with Person 3
    g.put_edge(2, 3)  # Person 2 is friends with Person 3
    g.put_edge(3, 4)  # Person 3 is friends with Person 4

    # Check some relationships
    print("Are Person 0 and Person 1 friends?", g.is_edge(0, 1))  # Expected: True
    print("Are Person 0 and Person 3 friends?", g.is_edge(0, 3))  # Expected: False
    print("Are Person 1 and Person 3 friends?", g.is_edge(1, 3))  # Expected: True



#run with venv/bin/python lab10.py