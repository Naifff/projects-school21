from flask import Flask
from config import Config

app1 = Flask(__name__)
app1.config.from_object(Config)

from app import routes
