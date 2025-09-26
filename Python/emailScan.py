# Write a program that scans an email address and forms a tuple of user name and domain.

dummy_mail = "example@gmail.com"

user_name = dummy_mail.split("@")[0]
domain = dummy_mail.split("@")[1]
email_tuple = (user_name, domain)
print(f"Email: {dummy_mail}\nTuple: {email_tuple}")