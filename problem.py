from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
import time

# Set up Chrome options
chrome_options = Options()
chrome_options.add_argument("--headless")  # Run in background (remove if you want to see it)
chrome_options.add_argument("--no-sandbox")
chrome_options.add_argument("--disable-dev-shm-usage")

# Set up ChromeDriver path
chromedriver_path = "/path/to/chromedriver"  # Update with actual path
service = Service(chromedriver_path)

# Number of visits
num_visits = 10

# GitHub Profile URL
url = "https://github.com/nandeeshbhatrai"

# Launch browser and visit profile multiple times
for i in range(num_visits):
    driver = webdriver.Chrome(service=service, options=chrome_options)
    driver.get(url)
    time.sleep(5)  # Wait to simulate real browsing
    driver.quit()
    print(f"Visit {i+1} completed.")

print("All visits done!")
