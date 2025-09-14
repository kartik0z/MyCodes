import requests
from requests.structures import CaseInsensitiveDict
    
url = "https://api.metals.dev/v1/latest?api_key=HGXF6AH7EAS6J5HKKZIM259HKKZIM&currency=USD&unit=toz"
headers = CaseInsensitiveDict()
headers["Accept"] = "application/json"

resp = requests.get(url, headers=headers)
print(resp)