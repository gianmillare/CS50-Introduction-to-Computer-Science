import random
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def home():
    random_number = random.randint(0, 1)
    return render_template("index.html", number=random_number )
    