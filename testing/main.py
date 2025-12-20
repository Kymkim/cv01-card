from playwright.sync_api import sync_playwright
import os
import secret

AUTH_FILE = "auth.json"

def scrape_player_data():

    playerData = []

    with sync_playwright() as p:
        browser = p.chromium.launch(headless=False)

        # Use existing auth if available
        if os.path.exists(AUTH_FILE):
            context = browser.new_context(storage_state=AUTH_FILE)
            print("Loaded saved authentication!")
        else:
            context = browser.new_context()
            print("No saved authentication, starting fresh...")

        page = context.new_page()
        page.goto("https://maimaidx-eng.com")

        # Check if login page
        if page.locator("input[type=password]").count() > 0:
            print("❌ Login required!")

            print("Please log in manually, then press ENTER here...")
            input()
            
            context.storage_state(path=AUTH_FILE)
            print("Authentication saved for future runs!")

        else:
            print("Already logged in via saved auth!")
            page.goto("https://maimaidx-eng.com/maimai-mobile/playerData/")

        print("Current page URL:", page.url)
        print("Rating:",page.locator("div.rating_block").text_content())

        browser.close()

scrape_player_data()