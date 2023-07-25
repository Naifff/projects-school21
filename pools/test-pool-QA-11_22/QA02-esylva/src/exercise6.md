
## POST /api/authorization/register


### Authorization
1. 
http://94.139.255.171:5000/api/authorization/register

Ожидаемый результат
Регистрация неуспешна (адрес электронной почты есть в базе)

Request Headers
Content-Type: application/json
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 957fe835-add0-4a43-b885-0c9517a2b737
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Content-Length: 243
Request Body
{
  "name": "string",
  "birthday": "2023-01-21T14:54:18.670Z",
  "sex": 0,
  "email": "user@example.com",
  "password": "string",
  "roleId": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
  "bankId": "3fa85f64-5717-4562-b3fc-2c963f66afa6"
}

Response Headers
Content-Type: text/plain; charset=utf-8
Date: Sun, 22 Jan 2023 15:21:32 GMT
Server: Kestrel
Transfer-Encoding: chunked
Response Body
User with this email adress already exist

Особенности запроса 
POST

2. 
http://94.139.255.171:5000/api/authorization/login

Ожидаемый результат: bearer token

Request Headers
Content-Type: application/json
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 957fe835-add0-4a43-b885-0c9517a2b737
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Content-Length: 243
Request Body
{
  "email": "user@example.com",
  "password": "string"
}

Response Headers
Content-Type: text/plain; charset=utf-8
Date: Sun, 22 Jan 2023 17:14:08 GMT
Server: Kestrel
Set-Cookie: refreshToken=dk1ImYgdIoIUZJi67kaqSgkLKk2b%2FZ0mNtKhLZghb4Rba4rnoW%2FZk7RpJIHON35BeSOlPcn8bXruSh0RI4UKiA%3D%3D; expires=Wed, 25 Jan 2023 17:14:08 GMT; path=/; httponly
Transfer-Encoding: chunked
Response Body
eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiJlNzQ2YTY1MC1iODNmLTRiYTYtOGQ2Mi1lMzFjOTIxMmVlYjAiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoic3RyaW5nIiwiaHR0cDovL3NjaGVtYXMueG1sc29hcC5vcmcvd3MvMjAwNS8wNS9pZGVudGl0eS9jbGFpbXMvZW1haWxhZGRyZXNzIjoidXNlckBleGFtcGxlLmNvbSIsImh0dHA6Ly9zY2hlbWFzLm1pY3Jvc29mdC5jb20vd3MvMjAwOC8wNi9pZGVudGl0eS9jbGFpbXMvcm9sZSI6IkFkbWluIiwiZXhwIjoxNjc0NDA5NDg4fQ.H_hFAKtlpxtblYQwLUXzbTQ3BMiwllk4xTB0OnkZPQnzpuBcOdVwG25MZp5nDfbOQU3ct9Z1OeTiIOpXj3-MEA

Особенности запроса 
POST

3. 
http://94.139.255.171:5000/api/authorization/refresh-token

Ожидаемый результат: изменение bearer token

Request Headers
Content-Type: application/json
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: a45d9775-6dc1-41dd-9559-cea7ddef3b2d
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Content-Length: 580
Cookie: refreshToken=dk1ImYgdIoIUZJi67kaqSgkLKk2b%2FZ0mNtKhLZghb4Rba4rnoW%2FZk7RpJIHON35BeSOlPcn8bXruSh0RI4UKiA%3D%3D
Request Body
"eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiJlNzQ2YTY1MC1iODNmLTRiYTYtOGQ2Mi1lMzFjOTIxMmVlYjAiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoic3RyaW5nIiwiaHR0cDovL3NjaGVtYXMueG1sc29hcC5vcmcvd3MvMjAwNS8wNS9pZGVudGl0eS9jbGFpbXMvZW1haWxhZGRyZXNzIjoidXNlckBleGFtcGxlLmNvbSIsImh0dHA6Ly9zY2hlbWFzLm1pY3Jvc29mdC5jb20vd3MvMjAwOC8wNi9pZGVudGl0eS9jbGFpbXMvcm9sZSI6IkFkbWluIiwiZXhwIjoxNjc0NDA5NDg4fQ.H_hFAKtlpxtblYQwLUXzbTQ3BMiwllk4xTB0OnkZPQnzpuBcOdVwG25MZp5nDfbOQU3ct9Z1OeTiIOpXj3-MEA"

Response Headers
Content-Type: text/plain; charset=utf-8
Date: Sun, 22 Jan 2023 17:17:29 GMT
Server: Kestrel
Set-Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D; expires=Wed, 25 Jan 2023 17:17:29 GMT; path=/; httponly
Transfer-Encoding: chunked
Response Body
eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiJlNzQ2YTY1MC1iODNmLTRiYTYtOGQ2Mi1lMzFjOTIxMmVlYjAiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoic3RyaW5nIiwiaHR0cDovL3NjaGVtYXMueG1sc29hcC5vcmcvd3MvMjAwNS8wNS9pZGVudGl0eS9jbGFpbXMvZW1haWxhZGRyZXNzIjoidXNlckBleGFtcGxlLmNvbSIsImh0dHA6Ly9zY2hlbWFzLm1pY3Jvc29mdC5jb20vd3MvMjAwOC8wNi9pZGVudGl0eS9jbGFpbXMvcm9sZSI6IkFkbWluIiwiZXhwIjoxNjc0NDA5Njg5fQ.iwKPiWr09tCVNRRqJAMOydLYbgSIRvCRegm6HE2QqRacMvNaVO6_fjll4FFtFvr7s-LW4lnMqA34FD5S-llVig

Особенности запроса 
POST

### Bank

1. POST api/banks
http://94.139.255.171:5000/api/banks

Ожидаемый результат: недостаточно прав

Request Headers
Content-Type: application/json
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 3992229e-c79a-475b-83e2-d494d81d344c
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Content-Length: 104
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Request Body
Response Headers
Content-Length: 0
Date: Sun, 22 Jan 2023 17:26:59 GMT
Server: Kestrel
WWW-Authenticate: Bearer
Response Body

Особенности запроса 
Требуется авторизация администратором

2. GET api/banks
http://94.139.255.171:5000/api/banks?skip=2&limit=2

Ожидаемый результат: Список из двух банков

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 10524029-ac4a-418f-8c5c-863aae66a121
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Request Body

Response Headers
Content-Type: application/json; charset=utf-8
Date: Sun, 22 Jan 2023 17:37:26 GMT
Server: Kestrel
Transfer-Encoding: chunked
Response Body
[{"bankId":"63b02cf9-9125-4e02-ac24-5b5c72a43d94","name":"Alfa-Bank","description":"Modern bank","state":2,"rating":5,"shortName":"Alfa"},{"bankId":"dcf18fa5-fbf0-41b5-bd7c-0ce972e192a2","name":"Erryk Sylva's Bank","description":"Erryk Sylva's Bank","state":2,"rating":0,"shortName":"ESB"}]

Особенности запроса 
можно указать лимит отзывов и пропуск отзывов

3. PATCH api/banks{id}
http://94.139.255.171:5000/api/banks/ed36e8a3-2446-468a-a8f5-77f1382045ac

Ожидаемый результат: недостаточно прав

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 41289056-3ac4-4ea9-a637-a8912c4e41ac
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Content-Length: 0
Request Body
Response Headers
Content-Length: 0
Date: Sun, 22 Jan 2023 17:41:32 GMT
Server: Kestrel
WWW-Authenticate: Bearer
Response Body

Особенности запроса 
Требуется авторизация администратором

4. DELETE api/banks{id}

http://94.139.255.171:5000/api/banks/ed36e8a3-2446-468a-a8f5-77f1382045ac

Ожидаемый результат: недостаточно прав

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 41289056-3ac4-4ea9-a637-a8912c4e41ac
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Content-Length: 0
Request Body
Response Headers
Content-Length: 0
Date: Sun, 22 Jan 2023 17:42:11 GMT
Server: Kestrel
WWW-Authenticate: Bearer
Response Body

Особенности запроса 
Требуется авторизация администратором

5. GET api/banks{id}

http://94.139.255.171:5000/api/banks/ed36e8a3-2446-468a-a8f5-77f1382045ac

Ожидаемый результат: информация о банке

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 04b31c71-2589-49be-8144-24a2ee457bbc
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Request Body

Response Headers
Content-Type: application/json; charset=utf-8
Date: Sun, 22 Jan 2023 17:52:15 GMT
Server: Kestrel
Transfer-Encoding: chunked
Response Body
{"bankId":"ed36e8a3-2446-468a-a8f5-77f1382045ac","name":"Выхухоль-Банк","description":"Банк для сбора средств для животных","state":2,"rating":0,"shortName":"ВБ"}

Особенности запроса 
нет

6. GET api/banks{id}

http://94.139.255.171:5000/api/banks/Name?name=Er&skip=1&limit=1

Ожидаемый результат: список из одного банка

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 067940d3-37b7-4130-92a1-265ac792089f
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Request Body

Response Headers
Content-Type: application/json; charset=utf-8
Date: Sun, 22 Jan 2023 17:56:45 GMT
Server: Kestrel
Transfer-Encoding: chunked
Response Body
[{"bankId":"1dc808f0-d45f-4baa-b3c2-694e3b83020a","name":"Sberbank","description":"Super bank!","state":2,"rating":0,"shortName":"Sber"}]

Особенности запроса 
нет

7. GET api/banks{id}/feedbacks
http://94.139.255.171:5000/api/banks/1dc808f0-d45f-4baa-b3c2-694e3b83020a/feedbacks

Ожидаемый результат: список отзывов (пустой список при их отсутствии)

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 23997dd0-41b8-4b65-bce3-45f5f68ec5d0
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Request Body

Response Headers
Content-Type: application/json; charset=utf-8
Date: Sun, 22 Jan 2023 17:59:00 GMT
Server: Kestrel
Transfer-Encoding: chunked
Response Body
[]

Особенности запроса 
можно указать лимит отзывов и пропуск отзывов

8. GET api/banks{id}/employee
http://94.139.255.171:5000/api/banks/dcf18fa5-fbf0-41b5-bd7c-0ce972e192a2/employee

Ожидаемый результат: недостаточно прав

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 23997dd0-41b8-4b65-bce3-45f5f68ec5d0
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Request Body

Response Headers
Content-Type: application/json; charset=utf-8
Date: Sun, 22 Jan 2023 17:59:00 GMT
Server: Kestrel
Transfer-Encoding: chunked
Response Body
[]

Особенности запроса 
Требуется авторизация администратором
можно указать лимит отзывов и пропуск отзывов

9. GET api/banks{id}/products

http://94.139.255.171:5000/api/banks/1dc808f0-d45f-4baa-b3c2-694e3b83020a/products

Ожидаемый результат: список отзывов (пустой список при их отсутствии)

Request Headers
User-Agent: PostmanRuntime/7.30.0
Accept: */*
Cache-Control: no-cache
Postman-Token: 186da1a6-4a12-4224-a066-9b0a4316852c
Host: 94.139.255.171:5000
Accept-Encoding: gzip, deflate, br
Connection: keep-alive
Cookie: refreshToken=vgA7Gdei4M7%2FI0heEdM8j4L23KCf5C6PQyifs07tEBJdlkGolqnJ0t1H9%2FP9IwWi%2B0l36xePjshbwOz%2B%2FHvrCg%3D%3D
Request Body

Response Headers
Content-Type: application/json; charset=utf-8
Date: Sun, 22 Jan 2023 18:13:12 GMT
Server: Kestrel
Transfer-Encoding: chunked
Response Body
[]

Особенности запроса 
можно указать лимит отзывов и пропуск отзывов
