import sqlite3
from flask import Flask, render_template, request, redirect

app = Flask(__name__)
conn = sqlite3.connect('lecture.db', check_same_thread=False)
c = conn.cursor()

@app.route("/")
def index():
    rows = c.execute("SELECT * FROM registrants;")
    return render_template("index.html", rows=rows)

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "GET":
        return render_template("register.html")
    else:
        name = request.form.get("name")
        if not name:
            return render_template("/apology.html", message="You must provide a name!")
        email = request.form.get("email")
        if not email:
            return render_template("apology.html", message="You must provide an email address!")
        c.execute("INSERT INTO registrants (name, email) VALUES (?,?)", (name, email))
        conn.commit()
        return redirect("/")


# @app.route("/")
# def index():
#     with sqlite3.connect('lecture.db') as conn:
#         c = conn.cursor()
#         rows = c.execute("SELECT * FROM registrants;")
#         return render_template("index.html", rows=rows)