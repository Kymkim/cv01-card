from playwright.sync_api import sync_playwright
import os
import json
import time
import random

AUTH_FILE = "auth.json"

def loop_scrape():
    while True:
        data = scrape_player_data()
        with open("data.json", "w") as json_file:
            json.dump(data, json_file)
        time.sleep(random.random(30,120))


def scrape_player_data():

    playerData = {}

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
            browser = p.chromium.launch(headless=False)
            context = browser.new_context()
            page = context.new_page()
            page.goto("https://maimaidx-eng.com")

            if page.locator("input[type=password]").count() > 0:
            print("Login with your account - Press Enter when done")
            return playerData
        else:
            print("Already logged in via saved auth!")
            page.goto("https://maimaidx-eng.com/maimai-mobile/playerData/")

        print("Current page URL:", page.url)
        print("Rating:",page.locator("div.rating_block").text_content())
        print("Username:")

        playerData["username"] = page.locator("div.name_block").text_content()
        playerData["rating"] = page.locator("div.rating_block").text_content()

        print(page.content())

        print(playerData)

        browser.close()
        return playerData

