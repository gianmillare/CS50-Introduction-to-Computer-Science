from flask import Flask, render_template

app = Flask(__name__)

@app.route("/") #This is the default webpage (homepage)
def index():
    return render_template("index.html")

@app.route("/goodbye")
def bye():
    return "Goodbye!"