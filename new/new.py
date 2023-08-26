from flask import Flask, render_template, request
import requests
import webbrowser
app = Flask(__name__)

OPENLIBRARY_BASE_URL = "https://openlibrary.org"
BOOKS_API_ENDPOINT = "/api/books"
SEARCH_API_ENDPOINT = "/search.json"

@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        search_query = request.form.get('search_query')
        if search_query:
            search_results = search_books(search_query)
            return render_template('index.html', search_results=search_results)
    
    return render_template('index.html', search_results=[])

def search_books(query):
    response = requests.get(f"{OPENLIBRARY_BASE_URL}{SEARCH_API_ENDPOINT}", params={'q': query})
    if response.status_code == 200:
        data = response.json()
        return data.get('docs', [])
    return []

if __name__ == '__main__':
    webbrowser.open('http://127.0.0.1:5000/')
    app.run(debug=True)
