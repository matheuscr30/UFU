import os
from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello():
    response = f'Hello World from Server {os.environ.get("NUM_SERVER")}'
    return response

if __name__ == "__main__":
    app.run(host = "0.0.0.0", port = int("5000"), debug = True)
