import time
import requests
import logging
import http.client
from requests.exceptions import RequestException

# Enable HTTP debugging
http.client.HTTPConnection.debuglevel = 1
logging.basicConfig(level=logging.DEBUG)
logging.getLogger("urllib3").setLevel(logging.DEBUG)

# Function to send login request with retries
def send_login_request_with_retry():
    url = "http://10.250.209.251:1000/login"
    headers = {
        "4Tredir": "http://10.250.209.251:1000/login?040231f1c1f5eae7",
        "Content-Type": "application/x-www-form-urlencoded",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/132.0.0.0 Safari/537.36",
        "Connection": "keep-alive"
    }
    data = {
        "magic": "06063afbc1fce9fd",
        "username": "2203101",
        "password": "BTech#22@"
    }

    retries = 5  # Number of retry attempts
    for attempt in range(retries):
        try:
            print(f"Attempting login... Try {attempt + 1}")
            response = requests.post(url, headers=headers, data=data, timeout=10)
            print(f"Login request sent. Status code: {response.status_code}, Response: {response.text}")
            return True
        except RequestException as e:
            print(f"Attempt {attempt + 1} failed: {e}")
            time.sleep(2 ** attempt)  # Exponential backoff

    print("All login retries failed.")
    return False

# Function to send logout request
def send_logout_request():
    url = "http://10.250.209.251:1000/logout?0c030c03080f0009"
    headers = {
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
        "Accept-Encoding": "gzip, deflate",
        "Accept-Language": "en-US,en;q=0.9,ru;q=0.8",
        "Connection": "keep-alive",
        "Host": "10.250.209.251:1000",
        "Referer": "http://10.250.209.251:1000/keepalive?0e0800080b030800",
        "Upgrade-Insecure-Requests": "1",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/132.0.0.0 Safari/537.36"
    }

    try:
        print("Sending logout request...")
        response = requests.get(url, headers=headers, timeout=10)
        print(f"Logout request sent. Status code: {response.status_code}, Response: {response.text}")
    except RequestException as e:
        print(f"An error occurred during logout: {e}")

# Main script to manage login and logout requests
if __name__ == "__main__":
    print("Starting background request sender...")
    while True:
        send_logout_request()
        print("Attempting login...")
        login_success = send_login_request_with_retry()
        
        if login_success:
            print("Login successful. Waiting for 2 hours before logout...")
        else:
            print("Login failed. Skipping logout and retrying in 2 hours.")

        time.sleep(2 * 60 * 60)  # Wait 2 hours
        
        if login_success:  # Only send logout if login was successful
            send_logout_request()
            print("Logout completed. Waiting for 2 hours before the next login...")
            time.sleep(2 * 60 * 60)  # Wait another 2 hours
