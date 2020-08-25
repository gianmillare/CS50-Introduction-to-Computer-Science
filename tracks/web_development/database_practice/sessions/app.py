from flask import Flask, render_template, request, session, redirect
from flask_session import Session 

app = Flask(__name__)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

list_of_items = []

@app.route("/")
def task():
    if "list_of_items" not in session:
        session["list_of_items"] = []
    return render_template("tasks.html", items=session["list_of_items"])

@app.route("/add", methods=["GET", "POST"])
def add():
    if request.method == "GET":
        return render_template("add.html")
    else:
        new_item = request.form.get("task")
        session["list_of_items"].append(new_item)
        return redirect("/")