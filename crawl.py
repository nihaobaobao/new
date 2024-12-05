# crawl somthing from the web

import requests
from bs4 import BeautifulSoup

def crawl(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    return soup

def main():
    url = 'https://www.google.com'
    soup = crawl(url)
    print(soup.prettify())

if __name__ == '__main__':
    main()
