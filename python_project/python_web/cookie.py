import requests
se=requests.session()
log_url= "https://ptlogin.4399.com/ptlogin/login.do?v=1"

log_headers={
    'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.128 Safari/537.36 Edg/89.0.774.77'
}
log_data={
    'password': '1998617',
    'username': 'ljxljx1998617'
}
log_rsp=se.post(url=log_url,headers=log_headers,data=log_data)
print(log_rsp.status_code)
#
ljx_url='https://u.4399.com/profile/'
ljx_rsp=se.get(url=ljx_url,headers=log_headers).text
print(ljx_rsp)
# txt=rspp.json()
# print(txt)
# with open("tmp",'w',encoding='utf-8') as fl:
#     fl.write(txt)
