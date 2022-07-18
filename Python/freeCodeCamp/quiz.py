class Question:
    def __init__(self, question, answer):
        self.question = question
        self.answer = answer

questions = [
    Question("What's the color of a banana?\na) Red\nb) Yellow\nc) Blue\n", "b"),
    Question("How many faces does a cube have?\na) 4\nb) 6\nc) 8\n", "b"),
    Question("How many millimeters does a meter have?\na) 100\nb) 1000\nc) 10000\n", "b")
]


def run_quiz():
    score = 0
    for question in questions:
        print(question.question)
        answer = input("Type a letter: ")
        if answer == question.answer:
            score += 1
    
    print("Score " + str(score) + "/" + str(len(questions)))

run_quiz()
