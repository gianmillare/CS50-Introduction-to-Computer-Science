from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/submit_email")
def submit_email():
    email = request.args.get("email")
    return render_template("formcompleted.html", email=email)