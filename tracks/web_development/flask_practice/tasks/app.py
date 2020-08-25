from flask import Flask, render_template, request, redirect

app = Flask(__name__)

list_of_items = []

@app.route("/")
def task():
    return render_template("task.html", items=list_of_items)

@app.route("/add", methods=["GET", "POST"])
def add():
    if request.method == "GET":
        return render_template("add.html")
    else:
        new_item = request.form.get("task")
        list_of_items.append(new_item)
        return redirect("/")