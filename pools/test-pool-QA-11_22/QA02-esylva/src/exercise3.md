### GET /api/banks
200 
Response headers
 content-type: application/json; charset=utf-8 
 date: Fri,20 Jan 2023 17:46:16 GMT 
 server: Kestrel 
 transfer-encoding: chunked 

 	
Response body
[
  {
    "bankId": "3ede27f4-f3ec-42fa-95d5-6c21748bc542",
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
    "rating": 4.4,
    "shortName": "A"
  },
  {
    "bankId": "63b02cf9-9125-4e02-ac24-5b5c72a43d94",
    "name": "Alfa-Bank",
    "description": "Modern bank",
    "state": 2,
    "rating": 0,
    "shortName": "Alfa"
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
    "bankId": "291e916b-5283-4a17-b875-6887a89d3cb9",
    "name": "omega bank",
    "description": "я не альфа я омега",
    "state": 2,
    "rating": 0,
    "shortName": "obank"
  },
  {
    "bankId": "1406aa87-00bc-4ed5-a128-8e61242de10e",
    "name": "PlastiqBank",
    "description": "The number one",
    "state": 2,
    "rating": 4.6363635,
    "shortName": "PBank"
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
    "bankId": "1dc808f0-d45f-4baa-b3c2-694e3b83020a",
    "name": "Sberbank",
    "description": "Super bank!",
    "state": 2,
    "rating": 0,
    "shortName": "Sber"
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
    "bankId": "f20bae8a-a9fa-434a-9193-e35c37e7dde5",
    "name": "Scoleray",
    "description": "ьь",
    "state": 2,
    "rating": 0,
    "shortName": "Scoleray"
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
    "bankId": "63790786-d866-4654-9ccb-1a0b9e1d0766",
    "name": "SCOLERAY",
    "description": "Это только начало",
    "state": 2,
    "rating": 0,
    "shortName": "SCOLERAY"
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
    "bankId": "942a54a3-ae28-4704-b5a3-63deee23e2db",
    "name": "string",
    "description": "long integer",
    "state": 2,
    "rating": 0,
    "shortName": "longint"
  },
  {
    "bankId": "ed36e8a3-2446-468a-a8f5-77f1382045ac",
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
    "bankId": "b62a5eb9-b45a-4ffc-971e-6ec5e3283651",
    "name": "string",
    "description": "string",
    "state": 2,
    "rating": 0,
    "shortName": "string"
  },
  {
    "bankId": "22dd818f-30f6-4655-a9f0-6b041e1c0e9f",
    "name": "string",
    "description": "string",
    "state": 2,
    "rating": 0,
    "shortName": "string"
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
    "bankId": "b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1",
    "name": "Сбербанк",
    "description": "Отличный интернет-банк.",
    "state": 2,
    "rating": 0,
    "shortName": "Sber"
  }
]

### GET /api/banks/Name

200
Response headers
 content-type: application/json; charset=utf-8 
 date: Fri,20 Jan 2023 17:49:57 GMT 
 server: Kestrel 
 transfer-encoding: chunked 

	
Response body
[
  {
    "bankId": "3ede27f4-f3ec-42fa-95d5-6c21748bc542",
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
    "rating": 4.4,
    "shortName": "A"
  },
  {
    "bankId": "63b02cf9-9125-4e02-ac24-5b5c72a43d94",
    "name": "Alfa-Bank",
    "description": "Modern bank",
    "state": 2,
    "rating": 0,
    "shortName": "Alfa"
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
    "bankId": "291e916b-5283-4a17-b875-6887a89d3cb9",
    "name": "omega bank",
    "description": "я не альфа я омега",
    "state": 2,
    "rating": 0,
    "shortName": "obank"
  },
  {
    "bankId": "1406aa87-00bc-4ed5-a128-8e61242de10e",
    "name": "PlastiqBank",
    "description": "The number one",
    "state": 2,
    "rating": 4.6363635,
    "shortName": "PBank"
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
    "bankId": "1dc808f0-d45f-4baa-b3c2-694e3b83020a",
    "name": "Sberbank",
    "description": "Super bank!",
    "state": 2,
    "rating": 0,
    "shortName": "Sber"
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
    "bankId": "f20bae8a-a9fa-434a-9193-e35c37e7dde5",
    "name": "Scoleray",
    "description": "ьь",
    "state": 2,
    "rating": 0,
    "shortName": "Scoleray"
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
    "bankId": "63790786-d866-4654-9ccb-1a0b9e1d0766",
    "name": "SCOLERAY",
    "description": "Это только начало",
    "state": 2,
    "rating": 0,
    "shortName": "SCOLERAY"
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
    "bankId": "942a54a3-ae28-4704-b5a3-63deee23e2db",
    "name": "string",
    "description": "long integer",
    "state": 2,
    "rating": 0,
    "shortName": "longint"
  },
  {
    "bankId": "ed36e8a3-2446-468a-a8f5-77f1382045ac",
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
    "bankId": "b62a5eb9-b45a-4ffc-971e-6ec5e3283651",
    "name": "string",
    "description": "string",
    "state": 2,
    "rating": 0,
    "shortName": "string"
  },
  {
    "bankId": "22dd818f-30f6-4655-a9f0-6b041e1c0e9f",
    "name": "string",
    "description": "string",
    "state": 2,
    "rating": 0,
    "shortName": "string"
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
    "bankId": "b57ce0d9-1594-4c20-aa4d-8e5e62b47dc1",
    "name": "Сбербанк",
    "description": "Отличный интернет-банк.",
    "state": 2,
    "rating": 0,
    "shortName": "Sber"
  }
]

Другие запросы требуют введения bankId

### GET /api/banks/{id}/feedbacks
(curl -X 'GET' \
  'http://94.139.255.171:5000/api/banks/63b02cf9-9125-4e02-ac24-5b5c72a43d94/feedbacks' \
  -H 'accept: text/plain')
Request URL
http://94.139.255.171:5000/api/banks/63b02cf9-9125-4e02-ac24-5b5c72a43d94/feedbacks


200
Response headers
 content-type: application/json; charset=utf-8 
 date: Fri,20 Jan 2023 17:55:09 GMT 
 server: Kestrel 
 transfer-encoding: chunked

Response body
[]

### POST /api/banks
200
Response headers
 content-type: application/json; charset=utf-8 
 date: Sat,21 Jan 2023 16:12:27 GMT 
 location: /api/banks/dcf18fa5-fbf0-41b5-bd7c-0ce972e192a2 
 server: Kestrel 
 transfer-encoding: chunked

{
  "bankId": "dcf18fa5-fbf0-41b5-bd7c-0ce972e192a2",
  "name": "Erryk Sylva's Bank",
  "description": "Erryk Sylva's Bank",
  "state": 2,
  "rating": 0,
  "shortName": "ESB"
}



### PATCH /api/banks/{id}
200
Response headers
 content-type: application/json; charset=utf-8 
 date: Sat,21 Jan 2023 16:18:20 GMT 
 server: Kestrel 
 transfer-encoding: chunked

 {
  "bankId": "ed36e8a3-2446-468a-a8f5-77f1382045ac",
  "name": "Выхухоль-Банк",
  "description": "Банк для сбора средств для животных",
  "state": 2,
  "rating": 0,
  "shortName": "ВБ"
}

### DELETE /api/banks/{id}
204
	
Response headers
 date: Sat,21 Jan 2023 16:21:05 GMT 
 server: Kestrel 

### GET /api/banks/{id}/employee
200
Response headers
 content-type: application/json; charset=utf-8 
 date: Sat,21 Jan 2023 16:22:29 GMT 
 server: Kestrel 
 transfer-encoding: chunked

Response body
[
  {
    "userId": "7e3b18a9-e820-436d-a8a9-631191f02f76",
    "name": "in inci",
    "birthaday": "1959-02-11T09:49:13.987Z",
    "sex": 1,
    "email": "VcMumOrnAFH@UCVBQlnRoCo.ylz",
    "roleId": "4b8ee0fd-3f36-444c-8cd8-e6f64643e659",
    "bankId": "ed36e8a3-2446-468a-a8f5-77f1382045ac",
    "state": 0
  }
]