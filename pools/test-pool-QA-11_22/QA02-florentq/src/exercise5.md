# Authorization

## POST /authorization​/register
### Test Case 1. Проверка эндпоинта POST /authorization​/login
![register](misc/images/register.png) 
- URL: http://94.139.255.171:5000/api/authorization/register
- Request Headers
    ```
    Content-Type: application/json
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: c4fc9371-01b8-4a90-81e4-c02370f68399
    Host: 94.139.255.171:5000
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
     ```
- Request Body
    ```
    {
  "name": "04Di",
  "birthday": "2023-03-04T12:52:55.675Z",
  "sex": 0,
  "email": "41022024@example.com",
  "password": "4022024",
  "roleId": "b6ac9a45-4032-4289-b439-2cc4d65c3f18"
    }
    ```
- Response Headers
    ```
    Content-Type: application/json; charset=utf-8
    Date: Sat, 04 Feb 2023 14:41:30 GMT
    Server: Kestrel
    Location: /api/users/f8bb8bab-f6b7-4744-9082-cf448c00591e
    Transfer-Encoding: chunked    
    ```
- Response Body
    ```
    {
    "userId": "f8bb8bab-f6b7-4744-9082-cf448c00591e",
    "name": "04Di",
    "birthaday": "2023-03-04T12:52:55.675Z",
    "sex": 0,
    "email": "41022024@example.com",
    "roleId": "b6ac9a45-4032-4289-b439-2cc4d65c3f18",
    "bankId": null,
    "state": 0
    }
    ```

`Resolution: Passed. Everything is OK.`

## {+ POST /authorization​/login +}
### Test-case 2. Проверка эндпоинта POST /authorization​/register
![postlogin](misc/images/postlogin.png) 
- URL: http://94.139.255.171:4200/api/authorization/login
- Expected result: Code 200, access token
- Request Headers
    ```
    Content-Type: application/json
    Cache-Control: no-cache
    Postman-Token: 33465d2e-c46b-48a8-b3cc-f3c8d2fcc7e1
    Cookie:
    refreshToken=pMzaxZjRhPNx8l%2BBiPUCSHU58Wl0yy6Ga9Oe7Pp02pYO2rnvJNnZGfazfs5l%2F5P3l%2BEVgKe4%2FsI5YqVsEsJVxQ%3D%3D
      ```  
- Request Body
    ```
    {
    "email": "admin@mail.ru",
    "password": "Admin"
    }
    ```
- Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: text/plain; charset=utf-8
    date: Sat, 04 Feb 2023 14:50:09 GMT
    server: Kestrel
    set-cookie: refreshToken=SgVRk1RZA2mPVQPRRsjtx8RUjj%2FgNyRDd41GzUMOzQ9yybdinePlsPfOYSUqQ4q7yUiIZBo6MKEG2EWp1DfxzQ%3D%3D; expires=Tue, 07 Feb 2023 14:50:09 GMT; path=/; httponly
    transfer-encoding: chunked
    ```
- Response Body
    "eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1MjQwNDl9.ujxuCNc7mIwTYm8JkCrC7SgRxkX1oLI8Bb-FUjDoOrUWN__kDmRakxPVp2E3L0_ab1rJ7YAzf_ltbuJH4cFltg"

`Resolution: Passed. Everything is OK.`

## POST /authorization​/refresh-token
### Test-case 3. Проверка эндпоинта POST /authorization​/refresh-token
- URL: http://94.139.255.171:4200/api/authorization/refresh-token
- Expected result: Code 200, new token
- Request Headers
    ```
    Content-Type: application/json
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: 89bc62b3-546b-4d67-966e-7e10149f7c07
    Host: 94.139.255.171:4200
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    Cookie: refreshToken=SgVRk1RZA2mPVQPRRsjtx8RUjj%2FgNyRDd41GzUMOzQ9yybdinePlsPfOYSUqQ4q7yUiIZBo6MKEG2EWp1DfxzQ%3D%3D
    ```
- Request Body
    "eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1MjQwNDl9.ujxuCNc7mIwTYm8JkCrC7SgRxkX1oLI8Bb-FUjDoOrUWN__kDmRakxPVp2E3L0_ab1rJ7YAzf_ltbuJH4cFltg"
 - Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: text/plain; charset=utf-8
    date: Sat, 04 Feb 2023 14:59:27 GMT
    server: Kestrel
    set-cookie: refreshToken=FRLPEIk2DtLYlGazDOXTs3XxU%2FZA0%2B7IjASBBAHrF2cN%2Fm4SdePU6Oqpih6OrcPF9zY4aGfEQkPYQdlPQ7YR1Q%3D%3D; expires=Tue, 07 Feb 2023 14:59:28 GMT; path=/; httponly
    transfer-encoding: chunked   
    ```
- Response Body
    ```
    "eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1MjQ2MDh9.AlXwz6Q35ECbKzTpqJrJU4SS_-T4XDmAi-b25zCXwIcQjUHsbd1KGOr9AQVJd_Lz6os538Ni3Si598RkHYBWJA"
     ```

`Resolution: Passed. Everything is OK.`


    
# Banks
## POST /api/banks
### Test-case 4. Проверка эндпоинта POST /api/banks
- URL: http://94.139.255.171:4200/api/banks
- Expected result: Code 201, new bank created
- Request Headers
    ```
    Authorization: Bearer eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1MjQ2MDh9.AlXwz6Q35ECbKzTpqJrJU4SS_-T4XDmAi-b25zCXwIcQjUHsbd1KGOr9AQVJd_Lz6os538Ni3Si598RkHYBWJA
    Content-Type: application/json
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: dff5727e-7df1-4372-9200-98c76e01ee20
    Host: 94.139.255.171:4200
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    Cookie: refreshToken=FRLPEIk2DtLYlGazDOXTs3XxU%2FZA0%2B7IjASBBAHrF2cN%2Fm4SdePU6Oqpih6OrcPF9zY4aGfEQkPYQdlPQ7YR1Q%3D%3D
    ```
- Request Body
    ```
    {
  "name": "Qawsedr",
  "description": "Qawsedr Qawsder",
  "shortName": "Qawsder"
    }
    ```
- Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: application/json; charset=utf-8
    date: Sat, 04 Feb 2023 15:14:39 GMT
    server: Kestrel
    location: /api/banks/6bbf0ef4-4ff7-454f-b031-0dd79408149b
    transfer-encoding: chunked
    ```
- Response Body
    ```
    {
    "bankId": "6bbf0ef4-4ff7-454f-b031-0dd79408149b",
    "name": "Qawsedr",
    "description": "Qawsedr Qawsder",
    "state": 2,
    "rating": 0,
    "shortName": "Qawsder"
    }
    ```

`Resolution: Passed. Everything is OK.`

### Test-case 13. Проверка эндпоинта POST /api/banks со старым токеном bearer
- URL: http://94.139.255.171:4200/api/banks
- Expected result: Code 403, Error: Forbidden.
- Request Headers
    ```
    Authorization: Bearer eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1MjQwNDl9.ujxuCNc7mIwTYm8JkCrC7SgRxkX1oLI8Bb-FUjDoOrUWN__kDmRakxPVp2E3L0_ab1rJ7YAzf_ltbuJH4cFltg
    Content-Type: application/json
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: fd149613-0dab-4d56-871d-46f6a8611d7b
    Host: 94.139.255.171:4200
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    ```
- Request Body
    ```   
     {
    "name": "Qawsedr",
    "description": "Qawsedr Qawsder",
    "shortName": "Qawsder"
    }
    ```
- Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: application/json; charset=utf-8
    date: Sat, 04 Feb 2023 15:18:33 GMT
    server: Kestrel
    location: /api/banks/280362b7-ac15-4722-bfa4-e5666007eaf2
    transfer-encoding: chunked
    ```
- Response Body
    ```
    {
    "bankId": "280362b7-ac15-4722-bfa4-e5666007eaf2",
    "name": "Qawsedr",
    "description": "Qawsedr Qawsder",
    "state": 2,
    "rating": 0,
    "shortName": "Qawsder"
    }
    ```

``Resolution: Fail. Bank created with Authorization after refresh-token``

## GET /api/banks
### Test-case 5. Проверка эндпоинта GET /api/banks
![apibanks](misc/images/apibanks.png)
- URL: http://94.139.255.171:4200/api/banks
- Expected result: Code 201, list of registered banks
- Request Headers
    ```
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: 362060c2-9511-4ec3-bf1e-73250eab45e6
    Host: 94.139.255.171:4200
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    ```
- Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: application/json; charset=utf-8
    date: Sat, 04 Feb 2023 15:41:45 GMT
    server: Kestrel
    transfer-encoding: chunked
    ```
- Response Body
    ```
    {
        "bankId": "f5157c9f-c8d8-4561-9f05-1104babd5067",
        "name": "",
        "description": "new1",
        "state": 2,
        "rating": 0,
        "shortName": "SI"
    },
    {
        "bankId": "c06ae5f3-788b-4a74-a9fe-d22d10da2da9",
        "name": "5565 edited1",
        "description": "Yem1",
        "state": 2,
        "rating": 0,
        "shortName": "55651"
    },
    {
        "bankId": "48dd1139-c2c0-47cf-98c1-c143b0a48c25",
        "name": "A-Bank",
        "description": "Описание банка",
        "state": 2,
        "rating": 4.2222223,
        "shortName": "A"
    },
    {
        "bankId": "63b02cf9-9125-4e02-ac24-5b5c72a43d94",
        "name": "Alfa-Bank",
        "description": "Modern bank",
        "state": 2,
        "rating": 4.6666665,
        "shortName": "Alfa"
    },
    {
        "bankId": "3212f61b-b058-4dff-a81e-4c71cc580865",
        "name": "Alfa-Bank",
        "description": "Modern bank",
        "state": 2,
        "rating": 0,
        "shortName": "Alfa"
    },
    {
        "bankId": "dcf18fa5-fbf0-41b5-bd7c-0ce972e192a2",
        "name": "Erryk Sylva's Bank",
        "description": "Erryk Sylva's Bank",
        "state": 2,
        "rating": 0,
        "shortName": "ESB"
    },
    {
        "bankId": "199feece-107c-4c63-8c9b-c043051d15bf",
        "name": "Giorgio",
        "description": "дубль",
        "state": 2,
        "rating": 0,
        "shortName": "Jo-jo"
    },
    {
        "bankId": "e4895eb2-b749-4ad8-bfdb-4cf81e0c7249",
        "name": "Giorgio",
        "description": "perfecto",
        "state": 2,
        "rating": 0,
        "shortName": "Jo-jo"
    },
    {
        "bankId": "3790d90d-4179-4e9e-9fae-0c3e0c5989a4",
        "name": "Kek",
        "description": "The key.",
        "state": 2,
        "rating": 5,
        "shortName": "k"
    },
    {
        "bankId": "f6bc142e-cb97-42d0-bb38-79be00cdd44c",
        "name": "lklk",
        "description": "hhhhhhh",
        "state": 2,
        "rating": 0,
        "shortName": "lk"
    },
    {
        "bankId": "d2e28d2d-5da9-4b97-a1df-887327121108",
        "name": "NewAlFA",
        "description": "string",
        "state": 2,
        "rating": 0,
        "shortName": "string"
    },
    {
        "bankId": "9a5701cb-0941-4201-a72f-39e5fbdd4b4d",
        "name": "NewSber",
        "description": "super",
        "state": 2,
        "rating": 0,
        "shortName": "NS"
    },
    {
        "bankId": "291e916b-5283-4a17-b875-6887a89d3cb9",
        "name": "omega bank",
        "description": "я не альфа я омега",
        "state": 2,
        "rating": 4,
        "shortName": "obank"
    },
    {
        "bankId": "1406aa87-00bc-4ed5-a128-8e61242de10e",
        "name": "PlastiqBank",
        "description": "The number one",
        "state": 2,
        "rating": 4.6666665,
        "shortName": "PBank"
    },
    {
        "bankId": "6bbf0ef4-4ff7-454f-b031-0dd79408149b",
        "name": "Qawsedr",
        "description": "Qawsedr Qawsder",
        "state": 2,
        "rating": 0,
        "shortName": "Qawsder"
    },
    {
        "bankId": "280362b7-ac15-4722-bfa4-e5666007eaf2",
        "name": "Qawsedr",
        "description": "Qawsedr Qawsder",
        "state": 2,
        "rating": 0,
        "shortName": "Qawsder"
    },
    {
        "bankId": "87424bab-8fc1-430c-b0a8-dd34f8bb8315",
        "name": "Rich-Bank",
        "description": "Описание банка",
        "state": 2,
        "rating": 0,
        "shortName": "RB"
    },
    {
        "bankId": "9f9d01b0-b7a9-4851-aae0-c87daf1d62c6",
        "name": "Rich-Bank",
        "description": "Описание банка",
        "state": 2,
        "rating": 0,
        "shortName": "RB"
    },
    {
        "bankId": "1dc808f0-d45f-4baa-b3c2-694e3b83020a",
        "name": "Sberbank",
        "description": "Super bank!",
        "state": 2,
        "rating": 0,
        "shortName": "Sber"
    },
    {
        "bankId": "ce41ed04-90dd-4c7a-af3a-afb32d379a5c",
        "name": "Sberbank",
        "description": "Double bank",
        "state": 2,
        "rating": 0,
        "shortName": "Sber"
    },
    {
        "bankId": "1660e6cd-41ec-4651-b0db-34b492f140db",
        "name": "SberIp",
        "description": "new1",
        "state": 2,
        "rating": 0,
        "shortName": "SI"
    },
    {
        "bankId": "905f39ae-218e-41e6-b204-4110c27721e2",
        "name": "SberIp",
        "description": "new1",
        "state": 2,
        "rating": 0,
        "shortName": "SI"
    },
    {
        "bankId": "f20bae8a-a9fa-434a-9193-e35c37e7dde5",
        "name": "Scoleray",
        "description": "ьь",
        "state": 2,
        "rating": 0,
        "shortName": "Scoleray"
    },
    {
        "bankId": "ebfe6fa0-d224-4585-83dd-ec40ed78b1d4",
        "name": "Scoleray",
        "description": "Банк - всегда рядом с домом",
        "state": 2,
        "rating": 0,
        "shortName": "SY"
    },
    {
        "bankId": "f43c1b80-9668-4659-8365-d55c981bd704",
        "name": "Scoleray",
        "description": "",
        "state": 2,
        "rating": 0,
        "shortName": ""
    },
    {
        "bankId": "63790786-d866-4654-9ccb-1a0b9e1d0766",
        "name": "SCOLERAY",
        "description": "Это только начало",
        "state": 2,
        "rating": 0,
        "shortName": "SCOLERAY"
    },
    {
        "bankId": "a1eb1b61-c9ea-4a61-81cc-8152a2975e58",
        "name": "SCOLERAY",
        "description": "",
        "state": 2,
        "rating": 0,
        "shortName": ""
    },
    {
        "bankId": "c58cfe01-21d8-4447-b6d3-62b19a7d16bf",
        "name": "ShlyapaBank",
        "description": "Лучше чем шляпа, но это не точно",
        "state": 2,
        "rating": 0,
        "shortName": "SHB"
    },
    {
        "bankId": "b62a5eb9-b45a-4ffc-971e-6ec5e3283651",
        "name": "string",
        "description": "string",
        "state": 2,
        "rating": 0,
        "shortName": "string"
    },
    {
        "bankId": "fd52c5a3-929f-463a-b585-2ea03bb5b24e",
        "name": "string",
        "description": "string",
        "state": 2,
        "rating": 0,
        "shortName": "string"
    },
    {
        "bankId": "c0355ade-15c9-4b1b-8099-e914adfafcae",
        "name": "string",
        "description": "string",
        "state": 2,
        "rating": 0,
        "shortName": "string"
    },
    {
        "bankId": "7aace393-872a-4dbb-b86d-7c79088aada4",
        "name": "string",
        "description": "string",
        "state": 2,
        "rating": 0,
        "shortName": "string"
    },
    {
        "bankId": "0b1e3ac8-f291-44ec-b282-7866bcbd6800",
        "name": "string",
        "description": "string",
        "state": 2,
        "rating": 0,
        "shortName": "string"
    },
    {
        "bankId": "ce6dca63-8310-490e-8f29-b4b9120acd6b",
        "name": "string",
        "description": "long integer",
        "state": 2,
        "rating": 0,
        "shortName": "longint"
    },
    {
        "bankId": "736726d5-7984-4be1-b99a-c13a9a348b91",
        "name": "string",
        "description": "string",
        "state": 2,
        "rating": 0,
        "shortName": "string"
    },
    {
        "bankId": "680b6b29-6dcc-4276-b554-a44bd8ec631d",
        "name": "test11",
        "description": "test",
        "state": 2,
        "rating": 0,
        "shortName": "t11"
    },
    {
        "bankId": "22dd818f-30f6-4655-a9f0-6b041e1c0e9f",
        "name": "test11",
        "description": "test test",
        "state": 2,
        "rating": 0,
        "shortName": "t11"
    },
    {
        "bankId": "85bcc92d-84f6-4149-91d3-3ce42e8c6674",
        "name": "TintinBank",
        "description": "Тиньтиньбанк",
        "state": 2,
        "rating": 0,
        "shortName": "Tintin"
    },
    {
        "bankId": "14043429-7962-4ff9-a631-949851ab32e6",
        "name": "Uralsib",
        "description": "Not modern bank",
        "state": 2,
        "rating": 0,
        "shortName": "Ural"
    },
    {
        "bankId": "ed36e8a3-2446-468a-a8f5-77f1382045ac",
        "name": "Выхухоль-Банк",
        "description": "Банк для сбора средств для животных",
        "state": 2,
        "rating": 0,
        "shortName": "ВБ"
    },
    {
        "bankId": "69613d84-8d38-499c-bab7-e2e9af928d77",
        "name": "Сбербанк",
        "description": "Отличный интернет-банк.",
        "state": 2,
        "rating": 0,
        "shortName": "Sber"
    },
    {
        "bankId": "b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1",
        "name": "Сбербанк",
        "description": "Отличный интернет-банк.",
        "state": 2,
        "rating": 0,
        "shortName": "Sber"
    }
    ```

``Resolution: Passed. Everything is OK.``

## PATCH /api/banks/id
### Test-case 6. Проверка эндпоинта PATCH /api/banks/id
- URL: http://94.139.255.171:4200/api/banks/280362b7-ac15-4722-bfa4-e5666007eaf2
- Expected result: Code 200, return updated banks
- Request Headers
    ```
    Authorization: Bearer eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1Mjc2OTh9.SYep0eRmjZh5xmr4bzDszLMvCURNGXYnEyBR5gkg0vJfrOAwa8xEeWoQZ2HASyPA5pDvqoF3CQCUnjlZ6HR6PQ
    Content-Type: application/json
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: b507cd57-696f-405a-9e58-4858f42850b8
    Host: 94.139.255.171:4200
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    ```
- Request Body
    ```   
     {
        "name": "Qawsedr",
        "description": "Qaw Qaws",
        "shortName": "Qaw"
      }
    ```
- Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: application/json; charset=utf-8
    date: Sat, 04 Feb 2023 15:51:06 GMT
    server: Kestrel
    transfer-encoding: chunked
    ```
- Response Body
    ```
    {
    "bankId": "280362b7-ac15-4722-bfa4-e5666007eaf2",
    "name": "Qawsedr",
    "description": "Qaw Qaws",
    "state": 2,
    "rating": 0,
    "shortName": "Qaw"
    }
    ```

``Resolution: Passed. Everything is OK.``

## DELETE /api/banks/id
### Test-case 7. Проверка эндпоинта DELETE /api/banks/id
- URL: http://94.139.255.171:4200/api/banks/280362b7-ac15-4722-bfa4-e5666007eaf2
  - On step 1 - Code 204: Success
  - On step 2 - Code 404: Error: Not Found
#### Step 1. DELETE /api/banks/{id}
- Request Headers
    ```
    Authorization: Bearer eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1Mjc2OTh9.SYep0eRmjZh5xmr4bzDszLMvCURNGXYnEyBR5gkg0vJfrOAwa8xEeWoQZ2HASyPA5pDvqoF3CQCUnjlZ6HR6PQ
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: 54d8910d-1c27-4841-9652-4c4fd174eba5
    Host: 94.139.255.171:5000
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    ```
- Request Body
    ```   
    Date: Sat, 04 Feb 2023 16:03:19 GMT
    Server: Kestrel
    ```
#### Step 2. GET /api/banks/{id}
- Request Headers
    ```
    Authorization: Bearer eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1Mjc2OTh9.SYep0eRmjZh5xmr4bzDszLMvCURNGXYnEyBR5gkg0vJfrOAwa8xEeWoQZ2HASyPA5pDvqoF3CQCUnjlZ6HR6PQ
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: 2d97dc8e-d5d7-4b43-b2d4-7fd8aadf3cd2
    Host: 94.139.255.171:5000
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    Cookie: refreshToken=fwNoM1Pqeibby5KZ1hCeudYOE76yqVlXT01I0KGkEb1AR%2B99xfGi3b%2B12wp%2B%2F%2BWQZdus%2F4HrTcEK2rvVJ5gh2g%3D%3D
    ```
- Response Headers
    ```
    Content-Type: text/plain; charset=utf-8
    Date: Sat, 04 Feb 2023 16:08:59 GMT
    Server: Kestrel
    Transfer-Encoding: chunked
     ```   
``Resolution: Passed. Everything is OK.``

## GET /api/banks/id
### Test-case 8. Проверка эндпоинта GET /api/banks/id
- URL: http://94.139.255.171:4200/api/banks/48dd1139-c2c0-47cf-98c1-c143b0a48c25
- Expected result: Code 200, Bank info
- Request Headers
    ```
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: ab6021f4-6dfb-499e-9bcc-5b9ef8b87d45
    Host: 94.139.255.171:5000
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    Cookie: refreshToken=fwNoM1Pqeibby5KZ1hCeudYOE76yqVlXT01I0KGkEb1AR%2B99xfGi3b%2B12wp%2B%2F%2BWQZdus%2F4HrTcEK2rvVJ5gh2g%3D%3D
    ```
- Response Headers
    ```
    Content-Type: application/json; charset=utf-8
    Date: Sat, 04 Feb 2023 16:13:49 GMT
    Server: Kestrel
    Transfer-Encoding: chunked
    ```
- Response Body
    ```
    {
    "bankId": "48dd1139-c2c0-47cf-98c1-c143b0a48c25",
    "name": "A-Bank",
    "description": "Описание банка",
    "state": 2,
    "rating": 4.2222223,
    "shortName": "A"
    }
    ```
``Resolution: Passed. Everything is OK.``

## GET /api/banks/Name
### Test-case 9. Проверка эндпоинта GET /api/banks/Name
- URL: http://94.139.255.171:4200/api/banks/Name?name=Сбербанк
- Expected result: Code 200, Bank info
- Request Headers
    ```
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: b1d525b5-f6ff-4719-a8f4-24ac3b867be5
    Host: 94.139.255.171:4200
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    ```
- Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: application/json; charset=utf-8
    date: Sat, 04 Feb 2023 16:16:44 GMT
    server: Kestrel
    transfer-encoding: chunked
    ```
- Response Body
    ```
    {
        "bankId": "69613d84-8d38-499c-bab7-e2e9af928d77",
        "name": "Сбербанк",
        "description": "Отличный интернет-банк.",
        "state": 2,
        "rating": 0,
        "shortName": "Sber"
    },
    {
        "bankId": "b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1",
        "name": "Сбербанк",
        "description": "Отличный интернет-банк.",
        "state": 2,
        "rating": 0,
        "shortName": "Sber"
    }
    ```

``Resolution: Passed. Everything is OK.``

## GET /api/banks/id/feedbacks
### Test-case 10. Проверка эндпоинта GET /api/banks/id/feedbacks
- URL: http://94.139.255.171:5000/api/banks/1406aa87-00bc-4ed5-a128-8e61242de10e/feedbacks
- Expected result: Code 200, feedbacks
- Request Headers
    ```
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: 4b9cee65-ca4e-4922-b6e0-7b1185c81cd9
    Host: 94.139.255.171:5000
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    Cookie: refreshToken=fwNoM1Pqeibby5KZ1hCeudYOE76yqVlXT01I0KGkEb1AR%2B99xfGi3b%2B12wp%2B%2F%2BWQZdus%2F4HrTcEK2rvVJ5gh2g%3D%3D
    ```
- Response Headers
    ```
    Content-Type: application/json; charset=utf-8
    Date: Sat, 04 Feb 2023 16:19:33 GMT
    Server: Kestrel
    Transfer-Encoding: chunked
    ```
- Response Body
    ```
    {
        "feedbackId": "872cce22-1778-4764-b811-54baf663ee23",
        "rating": 5,
        "text": "Good ipoteka, rekomenduyu",
        "date": "2023-01-16T07:00:50.324765Z",
        "state": 2,
        "isLatest": true,
        "pruductId": "292c9f09-cb44-483f-b4c7-0176bacc4289",
        "userId": "c1e8ff80-1b73-48fa-87e1-79590185abc6"
    },
    {
        "feedbackId": "de5f6485-8cdc-45f8-a997-87c06575e995",
        "rating": 4,
        "text": "У банка только один филиал и тот находится в Казани.",
        "date": "2023-01-17T01:20:39.381231Z",
        "state": 2,
        "isLatest": true,
        "pruductId": "292c9f09-cb44-483f-b4c7-0176bacc4289",
        "userId": "fafcbd69-7419-46c0-ab8a-08b57abce527"
    },
    {
        "feedbackId": "3310dbd4-cfc7-4c57-b122-284acb97df4a",
        "rating": 5,
        "text": "norm",
        "date": "2023-01-17T17:29:11.347126Z",
        "state": 2,
        "isLatest": true,
        "pruductId": "292c9f09-cb44-483f-b4c7-0176bacc4289",
        "userId": "f834df33-66c3-43e9-811f-fcab484ad3b8"
    },
    {
        "feedbackId": "f72988ea-154a-4f44-a676-61921313b780",
        "rating": 3,
        "text": "",
        "date": "2023-01-17T17:29:18.517712Z",
        "state": 2,
        "isLatest": true,
        "pruductId": "292c9f09-cb44-483f-b4c7-0176bacc4289",
        "userId": "f834df33-66c3-43e9-811f-fcab484ad3b8"
    },
    {
        "feedbackId": "351dee91-a200-4337-93cc-998d50c0032a",
        "rating": 4,
        "text": "",
        "date": "2023-01-17T17:29:23.469145Z",
        "state": 2,
        "isLatest": true,
        "pruductId": "292c9f09-cb44-483f-b4c7-0176bacc4289",
        "userId": "f834df33-66c3-43e9-811f-fcab484ad3b8"
    },
    {
        "feedbackId": "7ff414e1-def9-48cc-b28c-5be5ad1d74bf",
        "rating": 5,
        "text": "всем ипотеку и на 30 лет ",
        "date": "2023-01-21T13:09:39.163584Z",
        "state": 2,
        "isLatest": true,
        "pruductId": "292c9f09-cb44-483f-b4c7-0176bacc4289",
        "userId": "a16f3f43-7723-43e6-b119-2ba50f59f31d"
    }
    ```

``Resolution: Passed. Everything is OK.``

## GET /api/banks/id/employee
### Test-case 11. Проверка эндпоинта GET /api/banks/id/employee
- URL: http://94.139.255.171:4200/api/banks/85bcc92d-84f6-4149-91d3-3ce42e8c6674/employee
- Expected result: Code 200, employees
- Request Headers
    ```
    Authorization: Bearer eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1Mjk3OTR9.k2PlWuyTIF-DDNSovPKuuPjPUQ3GBv--d5YWCYkTQzaJd3AiQaTWrvbc-nOqzfs1WjJ4XzU3p3Z1xKAzCg08Jw
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: 980e04b0-9241-4b15-99d4-93ae1735ed8a
    Host: 94.139.255.171:5000
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    ```
- Response Headers
    ```
    Content-Type: application/json; charset=utf-8
    Date: Sat, 04 Feb 2023 16:27:14 GMT
    Server: Kestrel
    Transfer-Encoding: chunked
    ```
- Response Body
    ```
    {
        "userId": "c01728bb-5e7f-449b-b73e-f76c365c53df",
        "name": "testuse",
        "birthaday": "2023-01-29T16:13:26.676Z",
        "sex": 0,
        "email": "testuse@test.com",
        "roleId": "b6ac9a45-4032-4289-b439-2cc4d65c3f18",
        "bankId": "85bcc92d-84f6-4149-91d3-3ce42e8c6674",
        "state": 0
    }
    ```

``Resolution: Passed. Everything is OK.``

## GET /api/banks/id/products
### Test-case 12. Проверка эндпоинта GET /api/banks/id/products
- URL: http://94.139.255.171:4200/api/banks/1406aa87-00bc-4ed5-a128-8e61242de10e/products
- Expected result: Code 200, products
- Request Headers
    ```
    Authorization: Bearer eyJhbGciOiJodHRwOi8vd3d3LnczLm9yZy8yMDAxLzA0L3htbGRzaWctbW9yZSNobWFjLXNoYTUxMiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI3Y2JiNWZiOS0zYmQzLTQ1MmYtOTc5NS02NmM3NDU4YmIzNTMiLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9uYW1lIjoiQWRtaW4iLCJodHRwOi8vc2NoZW1hcy54bWxzb2FwLm9yZy93cy8yMDA1LzA1L2lkZW50aXR5L2NsYWltcy9lbWFpbGFkZHJlc3MiOiJhZG1pbkBtYWlsLnJ1IiwiaHR0cDovL3NjaGVtYXMubWljcm9zb2Z0LmNvbS93cy8yMDA4LzA2L2lkZW50aXR5L2NsYWltcy9yb2xlIjoiQWRtaW4iLCJleHAiOjE2NzU1Mjk3OTR9.k2PlWuyTIF-DDNSovPKuuPjPUQ3GBv--d5YWCYkTQzaJd3AiQaTWrvbc-nOqzfs1WjJ4XzU3p3Z1xKAzCg08Jw
    User-Agent: PostmanRuntime/7.30.1
    Accept: */*
    Cache-Control: no-cache
    Postman-Token: 22e6846b-2b44-4b1d-8f21-20443bdb45fa
    Host: 94.139.255.171:4200
    Accept-Encoding: gzip, deflate, br
    Connection: keep-alive
    Cookie: refreshToken=DhOPA1iH0E5ZPgr4Spdi3dcfQqfPXO8yek1cDpzKqbzlQSjeTdeTP0VKsX9Jq4U%2ByNSdmPmC8FjV%2FxN2ScuBuw%3D%3D
    ```
- Response Headers
    ```
    X-Powered-By: Express
    Access-Control-Allow-Origin: *
    connection: close
    content-type: application/json; charset=utf-8
    date: Sat, 04 Feb 2023 17:18:56 GMT
    server: Kestrel
    transfer-encoding: chunked

    ```
- Response Body
    ```
    {
        "productId": "292c9f09-cb44-483f-b4c7-0176bacc4289",
        "name": "Ipoteka",
        "description": "ipoteka na veka",
        "state": 2,
        "avgRating": 4.3333335,
        "bankId": "1406aa87-00bc-4ed5-a128-8e61242de10e",
        "categoryId": "f2d71dda-de6a-4c61-b9c6-e634adf1a9f4"
    },
    {
        "productId": "e8694ee7-3189-4fd0-abdc-7a794cd33cf2",
        "name": "Доллары",
        "description": "",
        "state": 2,
        "avgRating": 5,
        "bankId": "1406aa87-00bc-4ed5-a128-8e61242de10e",
        "categoryId": "6c39297d-c9ac-4c1a-aba9-3078be16eaa5"
    }
    ```

``Resolution: Passed. Everything is OK.``
