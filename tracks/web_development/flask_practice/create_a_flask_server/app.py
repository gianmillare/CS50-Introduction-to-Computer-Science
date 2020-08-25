import random
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/") #This is the default webpage (homepage)
def index():
    random_number = random.randint(1, 100)
    return render_template("index.html", name="Gian Millare", number=random_number)

@app.route("/goodbye")
def bye():
    return "Goodbye!"