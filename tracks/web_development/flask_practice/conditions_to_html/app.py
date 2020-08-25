from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/name")
def name():
    name = request.args.get("myname")
    if not name:
        return render_template("no_name.html")
    return render_template("yes_name.html", name=name)