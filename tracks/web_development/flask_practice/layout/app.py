from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/layout")
def layout():
    name = request.args.get("layout")
    if not name:
        return render_template("no_name.html")
    return render_template("name.html", name=name)