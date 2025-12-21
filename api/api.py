from flask import Flask, request, jsonify
import scraper

app = Flask(__name__)

@app.route("/rhythm-games/maimai-data")
def get_maimai_data():
    data = scraper.scrape_player_data()
    if data:
        return jsonify(data), 200
    else:
        return jsonify(data), 500

if __name__ == "__main__":
    app.run(debug=True, port=8000)