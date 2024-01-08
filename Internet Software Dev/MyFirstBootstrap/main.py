import flask
from flask import Flask

main = Flask(__name__)


@main.route('/')
def home():  # put application's code here
    return flask.render_template('home.html')


@main.route('/education/')
def education():  # put application's code here
    return flask.render_template('education.html')


@main.route('/work/')
def work():  # put application's code here
    return flask.render_template('work.html')


if __name__ == '__main__':
    main.run()
